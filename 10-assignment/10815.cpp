#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int fn(int num, vector<int>& cards) {
    int left = 0, right = cards.size() - 1;
    int result = 0;
    while (left <= right) {
        int mid = (right + left) / 2;
        if (num > cards[mid]) {
            left = mid+1;
        } else if (num < cards[mid]) {
            right = mid-1;
        } else {
            result = 1;
            break;
        }
    }
    return result;
}

int main() {
    //입력
    int num_card, num_match;
    cin >> num_card;
    vector<int> cards(num_card);
    for (int i = 0; i<num_card; i++) {
        cin>>cards[i];
    }
    sort(cards.begin(), cards.end()); //정렬

    cin >> num_match;
    vector<int> match(num_match);
    for (int i = 0; i<num_match; i++) {
        int num;
        cin >> num;
        match[i] = fn(num, cards);
    }

    for (int i = 0; i<num_match; i++) {
        cout<<match[i]<<" ";
    }

    return 0;
}
//
// Created by 양인경 on 25. 5. 9.
//
