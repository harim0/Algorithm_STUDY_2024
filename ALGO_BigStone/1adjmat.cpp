#include<iostream>

using namespace std;

int visited[10]={0,};

void rec_visit(int i, int a[][10]){
    for(int k=0; k<10; k++){
        if(!visited[k]&&a[i][k]){
            visited[k]=1;
            cout<<k<<endl;
            rec_visit(k,a);
        }
    }
}

int main(){
    int a[10][10];
    a[0][1]=a[1][0]=1;
    a[0][2]=a[2][0]=1;
    a[3][2]=a[2][3]=1;

    for(int i=0; i<10; i++){
        // if(!visited[i]){
        //     rec_visit(i, a);
        // }
        for(int j=0; j<10; j++){
            if(!visited[i]&&a[i][j]){
                visited[i]=1;
                cout<<i<<endl;
                rec_visit(i, a);
            }
        }
    }

    return 0;
}