#include<bits/stdc++.h>

using namespace std;

int cnt = 0;
void ex1_rallo(int N){
    for(int i=2400; i<10e6; i++){
        string a = to_string(i);
        if(a.find("2400")!=string::npos){
            if(cnt==N){ 
                cout<<i<<endl;
                break;
            }
            cnt++;
        }
    }
}
/*
10
24 35 38 40 49 59 60 67 83 98
*/
int N;
int arr[100];
int visited[100];

int check_prime(int num){
    if(num<=1) return 0;
    if(num==2) return 1;
    if(num%2==0) return 0;
    for(int i=2; i*i<=num; i++){
        if(num%i==0) return 0;
    }
    return 1;
}
int ex2_prime(int idx, int add_sum){
    // cout<<"idx: "<<idx<<", num: "<<arr[idx]<<", add_sum: "<<add_sum<<endl;
    if(idx==N) return check_prime(add_sum);
    return ex2_prime(idx+1, add_sum)+ex2_prime(idx+1, add_sum+arr[idx]);
}
int max_num = 0;
void ex3_big(int idx, int add_sum){
    if(max_num<add_sum) max_num = add_sum;
    if(idx==N) return;
    ex3_big(idx+1, add_sum%11);
    ex3_big(idx+1, (add_sum+arr[idx])%11);
}

int main(){
    cin>>N;

    // cout<<"ex1_rallo: ";
    // ex1_rallo(N);

    for(int i=0; i<N; i++){
        cin>>arr[i];
    }

    // cout<<ex2_prime(0, 0)<<endl;
    ex3_big(0, 0);
    cout<<max_num<<endl;
    return 0;
}