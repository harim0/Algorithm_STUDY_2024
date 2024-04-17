#include<bits/stdc++.h>

using namespace std;

const int n = 52;
int matrix[n][n]={0,};
int visited[n][n]={0,};
int N,M;

int dx[]={-1,0,1,0};
int dy[]={0,1,0,-1};

vector<pair<int,int>>home;
vector<pair<int,int>>chicken;
vector<int> vec;

int distSum = 0;
int min_distSum = 10000;
void print(){
    for(auto i: vec) cout<<"chicken: ("<<chicken[i].first<<","<<chicken[i].second<<")\n";
    cout<<endl;
    for(auto i: home) cout<<"home: ("<<i.first<<","<<i.second<<")\n";
    cout<<endl;
    for(auto i: vec) cout<<i<<" ";
    cout<<endl;
}
void backTsearch(){
    distSum=0;
    for(int i=0; i<home.size(); i++){
        int chicken_dist=100000;
        for(auto idx: vec){
            int dist=abs(home[i].second-chicken[idx].second)+abs(home[i].first-chicken[idx].first);
            // cout<<"idx: "<<idx<<"i: "<<i<<", dist: "<<dist<<endl;
            if(chicken_dist>dist) 
                chicken_dist=dist;
        }
        // cout<<"chicken!: "<<chicken_dist<<endl;
        distSum+=chicken_dist;
    }
}
void comb(int start, int size){
    if(vec.size()==size){ 
        // print();
        backTsearch();
        // cout<<"distSum: "<<distSum<<endl;
        if(distSum<min_distSum) min_distSum=distSum;
    }
    for(int idx=start; idx<chicken.size(); idx++){
        vec.push_back(idx);
        comb(idx+1,size);
        vec.pop_back();
    }
}

int main(){
    cin>>N>>M;
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            cin>>matrix[i][j];
            if(matrix[i][j]==1){
                home.push_back({i,j});
            }
            else if(matrix[i][j]==2){
                chicken.push_back({i,j});
            }
        }
    }
    comb(0,M);
    cout<<min_distSum<<endl;
    
    return 0;
}