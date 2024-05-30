#include<bits/stdc++.h>
// 와. 런타임 에러 타입! 문자열 기준 100글자
using namespace std;

vector<string> store;
string temp;

void pullNum(){
    while(true){
        if(temp.size()&&temp.front()=='0') temp.erase(temp.begin());
        else break;
    }
    if(temp.size()==0) temp="0";
    store.push_back(temp);
    temp="";
}

bool cmp(string a, string b){
    if(a.size()==b.size()) return a<b;
    return a.size()<b.size();
}

int main(){
    int l;
    cin>>l;
    for(int i=0; i<l; i++){
        string s;
        cin>>s;

        temp="";
        for(int idx=0; idx<s.length(); idx++){
            if(s[idx]<65) temp+=s[idx];
            else if(temp.size()) pullNum();
        }
        if(temp.size()) pullNum();
    }
    sort(store.begin(), store.end(), cmp);
    for(auto g: store) cout<<g<<endl;

    return 0;
}
