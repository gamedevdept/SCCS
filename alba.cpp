/*게임객체 미니게임 - 때밀이 알바
매 라운드마다 랜덤한 10개의 화살표 출력
제한 시간 안에 방향에 맞는 wasd 키 입력
시간초과 시 게임종료*/

#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <chrono>
#include <string>

using namespace std;
using namespace chrono;
//랜덤 방향 생성
char getRandomDirection() {
    char dir[4] = { 'w','a','s','d' };
    return dir[rand() % 4];
}
//화살표 출력
void printArrow(char dir) {
    switch (dir) {
    case 'w': cout << "↑"; break;
    case 'a': cout << "←"; break;
    case 's': cout << "↓"; break;
    case 'd': cout << "→"; break;
    }
}

int main() {
    srand(time(0));

    int round = 1;
    int count = 10;
    int startTime = 10;
    int minTime = 1;
    int totalCorrect = 0;
    vector <char> problem;
    vector <char> answer;

    cout << "---목욕탕 때밀이 알바---" << endl;
    cout << "화살표를 보고 올바른 방향으로 때를 밀자!" << endl;
    cout << "↑:w ←:a ↓:s →:d" << endl;
    cout << "한 번이라도 시간 초과하면 알바 종료" << endl;

    while (true) {
        int timeLimit = max(startTime - round + 1, minTime);
        cout << "--- " << round << "번째 손님" << " 제한시간: " << timeLimit << "초 ---" << endl;
        //문제 생성
        for (int i = 0; i < count; i++) {
            char dir = getRandomDirection();
            problem.push_back(dir);
            printArrow(dir);
        }
        //답 입력
        auto start = steady_clock::now();
        cout << endl << "시작! > ";
        string input;
        getline(cin, input);
        auto end = steady_clock::now();
        int elasped = duration_cast<seconds>(end - start).count();
        //시간 초과 검사
        if (elasped > timeLimit) {
            cout << "시간 초과!" << endl;
            break;
        }
        //정답 확인
        answer = vector<char>(input.begin(), input.end());
        int correct = 0;
        for (int i = 0; (i < problem.size()) && (i < answer.size()); i++) {
            if (problem[i] == answer[i])
                correct++;
        }
        totalCorrect += correct;
        cout << "성공 횟수:" << correct << endl;

        round++;
        problem.clear();
    }

    cout << "--- 알바 종료 ---" << endl;
    cout << "총 손님 수: " << round - 1 << endl;
    cout << "총 성공 횟수: " << totalCorrect << endl;
    return 0;
}