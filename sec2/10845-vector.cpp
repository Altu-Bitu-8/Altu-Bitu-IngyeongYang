#include <iostream>
#include <vector>

#define MAX_SIZE 10000

using namespace std;

int main() {
    ios::sync_with_stdio(false); //실행속도 향상
    cin.tie(NULL); cout.tie(NULL); //입력 끝난 후 출력

    int N;
    cin >> N;

    vector<int> q(MAX_SIZE);
    int front = 0; int rear = 0; //front가 앞, rear에서 입력

    string cmd; //명령어
    int x;
    //queue를 원형으로 만들어서 저장

    while (N--) {
        cin >> cmd;
        if (cmd == "push") {
            cin >> x;
            rear = (rear+1)%MAX_SIZE; //위치를 rear를 저장 위치로 옮김
            q[rear] = x;
        } else if (cmd == "pop") {
            if (rear == front) {
                cout << "-1" << '\n';
            } else {
                front = (front+1)%MAX_SIZE; //처음 front는 아무것도 저장 안 되는 곳에 위치 즉 그 다음 위치부터 저장되어 있음
                cout << q[front] << '\n';
            }
        } else if (cmd == "size") {
            cout << rear - front << '\n';
        } else if (cmd == "empty") {
            cout << (front == rear) <<'\n';
        } else if (cmd == "front") {
            if (rear == front) {
                cout << "-1" << '\n';
            } else {
                cout << q[(front+1)%MAX_SIZE] << '\n';
            }
        } else if (cmd == "back") {
            if (rear == front) {
                cout << "-1" << '\n';
            } else {
                cout << q[rear] << '\n';
            }
        }
    }
    return 0;
}
//
// Created by 양인경 on 25. 2. 25.
//
