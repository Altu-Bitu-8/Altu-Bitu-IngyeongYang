#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

//typedef pair<int, int> pi;로 대신 사용 가능
//지원자 구조체 생성
struct applicant {
    int application_rank, interview_rank;
};

bool cmp(const applicant &a, const applicant &b) {
    return a.application_rank < b.application_rank;
}

//int calcPpl(const vector<pi>& score){
//int len = 벡터 사이즈, max = 첫사람의 두번째 요소
//밑에 함수 정리해서 사용
//for (auto & applicant : applicants) {
//if (applicant.interview_rank < best_interview_rank ) {
//    select_cnt += 1;
//    best_interview_rank = applicant.interview_rank;
//


int main() {
    //테스트 케이스의 개수
    int T;
    cin >> T;
    //while(T--) => T번만큼 반복 for 대신 사용
    for (int i = 0; i<T; i++) {
        //지원자의 숫자
        int N;
        cin >> N;
        //vector<pi> score(N)
        vector<applicant> applicants;
        applicants.assign(N, {});
        for (int j = 0; j<N; j++) {
          //cin >> score[i].first >> score[i].second
            cin >> applicants[j].application_rank >> applicants[j].interview_rank;
        }
        //sort(score.begin(), score.end()); => 첫 요소 기준으로 정렬 if 두번째 요소 기준으로 정렬을 원할 시...
        //값을 바꿔서 받거나 score.second.begin()으로 사용
        sort(applicants.begin(), applicants.end(), cmp);
        int select_cnt = 0;
        int best_interview_rank = N+1;
        for (auto & applicant : applicants) {
            if (applicant.interview_rank < best_interview_rank ) {
                select_cnt += 1;
                best_interview_rank = applicant.interview_rank;
            }
        }
        cout << select_cnt << '\n';
    }
    return 0;
}

//
// Created by 양인경 on 25. 2. 20.
//
