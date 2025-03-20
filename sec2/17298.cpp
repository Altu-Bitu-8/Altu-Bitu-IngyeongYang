#include <iostream>
#include <stack>
#include <vector>

using namespace std;

//오큰수

vector<int> getNGE(int n, vector<int>& v) {
    vector<int> result(n);
    stack<int> s;

    for (int i = 0; i < n; i++) {
        //구현
    }

    return result;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int N;
    cin >> N; //입력

    vector<int> v(N);
    for (int i = 0; i < N; i++) {
        cin >> v[i]; //입력값 벡터에 넣기
    }

    vector<int> result = getNGE(N, v);

    for (int i = 0; i<n; i++) {
        cout << result[i] << " ";
    }
}
//
// Created by 양인경 on 25. 2. 28.
//
