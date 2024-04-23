#include<bits/stdc++.h>

using namespace std;

int const n = 4;
int INF = 10000000;

int graph[n][n]={
    {0,5,INF,8},
    {7,0,9,INF},
    {2,INF,0,4},
    {INF,INF,3,0}
};

void floydWarshall(){
    int dist[n][n];
    for(int i=0; i<n; i++)
        for(int j=0; j<n; j++)
            dist[i][j] = graph[i][j];
    
    for(int k=0; k<n; k++){
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                if(dist[i][k]+dist[k][j]<dist[i][j])
                    dist[i][j] = dist[i][k]+dist[k][j];
            }
        }
    }

    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cout<<dist[i][j]<<" ";
        }
        cout<<"\n";
    }
}

int main(){
    floydWarshall();

    return 0;
}