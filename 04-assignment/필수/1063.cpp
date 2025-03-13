#include <iostream>

using namespace std;

bool checkOUT(string king, string stone){ //체스판에서 나갔는지 확인
  if (stone[0] < 'A' || stone[0] > 'H' || stone[1] < '1' || stone[1] > '8' || king[0] < 'A' || king[0] > 'H' || king[1] < '1' || king[1] > '8'){
    return true;
  }
  return false;
}

string cmdR(string& position){
  position[0] = position[0] + 1;
  return position;
}

string cmdL(string& position){
  position[0] = position[0] - 1;
  return position;
}

string cmdB(string& position){
  position[1] = position[1] - 1;
  return position;
}

string cmdT(string& position){
  position[1] = position[1] + 1;
  return position;
}


void moveChess(string& king_p, string& stone_p, string& cmd){
  //tmp = origin_p_king and origin_p_stone
  string tmp_k = king_p;
  string tmp_s = stone_p;
  if(cmd == "R"){
    cmdR(king_p);
    // king position = [same][+1];
  } else if(cmd == "L"){
    cmdL(king_p);
    // king position = [same][-1];
  } else if(cmd == "B"){
    cmdB(king_p);
    // king position = [-1][same];
  } else if(cmd == "T"){
    cmdT(king_p);
    // king position = [+1][same];
  } else if(cmd == "RT"){
    cmdR(king_p);
    cmdT(king_p);
    // R -> T
  } else if(cmd == "LT"){
    cmdL(king_p);
    cmdT(king_p);
    // L -> T
  } else if(cmd == "RB"){
    cmdR(king_p);
    cmdB(king_p);
    // R -> B
  } else if(cmd == "LB"){
    cmdL(king_p);
    cmdB(king_p);
    // L -> B
  }
  if(king_p == stone_p){
    if(cmd == "R"){
      cmdR(stone_p);
    } else if(cmd == "L"){
      cmdL(stone_p);
    } else if(cmd == "B"){
      cmdB(stone_p);
    } else if(cmd == "T"){
      cmdT(stone_p);
    } else if(cmd == "RT"){
      cmdR(stone_p);
      cmdT(stone_p);
    } else if(cmd == "LT"){
      cmdL(stone_p);
      cmdT(stone_p);
    } else if(cmd == "RB"){
      cmdR(stone_p);
      cmdB(stone_p);
    } else if(cmd == "LB"){
      cmdL(stone_p);
      cmdB(stone_p);
    }
  }
  //if king_P = stone_P => move stone
  if(checkOUT(king_p, stone_p)){
    king_p = tmp_k;
    stone_p = tmp_s;
  }
  // if out => go back to origin
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL);

  //입력
  string king_p; string stone_p; int N;
  cin >> king_p >> stone_p >> N;

  //위치값을 두개로 나눠야함 입력을 받고 p[0] = a~h, p[1] = 1~8

  string cmd;

  //연산
  while(N--){
    cin >> cmd;
    moveChess(king_p, stone_p, cmd);
  }

  //출력
  cout << king_p << '\n';
  cout << stone_p << '\n';
}
//
// Created by 양인경 on 25. 3. 12.
//
