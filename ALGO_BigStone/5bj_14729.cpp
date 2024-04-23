#include <bits/stdc++.h>

using namespace std;

int n;
priority_queue<double> pq;
vector<double> vec;

int main(){
    cin>>n;
    for(int i=0; i<n; i++){
        double score;
        cin>>score;
        if(pq.size()==7){
            pq.push(score);
            pq.pop();
        }else{
            pq.push(score);
        }
    }

    while(pq.size()){
        vec.push_back(pq.top());
        pq.pop();
    }
    reverse(vec.begin(), vec.end());
    for(double i: vec) printf("%.3lf\n", i);

    return 0;
}