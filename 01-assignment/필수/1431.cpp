#include <iostream>;
#include <vector>;
#include <algorithm>;

using namespace std;

int sumNum(const string& str){
    //숫자 모든 자리 합 구하는 함수
    int sum = 0;
    for(char c : str){
        if(isdigit(c)){
            sum += c -'0';
        }
    }
    return sum;
}

bool cmp(const string& ser_num1, const string& ser_num2){
    if(ser_num1.size() != ser_num2.size()){
        return ser_num1.size() < ser_num2.size();
    }
    if(sumNum(ser_num1) != sumNum(ser_num2)){
        return sumNum(ser_num1) < sumNum(ser_num2);
    }
    return ser_num1 < ser_num2;
}

int main(){
    int n;

    //입력
    cin >> n;
    vector<string> ser_num(n);
    for(int i = 0; i<n; i++){
        cin >> ser_num[i];
    }
    //연산
    sort(ser_num.begin(), ser_num.end(), cmp);
    //출력
    for(int i = 0; i<ser_num.size(); i++){
        cout << ser_num[i] << '\n';
    }
    return 0;
}