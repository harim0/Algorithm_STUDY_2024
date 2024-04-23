#include<bits/stdc++.h>

using namespace std;

typedef pair<long long, long long> p;
int n;

int main(){
    cin>>n;
    priority_queue<p, vector<p>, greater<p>> pq;
    for(int i=0; i<n; i++){
        long long x,y;
        cin>>x>>y;
        pq.push({x,y});
    }

    long long dist = 0;
    long long prevFrom = pq.top().first;
    long long prevTo = pq.top().second;
    pq.pop();
    while(pq.size()){
        // cout<<">> pq: "<<pq.top().first<<" -to- "<<pq.top().second<<endl;
        if(prevTo<pq.top().first){
            dist+=(prevTo-prevFrom);
            // cout<<"dist2: "<<dist<<", prev: "<<prevFrom<<" -to- "<<prevTo<<endl;
            prevFrom = pq.top().first;
            prevTo = pq.top().second;
        }else if(pq.top().first<=prevTo&&pq.top().second>=prevTo){
            // cout<<"dist3: "<<dist<<", prev: "<<prevFrom<<" -to- "<<prevTo<<endl;
            prevTo = pq.top().second;
        }
        pq.pop();
    }
    dist+=(prevTo-prevFrom);
    cout<<dist<<"\n";

    return 0;
}