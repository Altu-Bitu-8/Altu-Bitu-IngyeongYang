#include <iostream>
#include <queue>

using namespace std;

void findingNum(priority_queue<int, vector<int>, greater<int>> &numbers, int &num){
    int x;
    cin >> x;
    numbers.push(x);
    if(numbers.size() > num){
        numbers.pop();
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    priority_queue<int, vector<int>, greater<int>> numbers;
    //입력
    int n; // 줄의 갯수
    cin>>n;

    //입력을 받은 후 n번쨰 이후 숫자는 날리기
    //연산
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            findingNum(numbers, n);
        }
    }

    //출력
    cout<<numbers.top()<<'\n';
}
//
// Created by 양인경 on 25. 3. 21.
//
