#include <iostream>

using namespace std;

int com_num;
int line;
int cm_graph[101][101] = {0,};
bool visited[101] = {false,};
int cnt = 0;

void virus(int from){
  for(int i = 1; i<=com_num; i++) {
    if(cm_graph[from][i] == 1 && !visited[i]) {
      visited[i] = true;
      virus(i);
    }
  }
}

int main(){
    cin >> com_num;
    cin >> line;

    for(int i = 0; i < line; i++){
      int cm_num1, cm_num2;
      cin >> cm_num1 >> cm_num2;
      cm_graph[cm_num1][cm_num2] = cm_graph[cm_num2][cm_num1] = 1;
    }

    visited[1] = true;
    virus(1);

    for(int i = 2; i<= com_num; i++){
      if(visited[i]){
        cnt++;
      }
    }

    cout << cnt << '\n';

}
//
// Created by 양인경 on 25. 4. 11.
//
