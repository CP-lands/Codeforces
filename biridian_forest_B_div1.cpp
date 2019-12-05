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
 
bool isPrime(ll n)
{
	if(n < 2) return false;
	if(n == 2) return true;
	for(ll i = 2; i * i <= n; i++)
		if(n % i == 0) return false;
	return true;
}
ll power(ll a, ll k)
{
	if (k == 0) return 1;
	if (k == 1) return a;
	ll tmp = power(a, k >> 1);
	tmp = (tmp * tmp) % MOD;
	return k % 2 ? (tmp * a) % MOD : tmp;
}
string int_to_string(int n)
{
	string res = "";
	while(n / 10 > 0)
	{
		res += n % 10 + '0';
		n /= 10;
	}
	res += n % 10 + '0';
	string ans = "";
	for(int i = res.size() - 1; i >= 0; i--)
		ans += res[i];
	return ans;
}
ll string_to_int(string s)
{
	ll res = 0;
	for(int i = 0; i < s.size(); i++)
		res += (s[i] - '0') * power(10, s.size() - 1- i);
	return res;
}
int get_gcd(int a, int b)
{
	if(b == 0) return a;
	return get_gcd(b, a % b);
}

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
