#include<bits/stdc++.h>

using namespace std;
int k, n;
long long int Lan[10001];

int isValid(long long int l){
    int cnt = 0;
    for(int i=0; i<k; i++){
        cnt+=Lan[i]/l;
    }
    return cnt>=n;
}

int main(){
    cin>>k>>n;
    long long int  max_len = 1000000000;
    for(int i=0; i<k; i++){
        cin>>Lan[i];
        max_len = max(max_len, Lan[i]);
    }

    long long int  left = 1;
    long long int  right = max_len;
    long long int  min_len = 0;
    while(left<=right){
        long long int  mid = (left+right)/2;
        if(isValid(mid)){
            min_len = max(min_len, mid);
            left = mid+1; 
        }else{
            right = mid-1; 
        }
    }

    cout<<min_len<<endl;

    return 0;
}