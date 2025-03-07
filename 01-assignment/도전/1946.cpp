#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

//지원자 구조체 생성
struct applicant {
    int application_rank, interview_rank;
};

bool cmp(const applicant &a, const applicant &b) {
    return a.application_rank < b.application_rank;
}



int main() {
    //테스트 케이스의 개수
    int T;
    cin >> T;
    for (int i = 0; i<T; i++) {
        //지원자의 숫자
        int N;
        cin >> N;
        vector<applicant> applicants;
        applicants.assign(N, {});
        for (int j = 0; j<N; j++) {
            cin >> applicants[j].application_rank >> applicants[j].interview_rank;
        }
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