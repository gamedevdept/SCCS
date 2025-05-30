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
    cout << "\033[23;40H������������������������������������������������������������������������������������������������������������������������������������������������������������������������������\n";
    cout << "\033[33;40H������������������������������������������������������������������������������������������������������������������������������������������������������������������������������\n";
}

void textClear() {
    cout << "\033[25;0H\033[2K";
    cout << "\033[26;0H\033[2K";
    cout << "\033[27;0H\033[2K";
    cout << "\033[28;0H\033[2K";
    cout << "\033[29;0H\033[2K";
    cout << "\033[30;0H\033[2K";
    cout << "\033[31;0H";
}

void imgClear() {
    cout << "\033[16;0H\033[2K";
    cout << "\033[17;0H\033[2K";
    cout << "\033[18;0H\033[2K";
    cout << "\033[19;0H\033[2K";
    cout << "\033[20;0H\033[2K";
    cout << "\033[21;0H\033[2K";
    cout << "\033[22;0H";
}

// �ñر� ui
void ultimgUpdate(Player player, Badman badman) {
    imgClear();

    cout << "\033[21;74H";
    for (int i = 0; i < player.heart; i++) {
        cout << "��";
    }
    cout << "\033[21;83H";
    for (int i = 0; i < badman.heart; i++) {
        cout << "��";
    }
    cout << "\033[13;50H";
    for (int i = 0; i < p_ult; i++) {
        cout << "��";
    }

    cout << "\033[18;73H             \\0/\n";
    cout << "\033[19;73H   = = �Ĥ�)o | \n";
    cout << "\033[20;73H             // \n";

}

// �÷��̾�� ���ġ ui
void imgUpdate(Player player, Badman badman) {
    imgClear();
    // ���� �� �ð����� ���
    cout << "\033[21;74H";
    for (int i = 0; i < player.heart; i++) {
        cout << "��";
    }
    cout << "\033[21;83H";
    for (int i = 0; i < badman.heart; i++) {
        cout << "��";
    }
    cout << "\033[13;50H";
    for (int i = 0; i < p_ult; i++) {
        cout << "��";
    }

    // �⺻
    if (player.choice == 0 && badman.choice == 0) {
        cout << "\033[18;73H  o        0\n";
        cout << "\033[19;73H /|\\      (|) \n";
        cout << "\033[20;73H  /)      (\\ \n";
        cout << "\033[12;0H";
    }
    // �÷��̾��� ����
    else if (player.choice < 0 || player.choice>4) {
        cout << "\033[18;73H  o        0\n";
        cout << "\033[19;73H /|��     (|) \n";
        cout << "\033[20;73H  /)      (\\ \n";
        cout << "\033[12;0H";
    }
    else if (player.choice == 0 && p_ult < 3) {
        cout << "\033[18;73H  o        0\n";
        cout << "\033[19;73H /|��     (|) \n";
        cout << "\033[20;73H  /)      (\\ \n";
        cout << "\033[12;0H";
    }
    else if (turn == 0 && player.choice == badman.choice) {
        cout << "\033[18;73H  o         0\n";
        cout << "\033[19;73H /|��  hit /|\\ \n";
        cout << "\033[20;73H  /)       // \n";
        cout << "\033[12;0H";
    }
    else if (turn == 0 && player.choice != badman.choice) {
        cout << "\033[18;73H  o         \\0/\n";
        cout << "\033[19;73H /|��  miss  | \n";
        cout << "\033[20;73H  /)        (\\ \n";
        cout << "\033[12;0H";
    }
    // ���ġ�� ����
    else if (turn == 1 && player.choice == badman.choice) {
        cout << "\033[18;73Ho          0\n";
        cout << "\033[19;73H/|\\ hit! ��|\\ \n";
        cout << "\033[20;73H \\\\        (\\ \n";
        cout << "\033[12;0H";
    }
    else if (turn == 1 && player.choice != badman.choice) {
        cout << "\033[18;70H o         0/\n";
        cout << "\033[19;70H/|\\ miss ��| \n";
        cout << "\033[20;70H \\\\       (\\ \n";
        cout << "\033[12;0H";
    }
}

void intro() {
    cout << "\033[18;70H o              .�� ����. ��\n";
    cout << "\033[19;70H/|\\    �� .����\n";
    cout << "\033[20;70H /)\n";

    cout << "\033[25;40H   �˹ٸ� ã�Ƴ��� ��žտ� �ǹ��� �������� ����Դ�.\n";
    //std::this_thread::sleep_for(std::chrono::seconds(3));
    cout << "\033[26;40H   [ �⺻�Ƿں� 500���� ���ġ�� ������ ������ �߰����ʽ��� �帳�ϴ�~ ]\n";
    //std::this_thread::sleep_for(std::chrono::seconds(5));
    cout << "\033[27;40H   �ϳ� ¬©�� �ݾ��̴�!\n\033[28;40H   ...�������� �� �� �Ẽ��?\n\n";
    //std::this_thread::sleep_for(std::chrono::seconds(5));
    cout << "\033[30;40H   (�ƹ�Ű�� ���� ������ ���ӽ���)";
    getchar();
    textClear();
}

void badEnding() {
    textClear();
    imgClear();

    cout << "\033[18;65H\\o/               0/\n";
    cout << "\033[19;65H |  = =         ��| = =\n";
    cout << "\033[20;65H (\\               (\\ \n";

    cout << "\033[25;40H   ����� ���ġ���� �ε�ܸ°� ������ �����ĳ��Դ�.\n";
    //std::this_thread::sleep_for(std::chrono::seconds(3));
    cout << "\033[26;40H   [ ���ġ���� ���� �⼼��������� �׷��� ������ּż� �����մϴ�... ]\n";
    //std::this_thread::sleep_for(std::chrono::seconds(3));
    cout << "\033[27;40H   �Ƿں�� " << sumMoney << "���� �޾Ҵ�.\n";
    //std::this_thread::sleep_for(std::chrono::seconds(5));
    cout << "\033[28;40H   ������ �����ϴ�, �����ϰ� �ٽ� ���ġ���� ������ ����.\n\n";
    //std::this_thread::sleep_for(std::chrono::seconds(5));
    cout << "\033[30;40H   (�ƹ�Ű�� ���� ��������)";
    getchar();
    city.money += sumMoney;
}

void happyEnding() {
    textClear();
    imgClear();

    cout << "\033[18;70H  o             .�� ����. ��\n";
    cout << "\033[19;70H (|)    �� .����\n";
    cout << "\033[20;70H / \\\n";
    cout << "\033[12;0H";

    cout << "\033[25;40H   ����� ���ġ���� ��� ���������־���!\n";
    //std::this_thread::sleep_for(std::chrono::seconds(5));
    cout << "\033[26;40H   ����ϻ����� �𸣳� ����� ������ ��ȭ�� ���ѳ����̴�!\n";
    //std::this_thread::sleep_for(std::chrono::seconds(3));
    cout << "\033[27;40H   [ ���ġ���� ���п� �����������. �����մϴ�^^ ]\n";
    //std::this_thread::sleep_for(std::chrono::seconds(3));
    cout << "\033[28;40H   �Ƿں� ���ʽ����� �� " << sumMoney << "���� �޾Ҵ�.\n";
    //std::this_thread::sleep_for(std::chrono::seconds(5));
    cout << "\033[29;40H   ...����� ������ ������ ����������!\n\n";
    //std::this_thread::sleep_for(std::chrono::seconds(5));
    cout << "\033[31;40H   (�ƹ�Ű�� ���� ��������)";
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
        cout << "\033[13;40H[ " << round << "/" << stage << " ] " << endl;

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

            cout << "\033[25;40H   <�÷��̾��� ����>\n\n";
            cout << "\033[27;40H   �����¿� �� ���� (1:��, 2:��, 3:��, 4:�� | 0:�ñر�) : ";
            player.setChoice();
            badman.setChoice();
            // �ñر� ���ý�
            if (player.choice == 0) {
                // �ñر� �ߵ� ����
                if (p_ult >= 3) {
                    cout << "\033[28;40H   ����� �ñر⸦ �����ߴ�.\n";
                    cout << "\033[29;40H   ȿ���� �����ߴ�!";
                    badman.heart -= 2;
                    ultimgUpdate(player, badman);
                    getchar();

                    p_ult -= 3;
                    cout << "\033[13;50H       "; // �ñر� ǥ�� �����ֱ�
                    if (badman.heart <= 0) { return 1; }
                    break;
                }
                // �ñر� �ߵ� ���н� �ٽü���
                else {
                    cout << "\033[28;40H   �̷�, ���� ����� �ñر�� �غ���� �ʾҴ�.\n";
                    cout << "\033[29;40H   ���ġ�� ����� �ֶ��� �Ĵٺ��� �ִ�.\n";
                    cout << "\033[30;40H   ������ ����� ���ϰ� �ٽ� �ָ��� �ֵθ���.\n";
                    imgUpdate(player, badman);
                    getchar();
                    continue;
                }
            }
            // �߸� ���ý� �ٽ� ����
            else if (player.choice < 0 || player.choice>4) {
                cout << "\033[28;40H   �̷�, ����� �̻��� ���� �ܳ��ߴ�.\n";
                cout << "\033[29;40H   ���ġ�� �꽺���� ����� ����� �� �ϴ�.\n";
                cout << "\033[30;40H   ������ ����� ���ϰ� �ٽ� �ָ��� �ֵθ���.\n";
                imgUpdate(player, badman);
                getchar();
                continue;
            }
            // ����� ���ý�
            else {
                cout << "\033[28;40H   �÷��̾� ����: " << player.choice << " | ���ġ ����: " << badman.choice << endl;
                if (player.choice == badman.choice) {
                    cout << "\033[29;40H   ����� ���ġ�� ���� ���ȴ�!";
                    badman.heart--;
                    imgUpdate(player, badman);
                    getchar();
                    if (badman.heart <= 0) { return 1; } // �������� Ŭ����
                }
                else {
                    cout << "\033[29;40H   ���ġ�� ������ ������ ���ߴ�!";
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

            cout << "\033[25;40H   <���ġ�� ����>\n\n";
            cout << "\033[27;40H   �����¿� �� ���� (1:��, 2:��, 3:��, 4:��) : ";
            player.setChoice();
            badman.setChoice();
            // �÷��̾ �߸� ���ý� ���ݼ���
            if (player.choice <= 0 || player.choice > 4) {
                cout << "\033[28;40H   �÷��̾� ����: " << player.choice << " | ���ġ ����: " << badman.choice << endl;
                cout << "\033[29;40H   ����, ����� ������� ������ ���ߴ�.\n";
                cout << "\033[30;40H   ������ ���ִٰ� �״�� ���¾Ҵ�.\n";
                player.choice = 1, badman.choice = 1;
                player.heart--;
                imgUpdate(player, badman);
                getchar();
                if (player.heart <= 0) { return 0; }
                break;
            }
            // ���ġ�� ���� ����
            cout << "\033[28;40H   �÷��̾� ����: " << player.choice << " | ���ġ ����: " << badman.choice << endl;
            if (player.choice == badman.choice) {
                cout << "\033[29;40H   ���ġ�� ����� ���� ���ȴ�!";
                player.heart--;
                imgUpdate(player, badman);
                getchar();
                if (player.heart <= 0) { return 0; }
                break;
            }
            // ���ġ�� ���� ����
            else {
                cout << "\033[29;40H   ����� �����ϰ� �ָ��� ���ߴ�!";
                imgUpdate(player, badman);
                p_ult++;
                if (p_ult == 3) {
                    cout << "\033[13;50H�١١�";
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
            cout << "\033[18;73H  o        0\n";
            cout << "\033[19;73H /|\\      /|\\ = = \n";
            cout << "\033[20;73H  /)       (\\ \n";

            cout << "\033[21;74H";
            for (int i = 0; i < player.heart; i++) {
                cout << "��";
            }

            cout << "\033[25;40H   ��ƴ�� ���� �ٸ� ���ġ�� ��ſ��� �޷����!";
            getchar();
            continue;
        }
        //�й�
        else {
            badEnding();
            scr.clear();
            scr.drawEdge();
            p_ult = 0; // �÷��̾��� �ð�����
            return 0; //��������
        }
    }
    happyEnding();
    scr.clear();
    scr.drawEdge();
    p_ult = 0; // �÷��̾��� �ð�����
    return 0;
}