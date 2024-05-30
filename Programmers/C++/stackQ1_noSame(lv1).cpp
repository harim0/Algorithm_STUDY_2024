// 2024-03-05
#include <iostream>
#include <vector>

using namespace std;

// int visited[100];

vector<int> solution(vector<int> arr) 
{
    vector<int> answer;
    // 중복 제거
    // for(int i=0; i<arr.size(); i++){
    //     if(!visited[arr[i]]){ 
    //         visited[arr[i]] = 1;
    //         answer.push_back(arr[i]);
    //     }
    // }
    
    // 연속 제거 -> ㅘ unique & erase
    int prev = arr[0];
    answer.push_back(prev);
    for(int i=1; i<arr.size(); i++){
        if(arr[i]==prev) continue;
        else{
            answer.push_back(arr[i]);
        }
        prev = arr[i];
    }

    return answer;
}

int main(){
    // vector<int> v7 = {1,1,3,3,0,1,1};
    vector<int> v7 = {4,4,4,3,3};
    vector<int> rst = solution(v7);
    for(int i=0; i<rst.size(); i++){
        cout<<" "<<rst[i];
    }
}