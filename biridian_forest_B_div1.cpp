//--------Anivia_kid---------//
//-------did you test n = 1 ?-------//
//https://codeforces.com/problemset/problem/329/B
#include<bits/stdc++.h>
 
using namespace std;
 
#define fi first
#define se second
#define pb push_back
#define mp make_pair
typedef long long ll; 
const int MOD = 1e9 + 7;
const int MAXN = 1e5 + 100;

int movee[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

void Anivia_kid(){
	int n, m;
	cin>>n>>m;
	vector<vector<char>> matrix(n, vector<char> (m));
	int path[n][m];
	int x, y;
	int res_x, res_y;
	for(int i = 0; i < n; i++)
		for(int j = 0; j < m; j++){
			cin>>matrix[i][j];
			if(matrix[i][j] == 'E'){
				x = i; 
				y = j;
			}
		}
	map<pair<int, int>, int> my_map;
	vector<vector<bool>> visited(n, vector<bool> (m));
	queue<pair<int, int>> q;
 	q.push({x, y});
 	visited[x][y] = true;
 	path[x][y] = 0;
 	int battles;
 	while(!q.empty()){
 		pair<int, int> p = q.front();
 		q.pop();
 		for(int i = 0; i < 4; i++){
 			int xx = p.fi + movee[i][0];
 			int yy = p.se + movee[i][1];
 			if(xx >= 0 && xx < n && yy >= 0 && yy < m && matrix[xx][yy] != 'T' && !visited[xx][yy]){
 				q.push({xx, yy});
 				visited[xx][yy] = true;
 				if(matrix[xx][yy] - '0' > 0 && matrix[xx][yy] - '0' < 10){
 					my_map[{xx, yy}] = path[p.fi][p.se] + 1;
 				}
 				if(matrix[xx][yy] == 'S') battles = path[p.fi][p.se] + 1;
 				path[xx][yy] = path[p.fi][p.se] + 1;
 			}
 		}
 	}

 	int res = 0;
 	for(auto x: my_map){
 		if(x.se <= battles){
 			res += matrix[x.fi.fi][x.fi.se] - '0';
 		}
 	}
 	cout<<res<<"\n";

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
		Anivia_kid();
	}
}
