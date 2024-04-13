#include<iostream>

using namespace std;

int visited[10]={0,};
int a[11][11];

void go(int i){
    cout<<i<<endl;
    for(int k=0; k<10; k++){
        if(visited[k]) continue;
        if(a[i][k]){
            visited[k]=1;
            go(k);
        }
    }
}

int main(){
    a[1][2]=a[2][1]=1;
    a[1][3]=a[3][1]=1;
    a[4][3]=a[3][4]=1;

    for(int i=1; i<11; i++){
        for(int j=1; j<11; j++){
            if((!visited[i])&&a[i][j]){
                visited[i]=1;
                go(i);
            }
        }
    }

    return 0;
}