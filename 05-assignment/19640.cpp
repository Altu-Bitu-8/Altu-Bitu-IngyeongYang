#include <iostream>
#include <queue>

using namespace std;

struct person {
    int wdays, rtol, linenum, index;
};

struct cmp {
    bool operator()(person& a, person& b) {
        if (a.wdays != b.wdays) return (a.wdays < b.wdays);
        else if (a.rtol != b.rtol) return (a.rtol < b.rtol);
        else return (a.linenum > b.linenum);
    }
};

int main() {

    //입력
    int n, m, k;
    cin >> n >> m >> k;

    //연산
    priority_queue<person, vector<person>, cmp> pq; // 맨 앞에 있는거끼리 비교하는 우선순위 큐
    vector<queue<person>> line(m);

    //줄에 사원들 넣기
    for (int i = 0; i < n; i++) {
        int lnum = i%m;
        int w, r;
        cin >> w >> r;
        line[lnum].push({w, r,lnum, i});
    }

    //우선순위 큐에 맨 앞 사원들 넣기
    for (int i = 0; i<m; i++) {
        if (!line[i].empty()) { //비어있지 않을 때만 넣기
            pq.push(line[i].front()); //맨 앞 사원 넣기
            line[i].pop(); //넣은 사원은 그 줄에서 뺴기
        }
    }

    int cnt = 0;
    while (true) {
        if (pq.top().index == k) { //데카가 out되면 반복문 종료
            break;
        }
        int num = pq.top().linenum; //out된 사원의 줄 번호 기억
        pq.pop();
        cnt++;
        if (!line[num].empty()) { //out된 사원의 줄 안 끝났을 때 입력
            pq.push(line[num].front()); //out된 사원의 줄에서 새로운 사람 넣기
            line[num].pop();
        }
    }

    //출력
    cout << cnt << '\n';
}
//
// Created by 양인경 on 25. 3. 21.
//

