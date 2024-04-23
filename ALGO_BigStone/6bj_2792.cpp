#include<bits/stdc++.h>

using namespace std;

int n,m;

int main(){
    cin>>n>>m;
    int jewry[m];
    int sum = 0;
    for(int i=0; i<m; i++){
        cin>>jewry[i];
        sum+=jewry[i];
    }

    int k=sum/n;
    int cnt = 0;
    // cout<<"inital k: "<<k<<endl;
    while(cnt!=n){
        cnt = 0;
        for(int i=0; i<m; i++){
            cnt+=jewry[i]/k;
            if(jewry[i]%k>0) cnt++;
        }
        // cout<<"cnt: "<<cnt<<endl;
        if(cnt<n) k--;
        else if(cnt>n) k++;
        // cout<<"updated k: "<<k<<endl;
    }
    cout<<k<<"\n";

    return 0;
}