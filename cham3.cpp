#include <iostream>
#include <cstdlib>
#include <ctime>
#include <thread>
#include <chrono>
#include "cham3.h"
#include "cursor.h"
#include "screen.h"
#include "city.h"

using namespace std;
int sumMoney = 500; // 기본의뢰비
int turn; // 0이면 플레이어공격, 1이면 양아치공격
int p_ult = 0; // 플레이어의 궁게이지

// 텍스트창 ui
void init_UI() {
    scr.clear();
    cout << "\033[10;0H┌─────────────────────────────────────────────────────────────────────────────────────┐\n";
    cout << "\033[20;0H└─────────────────────────────────────────────────────────────────────────────────────┘\n";
}

void textClear() {
    cout << "\033[12;0H\033[2K";
    cout << "\033[13;0H\033[2K";
    cout << "\033[14;0H\033[2K";
    cout << "\033[15;0H\033[2K";
    cout << "\033[16;0H\033[2K";
    cout << "\033[17;0H\033[2K";
    cout << "\033[12;0H";
}

void imgClear() {
    cout << "\033[3;0H\033[2K";
    cout << "\033[4;0H\033[2K";
    cout << "\033[5;0H\033[2K";
    cout << "\033[6;0H\033[2K";
    cout << "\033[7;0H\033[2K";
    cout << "\033[8;0H\033[2K";
    cout << "\033[5;0H";
}

// 궁극기 ui
void ultimgUpdate(Player player, Badman badman) {
    imgClear();

    cout << "\033[8;39H";
    for (int i = 0; i < player.heart; i++) {
        cout << "♥";
    }
    cout << "\033[8;48H";
    for (int i = 0; i < badman.heart; i++) {
        cout << "♥";
    }
    cout << "\033[0;10H";
    for (int i = 0; i < p_ult; i++) {
        cout << "★";
    }

    cout << "\033[5;38H             \\0/\n";
    cout << "\033[6;38H   = = つㅡ)o | \n";
    cout << "\033[7;38H             // \n";

}

// 플레이어와 양아치 ui
void imgUpdate(Player player, Badman badman) {
    imgClear();
    // 생명 및 궁게이지 출력
    cout << "\033[8;39H";
    for (int i = 0; i < player.heart; i++) {
        cout << "♥";
    }
    cout << "\033[8;48H";
    for (int i = 0; i < badman.heart; i++) {
        cout << "♥";
    }
    cout << "\033[0;10H";
    for (int i = 0; i < p_ult; i++) {
        cout << "★";
    }

    // 기본
    if (player.choice == 0 && badman.choice == 0) {
        cout << "\033[5;38H  o        0\n";
        cout << "\033[6;38H /|\\      (|) \n";
        cout << "\033[7;38H  /)      (\\ \n";
        cout << "\033[12;0H";
    }
    // 플레이어의 공격
    else if (player.choice < 0 || player.choice>4) {
        cout << "\033[5;38H  o        0\n";
        cout << "\033[6;38H /|￣     (|) \n";
        cout << "\033[7;38H  /)      (\\ \n";
        cout << "\033[12;0H";
    }
    else if (player.choice == 0 && p_ult < 3) {
        cout << "\033[5;38H  o        0\n";
        cout << "\033[6;38H /|￣     (|) \n";
        cout << "\033[7;38H  /)      (\\ \n";
        cout << "\033[12;0H";
    }
    else if (turn == 0 && player.choice == badman.choice) {
        cout << "\033[5;38H  o         0\n";
        cout << "\033[6;38H /|￣  hit /|\\ \n";
        cout << "\033[7;38H  /)       // \n";
        cout << "\033[12;0H";
    }
    else if (turn == 0 && player.choice != badman.choice) {
        cout << "\033[5;38H  o         \\0/\n";
        cout << "\033[6;38H /|￣  miss  | \n";
        cout << "\033[7;38H  /)        (\\ \n";
        cout << "\033[12;0H";
    }
    // 양아치의 공격
    else if (turn == 1 && player.choice == badman.choice) {
        cout << "\033[5;38Ho          0\n";
        cout << "\033[6;38H/|\\ hit! ￣|\\ \n";
        cout << "\033[7;38H \\\\        (\\ \n";
        cout << "\033[12;0H";
    }
    else if (turn == 1 && player.choice != badman.choice) {
        cout << "\033[5;38H o         0/\n";
        cout << "\033[6;38H/|\\ miss ￣| \n";
        cout << "\033[7;38H \\\\       (\\ \n";
        cout << "\033[12;0H";
    }
}

void intro() {
    cout << "\033[5;35H o              .˛ 。°. 。\n";
    cout << "\033[6;35H/|\\    ㅁ .。°\n";
    cout << "\033[7;35H /)\n";

    cout << "\033[12;0H   알바를 찾아나선 당신앞에 의문의 전단지가 날라왔다.\n";
    //std::this_thread::sleep_for(std::chrono::seconds(3));
    cout << "   [ 기본의뢰비 500원에 양아치들 참교육 성공시 추가보너스도 드립니다~ ]\n";
    //std::this_thread::sleep_for(std::chrono::seconds(5));
    cout << "   꽤나 짭짤한 금액이다!\n   ...오랜만에 힘 좀 써볼까?\n\n";
    //std::this_thread::sleep_for(std::chrono::seconds(5));
    cout << "   (아무키나 눌러 참참참 게임시작)";
    getchar();
    textClear();
}

void badEnding() {
    textClear();
    imgClear();

    cout << "\033[5;30H\\o/               0/\n";
    cout << "\033[6;30H |  = =         ￣| = =\n";
    cout << "\033[7;30H (\\               (\\ \n";

    cout << "\033[12;0H   당신은 양아치에게 두들겨맞고 간신히 도망쳐나왔다.\n";
    //std::this_thread::sleep_for(std::chrono::seconds(3));
    cout << "   [ 양아치들이 아직 기세등등하지만 그래도 노력해주셔서 감사합니다... ]\n";
    //std::this_thread::sleep_for(std::chrono::seconds(3));
    cout << "   의뢰비로 " << sumMoney << "원을 받았다.\n";
    //std::this_thread::sleep_for(std::chrono::seconds(5));
    cout << "   마음이 찝찝하다, 수련하고 다시 양아치들을 잡으러 오자.\n\n";
    //std::this_thread::sleep_for(std::chrono::seconds(5));
    cout << "   (아무키나 눌러 게임종료)";
    getchar();
    city.money += sumMoney;
}

void happyEnding() {
    textClear();
    imgClear();

    cout << "\033[5;35H  o             .˛ 。°. 。\n";
    cout << "\033[6;35H (|)    ㅁ .。°\n";
    cout << "\033[7;35H / \\\n";
    cout << "\033[12;0H";

    cout << "\033[12;0H   당신은 양아치들을 모두 참교육해주었다!\n";
    //std::this_thread::sleep_for(std::chrono::seconds(5));
    cout << "   잠시일뿐일지 모르나 당신은 마을의 평화를 지켜낸것이다!\n";
    //std::this_thread::sleep_for(std::chrono::seconds(3));
    cout << "   [ 양아치들이 덕분에 조용해졌어요. 감사합니다^^ ]\n";
    //std::this_thread::sleep_for(std::chrono::seconds(3));
    cout << "   의뢰비에 보너스까지 총 " << sumMoney << "원을 받았다.\n";
    //std::this_thread::sleep_for(std::chrono::seconds(5));
    cout << "   ...당신의 마음과 지갑이 웅장해졌다!\n\n";
    //std::this_thread::sleep_for(std::chrono::seconds(5));
    cout << "   (아무키나 눌러 게임종료)";
    getchar();
    city.money += sumMoney;
}

//------------------------------------- play-------------------------------------------

void Player::setChoice() {
    cin >> Player::choice;
    cin.ignore();
}

void Badman::setChoice() {
    choice = rand() % 4 + 1;
}

int Game::fight() {
    while (1) {
        cout << "\033[0;0H[ " << round << "/" << stage << " ] " << endl;

        imgClear();
        textClear();
        player.choice = 0, badman.choice = 0; //선택초기화
        imgUpdate(player, badman); // 기본화면 출력됨
        turn = 0;

        // 플레이어 선공격
        while (1) {
            imgClear();
            textClear();
            player.choice = 0, badman.choice = 0; //선택초기화
            imgUpdate(player, badman);
            turn = 0;

            cout << "   <플레이어의 공격>\n\n";
            cout << "   상하좌우 중 선택 (1:상, 2:하, 3:좌, 4:우 | 0:궁극기) : ";
            player.setChoice();
            badman.setChoice();
            // 궁극기 선택시
            if (player.choice == 0) {
                // 궁극기 발동 성공
                if (p_ult >= 3) {
                    cout << "   당신은 궁극기를 시전했다.\n";
                    cout << "   효과는 굉장했다!";
                    badman.heart -= 2;
                    ultimgUpdate(player, badman);
                    getchar();

                    p_ult -= 3;
                    cout << "\033[0;10H       "; // 궁극기 표시 지워주기
                    if (badman.heart <= 0) { return 1; }
                    break;
                }
                // 궁극기 발동 실패시 다시선택
                else {
                    cout << "   이런, 아직 당신의 궁극기는 준비되지 않았다.\n";
                    cout << "   양아치가 당신을 멀뚱이 쳐다보고 있다.\n";
                    cout << "   뻘쭘한 당신은 급하게 다시 주먹을 휘두른다.\n";
                    imgUpdate(player, badman);
                    getchar();
                    continue;
                }
            }
            // 잘못 선택시 다시 선택
            else if (player.choice < 0 || player.choice>4) {
                cout << "   이런, 당신은 이상한 곳을 겨냥했다.\n";
                cout << "   양아치가 헛스윙한 당신을 비웃는 듯 하다.\n";
                cout << "   뻘쭘한 당신은 급하게 다시 주먹을 휘두른다.\n";
                imgUpdate(player, badman);
                getchar();
                continue;
            }
            // 제대로 선택시
            else {
                cout << "   플레이어 선택: " << player.choice << " | 양아치 선택: " << badman.choice << endl;
                if (player.choice == badman.choice) {
                    cout << "   당신은 양아치를 힘껏 때렸다!";
                    badman.heart--;
                    imgUpdate(player, badman);
                    getchar();
                    if (badman.heart <= 0) { return 1; } // 스테이지 클리어
                }
                else {
                    cout << "   양아치가 공격을 가볍게 피했다!";
                    imgUpdate(player, badman);
                    getchar();
                }
                break;
            }
        }

        // 양아치의 후공격
        while (1) {
            imgClear();
            textClear();
            player.choice = 0, badman.choice = 0; //선택초기화
            imgUpdate(player, badman);
            turn = 1;

            cout << "   <양아치의 공격>\n\n";
            cout << "   상하좌우 중 선택 (1:상, 2:하, 3:좌, 4:우) : ";
            player.setChoice();
            badman.setChoice();
            // 플레이어가 잘못 선택시 공격성공
            if (player.choice <= 0 || player.choice > 4) {
                cout << "   플레이어 선택: " << player.choice << " | 양아치 선택: " << badman.choice << endl;
                cout << "   저런, 당신은 재빠르게 피하지 못했다.\n";
                cout << "   가만히 서있다가 그대로 얻어맞았다.\n";
                player.choice = 1, badman.choice = 1;
                player.heart--;
                imgUpdate(player, badman);
                getchar();
                if (player.heart <= 0) { return 0; }
                break;
            }
            // 양아치의 공격 성공
            cout << "   플레이어 선택: " << player.choice << " | 양아치 선택: " << badman.choice << endl;
            if (player.choice == badman.choice) {
                cout << "   양아치가 당신을 세게 때렸다!";
                player.heart--;
                imgUpdate(player, badman);
                getchar();
                if (player.heart <= 0) { return 0; }
                break;
            }
            // 양아치의 공격 실패
            else {
                cout << "   당신은 날렵하게 주먹을 피했다!";
                imgUpdate(player, badman);
                p_ult++;
                if (p_ult == 3) {
                    cout << "\033[0;10H☆☆☆";
                }
                getchar();
                break;
            }
        }
    }
}

// 돈계산
void calMoney(int randomHeart, int victoryStage, int victory) {
    int money = 0;
    if (victory == 1) {
        money += randomHeart * 100; // 무찌른 양아치의 체력에 따라 100원씩 보너스
        money *= victoryStage;  // stage따라 *보너스 -> 언제든 바꿔도 됨
        sumMoney += money;
    }
}

int gameplay() {
    srand(time(NULL));

    init_UI();
    intro();

    Player player;
    int stage = rand() % 3 + 1; // 랜덤 스테이지 1~3
    int victory; // 승패확인용

    for (int i = 1; i <= stage; i++) {
        int randomHeart = rand() % 3 + 2; // 랜덤 양아치 체력 2~4

        Badman badman(randomHeart);
        Game game(i, stage, player, badman);
        victory = game.fight(); // 플레이어가 승리시 return 1

        calMoney(randomHeart, i, victory); //양아치 체력(등급)따라 받는돈 다름, 전투횟수에 따른 추가수익

        //승리
        if (victory == 1) {
            // 마지막 스테이지 승리한 경우 해피엔딩
            if (i == stage) {
                break;
            }

            // 마지막 스테이지 아니면 다음 스테이지로
            imgClear();
            textClear();
            cout << "\033[5;40H  o        0\n";
            cout << "\033[6;40H /|\\      /|\\ = = \n";
            cout << "\033[7;40H  /)       (\\ \n";

            cout << "\033[8;41H";
            for (int i = 0; i < player.heart; i++) {
                cout << "♥";
            }

            cout << "\033[12;0H   쉴틈도 없이 다른 양아치가 당신에게 달려든다!";
            getchar();
            continue;
        }
        //패배
        else {
            badEnding();
            scr.clear();
            scr.drawEdge();
            return 0; //게임종료
        }
    }
    happyEnding();
    scr.clear();
    scr.drawEdge();
    return 0;
}