#include <iostream>

using namespace std;

int MAX = 10;

bool isSimilar(string standard, string& s1){
    //비교 후 같으면 삭제, 배열의 사이즈가 >1이면 비슷한 단어가 아님.
    for(int i = 0; i < standard.length(); i++){
        int f1 = s1.find(standard[i]);
        if(f1 != -1){
            s1.erase(f1, 1);
            standard.erase(i, 1);
            i--;
        }
    }
    if(s1.length()<=1 && standard.length()<=1){
        return true; //아니면 -> false
    }
    return false; //비슷한 단어이면 -> true
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    //입력
    int n; //입력될 단어 수
    cin>>n;

    string standard; //기준이 될 단어
    cin>>standard;

    n--;

    string st;
    int cnt = 0;

    while(n--){
        cin>>st;
        //연산 : 비슷한 단어인지 확인 bool
        if(isSimilar(standard, st)){
            cnt++;
        }
    }

    cout<<cnt<<'\n';
}
//
// Created by 양인경 on 25. 3. 21.
//
