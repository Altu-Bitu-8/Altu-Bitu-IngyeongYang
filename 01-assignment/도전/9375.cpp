#include <iostream>
#include <map>

using namespace std;

int countNum(map<string, int>& clothes) {
    int cnt = 1;
    for (auto it : clothes) {
        cnt = cnt * (it.second + 1);
    }
    return cnt-1;
}

void inputClothes(int num_clothes) {
    string name, type;
    map<string, int> clothes;
    for (int i = 0; i < num_clothes; i++) {
        cin >> name >> type;
        clothes[type]++;
    }
    cout << countNum(clothes) << '\n';
}

int main() {
    int testcase, num_clothes;
    //입력
    cin >> testcase;
    for (int i = 0; i < testcase; i++) {
        cin >> num_clothes;
        inputClothes(num_clothes);
    }
}