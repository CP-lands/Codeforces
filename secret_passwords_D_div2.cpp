//--------Anivia_kid---------//
//-------did you test n = 1 ?-------//
//https://codeforces.com/contest/1263/problem/D
#include<bits/stdc++.h>
 
using namespace std;
 
#define fi first
#define se second
#define pb push_back

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

set<int> s[26];
set<int> ss;
map<char, int> mp;

void Anivia_kid(){
	mp['a'] = 0;
	mp['b'] = 1;
	mp['c'] = 2;
	mp['d'] = 3;
	mp['e'] = 4;
	mp['f'] = 5;
	mp['g'] = 6;
	mp['h'] = 7;
	mp['i'] = 8;
	mp['j'] = 9;
	mp['k'] = 10;
	mp['l'] = 11;
	mp['m'] = 12;
	mp['n'] = 13;
	mp['o'] = 14;
	mp['p'] = 15;
	mp['q'] = 16;
	mp['r'] = 17;
	mp['s'] = 18;
	mp['t'] = 19;
	mp['u'] = 20;
	mp['v'] = 21;
	mp['x'] = 22;
	mp['y'] = 23;
	mp['w'] = 24;
	mp['z'] = 25;
	
	int n;
	cin>>n;
	vector<int> g[26];
	for(int i = 0; i < n; i++){
		string t;
		cin>>t;
		int l = t.size();
		ss.insert(mp[t[0]]);
		for(int j = 0; j < l - 1; j++){
			int a = mp[t[j]];
			int b = mp[t[j + 1]];
			if(a != b && s[a].find(b) == s[a].end()){
				s[a].insert(b);
				g[a].pb(b);
				ss.insert(a);
			}
			if(a != b && s[b].find(a) == s[b].end()){
				g[b].pb(a);
				s[b].insert(a);
				ss.insert(b);
			}
		}
	}

	int res = 0;
	vector<bool> visited(26);
	queue<int> q;
	for(int i = 0; i < 26; i++){
		if(ss.find(i) == ss.end()) continue;
		if(!visited[i]) res++;
		q.push(i);
		visited[i] = true;
		while(!q.empty()){
			int current = q.front();
			q.pop();
			for(auto x: g[current]){
				if(!visited[x]){
					visited[x] = true;
					q.push(x);
				}
			}
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
