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
int ex2_prime(int idx, int add_sum){
    // visited[idx]=1;
    // add_sum+=arr[idx];
    cout<<"num: "<<arr[idx]<<", add_sum: "<<add_sum<<endl;

    bool prime = 1;
    for(int i=2; i<add_sum; i++){
        if(add_sum%i==0) prime=0;
    }
    if(prime==1){ 
        cout<<"prime!!!"<<endl;
        return 1;
    }
    // for(int i=0; i<N; i++){
    //     if(!visited[i]) return ex2_prime(i, add_sum);
    // }
    if(idx+1<N){
        ex2_prime(idx+1, add_sum+arr[idx]);
        ex2_prime(idx+1, add_sum);
    }
    return 0;
}

int main(){
    cin>>N;

    // cout<<"ex1_rallo: ";
    // ex1_rallo(N);

    for(int i=0; i<N; i++){
        cin>>arr[i];
    }

    int cnt_prime=0;
    // for(int i=0; i<N; i++){
    //     // if(!visited[i]) cnt_prime+=ex2_prime(i, 0);
    //     memset(visited, 0, sizeof(visited));
    //     cnt_prime+=ex2_prime(i, 0);
    // }
    cnt_prime+=ex2_prime(0, 0);
    cout<<"cnt_prime: "<<cnt_prime<<endl;
    return 0;
}