#include<iostream>
#include<vector>

using namespace std;

int memo[21][21][21]={0,}; // -50 ~ 50
// int memo[101][101][101]={0,}; // -50 ~ 50

int recur_w(int a, int b, int c){
    if(a<=0||b<=0||c<=0){
        return 1;
    }else if(a>20||b>20||c>20){
        return recur_w(20, 20, 20);
    }else if(memo[a][b][c]>0){
        return memo[a][b][c];
    }else if(a<b && b<c){
        memo[a][b][c] = recur_w(a, b, c-1)+recur_w(a, b-1, c-1)-recur_w(a, b-1, c);
    }else{
        memo[a][b][c] = recur_w(a-1, b, c)+recur_w(a-1, b-1, c)+recur_w(a-1, b, c-1)-recur_w(a-1, b-1, c-1);
    }
    return memo[a][b][c];
}
// int recur_w(int a, int b, int c){
//     if(memo[a+50][b+50][c+50]>0){
//         return memo[a+50][b+50][c+50];
//     }else{
//         if(a<=0||b<=0||c<=0){
//             memo[a+50][b+50][c+50] = 1;
//         }else if(a>20||b>20||c>20){
//             memo[a+50][b+50][c+50] = recur_w(20, 20, 20);
//         }else if(a<b && b<c){
//             memo[a+50][b+50][c+50] = recur_w(a, b, c-1)+recur_w(a, b-1, c-1)-recur_w(a, b-1, c);
//         }else{
//             memo[a+50][b+50][c+50] = recur_w(a-1, b, c)+recur_w(a-1, b-1, c)+recur_w(a-1, b, c-1)-recur_w(a-1, b-1, c-1);
//         }
//         return memo[a+50][b+50][c+50];
//     }
// }

int main(){
    // int a,b,c;
    // cin>>a>>b>>c;
    // cout<<"w("<<a<<", "<<b<<", "<<c<<") = "<<recur_w(a,b,c)<<endl;
    // while(a!=-1&&b!=-1&&c!=-1){
    //     cin>>a>>b>>c;
    //     cout<<"w("<<a<<", "<<b<<", "<<c<<") = "<<recur_w(a,b,c)<<endl;
    // }
    int a,b,c;
    while(1){
        cin>>a>>b>>c;
        if(!(a==-1&&b==-1&&c==-1)) 
            cout<<"w("<<a<<", "<<b<<", "<<c<<") = "<<recur_w(a,b,c)<<endl;
        else
            break;
    }
    return 0;
}