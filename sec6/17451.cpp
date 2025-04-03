#include <iostream>
#include <vector>

using namespace std;

typedef long long ll;

ll findSpeed(vector<ll>& v){
  ll speed;
  for(int i = 0; i < v.size()-1; i++){
    if(v[i] <= v[i+1]){
      continue;
    }
    if(v[i]%v[i+1] == 0){
      v[i+1] *= (v[i]/v[i+1]);
      continue;
    }
    v[i+1] *= (v[i]/v[i+1])+1; //곱할 수를 찾는 방식으로 하니까 연산을 너무 많이 하게 됨. 따라서 나눠서 몫+1 한 수를 곱하면 곱할 수를 바로 찾을 수 있음.
  }
  speed = v[v.size()-1];
  return speed;
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);
  //입력
  int n;
  cin>>n;

  vector<ll> speed(n);
  for(int i = n-1; i >= 0; i--){
    cin>>speed[i];
  }

  cout << findSpeed(speed);
  //뒷 숫자보다 크게 만들어야함. 배수를 해서라도
  return 0;
}
//
// Created by 양인경 on 25. 3. 27.
//
