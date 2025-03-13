#include <iostream>

using namespace std;

const int MAXE = 15;
const int MAXS = 28;
const int MAXM = 19;

int findYear(int E, int S, int M) {
    int result = 0;
    while (E != 0 && S != 0 && M != 0) {
        result++;
        E--;
        S--;
        M--;
        if (E == 0 && (S != 0 || M != 0)) {
            E = 15;
        }
        if ((E != 0 || M != 0) && S == 0) {
            S = 28;
        }
        if ((E != 0 || S != 0) && M == 0) {
            M = 19;
        }
    }
    return result;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    //입력
    int E; int S; int M; //지구 태양 달
    cin >> E >> S >> M;

    //연산
    int year = findYear(E, S, M);

    //출력
    cout << year << '\n';
    return 0;
}
//
// Created by 양인경 on 25. 3. 11.
//
