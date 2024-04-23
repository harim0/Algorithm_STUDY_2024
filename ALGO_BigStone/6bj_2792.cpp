#include<bits/stdc++.h>

using namespace std;

long long n,m;

int main(){
    cin>>n>>m;
    long long jewry[m], sum = 0, high = 0;
    for(int i=0; i<m; i++){
        cin>>jewry[i];
        high = max(high, jewry[i]);
        sum+=jewry[i];
    }

    long long low = sum/n, mid, rst = 1e9, cnt = 0;
    while(low<=high){
        mid = (low + high)/2;
        cnt = 0;
        for(int i=0; i<m; i++){
            cnt+=jewry[i]/mid;
            if(jewry[i]%mid) cnt++;
        }
        if(cnt<=n){ 
            rst = min(rst, mid);
            high = mid-1;
        }
        else low = mid+1;
    }
    cout<<rst<<"\n";

    return 0;
}