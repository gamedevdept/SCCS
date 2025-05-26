/*���Ӱ�ü �̴ϰ��� - ������ �˹�
�� ���帶�� ������ 10���� ȭ��ǥ ���
���� �ð� �ȿ� ���⿡ �´� wasd Ű �Է�
�ð��ʰ� �� ��������*/

#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <chrono>
#include <string>

using namespace std;
using namespace chrono;
//���� ���� ����
char getRandomDirection() {
    char dir[4] = { 'w','a','s','d' };
    return dir[rand() % 4];
}
//ȭ��ǥ ���
void printArrow(char dir) {
    switch (dir) {
    case 'w': cout << "��"; break;
    case 'a': cout << "��"; break;
    case 's': cout << "��"; break;
    case 'd': cout << "��"; break;
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

    cout << "---����� ������ �˹�---" << endl;
    cout << "ȭ��ǥ�� ���� �ùٸ� �������� ���� ����!" << endl;
    cout << "��:w ��:a ��:s ��:d" << endl;
    cout << "�� ���̶� �ð� �ʰ��ϸ� �˹� ����" << endl;

    while (true) {
        int timeLimit = max(startTime - round + 1, minTime);
        cout << "--- " << round << "��° �մ�" << " ���ѽð�: " << timeLimit << "�� ---" << endl;
        //���� ����
        for (int i = 0; i < count; i++) {
            char dir = getRandomDirection();
            problem.push_back(dir);
            printArrow(dir);
        }
        //�� �Է�
        auto start = steady_clock::now();
        cout << endl << "����! > ";
        string input;
        getline(cin, input);
        auto end = steady_clock::now();
        int elasped = duration_cast<seconds>(end - start).count();
        //�ð� �ʰ� �˻�
        if (elasped > timeLimit) {
            cout << "�ð� �ʰ�!" << endl;
            break;
        }
        //���� Ȯ��
        answer = vector<char>(input.begin(), input.end());
        int correct = 0;
        for (int i = 0; (i < problem.size()) && (i < answer.size()); i++) {
            if (problem[i] == answer[i])
                correct++;
        }
        totalCorrect += correct;
        cout << "���� Ƚ��:" << correct << endl;

        round++;
        problem.clear();
    }

    cout << "--- �˹� ���� ---" << endl;
    cout << "�� �մ� ��: " << round - 1 << endl;
    cout << "�� ���� Ƚ��: " << totalCorrect << endl;
    return 0;
}