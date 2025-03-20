#include <iostream>

using namespace std;

vector<bool> isPrime(int n) {
    vector<bool> is_prime(n, true);
    is_prime[0] = is_prime[1] = false;
    for (int i = 2; i <= sqrt(n); i++) {
        if (is_prime[i]) {
            for (int j = i * i; j < n; j += i) {
                is_prime[j] = false;
            }
        }
    }
    return is_prime;
}

vector<int> findNum(vector<bool> prime) { //이 반복문은 상근수의 합만 구함 만약 반복되는 수라면? like 4
    vector<int> res;
    int sum = 0;
    for (int i = 2; i < prime.size(); i++) {
        if (prime[i]) {
            while (i != 0) {
                int tmp;
                tmp = i%10;
                sum += tmp*tmp;
                i /= 10;
            }
        }
        res[i] = sum;
    }
    return res;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int n;
    cin >> n; //숫자 입력

    //소수 저장
    vector<bool> prime = isPrime(n);
    //상근수 확인
    vector<int> result = findnum(prime);
    return 0;
}
//
// Created by 양인경 on 25. 3. 7.
//
