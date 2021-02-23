//--------------my brain isn't at home right now----------------------
#include<bits/stdc++.h>
 
using namespace std;
//https://codeforces.com/gym/102942/problem/E
 
#define fi first
#define se second
#define pb push_back
#define nl '\n'
#define bug cout<<"bug here!"<<nl
typedef long long ll;
 
const int MOD = 1e9 + 7;
 
int dp[100001][10];
 
void Solve(){
	int n;
	string s;
	cin>>n>>s;
	int pre = 0;
	int current = 0;
	bool isValid = true;
	for(auto x: s){
		if(x == '-') continue;
		current = x - '0';
		if(current < pre) isValid = false;
		pre = current;
	}
	if(!isValid){
		cout<<0<<nl;
		return;
	}
	for(int i = 0; i <= n; i++){
		for(int j = 0; j < 10; j++)
			dp[i][j] = 0;
	}
	if(s[0] == '-'){
		for(int i = 0; i < 10; i++) dp[0][i] = 1;
	}
	else dp[0][s[0] - '0'] = 1;
	for(int i = 1; i < n; i++){
		if(s[i] == '-'){
			for(int j = 1; j < 10; j++){
				for(int k = 1; k <= j; k++){
					dp[i][j] += dp[i - 1][k];
					dp[i][j] = dp[i][j] % MOD;
				}
			}
		}
		else{
			int current = s[i] - '0';
			for(int k = 1; k <= current; k++){
				dp[i][current] += dp[i - 1][k];
				dp[i][current] = dp[i][current] % MOD;
			}
			for(int k = current + 1; k < 10; k++)
				dp[i][k] = 0;
		}
	}
	ll res = 0;
	for(int i = 1; i < 10; i++){
		res += dp[n - 1][i];
		res = res % MOD;
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