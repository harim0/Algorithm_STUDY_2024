// 2024-03-11 12:30
#include<iostream>
#include<vector>
#include<string>

using namespace std;

int memo[1000001]={0,};

int num_bin(int num){
    if(memo[num]>0){
        return memo[num];
    }else if(num==1){
        memo[1] = 1;
        return 1;
    }else if(num==2){
        memo[2] = 2;
        return 2;
    }else{

    }

}

int main(){
    int n;
    cin>>n;

    cout<<num_bin(n)<<endl;

    return 0;
}