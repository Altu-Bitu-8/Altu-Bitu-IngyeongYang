#include <iostream>

using namespace std;

int person;
int target1, target2;
int line_num;
int family_tree[101][101];
bool visited[101] = {false,};
int result = -1;

void dfs(int current, int cnt){
  if(current == target2){
    result = cnt;
    return;
  }

  visited[current] = true; //방문함

  for(int i = 1;i<= person;i++){
    if(family_tree[current][i] == 1 && !visited[i]){
      dfs(i, cnt+1);
    }
  }
}

int main(){
  cin >> person;
  cin >> target1 >> target2;
  cin >> line_num;

  for(int i = 0; i < line_num; i++){
    int tmp1, tmp2;
    cin >> tmp1 >> tmp2;
    family_tree[tmp1][tmp2] = family_tree[tmp2][tmp1] = 1;
  }

  dfs(target1, 0);

  cout << result << '\n';
}