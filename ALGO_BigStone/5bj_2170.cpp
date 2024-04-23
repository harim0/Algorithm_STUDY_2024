#include<bits/stdc++.h>
// umm... tie... stdin...
using namespace std;

typedef pair<int, int> p;
int n;
p arr[1000004];
int main(){
    cin>>n;
    for(int i=0; i<n; i++){
        cin>>arr[i].first>>arr[i].second;
    }
    sort(arr, arr+n);

    int dist = 0;
    int prevFrom = arr[0].first;
    int prevTo = arr[0].second;
    for(int i=1; i<n; i++){
        // cout<<">> arr: "<<arr[i].first<<" -to- "<<arr[i].second<<endl;
        if(prevTo<arr[i].first){
            dist+=(prevTo-prevFrom);
            // cout<<"dist2: "<<dist<<", prev: "<<prevFrom<<" -to- "<<prevTo<<endl;
            prevFrom = arr[i].first;
            prevTo = arr[i].second;
        }else if(arr[i].first<=prevTo&&arr[i].second>=prevTo){
            // cout<<"dist3: "<<dist<<", prev: "<<prevFrom<<" -to- "<<prevTo<<endl;
            prevTo = arr[i].second;
        }
    }
    dist+=(prevTo-prevFrom);
    cout<<dist<<"\n";

    return 0;
}