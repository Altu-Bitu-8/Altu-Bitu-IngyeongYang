#include <iostream>
#include <deque>

using namespace std;

int main() {
    int N;
    cin >> N;

    deque<int> dq;
    string cmd;
    int x;

    while (N--) {
        cin >> cmd;
        if (cmd == "push_front") {
            cin >> x;
            dq.push_front(x);
        } else if (cmd == "push_back") {
            cin >> x;
            dq.push_back(x);
        } else if (cmd == "pop_front") {
            if (dq.empty()) {
                cout << "-1" << '\n';
            } else {
                cout << dq.front() << '\n';
                dq.pop_front();
            }
        } else if (cmd == "pop_back") {
            if (dq.empty()) {
                cout << "-1" << '\n';
            } else {
                cout << dq.back() << '\n';
                dq.pop_back();
            }
        } else if (cmd == "size") {
            cout << dq.size() << '\n';
        } else if (cmd == "empty") {
            cout << dq.empty() << '\n';
        } else if (cmd == "front") {
            if (dq.empty()) {
                cout << "-1" << '\n';
            } else {
                cout << dq.front() << '\n';
            }
        } else if (cmd == "back") {
            if (dq.empty()) {
                cout << "-1" << '\n';
            } else {
                cout << dq.back() << '\n';
            }
        }
    }
    return 0;
}
//
// Created by 양인경 on 25. 2. 25.
//
