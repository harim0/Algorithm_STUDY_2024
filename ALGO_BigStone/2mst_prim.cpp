#include<bits/stdc++.h>

using namespace std;

typedef pair<int, int> p;
const int n = 7;
vector<p> edge[n];
int visited[n]={0,};

struct compare {
    bool operator()(p a, p b) {
        return a.first > b.first; // weight
    }
};

int sum = 0;
void Prim() {
    priority_queue<p, vector<p>, compare> pq; // greater<p>
    pq.push({0,0});

    cout<<"Used Edge\n";

    while(!pq.empty()){
        int vertex = pq.top().second;
        int weight = pq.top().first;
        pq.pop();

        if(visited[vertex]) continue;
        visited[vertex] = 1;
        sum+=weight;

        cout<<"Connected Vertices : ";
        for (int i = 0; i < n; i++) {
			if (visited[i]) cout << i << ' ';
		}
        cout<<"\tWeight : "<<weight<<"\n";

        for(int i=0; i<edge[vertex].size(); i++){
            int nxtVertex = edge[vertex][i].second;
            int nxtWeight = edge[vertex][i].first;
            if(visited[nxtVertex]) continue;
            pq.push({nxtWeight,nxtVertex});
        }
    }
    cout<<"total sum: "<<sum<<endl;
}

void init() {
    edge[0].push_back({ 16,1 });
	edge[1].push_back({ 16,0 });
	edge[0].push_back({ 21,2 });
	edge[2].push_back({ 21,0 });
	edge[0].push_back({ 19,4 });
	edge[4].push_back({ 19,0 });
	edge[1].push_back({ 11,2 });
	edge[2].push_back({ 11,1 });
	edge[1].push_back({ 5,3 });
	edge[3].push_back({ 5,1 });
	edge[1].push_back({ 6,5 });
	edge[5].push_back({ 6,1 });
	edge[2].push_back({ 33,4 });
	edge[4].push_back({ 33,2 });
	edge[2].push_back({ 14,5 });
	edge[5].push_back({ 14,2 });
	edge[3].push_back({ 10,5 });
	edge[5].push_back({ 10,3 });
	edge[4].push_back({ 18,5 });
	edge[5].push_back({ 18,4 });
}

int main(){
    init();
    printf("[MST :: PRIM]\n");
    Prim();

    return 0;
}
