#include <iostream>

using namespace std;

void calSet(string& cmd, int& S) {
    int x;
    if (cmd == "add") {
        cin >> x;
        if (!(S & (1<<(x-1)))) {
            S += 1 << (x-1); //있는지 확인
        }//x 추가
    } else if (cmd == "remove") {
        cin >> x;
        if (S & (1<<(x-1))) {
            S = S & ~(1<<(x-1)); //있는지 확인
        }
        //x 제거
    } else if (cmd == "check") {
        cin >> x;
        if (S & (1<<(x-1))) { //있는지 확인
            cout << "1" << '\n';
        } else {
            cout << "0" << '\n';
        }
        //x가 있으면 1, 없으면 0 출력
    } else if (cmd == "toggle") {
        cin >> x;
        if (S & (1<<(x-1))) { //있는지 확인
            S = S & ~(1<<(x-1));
        } else {
            S += 1 << (x-1);
        }//x가 있으면 제거, 없으면 x 추가
    } else if (cmd == "all") {
        S = ((1 <<20) - 1);
        //S를 {1,...20}으로 변경
    } else if (cmd == "empty") {
        S = 0 ; //공집합으로 만듦
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    //입력
    int M; //연산해야하는 수
    cin >> M;

    //연산
    int S = 0;
    while (M--) {
        string cmd;
        cin >> cmd;
        calSet(cmd, S);
    }
    //출력

    return 0;
}

//
// Created by 양인경 on 25. 3. 11.
//
