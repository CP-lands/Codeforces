// She says yes :)
#include<bits/stdc++.h>
 
using namespace std;
//https://codeforces.com/contest/1475/problem/D
 
#define fi first
#define se second
#define pb push_back
#define nl '\n'
#define bug cout<<"bug here!"<<nl
typedef long long ll;
 
void Solve(){
	int n, m;
	cin>>n>>m;
	ll sum = 0;
	vector<pair<int, int>> v(n);
	for(int i = 0; i < n; i++){
		cin>>v[i].se;
		sum += v[i].se;
	}
	for(int i = 0; i < n; i++){
		cin>>v[i].fi;
	}
	if(sum < m){
		cout<<-1<<nl;
		return;
	}
	sort(v.rbegin(), v.rend());
	vector<int> k1, k2;
	for(auto x: v){
		if(x.fi == 1) k1.pb(x.se);
		else k2.pb(x.se);
	}
	int n1 = k1.size();
	int n2 = k2.size();
	vector<ll> dp1(n1), dp2(n2);
	int ans = INT_MAX;
	for(int i = 0; i < n1; i++){
		dp1[i] = k1[i];
		if(i) dp1[i] += dp1[i - 1];
		if(dp1[i] >= m && ans == INT_MAX) ans = i + 1;
	}
	for(int i = 0; i < n2; i++){
		dp2[i] = k2[i];
		if(i) dp2[i] += dp2[i - 1];
	}
	for(int i = 0; i < n2; i++){
		sum = dp2[i];
		if(sum >= m){
			ans = min(ans, (i + 1) * 2);
			break;
		}
		ll need = m - sum - 1;
		int x = upper_bound(dp1.begin(), dp1.end(), need) - dp1.begin() + 1;
		if(x <= n1) ans = min(ans, x + (i + 1) * 2);
	}
	cout<<ans<<nl;
}
int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int T = 1;
	cin>>T;
	while(T--){
		Solve();
	}
}