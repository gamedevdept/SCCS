#include <vector>

using namespace std;

#ifndef CLEANINGALBA_H
#define CLEANINGALBA_H

class CleaningGame
{
private:
    int size = 10; // 판 크기
    int obstacle = 6; // 장애물 개수
    vector<pair<int, int>> obstacles; // 장애물 위치 -> 벡터에 {int first, int second} 형태로 저장되나봄.
    int trash = 10; // 쓰레기 개수
    vector<pair<int, int>> trashes; // 쓰레기 위치
    pair<int, int> playerPos; // 플레이어 위치
    int point = 0;
public:
    CleaningGame();
    // 생성할때 겹치는 위치 있는지 확인용
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




