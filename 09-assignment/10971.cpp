#include <iostream>
#include <algorithm>
#include <vector>
#include <climits>

using namespace std;

int result = INT_MAX;
int start;

void fn(vector<vector<int>>& weight, int i, vector<bool>& visited, int& sum, int& cnt){
  if(cnt == visited.size()) {
    if(weight[i][start] != 0){
      result = min(result, sum + weight[i][start]);
    }
    return;
  }
  for(int j = 0; j<weight.size(); j++) {
      if(!visited[j] && weight[i][j] != 0) {
        visited[j] = true;
        sum += weight[i][j];
        cnt++;
        fn(weight, j, visited, sum, cnt);

        visited[j] = false;
        sum -= weight[i][j];
        cnt--;
      }
    }
}

int main() {
  int n; //number of cities
  cin>>n;

  vector<vector<int>> weight(n, vector<int>(n));
  vector<bool> visited(n, false);
  for(int i=0; i<n; i++){
    for(int j=0; j<n; j++){
      cin >> weight[i][j];
    }
  }
  for(int i = 0; i<weight.size(); i++) {
    //처음 시작점이 i
    start = i;
    int sum = 0;
    int cnt = 1;
    visited[i] = true;
    fn(weight, i, visited, sum, cnt);
    visited[i] = false;
  }
  cout << result << '\n';
}

//
// Created by 양인경 on 25. 5. 1.
//
