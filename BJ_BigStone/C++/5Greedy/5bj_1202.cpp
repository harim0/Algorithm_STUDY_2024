#include <bits/stdc++.h>

using namespace std;

long long n, k;

int main()
{
    cin >> n >> k;
    vector<pair<long long,long long>> jewry(n);
    vector<long long> bag(k);

    for(int i=0; i<n; i++)
        cin>>jewry[i].first>>jewry[i].second;
    for(int i=0; i<k; i++)
        cin>>bag[i];

    sort(bag.begin(), bag.end());
    sort(jewry.begin(), jewry.end());

    priority_queue<long long> pq;
    long long sum = 0;
    int j = 0;
    for(int i=0; i<k; i++){
        while(j<n&&jewry[j].first<=bag[i]) pq.push(jewry[j++].second);
        if(pq.size()){
            sum+=pq.top();
            pq.pop();
        }
    }

    cout<<sum<<"\n";

    return 0;
}