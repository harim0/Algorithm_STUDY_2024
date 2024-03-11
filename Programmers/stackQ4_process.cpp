// 2024-03-08
// 우선순위 큐?
#include <iostream>
#include <vector>

using namespace std;

int solution(vector<int> priorities, int location) {
    int answer = 0;

    vector<pair<int,int>> restart;
    for(int i=0; i<priorities.size(); i++){
        restart.push_back(make_pair(i,priorities[i]));
    }

    int begin = 0;
    int end = restart.size()-1;

    int max = restart[begin].second;
    for(int i=begin+1; i<=end; i++){
        if(restart[i].second>max){
            max = restart[i].second;
        }
    }

    while(begin<=end){ // <-ㅇㄴ
        end = restart.size()-1; // 1 위치 헷갈려
        cout<<"max: "<<max<<", begin: "<<begin<<", end: "<<end<<endl;

        if(restart[begin].second<max){
            restart.push_back(restart[begin]);
            begin++;
        }else{
            answer++;
            if(location==restart[begin].first) break;
            begin++;
            
            max = 0;
            for(int i=begin; i<=end; i++){ // 2 max update
                if(restart[i].second>max){
                    max = restart[i].second;
                }
            }
        }
    }

    return answer;
}

int main(){
    int rst1 = solution({2, 2, 2, 1, 3, 4}, 3);
    int rst2 = solution({1, 1, 9, 1, 1, 1}, 0);

    cout<<"rst1: "<<rst1<<endl;
    cout<<"rst2: "<<rst2<<endl;

    return 0;
}
