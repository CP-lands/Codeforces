//--------------my brain isn't at home right now----------------------
#include<bits/stdc++.h>
 
using namespace std;
//https://codeforces.com/contest/1475/problem/E
 
#define fi first
#define se second
#define pb push_back
#define nl '\n'
#define bug cout<<"bug here!"<<nl
typedef long long ll;
 
const int MOD = 1e9 + 7;
const int N = 1e5 + 1;
 
ll fact[N], save[N];
 
ll power(ll a, ll x){
	if(!x) return 1;
	if(x == 1) return a % MOD;
	ll tmp = power(a, x >> 1);
	tmp = (tmp * tmp) % MOD;
	return x % 2 ? (tmp * a) % MOD : tmp;
}
ll InverseEuler(ll n){
	return power(n, MOD - 2);
}
ll C(ll n, ll r){
	if(!r) return 1;
	if(n < r) return 0;
	if(n == r) return 1;
	ll l, j, k;
	l = fact[n], j = fact[r], k = fact[n - r];
	return (l * ((save[r] * save[n - r]) % MOD)) % MOD;
}
 
void Solve(){
	int n, k;
	cin>>n>>k;
	vector<int> v(n);
	for(int i = 0; i < n; i++)
		cin>>v[i];
	sort(v.rbegin(), v.rend());
	int up = v[k - 1];
	int pre = k - 2, suf = k;
	int need = 1;
	while(pre >= 0 && v[pre] == up){
		pre--;
		need++;
	}
	int times = need;
	while(suf < n && v[suf] == up){
		suf++;
		times++;
	}
	cout<<C(times, need)<<nl;
}
int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	fact[1] = 1;
	save[1] = InverseEuler(1);
	for(int i = 2; i < 1e5 + 1; i++){
		fact[i] = (fact[i - 1] * i) % MOD;
		save[i] = InverseEuler(fact[i]);
	}
	int T = 1;
	cin>>T;
	while(T--){
		Solve();
	}
}