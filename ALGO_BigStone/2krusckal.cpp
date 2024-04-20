#include<bits/stdc++.h>

using namespace std;

typedef pair <int, pair<int,int>> p;

vector<p> edges;
int vertices[100001];
int v=6;

int getRoot(int x){
    if(vertices[x]==x) return x;
    return vertices[x] = getRoot(vertices[x]);
}
void unionParent(int a, int b){
    a = getRoot(a);
    b = getRoot(b);
    if(a<b) vertices[b] = a;
    else vertices[a] = b;
}
int isSameParent(int a, int b){
    a = getRoot(a);
    b = getRoot(b);
    if(a==b) return 1;
    else return 0;
}
vector<p> kruskal(){
    vector<p> mst;
    for(int i=0; i<edges.size(); i++){
        p cur_edge = edges[i];

        int f = cur_edge.second.first;
        int s = cur_edge.second.second;

        if(getRoot(f)==getRoot(s)) continue;
        mst.push_back(cur_edge);
        unionParent(f,s);

        if (mst.size() == v - 1) return mst;
    }
    return mst;
}

void init(){
    edges.push_back({ 1, {1, 5} });
    edges.push_back({ 4, {1, 3} });
    edges.push_back({ 3, {1, 4} });
    edges.push_back({ 9, {1, 2} });
    edges.push_back({ 4, {2, 4} });
    edges.push_back({ 5, {2, 5} });
    edges.push_back({ 6, {3, 6} });
    edges.push_back({ 2, {4, 5} });
    edges.push_back({ 8, {4, 6} });

    sort(edges.begin(), edges.end());

    for (int i = 1; i <= 6; i++) vertices[i] = i;
}
int main(){
    init();
    vector<p> mst = kruskal();

    cout<<"[MST :: KRUSKAL]\n";
    for (int i = 0; i < mst.size(); i++) {
        cout<<mst[i].second.first<<", "<< mst[i].second.second<<", dist: "<< mst[i].first<<"\n";
    }

    return 0;
}