#include <iostream>
#include <deque>

using namespace std;

void rotateAction(vector<deque<int>>& wheel, vector<int>& rotateNum){
  for(int i = 0; i < rotateNum.size(); i++) {
    if(rotateNum[i] == 1){
      int tmp = wheel[i].back();
      wheel[i].pop_back();
      wheel[i].push_front(tmp);
    }
    if(rotateNum[i] == -1){
      int tmp = wheel[i].front();
      wheel[i].pop_front();
      wheel[i].push_back(tmp);
    }
  }
}


void checkWheelR(vector<deque<int>>& wheel, int wnum, int w, vector<int>& rotateNum){
  int rot = w;
  for (int i = wnum; i < wheel.size()-1; i++) {
    if (wheel[i][2] == wheel[i+1][6]) {
      break;
    }
    rot = -rot;
    rotateNum[i+1] = rot;
  }
}

void checkWheelL(vector<deque<int>>& wheel, int wnum, int w, vector<int>& rotateNum){
  int rot = w;
  for (int i = wnum; i > 0; i--) {
    if (wheel[i][6] == wheel[i-1][2]) {
      break;
    }
    rot = -rot;
    rotateNum[i-1] = rot;
  }
}

int countWheel(vector<deque<int>>& wheel) {
  int cnt = 0;
  for (auto & i : wheel) {
    if (i[0] == 1) {
      cnt++;
    }
  }
  return cnt;
}

int main(){
  //입력
  int t;
  cin>>t; //톱니바퀴 갯수

  vector<deque<int>> wheel(t); //톱니바퀴
  for(int i=0;i<t;i++){
    string s;
    cin>>s;
    for(char c :s){
      wheel[i].push_back(c-'0');
    }
  }

  int k;
  cin>>k;
  for(int i=0;i<k;i++){
    vector<int> rotateNum(t,0); //회전유무 저장 0=회전 안 함, 1=시계, -1=반시계
    int wnum, w; //톱니바퀴 번호, 회전방향
    cin>>wnum>>w;
    int index = wnum-1;
    rotateNum[index] = w;
    checkWheelR(wheel, index, w, rotateNum);
    checkWheelL(wheel, index, w, rotateNum);
    rotateAction(wheel, rotateNum);
  }

  //출력
  cout << countWheel(wheel);

}
//
// Created by 양인경 on 25. 3. 27.
//
