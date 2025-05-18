#include <iostream>
#include <vector>

using namespace std;

int num_arr, lim_len;

int main(){
  //입력시작
  cin>>num_arr>>lim_len;
  vector<int> arr(num_arr);
  for(int i=0;i<num_arr;i++){
    cin>>arr[i];
  }
  int max_val = 0;
  for (int x : arr) {
    if (x > max_val) max_val = x;
  }
  //입력 끝

  //연산시작
  vector<int> count(max_val + 1, 0);
  int left = 0, result = 0;

  for (int right = 0; right < num_arr; right++) {
    count[arr[right]]++;

    while (count[arr[right]] > lim_len) {
      count[arr[left]]--;
      left++;
    }
    result = max(result, right - left + 1);
  }

  //출력
  cout << result << '\n';
  return 0;
}
//
// Created by 양인경 on 25. 5. 16.
//
