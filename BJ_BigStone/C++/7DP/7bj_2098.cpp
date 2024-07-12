#include<iostream>
#include<vector>

using namespace std;

int w[16][16] = {0,};
int memo[16] = {0,};
int rst = 1e9;

void recur_memo(int start, int end, int n, vector<int> bags, int cur_sum){ 
    if (bags.size()==n-1) {
        cur_sum+=w[end][0];
        rst = min(rst, cur_sum);
    }

    memo[end] = 1;
    for(int i=0; i<n; i++){
        if(i!=start&&i!=end&&memo[i]==0){
            bags.push_back(w[end][i]);
            recur_memo(end, i, n, bags, cur_sum+w[end][i]); 
            bags.pop_back();
        }
    }
    memo[end] = 0;
}

int main(){
    int n;
    cin>>n;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cin>>w[i][j];
        }
    }

    vector<int> bags;
    memo[0] = 1;
    for(int i=1; i<n; i++){
        bags.push_back(w[0][i]);
        recur_memo(0, i, n, bags, w[0][i]);
        bags.pop_back();
    }

    cout<<rst<<endl;

    return 0;
}