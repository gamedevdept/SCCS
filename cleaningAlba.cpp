#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#define location 17 //ui 좌우로 위치조정용 -> 메인게임에서 어떻게 이쁘게 맞추냐...


using namespace std;

int sumMoney = 0;

void clearScreen() {
    cout << "\033[0;0H";
    for (int i = 0; i < 20; i++) {
        for (int j = 0; j < 30; j++) {
            cout << " ";
        }
        cout << "\n";
    }
    cout << "\033[0;0H";
}

void calMoney(int point) {
    sumMoney += point * 100;
}

class CleaningGame {
private:
    int size; // 판 크기
    int obstacle; // 장애물 개수
    vector<pair<int, int>> obstacles; // 장애물 위치 -> 벡터에 {int first, int second} 형태로 저장되나봄.
    int trash; // 쓰레기 개수
    vector<pair<int, int>> trashes; // 쓰레기 위치
    pair<int, int> playerPos; // 플레이어 위치
    int point;

public:
    CleaningGame(int s = 10, int o = 6, int t = 10, int p = 0) : size(s), obstacle(o), trash(t), point(p) {
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
    bool contains(const vector<pair<int, int>>& vec, int x, int y) {
        for (const auto& p : vec) {
            if (p.first == x && p.second == y)
                return true;
        }
        return false;
    }

    void drawBoard() {
        // 판 테두리 윗줄
        cout << "\033[1;" << location << "H";
        for (int i = 0; i < size + 2; i++) cout << "\033[30;47m ";
        cout << "\033[0m\n";

        for (int i = 0; i < size; i++) {
            cout << "\033[" << 2 + i << ";" << location << "H";
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
        cout << "\033[" << size + 2 << ";" << location << "H";
        for (int i = 0; i < size + 2; i++) cout << "\033[30;47m ";
        cout << "\033[0m\n";
    }

    void movePlayer(char direction) {
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

    void moveObstacle() {
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

    bool checkCollision() {
        // 장애물 충돌
        for (auto& obs : obstacles) {
            if (playerPos.first == obs.first && playerPos.second == obs.second) {
                return true;
            }
        }
        return false; //충돌X
    }

    bool checkTrash() {
        // 모든 쓰레기 주웠는지 확인
        if (trashes.empty()) {
            return true;
        }
        return false; //쓰레기 남음
    }

    void run() {
        while (1) {
            char dir;
            clearScreen();
            drawBoard();
            cout << "\033[13;0H┌────────────────────────────────────────────┐\n";
            cout << "\033[19;0H└────────────────────────────────────────────┘\n";
            cout << "\033[15;0H   주운 쓰레기 개수 : " << point << "\n";
            cout << "   방향입력(wasd) : ";
            cin >> dir;
            movePlayer(dir);

            bool collision = checkCollision();
            if (collision) {
                clearScreen();
                drawBoard();
                calMoney(point);
                cout << "\033[13;0H┌────────────────────────────────────────────┐\n";
                cout << "\033[19;0H└────────────────────────────────────────────┘\n";
                cout << "\033[15;0H   주운 쓰레기 개수 : " << point << "\n";
                cout << "   당신은 청소를 하다가 사람과 부딪혔습니다! \n";
                cout << "   받은 알바비 : " << point << " * 100 = " << sumMoney << "\n";
                cout << "\033[20;0H";
                break;
            } //플레이어가 먼저 이동하기 때문에 충돌검사 해줌.

            moveObstacle();
            collision = checkCollision();
            if (collision) {
                clearScreen();
                drawBoard();
                calMoney(point);
                cout << "\033[13;0H┌────────────────────────────────────────────┐\n";
                cout << "\033[19;0H└────────────────────────────────────────────┘\n";
                cout << "\033[15;0H   주운 쓰레기 개수 : " << point << "\n";
                cout << "   당신은 청소를 하다가 사람과 부딪혔습니다! \n";
                cout << "   받은 알바비 : " << point << " * 100 = " << sumMoney << "\n";
                cout << "\033[20;0H";
                break;
            }
            bool gameClear = checkTrash();
            if (gameClear) {
                clearScreen();
                drawBoard();
                calMoney(point);
                cout << "\033[13;0H┌────────────────────────────────────────────┐\n";
                cout << "\033[19;0H└────────────────────────────────────────────┘\n";
                cout << "\033[15;0H   주운 쓰레기 개수 : " << point << "\n";
                cout << "   당신은 무사히 청소를 마쳤습니다! \n";
                cout << "   받은 알바비 : " << point << " * 100 = " << sumMoney << "\n";
                cout << "\033[20;0H";
                break;
            }
        }
    }
};

int main() {
    CleaningGame temp;
    temp.run();
    return 0;
}