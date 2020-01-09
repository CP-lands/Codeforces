//--------Anivia_kid---------//
//https://codeforces.com/problemset/problem/431/C
#include<bits/stdc++.h>

using namespace std;
 
#define fi first
#define se second
#define pb push_back
#define eb emplace_back
 
typedef long long ll; 
const int MOD = 1e9 + 7;

ll dp[100][2];

void Anivia_kid(){
	int n, k, d;
	cin>>n>>k>>d;
	dp[0][0] = 1;
	dp[0][1] = 0;
	for(int i = 1; i <= n; i++){
		dp[i][0] = 0;
		dp[i][1] = 0;
		for(int j = 1; j <= k; j++){
			if(i - j < 0) break;
			if(j < d){
				dp[i][0] += dp[i - j][0];
				dp[i][1] += dp[i - j][1];
				if(dp[i][0] >= MOD) dp[i][0] -= MOD;
				if(dp[i][1] >= MOD) dp[i][1] -= MOD;
			}
			else{
				dp[i][1] += dp[i - j][0];
				if(dp[i][1] >= MOD) dp[i][1] -= MOD;
				dp[i][1] += dp[i - j][1];
				if(dp[i][1] >= MOD) dp[i][1] -= MOD;
			}
		}
	}
	cout<<dp[n][1]<<'\n';

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