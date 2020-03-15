//https://codeforces.com/problemset/problem/20/C
#include<bits/stdc++.h>
 
using namespace std;

set<pair<int, int>> setd;
vector<long long> dist(100005, 1e15);
vector<long long> disttt(100005, 1e15);
set<pair<long long, int>> setdd;
vector<pair<int, int>> g[100005];

void addEdge(int u, int v, int d){
	g[u].push_back({v, d});
	g[v].push_back({u, d});
}

void dijkstra(int source, int end){
	dist[source] = 0;
	setd.insert({0, source});
	while(!setd.empty()){
		pair<long long, int> p = *setd.begin();
		setd.erase(setd.begin());
		int current = p.second;
		for(auto x: g[current]){
			if(dist[x.first] > dist[current] + x.second){
				if(setd.find({dist[x.first], x.first}) != setd.end())
					setd.erase({dist[x.first], x.first});
				dist[x.first] = dist[current] + x.second;
				setd.insert({dist[x.first], x.first});
			}
		}
	}
	disttt[end] = 0;
	setdd.insert({0, end});
	while(!setdd.empty()){
		pair<long long, int> p = *setdd.begin();
		setdd.erase(setdd.begin());
		int current = p.second;
		for(auto x: g[current]){
			if(disttt[x.first] > disttt[current] + x.second){
				if(setdd.find({disttt[x.first], x.first}) != setdd.end())
					setdd.erase({disttt[x.first], x.first});
				disttt[x.first] = disttt[current] + x.second;
				setdd.insert({disttt[x.first], x.first});
			}
		}
	}
}

void Solve(){
	int n, m;
	cin>>n>>m;
	while(m--){
		int u, v, d;
		cin>>u>>v>>d;
		addEdge(u, v, d);
	}
	dijkstra(1, n);
	if(dist[n] == 1e15){
		cout<<-1<<'\n';
		return;
	}
	vector<int> res;
	res.push_back(1);
	vector<bool> visited(n + 1);
	queue<int> q;
	q.push(1);
	visited[1] = true;
	while(!q.empty()){
		int current = q.front();
		q.pop();
		bool good = false;
		for(auto x: g[current]){
			int i = x.first;
			if(!visited[i] && dist[current] + x.second + disttt[i] == dist[n]){
				q.push(i);
				visited[i] = true;
				res.push_back(i);
				if(i == n){
					good = true;
					break;
				}
			}
		}
		if(good) break;
	}

	
	for(auto x: res)
		cout<<x<<" ";

	return;
}
 
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int q = 1;
	//cin>>q;
	while(q--){
		Solve();
	}
}
