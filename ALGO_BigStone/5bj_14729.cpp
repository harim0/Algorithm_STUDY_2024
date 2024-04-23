#include <bits/stdc++.h>

using namespace std;

int n;
priority_queue<double, vector<double>, greater<double>> pq;

int main(){
    cin>>n;
    for(int i=0; i<n; i++){
        double score;
        cin>>score;
        pq.push(score);
    }

    int cnt = 0;
    while(pq.size()){
        cnt++;
        cout<<fixed<<setprecision(3)<<pq.top()<<"\n";
        pq.pop();
        if(cnt==7) break;
    }
    return 0;
}