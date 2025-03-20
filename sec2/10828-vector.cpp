#include <iostream>
#include <vector>

using namespace std;

#define MAX_SIZE 10000

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int N;
    cin >> N;

    vector<int> st(MAX_SIZE);
    int top = -1;

    string cmd;
    int x;

    while (N--) {
        cin >> cmd;

        if (cmd == "push") {
            cin >> x;
            st[++top] = x;
        } else if (cmd == "pop") {
            if (top == -1) {
                cout << "-1" << '\n';
            }
            else {
                cout << st[top--] << '\n';
            }
        } else if (cmd == "size") {
            cout << top+1 << '\n';
        } else if (cmd == "empty") {
            cout << (top == -1) << '\n';
        } else if (cmd == "top") {
            if (top == -1) {
                cout << "-1" << '\n';
            }
            else {
                cout << st[top] << '\n';
            }
        } else{
            cerr << "Wrong command!" << '\n';
        }
    }
    return 0;
}
//
// Created by 양인경 on 25. 2. 25.
//
