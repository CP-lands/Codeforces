//https://codeforces.com/contest/1311/problem/C
#include<bits/stdc++.h>
 
using namespace std;

typedef long long ll;

void Anivia_kid(){
	int n, m;
	string s;
	cin>>n>>m>>s;
	vector<int> v(m);
	for(int i = 0; i < m; i++)
		cin>>v[i];
	map<char, int> mp;
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
	mp['w'] = 22;
	mp['x'] = 23;
	mp['y'] = 24;
	mp['z'] = 25;
	vector<vector<ll>> dp(n, vector<ll>(26));

	for(int i = 0; i < n; i++){
		if(i > 0) dp[i] = dp[i - 1];
		int k = mp[s[i]];
		dp[i][k]++;
	}
	vector<ll> res(26);
	for(int i = 0; i < m; i++){
		for(int j = 0; j < 26; j++){
			res[j] += dp[v[i] - 1][j];
		}
	}
	for(int j = 0; j < 26; j++){
		res[j] += dp[n - 1][j];
	}
	for(auto x: res){
		cout<<x<<" ";
	}
	cout<<'\n';

	return;
}
 
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int q;
	cin>>q;
	while(q--){
		Anivia_kid();
	}
}
