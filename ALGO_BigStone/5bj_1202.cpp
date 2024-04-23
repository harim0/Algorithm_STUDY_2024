#include <bits/stdc++.h>

using namespace std;

int n, k;
typedef pair<int,int> p;

vector<p> jewry;
vector<int> bag;

bool compare(const p a, const p b){
    return a.second>b.second;
}

int main()
{
    cin >> n >> k;
    for(int i=0; i<n; i++){
        int w,p;
        cin>>w>>p;
        jewry.push_back({w,p});
    }
    for(int i=0; i<k; i++){
        int maxW;
        cin>>maxW;
        bag.push_back(maxW);
    }
    int* visited = new int[k]{0,};
    sort(jewry.begin(), jewry.end(), compare);

    int sum = 0; // priority...가방 개수? 보석?
    for(int i=0; i<n; i++){
        for(int j=0; j<k; j++){
            if((!visited[j])&&jewry[i].first<=bag[j]){
                visited[j]=1;
                sum+=jewry[i].second;
                break;
            }
        }
    }

    cout<<sum<<"\n";

    return 0;
}