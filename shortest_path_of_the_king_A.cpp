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

int movee[8][2] = {{0, 1}, {1, 1}, {1, 0}, {1, -1}, {0, -1}, {-1, -1}, {-1, 0}, {-1, 1}};
string step[8] = {"U", "RU", "R", "RD", "D", "LD", "L", "LU"};

void Anivia_kid(){
	string s, t;
	cin>>s>>t;
	map<char, int> my_map;
	my_map['a'] = 1; my_map['b'] = 2; my_map['c'] = 3; my_map['d'] = 4;
	my_map['e'] = 5; my_map['f'] = 6; my_map['g'] = 7; my_map['h'] = 8;
	int x_start = my_map[s[0]], y_start = s[1] - '0';
	int x_end = my_map[t[0]], y_end = t[1] - '0';

	vector<vector<bool>> visited(9, vector<bool>(9));
	vector<vector<string>> trace(9, vector<string>(9));
	map<pair<int, int>, pair<int, int>> mm;
	mm[{x_start, y_start}] = {0, 0};
	queue<pair<int, int>> q;
	q.push({x_start, y_start});
	visited[x_start][y_start] = true;
	while(!q.empty()){
		if(visited[x_end][y_end]) break;
		pair<int, int> p = q.front();
		q.pop();
		for(int i = 0; i < 8; i++){
			int x = p.fi + movee[i][0];
			int y = p.se + movee[i][1];
			if(x > 0 && x < 9 && y > 0 && y < 9 && !visited[x][y]){
				visited[x][y] = true;
				q.push({x, y});
				trace[x][y] = step[i];
				mm[{x, y}] = {p.fi, p.se};
			}
		}
	}
	vector<string> res;
	while(mm[{x_end, y_end}].fi != 0){
		pair<int, int> p = mm[{x_end, y_end}];
		res.pb(trace[x_end][y_end]);
		x_end = p.fi;
		y_end = p.se;
	}
	cout<<res.size()<<"\n";
	for(int i = res.size() - 1; i >=0; i--)
		cout<<res[i]<<"\n";

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