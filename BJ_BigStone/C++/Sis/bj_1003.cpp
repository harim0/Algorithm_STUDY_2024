#include <bits/stdc++.h>

using namespace std;

int t,n;

int memo1[41]={0,1,1};
void fibonnaci(int n){
    for(int i=3; i<=n; i++){
        memo1[i] = memo1[i-1]+memo1[i-2];
    }
}
void print_fibonnaci(){
    while(t--){
        cin>>n;
        fibonnaci(n);
        if(n==0) cout<<1<<' '<<0<<'\n';
        else if(n==1) cout<<0<<' '<<1<<'\n';
        else cout<<memo1[n-1]<<' '<<memo1[n]<<'\n';
    }
}

int memo2[41][3];
void fibonnaci1(int n){
    memo2[0][1] = 0;
    memo2[1][0] = 0;
    memo2[0][0] = 1;
    memo2[1][1] = 1;
    for(int i=2; i<=n; i++){
        memo2[i][0] = memo2[i-1][0]+memo2[i-2][0];
        memo2[i][1] = memo2[i-1][1]+memo2[i-2][1];
    }
}
void print_fibonnaci1(){
    while(t--){
        cin>>n;
        fibonnaci1(n);
        cout<<memo2[n][0]<<" "<<memo2[n][1]<<"\n";
    }
}

int memo3[41]={0,};
int fibonnaci2(int n){
    if(n==0){
        memo3[n] = 0;
        return memo3[n];
    }else if(n==1){
        memo3[n] = 1;
        return memo3[n];
    }else if(memo3[n]){ 
        return memo3[n];
    }
    else{ 
        memo3[n] = fibonnaci2(n-1)+fibonnaci2(n-2);
        return memo3[n];
    }
}
void print_fibonnaci2(){
    while(t--){
        cin>>n;
        fibonnaci2(n);
        if(n==0) cout<<1<<' '<<0<<'\n';
        else if(n==1) cout<<0<<' '<<1<<'\n';
        else cout<<memo3[n-1]<<' '<<memo3[n]<<'\n';
    }
}

int main(){
    cin>>t;
    print_fibonnaci();
    // print_fibonnaci1();
    // print_fibonnaci2();
    return 0;
}

// #include<iostream>
// #include<cstring>

// using namespace std;

// int t;
// int num[41];

// int memo1[41]={0,1,1};
// void fibonnaci(int n){
//     for(int i=3; i<=n; i++){
//         memo1[i] = memo1[i-1]+memo1[i-2];
//     }
// }
// void print_fibonnaci(){
//     for(int i=0; i<t; i++){
//         fibonnaci(num[i]);
//         if(n==0) cout<<1<<' '<<0<<'\n';
//         else if(n==1) cout<<0<<' '<<1<<'\n';
//         else cout<<memo1[n-1]<<' '<<memo1[n]<<'\n';
//     }
// }

// int memo2[41][3];
// void fibonnaci1(int n){
//     memo2[0][1] = 0;
//     memo2[1][0] = 0;
//     memo2[0][0] = 1;
//     memo2[1][1] = 1;
//     for(int i=2; i<=n; i++){
//         memo2[i][0] = memo2[i-1][0]+memo2[i-2][0];
//         memo2[i][1] = memo2[i-1][1]+memo2[i-2][1];
//     }
// }
// void print_fibonnaci1(){
//     for(int i=0; i<t; i++){
//         fibonnaci1(num[i]);
//         cout<<memo2[num[i]][0]<<" "<<memo2[num[i]][1]<<"\n";
//     }
// }

// int memo3[41]={0,};
// int fibonnaci2(int n){
//     if(n==0){
//         memo3[n] = 0;
//         return memo3[n];
//     }else if(n==1){
//         memo3[n] = 1;
//         return memo3[n];
//     }else if(memo3[n]){ 
//         return memo3[n];
//     }
//     else{ 
//         memo3[n] = fibonnaci2(n-1)+fibonnaci2(n-2);
//         return memo3[n];
//     }
// }
// void print_fibonnaci2(){
//     for(int i=0; i<t; i++){
//         fibonnaci2(num[i]);
//         if(num[i]==0) cout<<1<<' '<<0<<'\n';
//         else if(num[i]==1) cout<<0<<' '<<1<<'\n';
//         else cout<<memo3[num[i]-1]<<' '<<memo3[num[i]]<<'\n';
//     }
// }
