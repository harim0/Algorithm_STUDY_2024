#include <iostream>
#include <string>
#include <vector>
#include <cmath>

using namespace std;

vector<int> solution_fail(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;
    vector<int> period;
    
    for(int i=0; i<progresses.size(); i++){
        period.push_back(int(ceil((100-progresses[i])/speeds[i])));
    } // 1. 아 0인 경우 문제 될 수 있겠다 -> ㄴㄴ 작업 진도 100 미만 
    // 2. 오히려 작업 속도가 작업 진도보다 큰 경우 3/100 -> ceil?
    // 3++. ceil 이 오답 이유 맞는 것 같은데?
    
    int cnt = 1;
    int prev = period[0]; // 3. 이거였누,, max가 아닌 단순 앞뒤만 비교,,

    for(int i=1; i<period.size(); i++){
        if(period[i]>prev){
            answer.push_back(cnt);
            cnt = 1;
        }else{
            cnt++;
        }
        if(i==period.size()-1)
            answer.push_back(cnt);
        prev = period[i];
    }

    return answer;
}
vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;
    vector<int> period;
    
    for(int i=0; i<progresses.size(); i++){
        period.push_back(int(ceil((double)(100-progresses[i])/speeds[i])));
    } // (99-progresses[i])/speeds[i]+1 방법도 있음 ㅌㅌ
    
    int cnt = 1;
    int max = period[0];

    for(int i=1; i<period.size(); i++){
        if(period[i]>max){
            answer.push_back(cnt);
            cnt = 1;
        }else{
            cnt++;
        }
        if(i==period.size()-1)
            answer.push_back(cnt);
        if(max<period[i]) max = period[i];
    }

    return answer;
}
vector<int> solution2(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;
    vector<int> period;
    
    for(int i=0; i<progresses.size(); i++){
        period.push_back(int(ceil((double)(100-progresses[i])/speeds[i])));
    }
    
    int cnt = 0;
    int end = period.size();
    for(int i=0; i<period.size(); i++){
        cnt++;
        if(i<end-1&&period[i]<period[i+1]||i==end-1){
            answer.push_back(cnt);
            cnt = 0;
        }
    }

    return answer;
}

int main(){
    vector<int> p1 = {95, 90, 99, 99, 95, 99}; // 5 10 1 1 5 1 
    vector<int> s1 = {1, 1, 1, 1, 1, 1}; // 5 ,10 1 1 5 1 -> 1 5
    vector<int> p2 = {93, 86, 30, 55}; // 7 70 45
    vector<int> s2 = {1, 2, 30, 10}; // 7 3 ,9 -> 2 1

    vector<int> rst = solution(p1,s1);
    vector<int> rst2 = solution(p2,s2);

    cout<<"rst1"<<"\n";
    for(auto data:rst){
        cout<<data<<" ";
    }
    cout<<"\n"<<"rst2"<<"\n";
    for(auto data:rst2){
        cout<<data<<" ";
    }

    // cout<<"ceil 함수 알아보기"<<endl; // 2. ceil 검증 완 -> 1  -> 아니었음....
    // cout<<ceil(3/10)<<endl; // 이것 봐...
    // cout<<ceil(11/1000)<<endl;
    // cout<<ceil(0.0012)<<endl;
    // cout<<3/10<<endl;
    // cout<<(double)3/10<<endl; // 오케 원인 파악,,,,,!!!!!!

    return 0;
}