#include <iostream>
#include <vector>

using namespace std;


int main() {
    int n;
    cin >> n; //수열의 크기

    vector<int> a(n); vector<int> dp(n,1);
    int max_len = 0;

    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    for(int i = 0; i < n; i++) {
        int len = 0;
        for(int j = 0; j<i; j++){
            if(a[i] > a[j]){
                len = max(len, dp[j]);
            }
        }
        dp[i] = len+1;
        if(max_len < dp[i]){
            max_len = dp[i];
        }
    }

    cout << max_len << endl;
}
//
// Created by 양인경 on 25. 4. 4.
//
