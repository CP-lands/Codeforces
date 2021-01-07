//--------------my brain isn't at home right now------------------
#include<bits/stdc++.h>  
 
using namespace std; 
//https://codeforces.com/contest/1472/problem/E
 
#define pb push_back
#define fi first
#define se second
#define nl '\n'
typedef long long ll;
 
void Solve(){
	int n;
	cin>>n;
	vector<pair<pair<int, int>, int>> v(n);
	map<pair<int, int>, int> mm;
	for(int i = 0; i < n; i++){
		int a, b;
		cin>>a>>b;
		if(a > b) swap(a, b);
		v[i] = {{a, b}, i};
		mm[{a, b}] = i + 1;
	}
	sort(v.begin(), v.end());
	vector<int> bs(n);
	for(int i = 0; i < n; i++){
		bs[i] = v[i].fi.fi;
	}
	vector<pair<int, int>> dp(n);
	dp[0] = {v[0].fi.fi, v[0].fi.se};
	vector<int> res(n);
	for(int i = 0; i < n; i++){
		int p = lower_bound(bs.begin(), bs.end(), v[i].fi.fi) - bs.begin();
		p--;
		if(p < 0) res[v[i].se] = -1;
		else{
			if(v[i].fi.se > dp[p].se) res[v[i].se] = mm[dp[p]];
			else{
				res[v[i].se] = -1;
			}
		}
		if(i > 0) dp[i] = dp[i - 1];
		if(v[i].fi.se < dp[i].se) dp[i] = {v[i].fi.fi, v[i].fi.se};
	}
	for(auto x: res) cout<<x<<" ";
	cout<<nl;
 
}
int main(){  
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T = 1;
    cin>>T;
    while(T--){
        Solve();
    }
}