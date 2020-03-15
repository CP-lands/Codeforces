#include<bits/stdc++.h>

//https://codeforces.com/problemset/problem/455/A
using namespace std;

vector<int> v(1e5 + 2);
vector<long long> dp(1e5 + 2);
 
void Solve(){
	int n;
	cin>>n;
	int maxx = 1;
	for(int i = 0; i < n; i++){
		int x;
		cin>>x;
		if(maxx < x) maxx = x;
		v[x]++;
	}
	dp[0] = 0;
	dp[1] = v[1];
	for(int i = 2; i <= maxx; i++){
		long long a = (long long)v[i] * i + dp[i - 2];
		if(a >= dp[i - 1]) dp[i] = a;
		else dp[i] = dp[i - 1];
	}
	long long res;
	if(dp[maxx - 1] >= dp[maxx - 2] + (long long)maxx * v[maxx]) res = dp[maxx - 1];
	else res = dp[maxx - 2] + (long long)maxx * v[maxx];
	cout<<res<<'\n';

	return;
}
int main(){
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int q = 1;
    //cin>>q;
    while(q--){
    	Solve();
    }
}