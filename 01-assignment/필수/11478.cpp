#include <iostream>
#include <set>

using namespace std;

int main() {
    string str;
    set<string> se;
    //입력
    cin >> str;

    //연속된 부분 문자열 생성 및 set에 입력
    for (int i = 0; i<str.length(); i++) {
        string temp;
        for (int j = i; j<str.length(); j++) {
            temp += str[j];
            se.insert(temp);
        }
    }

    cout << se.size() << endl;
    return 0;
}