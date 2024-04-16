#include<bits/stdc++.h>

using namespace std;

char matrix[101][101]={0,};

int N;

string QuadTreeZip(int y, int x, int size){
    if(size==1) return string(1,matrix[y][x]);
    char check = matrix[y][x];
    string ss="";
    for(int i=y; i<y+size; i++){
        for(int j=x; j<x+size; j++){
            if(matrix[i][j]!=check){
                ss.append("(");
                ss.append(QuadTreeZip(y,x,size/2)); // lu
                ss.append(QuadTreeZip(y,x+size/2,size/2)); // ru
                ss.append(QuadTreeZip(y+size/2,x,size/2)); // ld
                ss.append(QuadTreeZip(y+size/2,x+size/2,size/2)); // rd
                ss.append(")");
                return ss;
            }
        }
    }
    return string(1,matrix[y][x]);
}

// 재귀로 주어진 범위 내 값이 다 동일하면 압축. 아니면 재귀로 Quad
void display(){
    cout<<"---------------\n";
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            cout<<matrix[i][j]<<" ";
        }
        cout<<"\n";
    }
    cout<<"---------------\n";
}

int main(){
    cin>>N;
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            scanf("%1s", &matrix[i][j]);
        }
    }
    cout<<QuadTreeZip(0,0,N)<<endl;

    return 0;
}