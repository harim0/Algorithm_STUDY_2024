// 2024-03-09 16:30

#include <iostream>
#include <vector>
#include <stack>

using namespace std;

vector<int> solution(vector<int> prices) {
    vector<int> answer;
    for(int i=0; i<prices.size(); i++){
        int criteria = prices[i];
        int cnt = 0;
        for(int j=i; j<prices.size()-1; j++){
            if(prices[j]>=criteria) cnt++;
            else break;
        }
        answer.push_back(cnt);
    }
    return answer;
}


// 아니 시발 어떻게 이런 생각을 하지? -> 시간 흐르는 것 멈춤포인트 잡기
vector<int> solution_ref(vector<int> prices) {
    vector<int> answer(prices.size());
    stack<int> s;
    int size = prices.size();
    for(int i=0;i<size;i++){
        while(!s.empty()&&prices[s.top()]>prices[i]){
            cout<<"i: "<<i<<", s.top(): "<<s.top()<<endl;
            answer[s.top()] = i-s.top();
            s.pop();
        }
        s.push(i);
        cout<<"push i "<<i<<endl;
    }
    cout<<"wow"<<endl;
    while(!s.empty()){
        cout<<"2nd::"<<" s.top(): "<<s.top()<<endl;
        answer[s.top()] = size-s.top()-1;
        s.pop();
    }
    return answer;
}

int main(){
    vector<int> rst1 = solution_ref({1, 2, 3, 2, 3});
    
    for(auto a: rst1){
        cout<<a<<" ";
    }

    return 0;
}