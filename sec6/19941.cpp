#include <iostream>
#include <vector>

using namespace std;

int numHam(int& K, vector<int>& ham, vector<int>& hum){
  int cnt = 0;
  for(int i = 0; i < hum.size(); i++){
    bool state = false; //한 사람이 2개의 햄버거를 먹는 것을 방지하기 위해서
    if(hum[i] != 1){
      continue;
    }
    //인덱스가 배열 안에 존재하면서 햄버거가 그 인덱스에 존재할 때 사람에게 햄버거를 줌
    for(int j = K; j>0; j--){
      if(i-j >= 0 && ham[i-j] == 1){
        cnt++;
        ham[i-j] = 0;
        state = true;
        break;
      }
    }
    if(state == true){
      continue;
    }
    for(int j = 1; j<=K; j++){
      if(i+j < ham.size() && ham[i+j] == 1){
          cnt++;
          ham[i+j] = 0;
          break;
      }
    }
  }
  return cnt;
}

int main(){
  //입력
  int N, K;
  cin>>N>>K;

  string st;
  vector<int> ham(N,0);
  vector<int> hum(N,0);

  cin>>st;

  for(int i = 0; i<N; i++){
    if(st[i]=='H'){
      ham[i] = 1;
    }else if(st[i]=='P'){
      hum[i]=1;
    }
  }

  cout<<numHam(K, ham, hum)<<'\n';

  return 0;
}
//
// Created by 양인경 on 25. 3. 27.
//
