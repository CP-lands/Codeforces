//--------Anivia_kid---------//
//-------did you test n = 1 ?-------//
#include<bits/stdc++.h>
 
using namespace std;
 
#define fi first
#define se second
#define pb push_back
#define mp make_pair
typedef long long ll; 
const int MOD = 1e9 + 7;
const int MAXN = 1e5 + 100;

int fire[4][2] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
bool visited[2001][2001];

void Anivia_kid(){
	int n, m, k;
	cin>>n>>m>>k;

	for(int i = 1; i <= n; i++)
		for(int j = 1; j <= m; j++)
			visited[i][j] = false;

	int res_x, res_y;
	queue<pair<int, int>> q;

	for(int i = 0; i < k; i++){
		int x, y;
		cin>>x>>y;
		q.push({x, y});
		visited[x][y] = true;
	}

	while(!q.empty()){
		pair<int, int> p = q.front();
		q.pop();
		int current_x = p.fi;
		int current_y = p.se;
		res_x = current_x;
		res_y = current_y;
		for(int i = 0; i < 4; i++){
			int x_next = current_x + fire[i][0];
			int y_next = current_y + fire[i][1];
			if(x_next > 0 && x_next <= n && y_next > 0 && y_next <= m && !visited[x_next][y_next]){
				visited[x_next][y_next] = true;
				q.push({x_next, y_next});
			}
		}
	}
	cout<<res_x<<" "<<res_y<<endl;
 	
	return;
}
 
int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int q = 1;
	//cin>>q;
	while(q--){
		Anivia_kid();
	}
	return 0;
}
