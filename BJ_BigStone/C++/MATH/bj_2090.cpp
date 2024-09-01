// https://www.acmicpc.net/problem/2090
#include<bits/stdc++.h>

using namespace std;

vector<long long int> store;

long long int gcd(long long int a, long long int b){
    return b? gcd(b, a%b):a;
}
long long int lcm(long long int a, long long int b){
    return a*b/gcd(a,b);
}

int main(){
    int n;
    cin>>n;
    long long int c, denominator = 0;
    for(int i=0; i<n; i++){ 
        cin>>c;
        store.push_back(c);
    }
    sort(store.begin(), store.end());

    long long int nominator = store[0];

    for(int i=1; i<n; i++) nominator = lcm(store[i],nominator);

    for(int i=0; i<n; i++) denominator+=(nominator/store[i]);

    long long int piv = gcd(nominator, denominator);
    
    cout<<nominator/piv<<"/"<<denominator/piv<<endl;

    return 0;
}