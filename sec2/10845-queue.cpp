#include <iostream>
#include <queue>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    queue<int> q;
    int N;
    cin >> N;

    string cmd;
    int x;

    while (N--) {
        cin >> cmd;
        if (cmd == "push") {
            cin >> x;
            q.push(x);
        } else if (cmd == "pop") {
            if (q.empty()) {
                cout << "-1" << '\n';
            } else {
                cout << q.front() << '\n';
                q.pop();
            }
        } else if (cmd == "size") {
            cout << q.size() << '\n';
        } else if (cmd == "empty") {
            cout << q.empty() << '\n';
        } else if (cmd == "front") {
            if (q.empty()) {
                cout << "-1" << '\n';
            } else {
                cout << q.front() << '\n';
            }
        } else if (cmd == "back") {
            if (q.empty()) {
                cout << "-1" << '\n';
            } else {
                cout << q.back() << '\n';
            }
        }
    }
    return 0;
}
//
// Created by 양인경 on 25. 2. 25.
//
