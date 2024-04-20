#include<bits/stdc++.h>

using namespace std;

int vertices[100001];

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
class Edge {
public:
    int u, v, weight;
    Edge(int u, int v, int weight) : u(u), v(v), weight(weight) {}

    bool operator < (const Edge& edge) const {
        return weight < edge.weight;
    }
};

int n = 7, m = 11;
int sum = 0;
vector<Edge> edges;

void init(){
    edges.push_back(Edge(1,7,12));
    edges.push_back(Edge(1,4,28));
    edges.push_back(Edge(1,2,67));
    edges.push_back(Edge(1,5,17));
    edges.push_back(Edge(2,4,24));
    edges.push_back(Edge(2,5,62));
    edges.push_back(Edge(3,5,20));
    edges.push_back(Edge(3,6,37));
    edges.push_back(Edge(4,7,13));
    edges.push_back(Edge(5,6,45));
    edges.push_back(Edge(5,7,73));

    sort(edges.begin(), edges.end());

    for (int i = 0; i < n; i++) vertices[i] = i;
}
vector<Edge> kruskal(){
    vector<Edge> mst;
    for(int i=0; i<edges.size(); i++){
        if(!isSameParent(edges[i].u-1, edges[i].v-1)){
            sum+=edges[i].weight;
            mst.push_back(edges[i]);
            unionParent(edges[i].u-1, edges[i].v-1);
        }

        if(mst.size()==n-1) return mst;
    }
    return mst;
}

int main(){
    init();
    vector<Edge> mst = kruskal();

    cout<<"[MST :: KRUSKAL]\n";
    for(int i=0; i<mst.size(); i++){
        cout<<mst[i].u<<" - "<<mst[i].v<<" : cost = "<<mst[i].weight<<endl;
    }
    cout<<"total sum: "<<sum<<endl;

    return 0;
}