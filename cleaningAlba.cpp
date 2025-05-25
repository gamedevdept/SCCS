#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#define location 17 //ui �¿�� ��ġ������ -> ���ΰ��ӿ��� ��� �̻ڰ� ���߳�...


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
    int size; // �� ũ��
    int obstacle; // ��ֹ� ����
    vector<pair<int, int>> obstacles; // ��ֹ� ��ġ -> ���Ϳ� {int first, int second} ���·� ����ǳ���.
    int trash; // ������ ����
    vector<pair<int, int>> trashes; // ������ ��ġ
    pair<int, int> playerPos; // �÷��̾� ��ġ
    int point;

public:
    CleaningGame(int s = 10, int o = 6, int t = 10, int p = 0) : size(s), obstacle(o), trash(t), point(p) {
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
    bool contains(const vector<pair<int, int>>& vec, int x, int y) {
        for (const auto& p : vec) {
            if (p.first == x && p.second == y)
                return true;
        }
        return false;
    }

    void drawBoard() {
        // �� �׵θ� ����
        cout << "\033[1;" << location << "H";
        for (int i = 0; i < size + 2; i++) cout << "\033[30;47m ";
        cout << "\033[0m\n";

        for (int i = 0; i < size; i++) {
            cout << "\033[" << 2 + i << ";" << location << "H";
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
        cout << "\033[" << size + 2 << ";" << location << "H";
        for (int i = 0; i < size + 2; i++) cout << "\033[30;47m ";
        cout << "\033[0m\n";
    }

    void movePlayer(char direction) {
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

    void moveObstacle() {
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

    bool checkCollision() {
        // ��ֹ� �浹
        for (auto& obs : obstacles) {
            if (playerPos.first == obs.first && playerPos.second == obs.second) {
                return true;
            }
        }
        return false; //�浹X
    }

    bool checkTrash() {
        // ��� ������ �ֿ����� Ȯ��
        if (trashes.empty()) {
            return true;
        }
        return false; //������ ����
    }

    void run() {
        while (1) {
            char dir;
            clearScreen();
            drawBoard();
            cout << "\033[13;0H��������������������������������������������������������������������������������������������\n";
            cout << "\033[19;0H��������������������������������������������������������������������������������������������\n";
            cout << "\033[15;0H   �ֿ� ������ ���� : " << point << "\n";
            cout << "   �����Է�(wasd) : ";
            cin >> dir;
            movePlayer(dir);

            bool collision = checkCollision();
            if (collision) {
                clearScreen();
                drawBoard();
                calMoney(point);
                cout << "\033[13;0H��������������������������������������������������������������������������������������������\n";
                cout << "\033[19;0H��������������������������������������������������������������������������������������������\n";
                cout << "\033[15;0H   �ֿ� ������ ���� : " << point << "\n";
                cout << "   ����� û�Ҹ� �ϴٰ� ����� �ε������ϴ�! \n";
                cout << "   ���� �˹ٺ� : " << point << " * 100 = " << sumMoney << "\n";
                cout << "\033[20;0H";
                break;
            } //�÷��̾ ���� �̵��ϱ� ������ �浹�˻� ����.

            moveObstacle();
            collision = checkCollision();
            if (collision) {
                clearScreen();
                drawBoard();
                calMoney(point);
                cout << "\033[13;0H��������������������������������������������������������������������������������������������\n";
                cout << "\033[19;0H��������������������������������������������������������������������������������������������\n";
                cout << "\033[15;0H   �ֿ� ������ ���� : " << point << "\n";
                cout << "   ����� û�Ҹ� �ϴٰ� ����� �ε������ϴ�! \n";
                cout << "   ���� �˹ٺ� : " << point << " * 100 = " << sumMoney << "\n";
                cout << "\033[20;0H";
                break;
            }
            bool gameClear = checkTrash();
            if (gameClear) {
                clearScreen();
                drawBoard();
                calMoney(point);
                cout << "\033[13;0H��������������������������������������������������������������������������������������������\n";
                cout << "\033[19;0H��������������������������������������������������������������������������������������������\n";
                cout << "\033[15;0H   �ֿ� ������ ���� : " << point << "\n";
                cout << "   ����� ������ û�Ҹ� ���ƽ��ϴ�! \n";
                cout << "   ���� �˹ٺ� : " << point << " * 100 = " << sumMoney << "\n";
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