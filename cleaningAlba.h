#include <vector>

using namespace std;

#ifndef CLEANINGALBA_H
#define CLEANINGALBA_H

class CleaningGame
{
private:
    int size = 10; // �� ũ��
    int obstacle = 6; // ��ֹ� ����
    vector<pair<int, int>> obstacles; // ��ֹ� ��ġ -> ���Ϳ� {int first, int second} ���·� ����ǳ���.
    int trash = 10; // ������ ����
    vector<pair<int, int>> trashes; // ������ ��ġ
    pair<int, int> playerPos; // �÷��̾� ��ġ
    int point = 0;
public:
    CleaningGame();
    // �����Ҷ� ��ġ�� ��ġ �ִ��� Ȯ�ο�
    bool contains(const vector<pair<int, int>>& vec, int x, int y);
    void drawBoard();
    void movePlayer(char direction);
    void moveObstacle();
    bool checkCollision();
    bool checkTrash();
    void run();
    
};

void calMoney(int point);
int cleaningPlay();



#endif // !CLEANINGALBA_H




