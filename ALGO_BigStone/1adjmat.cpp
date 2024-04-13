#include<iostream>

using namespace std;

int visited_sol[10]={0,};
int visited[10]={0,};
int sol[11][11];

void go(int i){
    cout<<i<<endl;
    for(int k=0; k<10; k++){
        if(visited_sol[k]) continue;
        if(sol[i][k]){
            visited_sol[k]=1;
            go(k);
        }
    }
}

void rec_visit(int i, int mine[][10]){
    for(int k=0; k<10; k++){
        if(!visited[k]&&mine[i][k]){
            visited[k]=1;
            cout<<k<<endl;
            rec_visit(k,mine);
        }
    }
}

int main(){
    sol[1][2]=sol[2][1]=1;
    sol[1][3]=sol[3][1]=1;
    sol[4][3]=sol[3][4]=1;

    for(int i=1; i<11; i++){
        for(int j=1; j<11; j++){
            if((!visited_sol[i])&&sol[i][j]){
                visited_sol[i]=1;
                go(i);
            }
        }
    }

    int mine[10][10];
    mine[0][1]=mine[1][0]=1;
    mine[0][2]=mine[2][0]=1;
    mine[3][2]=mine[2][3]=1;

    for(int i=0; i<10; i++){
        // if(!visited[i]){
        //     rec_visit(i, mine);
        // }
        for(int j=0; j<10; j++){
            if(!visited[i]&&mine[i][j]){
                visited[i]=1;
                cout<<i<<endl;
                rec_visit(i, mine);
            }
        }
    }

    return 0;
}