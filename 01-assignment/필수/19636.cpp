#include <iostream>

using namespace std;

void noChangeCalDiet(const int& date, const int& energy_in, const int& working_a, int weight, const int& bmr_i, const int& chan_t) {
    int i = 0;
    int cons;
    int tmp;
    while (i<date) {
        cons = bmr_i + working_a;
        tmp = energy_in - cons;
        weight += tmp;
        i++;
    }
    if (weight<=0 || bmr_i <= 0) {
        //프린트 danger diet
        cout << "Danger Diet" << '\n';
    }else {
        cout << weight << " " << bmr_i << '\n';
    }
}

void calDiet(const int& date, const int& energy_in, const int& working_a, int weight, const int& bmr_i, const int& chan_t) {
    int i = 0;
    int cons;
    int tmp;
    int bmr_new = bmr_i;
    while (i<date) {
        cons = bmr_new + working_a;
        tmp = energy_in - cons;
        weight += tmp;
        if (abs(tmp)>chan_t) {
            bmr_new += ((tmp-1)/2);
        }
        i++;
    }
    string result;
    if ((bmr_i-bmr_new)>0) {
        result = "YOYO";
    }
    else {
        result = "NO";
    }
    if (weight<=0 || bmr_new <= 0) {
        //프린트 danger diet
        cout << "Danger Diet" << '\n';
    }else {
        cout << weight << " " << bmr_new << " " << result << '\n';
    }
}

int main() {
    //음수 나눗셈 시 -5/2 = -2 이므로 -1 추가해서 -3으로 만들어야함
    //다이어트 전 체중, 일일 에너지 섭취량 및 기초 대사량, 기초대사량 변화 역치
    //다이어트 전 일일 에너지 섭취량 = 기초 대사량, 활동 대사량 = 0
    int weight, bmr_i, chan_t;
    //다이어트 기간, 일일 에너지 섭취량, 일일 활동 대사량
    int date, energy_in, working_a;
    //입력
    cin >> weight >> bmr_i >> chan_t;
    cin >> date >> energy_in >> working_a;

    noChangeCalDiet(date, energy_in, working_a, weight, bmr_i, chan_t);

    calDiet(date, energy_in, working_a, weight, bmr_i, chan_t);
    return 0;
}