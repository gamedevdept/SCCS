#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <conio.h>

#include "screen.h"
#include "cleaningAlba.h"
#include "city.h"
#define location 77 //ui 좌우로 위치조정용 -> 메인게임에서 어떻게 이쁘게 맞추냐...

using namespace std;

int Money = 0;

void calMoney(int point) {
    Money += point * 100;
}


CleaningGame::CleaningGame() {
    srand(time(0));
    playerPos = { size / 2, size / 2 };

    // 장애물 위치 랜덤 초기화 (플레이어 위치랑 겹치지 않게)
    for (int i = 0; i < obstacle; i++) {
        int x, y;
        do {
            x = rand() % size;
            y = rand() % size;
        } while ((x == playerPos.first && y == playerPos.second) || contains(obstacles, x, y));
        obstacles.push_back({ x, y });
    }

    // 쓰레기 위치 랜덤 초기화 (플레이어, 장애물 위치랑 겹치지 않게)
    for (int i = 0; i < trash; i++) {
        int x, y;
        do {
            x = rand() % size;
            y = rand() % size;
        } while ((x == playerPos.first && y == playerPos.second) || contains(obstacles, x, y) || contains(trashes, x, y));
        trashes.push_back({ x, y });
    }
}

// 생성할때 겹치는 위치 있는지 확인용
bool CleaningGame::contains(const vector<pair<int, int>>& vec, int x, int y) {
    for (const auto& p : vec) {
        if (p.first == x && p.second == y)
            return true;
    }
    return false;
}

void CleaningGame::drawBoard() {
    // 판 테두리 윗줄
    cout << "\033[10;" << location << "H";
    for (int i = 0; i < size + 2; i++) cout << "\033[30;47m ";
    cout << "\033[0m\n";

    for (int i = 0; i < size; i++) {
        cout << "\033[" << 11 + i << ";" << location << "H";
        cout << "\033[30;47m \033[0m"; // 좌 테두리

        for (int j = 0; j < size; j++) {
            if (contains(obstacles, i, j)) cout << "\033[31mX\033[0m";           // 장애물
            else if (playerPos.first == i && playerPos.second == j) cout << "O"; // 플레이어
            else if (contains(trashes, i, j)) cout << "\033[33m*\033[0m";        // 쓰레기
            else cout << " ";                                                    // 빈칸
        }

        cout << "\033[30;47m \033[0m\n"; // 우 테두리
    }

    // 판 테두리 아랫줄
    cout << "\033[" << size + 11 << ";" << location << "H";
    for (int i = 0; i < size + 2; i++) cout << "\033[30;47m ";
    cout << "\033[0m\n";
}

void CleaningGame::movePlayer(char direction) {
    int newX = playerPos.first;
    int newY = playerPos.second;

    // 방향에 따라 위치 이동
    if (direction == 'w') newX--;
    else if (direction == 's') newX++;
    else if (direction == 'a') newY--;
    else if (direction == 'd') newY++;

    // 판 벗어나면 이동 안 함
    if (newX < 0 || newX >= size || newY < 0 || newY >= size)
        return;


    // 이동
    playerPos.first = newX;
    playerPos.second = newY;

    // 쓰레기 먹기 판정
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

        int dir = rand() % 4;  // 0:위, 1:아래, 2:좌, 3:우
        int newX = obs.first;
        int newY = obs.second;

        if (dir == 0) newX--;
        else if (dir == 1) newX++;
        else if (dir == 2) newY--;
        else if (dir == 3) newY++;

        // 이동 가능 여부 확인
        if (newX < 0 || newX >= size || newY < 0 || newY >= size)
            continue;  // 범위 벗어나면 이동 X
        if (contains(obstacles, newX, newY))
            continue;  // 다른 장애물 있으면 이동 X

        // 이동
        obs.first = newX;
        obs.second = newY;
    }
}

bool CleaningGame::checkCollision() {
    // 장애물 충돌
    for (auto& obs : obstacles) {
        if (playerPos.first == obs.first && playerPos.second == obs.second) {
            return true;
        }
    }
    return false; //충돌X
}

bool CleaningGame::checkTrash() {
    // 모든 쓰레기 주웠는지 확인
    if (trashes.empty()) {
        return true;
    }
    return false; //쓰레기 남음
}

void CleaningGame::run() {
    while (1) {
        char dir;
        scr.clear();
        drawBoard();
        cout << "\033[23;60H┌────────────────────────────────────────────┐\n";
        cout << "\033[29;60H└────────────────────────────────────────────┘\n";
        cout << "\033[25;60H   주운 쓰레기 개수 : " << point << "\n";
        cout << "\033[26;60H   방향입력(wasd) : ";
        cin >> dir;
        movePlayer(dir);

        bool collision = checkCollision();
        if (collision) {
            scr.clear();
            drawBoard();
            calMoney(point);
            cout << "\033[23;60H┌────────────────────────────────────────────┐\n";
            cout << "\033[29;60H└────────────────────────────────────────────┘\n";
            cout << "\033[25;60H   주운 쓰레기 개수 : " << point << "\n";
            cout << "\033[26;60H   당신은 청소를 하다가 사람과 부딪혔습니다! \n";
            cout << "\033[27;60H   받은 알바비 : " << point << " * 100 = " << Money << "\n";
            cout << "\033[28;60H   아무 키나 눌러 게임 종료";
            cout << "\033[30;0H";
            city.money += Money;
            break;
        } //플레이어가 먼저 이동하기 때문에 충돌검사 해줌.

        moveObstacle();
        collision = checkCollision();
        if (collision) {
            scr.clear();
            drawBoard();
            calMoney(point);
            cout << "\033[23;60H┌────────────────────────────────────────────┐\n";
            cout << "\033[29;60H└────────────────────────────────────────────┘\n";
            cout << "\033[25;60H   주운 쓰레기 개수 : " << point << "\n";
            cout << "\033[26;60H   당신은 청소를 하다가 사람과 부딪혔습니다! \n";
            cout << "\033[27;60H   받은 알바비 : " << point << " * 100 = " << Money << "\n";
            cout << "\033[28;60H   아무 키나 눌러 게임 종료";
            cout << "\033[30;0H";
            city.money += Money;
            break;
        }
        bool gameClear = checkTrash();
        if (gameClear) {
            scr.clear();
            drawBoard();
            calMoney(point);
            cout << "\033[23;60H┌────────────────────────────────────────────┐\n";
            cout << "\033[29;60H└────────────────────────────────────────────┘\n";
            cout << "\033[25;60H   주운 쓰레기 개수 : " << point << "\n";
            cout << "\033[26;60H   당신은 무사히 청소를 마쳤습니다! \n";
            cout << "\033[27;60H   받은 알바비 : " << point << " * 100 = " << Money << "\n";
            cout << "\033[28;60H   아무 키나 눌러 게임 종료";
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