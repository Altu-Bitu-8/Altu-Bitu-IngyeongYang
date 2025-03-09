#include <iostream>
#include <vector>
#include <cstdlib>

using namespace std;

int getGcd(int a, int b) {
    if (b == 0) {
        return a;
    }
    return getGcd(b, a % b);
}

int findMAX(int& s, vector<int> &position) {
    for (int & i : position) {
        i = abs(i - s); //수빈이의 현재 위치와 동생 위치의 차이 구하기
    }

    //유클리드 호제법 사용해서 차이값들의 최대공약수 구하기
    //유클리드 호제법을 이용하면 두 개 값을 이용해서 최대공약수를 구할 수 있음. 그럼 만약 값이 2개 이상이라면..?
    //첫 두개의 값을 비교해서 최대공약수를 구하고 그 뒤의 값과 비교 계속

    int maxd = position[0];
    for (int i = 1; i < position.size(); i++) {
        maxd = getGcd(maxd, position[i]);
    }

    return maxd;

}

int main() {
    int n;
    int s;
    cin >> n >> s; //동생 n명, 현재 점 s 위치 입력

    vector<int> position(n);

    //동생의 위치 입력
    for (int i = 0; i < n; i++) {
        cin >> position[i];
    }

    cout << findMAX(s, position) << '\n';

    return 0;
}