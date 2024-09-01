// 7에 mid가 3이라면, 3 3 1 = 3 2 2
// 7에 mid가 2라면, 2 2 2 1

// 지금 헷갈리는 것은 학생에게 최대한 공평하게 분배 가능한 최소 보석 수(최대 보석수 per 학생)를 구하는 문제가
// 보석 수를 이진 트리로 찾으며 학생 수를 셈한 결과가 현 학생 수와 동일한지로 해석하는 관점이 동치로 어떻게 놓는건지.
// 그 경우 위와 같은 디테일은 묵살되는 건데 괜찮은 건가?

// cnt가 의미하는 것은? 보석 수에 따른 학생 수
// 5개의 보석, 학생 수 3명 -> 2 2 1 mid=2

#include<bits/stdc++.h>

using namespace std;

long long n,m;

int main(){
    cin>>n>>m;
    long long jewry[m], high = 0, low = 1;
    for(int i=0; i<m; i++){
        cin>>jewry[i];
        high = max(high, jewry[i]);
    }

    // wrong answer 1
    // long long mid, rst = 1e9, cnt = 0;
    // while(low<=high){
    //     mid = (low+high)/2;
    //     // cout<<"low: "<<low<<", high: "<<high<<", mid: "<<mid;
    //     for(int j=0;j<m;j++){
    //         cnt+=jewry[j]/mid;
    //         if(jewry[j]%mid) cnt+=1;
    //     }
    //     // cout<<", cnt = "<<cnt<<endl;
    //     if(cnt<n){ // 학생 수가 작다는 것은 최대 보석 수가 너무 크다는 것 -> 문제
    //         high = mid-1;
    //     }else if(cnt>n){ // 학생 수가 크다는 것은 최대 보석 수가 너무 작다는 것 -> 문제
    //         low = mid+1;
    //     }else{
    //         rst = min(rst, mid); // ...?
    //         break;
    //     }
    //     cnt = 0;
    // }
    
    //  wrong answer 2
    long long mid, rst = 1e9, cnt = 0;
    while(low<=high){
        mid = (low+high)/2;
        // cout<<"low: "<<low<<", high: "<<high<<", mid: "<<mid;
        for(int j=0;j<m;j++){
            cnt+=jewry[j]/mid;
            if(jewry[j]%mid) cnt+=1;
        }
        // cout<<", cnt = "<<cnt<<endl;
        if(cnt>=n){ 
            low = mid+1;
            rst = min(rst, mid);
        }else{ 
            high = mid-1;
        }
        cnt = 0;
    }
    cout<<rst<<"\n";
    
    // correct answer
    // long long mid, rst = 1e9, cnt = 0;
    // while(low<=high){
    //     mid = (low+high)/2;
    //     // cout<<"low: "<<low<<", high: "<<high<<", mid: "<<mid;
    //     for(int j=0;j<m;j++){
    //         cnt+=jewry[j]/mid;
    //         if(jewry[j]%mid) cnt+=1;
    //     }
    //     // cout<<", cnt = "<<cnt<<endl;
    //     if(cnt<=n){ // 학생 수가 작다는 것은 최대 보석 수가 너무 크다는 것 -> 문제
    //         high = mid-1;
    //         rst = min(rst, mid);
    //     }else{ // 학생 수가 크다는 것은 최대 보석 수가 너무 작다는 것 -> 문제
    //         low = mid+1;
    //     }
    //     cnt = 0;
    // }
    // cout<<rst<<"\n";

    return 0;
}