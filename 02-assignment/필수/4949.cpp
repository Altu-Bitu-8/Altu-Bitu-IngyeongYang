#include <iostream>
#include <stack>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    while (true) {
        string cmd;
        stack<char> st;
        getline(cin, cmd);

        bool check = true;
        if (cmd == ".") {
            break;
        }
        for (char c : cmd) {
            if (c == '(' || c == '[') {
                st.push(c); //여는 괄호 스택에 넣기
            }
            else if (c == ')') {
                if (st.empty() || st.top() != '(') {
                    check = false;
                    break;
                }
                    st.pop();
            }
            else if (c == ']') {
                if (st.empty() || st.top() != '[') {
                    check = false;
                    break;
                }
                    st.pop();
            }
        }
        if (check == false || !st.empty()) {
            cout << "no" << '\n';
        } else {
            cout << "yes" << '\n';
        }
    }
    return 0;
}