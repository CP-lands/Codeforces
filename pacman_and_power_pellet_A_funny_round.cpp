//----------------just-trying-to-keep-this-happiness-----------------------
#include<bits/stdc++.h>
 
using namespace std;
//https://codeforces.com/gym/321516/problem/A
 
#define fi first
#define se second
#define pb push_back
#define nl '\n'
#define bug cout<<"bug here!"<<nl
typedef long long ll;
 
int movee[4][2] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
 
void Alice(){
	int n, m;
	cin>>n>>m;
	int x, y, a, b;
	vector<vector<char>> v(n, vector<char> (m));
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			cin>>v[i][j];
			if(v[i][j] == 'O'){
				a = i;
				b = j;
			}
			if(v[i][j] == 'P'){
				x = i;
				y = j;
			}
		}
	}
	 vector<vector<bool>> vst(n, vector<bool> (m));
	 vst[x][y] = true;
	 vector<vector<int>> times(n, vector<int> (m));
	 queue<pair<int, int>> q;
	 q.push({x, y});
	 while(!q.empty()){
	 	pair<int, int> p = q.front();
	 	q.pop();
	 	for(int i = 0; i < 4; i++){
	 		x = p.fi + movee[i][0];
	 		y = p.se + movee[i][1];
	 		if(x < 0) x = n - 1;
	 		if(x == n) x = 0;
	 		if(y < 0) y = m - 1;
	 		if(y == m) y = 0;
	 		if(!vst[x][y] && v[x][y] != '#'){
	 			vst[x][y] = true;
	 			q.push({x, y});
	 			times[x][y] = times[p.fi][p.se] + 1;
	 		}
	 	}
	 }
	 cout<<(vst[a][b] ? times[a][b] : -1)<<nl;
 
}
int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int T = 1;
	//cin>>T;
	while(T--){
		Alice();
	}
}