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
    p prev = pq.top();
    pq.pop();
    dist+=(prev.second-prev.first);
    while(pq.size()){
        // cout<<">> pq: "<<pq.top().first<<" -to- "<<pq.top().second<<endl;
        if(prev.second<=pq.top().first){
            dist+=(pq.top().second-pq.top().first);
            // cout<<"dist2: "<<dist<<", prev: "<<prev.first<<" -to- "<<prev.second<<endl;
            prev = pq.top();
        }
        pq.pop();
    }
    cout<<dist<<"\n";

    return 0;
}