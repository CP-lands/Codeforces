//--------Anivia_kid---------//
//-------did you test n = 1 ?-------//
//https://codeforces.com/contest/377/problem/A
#include<bits/stdc++.h>
 
using namespace std;
 
#define fi first
#define se second
#define pb push_back
#define mp make_pair
typedef long long ll; 
const int MOD = 1e9 + 7;
const int MAXN = 1e5 + 100;
 
bool visit[500][500];
int movee[4][2] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};

void Anivia_kid(){
	int n, m, k;
	cin>>n>>m>>k;
	char matrix[n][m];
	int remain = 0;
	int x_start, y_start;
	for(int i = 0; i < n; i++)
		for(int j = 0; j < m; j++){
			cin>>matrix[i][j];
			if(matrix[i][j] == '.'){
				remain++;
				x_start = i;
				y_start = j;
			}
		}
	remain -= k;
	visit[x_start][y_start] = true;
	remain--;
	queue<pair<int, int>> q;
	q.push({x_start, y_start});
	while(!q.empty() && remain > 0){
		pair<int, int> p = q.front();
		q.pop();
		for(int i = 0; i < 4; i++){
			int x = p.fi + movee[i][0];
			int y = p.se + movee[i][1];
			if(x >= 0 && x < n && y >= 0 && y < m && matrix[x][y] == '.' && visit[x][y] != true){
				visit[x][y] = true;
				remain--;
				q.push({x, y});
				if(remain == 0) break;
			}
		}
	}
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			if(matrix[i][j] == '.' && visit[i][j] != true) cout<<"X";
			else cout<<matrix[i][j];
		}
		cout<<endl;
	}

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
