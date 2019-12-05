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