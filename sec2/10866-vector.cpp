#include <iostream>
#include <vector>

using namespace std;

#define MAX_NUM 10000

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int N;
    cin >> N;

    string cmd;
    int x;
    int front = 0;
    int rear = 0;

    vector<int> v(MAX_NUM);
    while (N--) {
        cin >> cmd;
        if (cmd == "push_front") {
            cin >> x;
            front = (front+1)  % MAX_NUM;
            v[front] = x;
        } else if (cmd == "push_back") {
            cin >> x;
            v[rear] = x;
            rear = (rear-1+MAX_NUM)  % MAX_NUM;
        } else if (cmd == "pop_front") {
            if (front == rear) {
                cout << "-1" << '\n';
            } else {
                cout << v[front] << '\n';
                front = (front -1 + MAX_NUM) % MAX_NUM;
            }
        } else if (cmd == "pop_back") {
            if (front == rear) {
                cout << "-1" << '\n';
            } else {
                rear = (rear+1) % MAX_NUM;
                cout << v[rear] << '\n';
            }
        } else if (cmd == "size") {
            cout << (front + MAX_NUM - rear)%MAX_NUM << '\n';
        } else if (cmd == "empty") {
            cout << (front == rear) << '\n';
        } else if (cmd == "front") {
            if (front == rear) {
                cout << "-1" << '\n';
            } else {
                cout << v[front] << '\n';
            }
        } else if (cmd == "back") {
            if (front == rear) {
                cout << "-1" << '\n';
            } else {
                cout << v[(rear + 1)%MAX_NUM] << '\n';
            }
        }
    }
}
//
// Created by 양인경 on 25. 2. 25.
//
