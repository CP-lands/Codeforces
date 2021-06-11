#include<bits/stdc++.h>
 
using namespace std;
//https://codeforces.com/contest/1520/problem/E
 
#define nl '\n'
#define pb push_back
#define fi first
#define se second
#define bug cout<<"bug here!\n"
typedef long long ll;
 
 
void Solve(){
	int n;
	string s;
	cin>>n>>s;
	if(n == 1){
		cout<<0<<nl;
		return;
	}
	vector<ll> suf(n), pre(n);
	int cnt = 0;
	for(int i = 0; i < n; i++){
		if(s[i] == '.') pre[i] = cnt;
		else cnt++;
		if(i > 0) pre[i] += pre[i - 1];
 
	}
	cnt = 0;
	for(int i = n - 1; i >= 0; i--){
		if(s[i] == '.') suf[i] = cnt;
		else cnt++;
		if(i < n - 1) suf[i] += suf[i + 1];
	}
	ll res = 1e18;
	for(int i = 0; i < n - 1; i++){
		res = min(res, pre[i] + suf[i + 1]);
	}
	cout<<res<<nl;
 
}
 
int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int T = 1;
	cin>>T;
	while(T--){
		Solve();
	}
 
}