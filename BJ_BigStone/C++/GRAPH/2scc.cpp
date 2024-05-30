#include<bits/stdc++.h>
// METHOD to extract SCC using TARJANS's ALGORITHM from ndb blog
#define MAX 100001

using namespace std;

int d[MAX], id;
vector<int> matrix[MAX];
vector<vector<int>> SCC;
bool finished[MAX];
stack<int> stk;

int dfs(int x){
    d[x]=++id;
    cout<<"x: "<<x<<"(d[x]: "<<d[x]<<"), push\n";
    stk.push(x);

    int parent = d[x];
    for(int i=0; i<matrix[x].size(); i++){
        int y=matrix[x][i];
        if(d[y]==0) parent=min(parent, dfs(y));
        else if(!finished[y]) parent=min(parent, d[y]);
        cout<<"i: "<<i<<", y: "<<y<<", parent: "<<parent<<endl;
    }

    if(parent==d[x]){
        vector<int> scc;
        while(1){
            int top = stk.top();
            scc.push_back(top);
            stk.pop();
            finished[top]=true; // ^^
            if(top==x) break;
        }
        SCC.push_back(scc);
    }
    cout<<"parent: "<<parent<<endl;
    cout<<"----------------------\n";
    return parent;
}

int main(){
    int v = 11;
    matrix[1].push_back(2);
    matrix[2].push_back(3);
    matrix[3].push_back(1);
    matrix[4].push_back(2);
    matrix[4].push_back(5);
    matrix[5].push_back(7);
    matrix[6].push_back(5);
    matrix[7].push_back(6);
    matrix[8].push_back(5);
    matrix[8].push_back(9);
    matrix[9].push_back(10);
    matrix[10].push_back(11);
    matrix[11].push_back(3);
    matrix[11].push_back(8);

    for(int i=1; i<=v; i++){
        if(d[i]==0) dfs(i);
    }

    for(int i=0; i<SCC.size();  i++){
        cout<<"< "<<i+1<<" 번째 SCC >\n";
        for(int j=0; j<SCC[i].size(); j++){
            cout<<SCC[i][j]<<" ";
        }
        cout<<"\n\n";
    }

    return 0;
}