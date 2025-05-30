#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <conio.h>

#include "screen.h"
#include "cleaningAlba.h"
#include "city.h"
#define location 77 //ui �¿�� ��ġ������ -> ���ΰ��ӿ��� ��� �̻ڰ� ���߳�...

using namespace std;

int Money = 0;

void calMoney(int point) {
    Money += point * 100;
}


CleaningGame::CleaningGame() {
    srand(time(0));
    playerPos = { size / 2, size / 2 };

    // ��ֹ� ��ġ ���� �ʱ�ȭ (�÷��̾� ��ġ�� ��ġ�� �ʰ�)
    for (int i = 0; i < obstacle; i++) {
        int x, y;
        do {
            x = rand() % size;
            y = rand() % size;
        } while ((x == playerPos.first && y == playerPos.second) || contains(obstacles, x, y));
        obstacles.push_back({ x, y });
    }

    // ������ ��ġ ���� �ʱ�ȭ (�÷��̾�, ��ֹ� ��ġ�� ��ġ�� �ʰ�)
    for (int i = 0; i < trash; i++) {
        int x, y;
        do {
            x = rand() % size;
            y = rand() % size;
        } while ((x == playerPos.first && y == playerPos.second) || contains(obstacles, x, y) || contains(trashes, x, y));
        trashes.push_back({ x, y });
    }
}

// �����Ҷ� ��ġ�� ��ġ �ִ��� Ȯ�ο�
bool CleaningGame::contains(const vector<pair<int, int>>& vec, int x, int y) {
    for (const auto& p : vec) {
        if (p.first == x && p.second == y)
            return true;
    }
    return false;
}

void CleaningGame::drawBoard() {
    // �� �׵θ� ����
    cout << "\033[10;" << location << "H";
    for (int i = 0; i < size + 2; i++) cout << "\033[30;47m ";
    cout << "\033[0m\n";

    for (int i = 0; i < size; i++) {
        cout << "\033[" << 11 + i << ";" << location << "H";
        cout << "\033[30;47m \033[0m"; // �� �׵θ�

        for (int j = 0; j < size; j++) {
            if (contains(obstacles, i, j)) cout << "\033[31mX\033[0m";           // ��ֹ�
            else if (playerPos.first == i && playerPos.second == j) cout << "O"; // �÷��̾�
            else if (contains(trashes, i, j)) cout << "\033[33m*\033[0m";        // ������
            else cout << " ";                                                    // ��ĭ
        }

        cout << "\033[30;47m \033[0m\n"; // �� �׵θ�
    }

    // �� �׵θ� �Ʒ���
    cout << "\033[" << size + 11 << ";" << location << "H";
    for (int i = 0; i < size + 2; i++) cout << "\033[30;47m ";
    cout << "\033[0m\n";
}

void CleaningGame::movePlayer(char direction) {
    int newX = playerPos.first;
    int newY = playerPos.second;

    // ���⿡ ���� ��ġ �̵�
    if (direction == 'w') newX--;
    else if (direction == 's') newX++;
    else if (direction == 'a') newY--;
    else if (direction == 'd') newY++;

    // �� ����� �̵� �� ��
    if (newX < 0 || newX >= size || newY < 0 || newY >= size)
        return;


    // �̵�
    playerPos.first = newX;
    playerPos.second = newY;

    // ������ �Ա� ����
    for (int i = 0; i < trashes.size(); i++) {
        if (trashes[i].first == newX && trashes[i].second == newY) {
            trashes.erase(trashes.begin() + i);
            point++;
            break;
        }
    }

}

void CleaningGame::moveObstacle() {
    for (auto& obs : obstacles) {

        int dir = rand() % 4;  // 0:��, 1:�Ʒ�, 2:��, 3:��
        int newX = obs.first;
        int newY = obs.second;

        if (dir == 0) newX--;
        else if (dir == 1) newX++;
        else if (dir == 2) newY--;
        else if (dir == 3) newY++;

        // �̵� ���� ���� Ȯ��
        if (newX < 0 || newX >= size || newY < 0 || newY >= size)
            continue;  // ���� ����� �̵� X
        if (contains(obstacles, newX, newY))
            continue;  // �ٸ� ��ֹ� ������ �̵� X

        // �̵�
        obs.first = newX;
        obs.second = newY;
    }
}

bool CleaningGame::checkCollision() {
    // ��ֹ� �浹
    for (auto& obs : obstacles) {
        if (playerPos.first == obs.first && playerPos.second == obs.second) {
            return true;
        }
    }
    return false; //�浹X
}

bool CleaningGame::checkTrash() {
    // ��� ������ �ֿ����� Ȯ��
    if (trashes.empty()) {
        return true;
    }
    return false; //������ ����
}

void CleaningGame::run() {
    while (1) {
        char dir;
        scr.clear();
        drawBoard();
        cout << "\033[23;60H��������������������������������������������������������������������������������������������\n";
        cout << "\033[29;60H��������������������������������������������������������������������������������������������\n";
        cout << "\033[25;60H   �ֿ� ������ ���� : " << point << "\n";
        cout << "\033[26;60H   �����Է�(wasd) : ";
        cin >> dir;
        movePlayer(dir);

        bool collision = checkCollision();
        if (collision) {
            scr.clear();
            drawBoard();
            calMoney(point);
            cout << "\033[23;60H��������������������������������������������������������������������������������������������\n";
            cout << "\033[29;60H��������������������������������������������������������������������������������������������\n";
            cout << "\033[25;60H   �ֿ� ������ ���� : " << point << "\n";
            cout << "\033[26;60H   ����� û�Ҹ� �ϴٰ� ����� �ε������ϴ�! \n";
            cout << "\033[27;60H   ���� �˹ٺ� : " << point << " * 100 = " << Money << "\n";
            cout << "\033[28;60H   �ƹ� Ű�� ���� ���� ����";
            cout << "\033[30;0H";
            city.money += Money;
            break;
        } //�÷��̾ ���� �̵��ϱ� ������ �浹�˻� ����.

        moveObstacle();
        collision = checkCollision();
        if (collision) {
            scr.clear();
            drawBoard();
            calMoney(point);
            cout << "\033[23;60H��������������������������������������������������������������������������������������������\n";
            cout << "\033[29;60H��������������������������������������������������������������������������������������������\n";
            cout << "\033[25;60H   �ֿ� ������ ���� : " << point << "\n";
            cout << "\033[26;60H   ����� û�Ҹ� �ϴٰ� ����� �ε������ϴ�! \n";
            cout << "\033[27;60H   ���� �˹ٺ� : " << point << " * 100 = " << Money << "\n";
            cout << "\033[28;60H   �ƹ� Ű�� ���� ���� ����";
            cout << "\033[30;0H";
            city.money += Money;
            break;
        }
        bool gameClear = checkTrash();
        if (gameClear) {
            scr.clear();
            drawBoard();
            calMoney(point);
            cout << "\033[23;60H��������������������������������������������������������������������������������������������\n";
            cout << "\033[29;60H��������������������������������������������������������������������������������������������\n";
            cout << "\033[25;60H   �ֿ� ������ ���� : " << point << "\n";
            cout << "\033[26;60H   ����� ������ û�Ҹ� ���ƽ��ϴ�! \n";
            cout << "\033[27;60H   ���� �˹ٺ� : " << point << " * 100 = " << Money << "\n";
            cout << "\033[28;60H   �ƹ� Ű�� ���� ���� ����";
            cout << "\033[30;0H";
            city.money += Money;
            break;
        }
    }
    _getch();
    scr.clear();
    scr.drawEdge();
}

int cleaningPlay() {
    CleaningGame temp;
    temp.run();
    Money = 0;
    return 0;
}