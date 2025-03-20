#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int n; //적은 수의 개수
    cin >> n;

    vector<int> numbers;
    int i = 0;
    while (n--) {
        cin >> numbers[i++]; //적은 수 입력
    }
    //수의 차의 최대공약수의 약수를 구하면됨
}
//
// Created by 양인경 on 25. 3. 6.
//
