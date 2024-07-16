#include<bits/stdc++.h>
#include<cstring>

using namespace std;
string n;
int a,b,c;
int main(){
    cin>>n;
    string k = "";
    if(n.size()==1){
        n = '0'+n;
    }
    a = n[0]-'0';
    b = n[1]-'0';
    k = n[1];
    
    int cnt = 0;
    while(n.compare(k)){
        c = a+b;
        k = b+'0';
        string c2 = to_string(c);
        k += c2[c2.size()-1];
        a = k[0]-'0';
        b = k[1]-'0';
        cnt++;
    }
    cout<<cnt<<endl;
    return 0;
}