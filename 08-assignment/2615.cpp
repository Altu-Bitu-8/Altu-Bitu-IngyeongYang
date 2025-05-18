#include <iostream>

using namespace std;

int go[19][19];
int winner = 0;
int result_col, result_row = 0;

void checkGO(int c, int r, int i, int j){
  if(winner != 0) return;
  for(int k = 1; k<5; k++){
    int bi = i+k*c;
    int bj = j+k*r;
    if(bi >= 19 || bj >= 19 || bi < 0 || bj < 0) return;
    if(go[i][j] != go[bi][bj])return;
  }
  //find if there is true => 6개인지 확인
  //if 6개 => continue
  //else => return its winner
  int ai = i-1*c;
  int aj = j-1*r;
  int fi = i+5*c;
  int fj = j+5*r;
  if(ai < 19 && aj < 19 && ai >= 0 && aj >= 0 && go[i][j] == go[ai][aj])return;
  if(fi < 19 && fj < 19 && fi >= 0 && fj >= 0 && go[i][j] == go[fi][fj])return;
  winner = go[i][j];
  result_col = i+1; result_row = j+1;
  if (r == -1) {
    winner = go[i+4*c][j+4*r];
    result_col = i+4*c+1; result_row = j+4*r+1;
  }
}


int main(){
  //입력 오목판 만들기
  for(int i = 0; i < 19; i++) {
    for(int j = 0; j < 19; j++) {
      int tmp1;
      cin >> tmp1;
      go[i][j] = tmp1;
    }
  }

  //대각선 5개, 가로 5개, 세로 5개
  //대각선 5개 => [i][j], [i+1][j+1], [i+2][j+2], [i+3][j+3], [i+4][j+4]
  //가로 5개 => [i][j:j+4]
  //세로 5개 => [i:i+4,j]
  //5개 초과하는 경우도 생각
  //대각선 5개 만족하나 [i+5][j+5]도 같은 돌이면 이긴거 아님
  //가로 5개 만족하나 [i][j+5]도 같은 돌이면 이긴거 아님
  //세로 5개 만족하나 [i+5][j]도 같은 돌이면 이긴거 아님
  for(int i = 0; i < 19; i++) {
    for(int j = 0; j < 19; j++) {
      if(go[i][j] != 0){
        //대각선1
      	checkGO(1,1,i,j);
        //대각선2
        checkGO(1,-1,i,j);
      	//가로
      	checkGO(0,1,i,j);
      	//세로
      	checkGO(1,0,i,j);

      }
    }
  }

  cout << winner <<'\n';
  if(winner != 0){
    cout << result_col << " " << result_row << '\n';
  }
}
//
// Created by 양인경 on 25. 4. 11.
//
