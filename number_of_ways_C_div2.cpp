//--------Anivia_kid---------//
//https://codeforces.com/contest/466/problem/C
#include<bits/stdc++.h>

using namespace std;
 
#define fi first
#define se second
#define pb push_back
#define eb emplace_back
 
typedef long long ll; 
const int MOD = 1e9 + 7;

void Anivia_kid(){
	int n;
	cin>>n;
	vector<int> v(n);
	ll sum = 0;
	for(int i = 0; i < n; i++){
		cin>>v[i];
		sum += v[i];
	}
	if(sum % 3 != 0){
		cout<<0<<'\n';
		return;
	}
	sum /= 3;
	vector<int> dp(n);
	ll goal = 0;
	for(int i = n - 1; i >= 0; i--){
		goal += v[i];
		if(goal == sum) dp[i] = 1;
		else dp[i] = 0;
	}
	for(int i = n - 2; i >= 0; i--){
		dp[i] += dp[i + 1];
	}
	ll ans = 0;
	ll k = 0;
	for(int i = 0; i < n - 2; i++){
		k += v[i];
		if(k == sum){
			ans += dp[i + 2];
		}
	}
	cout<<ans<<'\n';

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