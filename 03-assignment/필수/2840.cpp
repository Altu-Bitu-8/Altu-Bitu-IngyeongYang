#include <iostream>
#include <vector>

using namespace std;

void alphWheel(int n, int k) { //행운의 바퀴 구현
    vector<char> wheel(n, '?');
    int i=0; char c;
    bool state = true;
    int temp = 0;
    bool alphabet[26] = {false}; //알파벳 확인

    while (k--) {
        cin >> i >> c; //입력
        temp += i; //앞의 값 저장한 temp에 i 더하기
        temp = (temp)%n; //구형으로 생각
        if (wheel[temp] == '?') {
            if (alphabet[c-'A']) { //알파벳이 이미 사용됨
                state = false;
            }
            wheel[temp] = c; //알파벳이 안 들어가 있으면 입력하기
            alphabet[c-'A'] = true;
        } else if (wheel[temp] != c) {
            //알파벳이 들어가 있고 지금 입력하려는 알파벳과 다른 경우
            state = false;
        } else { //알파벳이 들어가 있으며 지금 입력하려는 알파벳과 같은 경우
            continue;
        }
    }
    if (state) {
        int cnt = 0;
        while (cnt != n) { //바퀴의 칸의 수 만큼 반복문 돌리기
            cnt++;
            temp = (temp+n)%n;
            cout <<wheel[temp];
            temp--;
        }
    } else {
        cout << "!" << '\n';
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int n; int k; //바퀴의 칸의 수, 바퀴를 돌리는 횟수
    cin >> n >> k;

    alphWheel(n, k);
}