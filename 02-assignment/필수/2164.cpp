#include <iostream>
#include <queue>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    //입력
    int N;
    cin >> N; //num of card

    queue<int> q; //큐 선언
    for (int i = 1; i <= N; i++) {
        q.push(i);
    }

    while (true) {
        if (q.size() == 1) {
            cout << q.front() << '\n';
            break;
        }
        q.pop();
        q.push(q.front());
        q.pop();
    }
    return 0;
}