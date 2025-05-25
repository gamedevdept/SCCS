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
int sumMoney = 500; // �⺻�Ƿں�
int turn; // 0�̸� �÷��̾����, 1�̸� ���ġ����
int p_ult = 0; // �÷��̾��� �ð�����

// �ؽ�Ʈâ ui
void init_UI() {
    scr.clear();
    cout << "\033[10;0H������������������������������������������������������������������������������������������������������������������������������������������������������������������������������\n";
    cout << "\033[20;0H������������������������������������������������������������������������������������������������������������������������������������������������������������������������������\n";
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

// �ñر� ui
void ultimgUpdate(Player player, Badman badman) {
    imgClear();

    cout << "\033[8;39H";
    for (int i = 0; i < player.heart; i++) {
        cout << "��";
    }
    cout << "\033[8;48H";
    for (int i = 0; i < badman.heart; i++) {
        cout << "��";
    }
    cout << "\033[0;10H";
    for (int i = 0; i < p_ult; i++) {
        cout << "��";
    }

    cout << "\033[5;38H             \\0/\n";
    cout << "\033[6;38H   = = �Ĥ�)o | \n";
    cout << "\033[7;38H             // \n";

}

// �÷��̾�� ���ġ ui
void imgUpdate(Player player, Badman badman) {
    imgClear();
    // ���� �� �ð����� ���
    cout << "\033[8;39H";
    for (int i = 0; i < player.heart; i++) {
        cout << "��";
    }
    cout << "\033[8;48H";
    for (int i = 0; i < badman.heart; i++) {
        cout << "��";
    }
    cout << "\033[0;10H";
    for (int i = 0; i < p_ult; i++) {
        cout << "��";
    }

    // �⺻
    if (player.choice == 0 && badman.choice == 0) {
        cout << "\033[5;38H  o        0\n";
        cout << "\033[6;38H /|\\      (|) \n";
        cout << "\033[7;38H  /)      (\\ \n";
        cout << "\033[12;0H";
    }
    // �÷��̾��� ����
    else if (player.choice < 0 || player.choice>4) {
        cout << "\033[5;38H  o        0\n";
        cout << "\033[6;38H /|��     (|) \n";
        cout << "\033[7;38H  /)      (\\ \n";
        cout << "\033[12;0H";
    }
    else if (player.choice == 0 && p_ult < 3) {
        cout << "\033[5;38H  o        0\n";
        cout << "\033[6;38H /|��     (|) \n";
        cout << "\033[7;38H  /)      (\\ \n";
        cout << "\033[12;0H";
    }
    else if (turn == 0 && player.choice == badman.choice) {
        cout << "\033[5;38H  o         0\n";
        cout << "\033[6;38H /|��  hit /|\\ \n";
        cout << "\033[7;38H  /)       // \n";
        cout << "\033[12;0H";
    }
    else if (turn == 0 && player.choice != badman.choice) {
        cout << "\033[5;38H  o         \\0/\n";
        cout << "\033[6;38H /|��  miss  | \n";
        cout << "\033[7;38H  /)        (\\ \n";
        cout << "\033[12;0H";
    }
    // ���ġ�� ����
    else if (turn == 1 && player.choice == badman.choice) {
        cout << "\033[5;38Ho          0\n";
        cout << "\033[6;38H/|\\ hit! ��|\\ \n";
        cout << "\033[7;38H \\\\        (\\ \n";
        cout << "\033[12;0H";
    }
    else if (turn == 1 && player.choice != badman.choice) {
        cout << "\033[5;38H o         0/\n";
        cout << "\033[6;38H/|\\ miss ��| \n";
        cout << "\033[7;38H \\\\       (\\ \n";
        cout << "\033[12;0H";
    }
}

void intro() {
    cout << "\033[5;35H o              .�� ����. ��\n";
    cout << "\033[6;35H/|\\    �� .����\n";
    cout << "\033[7;35H /)\n";

    cout << "\033[12;0H   �˹ٸ� ã�Ƴ��� ��žտ� �ǹ��� �������� ����Դ�.\n";
    //std::this_thread::sleep_for(std::chrono::seconds(3));
    cout << "   [ �⺻�Ƿں� 500���� ���ġ�� ������ ������ �߰����ʽ��� �帳�ϴ�~ ]\n";
    //std::this_thread::sleep_for(std::chrono::seconds(5));
    cout << "   �ϳ� ¬©�� �ݾ��̴�!\n   ...�������� �� �� �Ẽ��?\n\n";
    //std::this_thread::sleep_for(std::chrono::seconds(5));
    cout << "   (�ƹ�Ű�� ���� ������ ���ӽ���)";
    getchar();
    textClear();
}

void badEnding() {
    textClear();
    imgClear();

    cout << "\033[5;30H\\o/               0/\n";
    cout << "\033[6;30H |  = =         ��| = =\n";
    cout << "\033[7;30H (\\               (\\ \n";

    cout << "\033[12;0H   ����� ���ġ���� �ε�ܸ°� ������ �����ĳ��Դ�.\n";
    //std::this_thread::sleep_for(std::chrono::seconds(3));
    cout << "   [ ���ġ���� ���� �⼼��������� �׷��� ������ּż� �����մϴ�... ]\n";
    //std::this_thread::sleep_for(std::chrono::seconds(3));
    cout << "   �Ƿں�� " << sumMoney << "���� �޾Ҵ�.\n";
    //std::this_thread::sleep_for(std::chrono::seconds(5));
    cout << "   ������ �����ϴ�, �����ϰ� �ٽ� ���ġ���� ������ ����.\n\n";
    //std::this_thread::sleep_for(std::chrono::seconds(5));
    cout << "   (�ƹ�Ű�� ���� ��������)";
    getchar();
    city.money += sumMoney;
}

void happyEnding() {
    textClear();
    imgClear();

    cout << "\033[5;35H  o             .�� ����. ��\n";
    cout << "\033[6;35H (|)    �� .����\n";
    cout << "\033[7;35H / \\\n";
    cout << "\033[12;0H";

    cout << "\033[12;0H   ����� ���ġ���� ��� ���������־���!\n";
    //std::this_thread::sleep_for(std::chrono::seconds(5));
    cout << "   ����ϻ����� �𸣳� ����� ������ ��ȭ�� ���ѳ����̴�!\n";
    //std::this_thread::sleep_for(std::chrono::seconds(3));
    cout << "   [ ���ġ���� ���п� �����������. �����մϴ�^^ ]\n";
    //std::this_thread::sleep_for(std::chrono::seconds(3));
    cout << "   �Ƿں� ���ʽ����� �� " << sumMoney << "���� �޾Ҵ�.\n";
    //std::this_thread::sleep_for(std::chrono::seconds(5));
    cout << "   ...����� ������ ������ ����������!\n\n";
    //std::this_thread::sleep_for(std::chrono::seconds(5));
    cout << "   (�ƹ�Ű�� ���� ��������)";
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
        player.choice = 0, badman.choice = 0; //�����ʱ�ȭ
        imgUpdate(player, badman); // �⺻ȭ�� ��µ�
        turn = 0;

        // �÷��̾� ������
        while (1) {
            imgClear();
            textClear();
            player.choice = 0, badman.choice = 0; //�����ʱ�ȭ
            imgUpdate(player, badman);
            turn = 0;

            cout << "   <�÷��̾��� ����>\n\n";
            cout << "   �����¿� �� ���� (1:��, 2:��, 3:��, 4:�� | 0:�ñر�) : ";
            player.setChoice();
            badman.setChoice();
            // �ñر� ���ý�
            if (player.choice == 0) {
                // �ñر� �ߵ� ����
                if (p_ult >= 3) {
                    cout << "   ����� �ñر⸦ �����ߴ�.\n";
                    cout << "   ȿ���� �����ߴ�!";
                    badman.heart -= 2;
                    ultimgUpdate(player, badman);
                    getchar();

                    p_ult -= 3;
                    cout << "\033[0;10H       "; // �ñر� ǥ�� �����ֱ�
                    if (badman.heart <= 0) { return 1; }
                    break;
                }
                // �ñر� �ߵ� ���н� �ٽü���
                else {
                    cout << "   �̷�, ���� ����� �ñر�� �غ���� �ʾҴ�.\n";
                    cout << "   ���ġ�� ����� �ֶ��� �Ĵٺ��� �ִ�.\n";
                    cout << "   ������ ����� ���ϰ� �ٽ� �ָ��� �ֵθ���.\n";
                    imgUpdate(player, badman);
                    getchar();
                    continue;
                }
            }
            // �߸� ���ý� �ٽ� ����
            else if (player.choice < 0 || player.choice>4) {
                cout << "   �̷�, ����� �̻��� ���� �ܳ��ߴ�.\n";
                cout << "   ���ġ�� �꽺���� ����� ����� �� �ϴ�.\n";
                cout << "   ������ ����� ���ϰ� �ٽ� �ָ��� �ֵθ���.\n";
                imgUpdate(player, badman);
                getchar();
                continue;
            }
            // ����� ���ý�
            else {
                cout << "   �÷��̾� ����: " << player.choice << " | ���ġ ����: " << badman.choice << endl;
                if (player.choice == badman.choice) {
                    cout << "   ����� ���ġ�� ���� ���ȴ�!";
                    badman.heart--;
                    imgUpdate(player, badman);
                    getchar();
                    if (badman.heart <= 0) { return 1; } // �������� Ŭ����
                }
                else {
                    cout << "   ���ġ�� ������ ������ ���ߴ�!";
                    imgUpdate(player, badman);
                    getchar();
                }
                break;
            }
        }

        // ���ġ�� �İ���
        while (1) {
            imgClear();
            textClear();
            player.choice = 0, badman.choice = 0; //�����ʱ�ȭ
            imgUpdate(player, badman);
            turn = 1;

            cout << "   <���ġ�� ����>\n\n";
            cout << "   �����¿� �� ���� (1:��, 2:��, 3:��, 4:��) : ";
            player.setChoice();
            badman.setChoice();
            // �÷��̾ �߸� ���ý� ���ݼ���
            if (player.choice <= 0 || player.choice > 4) {
                cout << "   �÷��̾� ����: " << player.choice << " | ���ġ ����: " << badman.choice << endl;
                cout << "   ����, ����� ������� ������ ���ߴ�.\n";
                cout << "   ������ ���ִٰ� �״�� ���¾Ҵ�.\n";
                player.choice = 1, badman.choice = 1;
                player.heart--;
                imgUpdate(player, badman);
                getchar();
                if (player.heart <= 0) { return 0; }
                break;
            }
            // ���ġ�� ���� ����
            cout << "   �÷��̾� ����: " << player.choice << " | ���ġ ����: " << badman.choice << endl;
            if (player.choice == badman.choice) {
                cout << "   ���ġ�� ����� ���� ���ȴ�!";
                player.heart--;
                imgUpdate(player, badman);
                getchar();
                if (player.heart <= 0) { return 0; }
                break;
            }
            // ���ġ�� ���� ����
            else {
                cout << "   ����� �����ϰ� �ָ��� ���ߴ�!";
                imgUpdate(player, badman);
                p_ult++;
                if (p_ult == 3) {
                    cout << "\033[0;10H�١١�";
                }
                getchar();
                break;
            }
        }
    }
}

// �����
void calMoney(int randomHeart, int victoryStage, int victory) {
    int money = 0;
    if (victory == 1) {
        money += randomHeart * 100; // ��� ���ġ�� ü�¿� ���� 100���� ���ʽ�
        money *= victoryStage;  // stage���� *���ʽ� -> ������ �ٲ㵵 ��
        sumMoney += money;
    }
}

int gameplay() {
    srand(time(NULL));

    init_UI();
    intro();

    Player player;
    int stage = rand() % 3 + 1; // ���� �������� 1~3
    int victory; // ����Ȯ�ο�

    for (int i = 1; i <= stage; i++) {
        int randomHeart = rand() % 3 + 2; // ���� ���ġ ü�� 2~4

        Badman badman(randomHeart);
        Game game(i, stage, player, badman);
        victory = game.fight(); // �÷��̾ �¸��� return 1

        calMoney(randomHeart, i, victory); //���ġ ü��(���)���� �޴µ� �ٸ�, ����Ƚ���� ���� �߰�����

        //�¸�
        if (victory == 1) {
            // ������ �������� �¸��� ��� ���ǿ���
            if (i == stage) {
                break;
            }

            // ������ �������� �ƴϸ� ���� ����������
            imgClear();
            textClear();
            cout << "\033[5;40H  o        0\n";
            cout << "\033[6;40H /|\\      /|\\ = = \n";
            cout << "\033[7;40H  /)       (\\ \n";

            cout << "\033[8;41H";
            for (int i = 0; i < player.heart; i++) {
                cout << "��";
            }

            cout << "\033[12;0H   ��ƴ�� ���� �ٸ� ���ġ�� ��ſ��� �޷����!";
            getchar();
            continue;
        }
        //�й�
        else {
            badEnding();
            scr.clear();
            scr.drawEdge();
            return 0; //��������
        }
    }
    happyEnding();
    scr.clear();
    scr.drawEdge();
    return 0;
}