#include <iostream>
#include <vector>

using namespace std;

int num_plate, num_div, num_fod, num_cp;


//생각하지 않은 경우, 쿠폰의 번호
int numProb(int num, vector<bool>& plateMap, vector<int>& plateNum){
  bool cmp = false;
  for(int i = 0; i<num_fod;i++){
    int j = (i+num+1)%num_plate;
    plateMap[plateNum[j]-1]=true;
  }

  int cnt = 0;
  for(int i = 0; i<num_div; i++){
    if(plateMap[i]==true){
      cnt++;
    }
  }

  if(plateMap[num_cp-1]==false){
    cnt++;
  }
  return cnt;
}

int main(){
  //입력 시작
  cin >> num_plate >> num_div >> num_fod >> num_cp;
  vector<int> plateNum(num_plate);
  for(int i=0;i<num_plate;i++){
    cin>>plateNum[i];
  }
  //입력 끝

  //연산 시작
  int max = 0;
  for(int i=0;i<num_plate;i++){
    vector<bool> plateMap(num_div, false);
    int tmp = numProb(i,plateMap,plateNum);
    if(max<tmp){
      max = tmp;
    }
  }

  //출력
  cout<<max<<'\n';
  return 0;
}
//
// Created by 양인경 on 25. 5. 16.
//
