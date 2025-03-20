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

vector<string> testConj(vector<int>& numbers, vector<string>& result) {
    vector<bool> is_prime = isPrime();
    for(int i = 0; i<numbers.size(); i++){
      bool state = false;
      /*int k = 3;
      while(is_prime[k]){
        if(is_prime[numbers[i]-k]){
          state = true;
          result[i] = "=" + to_string(k) + " + " + to_string(numbers[i]-k);
          break;
        }
        if(state == false){
          result[i] = "Goldbach's conjecture is wrong";
        }
        k++;
      }
    }*/ //틀림 왜지
    /*for (int i = 0; i<numbers.size(); i++) {
        bool state = false;
        for (int c = 3; c<numbers[i]; c++) {
            if (is_prime[numbers[i]-c]) { //가장 작은 소수로 뺀 값이 소수라면 b-a 값이 가장 큰 a+b임
                state = true;
                cout<< numbers[i] << " = "<< c << " + " << numbers[i]-c << '\n';
                break;
            }

        if ( state == false ) { //추론이 틀렸을 시
            cout << "Goldbach's conjecture is wrong" << '\n';
        }*/

    }
    return result;
}

int main() {
    int n; //테스트케이스
    vector<int> numbers; //테스트케이스 벡터
    vector<string> result;

    //입력
    while (cin >> n && n != 0) {
        numbers.push_back(n);
    }

    testConj(numbers, result);

    //출력
    for(int i = 0; i<result.size(); i++){
      cout << numbers[i] << result[i] << '\n';
    }

    return 0;
}

//
// Created by 양인경 on 25. 3. 5.
//
