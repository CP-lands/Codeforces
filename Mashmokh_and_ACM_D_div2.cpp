//--------Anivia_kid---------//
//-------did you test n = 1 ?-------//
//https://codeforces.com/problemset/problem/414/B
#include<bits/stdc++.h>

using namespace std;
 
#define fi first
#define se second
#define pb push_back
#define eb emplace_back
 
typedef long long ll; 
const int MOD = 1e9 + 7;

int dp[2001][2001];

vector<int> diviors(int n){
	vector<int> res;
	for(int i = 1; i * i <= n; i++){
		if(n % i == 0 && i * i != n){
			res.eb(i);
			res.eb(n / i);
		}
		if(i * i == n) res.eb(i);
	}
	return res;
}

void Anivia_kid(){
	int n, k;
	cin>>n>>k;
	vector<vector<int>> div;
	vector<int> v1;
	div.eb(v1);
	for(int i = 1; i <= n; i++){
		vector<int> v = diviors(i);
		div.eb(v);
	}
	for(int i = 1; i <= n; i++){
		dp[1][i] = 1;
	}
	for(int i = 2; i <= k; i++){
		for(int j = 1; j <= n; j++){
			for(auto x: div[j]){
				dp[i][j] += dp[i - 1][x];
				if(dp[i][j] >= MOD) dp[i][j] -= MOD;
			}
		}
	}
	ll res = 0;
	for(int i = 1; i <= n; i++){
		res += dp[k][i];
		if(res >= MOD) res -= MOD;
	}
	cout<<res<<'\n';

	return;
}
 
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
    //ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int q = 1;
	//cin>>q;
	while(q--){
		Anivia_kid();
	}
}