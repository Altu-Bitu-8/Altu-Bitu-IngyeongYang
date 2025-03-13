#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

const int MAX = 1000000;

vector<bool> isPrime() {
    vector<bool> is_prime(MAX+1, true); //소수 찾는 함수
    is_prime[0] = is_prime[1] = false;
    for (int k = 2; k <=sqrt(MAX); k++) {
        if (!is_prime[k]) {
            continue;
        }
        for (int j = k * k; j <= MAX; j += k) {
            is_prime[j] = false;
        }
    }
    return is_prime;
}

void testConj(vector<int>& numbers) {
    vector<bool> is_prime = isPrime();
    for (int i = 0; i<numbers.size(); i++) {
        bool state = false;
        for (int c = 3; c<numbers[i]; c++) {
            if (!is_prime[c]) {
                continue;
            }
            if (is_prime[numbers[i]-c]) { //가장 작은 소수로 뺀 값이 소수라면 b-a 값이 가장 큰 a+b임
                state = true;
                cout<< numbers[i] << " = "<< c << " + " << numbers[i]-c << '\n';
                break;
            }
        }
        if ( state == false ) { //추론이 틀렸을 시
            cout << "Goldbach's conjecture is wrong" << '\n';
        }

    }

}

int main() {
    int n; //테스트케이스
    vector<int> numbers; //테스트케이스 벡터

    //입력
    while (cin >> n && n != 0) {
        numbers.push_back(n);
    }

    testConj(numbers);

    return 0;
}