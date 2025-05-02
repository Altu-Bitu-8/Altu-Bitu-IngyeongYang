#include <iostream>
#include <vector>


using namespace std;

int doRound(vector<int>& box, vector<bool>& exist, int len, int n, int k) {
  int step = 0;
  while (true) {
    step++;
    int tmp1 = box[len-1];
    bool tmp2 = exist[len-1];
    exist[n-1] = false;
    for (int i = len-1; i>0; i--) {
      box[i] = box[i-1];
      exist[i] = exist[i-1];
    }
    box[0] = tmp1;
    exist[0] = tmp2;
    exist[n-1] = false;
    for (int i = len-1; i>=0; i--) {
      if (box[i+1] > 0 && !exist[i+1] && exist[i]) {
        exist[i+1] = true;
        exist[i] = false;
        box[i+1]--;
      }
    }
    if (box[0] > 0 && !exist[0]) {
      exist[0] = true;
      box[0]--;
    }
    int cnt = 0;
    for (int i = 0; i < len; i++) {
      if (box[i] == 0) {
        cnt++;
      }
    }
    if (cnt >= k) {
      break;
    }
  }
  return step;
}

int main(){
  int n, k; //length of belt and limit num of zero boxes
  cin>>n>>k;
  int len = 2*n;
  vector<int> robot(len);
  vector<bool> exist(len);
  for(int i=0;i<len;i++) {
    cin>>robot[i];
    exist[i] = false;
  }
  cout << doRound(robot, exist, len, n, k) << '\n';
}
//
// Created by 양인경 on 25. 5. 2.
//
