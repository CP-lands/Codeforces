//--------Anivia_kid---------//
//-------did you test n = 1 ?-------//
//https://codeforces.com/contest/769/problem/C
#include<bits/stdc++.h>
 
using namespace std;
 
#define fi first
#define se second
#define pb push_back
#define mp make_pair
typedef long long ll; 
const int MOD = 1e9 + 7;
const int MAXN = 1e5 + 100;
 
int shortest[1001][1001];
int movee[4][2] = {{1, 0}, {0, -1}, {0, 1}, {-1, 0}};
 
void Anivia_kid(){
	int n, m, k;
	cin>>n>>m>>k;
	if(k % 2 != 0){
		cout<<"IMPOSSIBLE"<<endl;
		return;
	}
	char matrix[n][m];
	int x_st, y_st;
	vector<vector<bool>> visited(n, vector<bool>(m));
	for(int i = 0; i < n; i++)
		for(int j = 0; j < m; j++){
			cin>>matrix[i][j];
			if(matrix[i][j] == 'X'){
				x_st = i;
				y_st = j;
			}
		}
	queue<pair<int, int>> q;
	q.push({x_st, y_st});
	visited[x_st][y_st] = true;
	shortest[x_st][y_st] = 0;
	while(!q.empty()){
		pair<int, int> p = q.front();
		q.pop();
		for(int i = 0; i < 4; i++){
			int x = p.fi + movee[i][0];
			int y = p.se + movee[i][1];
			if(x >= 0 && x < n && y >= 0 && y < m && !visited[x][y] && matrix[x][y] == '.'){
				visited[x][y] = true;
				q.push({x, y});
				shortest[x][y] = shortest[p.fi][p.se] + 1;
			}
		}
	}
	//for(auto x: my_map)
		//cout<<x.fi.fi<<" "<<x.fi.se<<" "<<x.se<<endl;
	//-----------find-path-----------
	int count = 1;
	while(count <= k){
		if(x_st + 1 < n && count + shortest[x_st + 1][y_st] <= k && (matrix[x_st + 1][y_st] == '.' || matrix[x_st + 1][y_st] == 'X')){
			cout<<"D";
			count++;
			x_st++;
		}
		else if(y_st - 1 >= 0 && count + shortest[x_st][y_st - 1] <= k && (matrix[x_st][y_st - 1] == '.' || matrix[x_st][y_st - 1] == 'X')){
			cout<<"L";
			count++;
			y_st--;
		}
		else if(y_st + 1 < m && count + shortest[x_st][y_st + 1] <= k && (matrix[x_st][y_st + 1] == '.' || matrix[x_st][y_st + 1] == 'X')){
			cout<<"R";
			count++;
			y_st++;
		}
		else if(x_st - 1 >= 0 && count + shortest[x_st - 1][y_st] <= k && (matrix[x_st - 1][y_st] == '.' || matrix[x_st - 1][y_st] == 'X')){
			cout<<"U";
			count++;
			x_st--;
		}
		else break;
	}
	if(count == 1) cout<<"IMPOSSIBLE"<<endl;
 
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
	return 0;
}
