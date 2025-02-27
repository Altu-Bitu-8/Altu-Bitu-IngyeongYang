#include <iostream>
#include <stack>

using namespace std;

int main() {
    string s1;
    string s2;
    cin >> s1 >> s2;

    stack<char> q;
    stack<char> r;
    stack<char> s;
    int k=0;
    for (char c : s1) {
        q.push(c);
    }
    for (char c : s2) {
        r.push(c);
    }
    while (!q.empty() || !r.empty() || k) {
        int sum = k;
        if (!q.empty()) {
            sum += q.top() - '0';
            q.pop();
        }
        if (!r.empty()) {
            sum += r.top() - '0';
            r.pop();
        }

        s.push((sum%10)+'0');
        k = sum/10;
    }
    while (!s.empty()) {
        cout << s.top();
        s.pop();
    }
    return 0;
}