#include <iostream>
#include <stack>

using namespace std;

int main() {
    int N;
    cin >> N;

    stack<int> st;

    string cmd;
    int x;

    while (N--) {
        cin >> cmd;
        if (cmd == "push") {
            cin >> x;
            st.push(x);
        }
        else if (cmd == "pop") {
            if (st.empty()) {
                cout << "-1" << '\n';
            }
            else {
                cout << st.top() << '\n';
                st.pop();
            }
        }
        else if (cmd == "size") {
            cout << st.size() << '\n';
        }
        else if (cmd == "empty") {
            cout << st.empty() << '\n';
        }
        else if (cmd == "top") {
            if (st.empty()) {
                cout << "-1" << '\n';
            }
            else {
                cout << st.top() << '\n';
            }
        }
    }
    return 0;
}
//
// Created by 양인경 on 25. 2. 25.
//
