#include<bits/stdc++.h>
 
using namespace std;
//https://codeforces.com/contest/1519/problem/C
 
#define nl '\n'
#define pb push_back
#define fi first
#define se second
#define bug cout<<"bug here!\n"
typedef long long ll;
 
const int N = 2e5 + 1;
 
vector<vector<int>> divv(N);
 
void Solve(){
	int n;
	cin>>n;
	vector<pair<int, int>> v(n);
	for(int i = 0; i < n; i++)
		cin>>v[i].fi;
	for(int i = 0; i < n; i++)
		cin>>v[i].se;
	sort(v.rbegin(), v.rend());
	vector<vector<int>> dp(n);
	for(int i = 0; i < n; i++){
		dp[v[i].fi - 1].pb(v[i].se);
	}
	for(int i = 0; i < n; i++){
		sort(dp[i].rbegin(), dp[i].rend());
	}
	vector<vector<ll>> suf(n);
	vector<ll> res(n + 1);
	for(int i = 0; i < n; i++){
		for(int j = 0; j < dp[i].size(); j++){
			suf[i].pb(dp[i][j]);
			if(j > 0) suf[i][j] += suf[i][j - 1];
		}
		vector<bool> vst(dp[i].size() + 1);
		for(int j = suf[i].size() - 1; j >= 0; j--){
			int k = j + 1;
			if(vst[k]) continue;
			for(auto x: divv[k]){
				if(vst[x]) continue;
				res[x] += suf[i][j];
				vst[x] = true;
			}
		}
	}
	for(int i = 1; i <= n; i++)
		cout<<res[i]<<" ";
	cout<<nl;
 
}
 
int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	for(int i = 1; i < N; i++){
		for(int j = 1; j * j <= i; j++){
			if(i % j == 0){
				divv[i].pb(j);
				if(i / j != j) divv[i].pb(i / j);
			}
		}
	}
	int T = 1;
	cin>>T;
	while(T--){
		Solve();
	}
 
}