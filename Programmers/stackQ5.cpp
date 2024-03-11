// 2024-03-09 15:00
// fail 이거는 문제 자체를 이해를 못하겠누. 예제도 그렇구,,

#include <iostream>
#include <vector>

using namespace std;

int solution(int bridge_length, int weight, vector<int> truck_weights) {
    int answer = 1;
    int sum_weights = 0;
    int cnt = 0;
    while(!truck_weights.empty()){
        int truck = truck_weights.front();
        truck_weights.erase(truck_weights.begin());
        cout<<"truck: "<<truck<<endl;

        sum_weights+=truck;
        cnt++;
        cout<<"대기 트럭에서 건넘 다리로"<<endl;
        answer++;
        cout<<"sum_weights: "<<sum_weights<<"cnt: "<<cnt<<endl;
        while(cnt+1<=bridge_length&&sum_weights+truck_weights.front()<=weight){
            cout<<"||| truck: "<<truck<<endl;
            truck = truck_weights.front();
            cout<<"||| truck: "<<truck<<endl;
            truck_weights.erase(truck_weights.begin());
            sum_weights+=truck;
            cnt++;
            cout<<"대기 트럭에서 건넘 다리로"<<endl;
            answer++;
        }
        cout<<">> answer: "<< answer<<'\n'<<endl;
            cout<<"||| <<< rst <<< ||| "<<endl;
            cnt=0;
            sum_weights=0;
    }
    answer++;
    return answer;
}

int main(){
    int rst1 = solution(2,10,{7,4,5,6});
    // int rst2 = solution(100,100,{10});

    cout<<"rst1: "<<rst1<<endl;
    // cout<<"rst2: "<<rst2<<endl;

    return 0;
}
