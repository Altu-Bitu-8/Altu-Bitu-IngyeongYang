#include <iostream>
#include <vector>

using namespace std;

int len_tunnel, num_lamp;

bool findLength(vector<int>&position, int N){
  if(position[0] - 0 > N){
    return false;
  }
  for(int k = 1; k<position.size(); k++){
    if(position[k] - position[k-1] > 2*N){
      return false;
    }
  }
  if(len_tunnel - position[num_lamp-1] > N){
    return false;
  }
  return true;
}


int main(){
  cin >> len_tunnel >> num_lamp;

  vector<int> position(num_lamp);
  for (int i = 0; i < num_lamp; i++) {
    cin >> position[i];
  }

  int left, right;
  left = 0;
  right = len_tunnel;

  int result = len_tunnel;

  while(left <= right){
    int mid = (left+right)/2;

    if (findLength(position, mid)){
      result = mid;
      right = mid - 1;
    }
    else{
      left = mid + 1;
    }
  }
  cout << result << '\n';
}
//
// Created by 양인경 on 25. 5. 9.
//
