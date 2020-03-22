#include<bits/stdc++.h>

//https://codeforces.com/contest/522/problem/B 
using namespace std;
 
void Solve(){
    int n;
    cin>>n;
    int v[200001][2];
    int maxx = 0;
    for(int i = 1; i <= n; i++){
        cin>>v[i][0]>>v[i][1];
        maxx += v[i][0];
    }
    vector<int> dp(n + 1);
    int tmp = 0;
    for(int i = 1; i <= n; i++){
        dp[i] = tmp;
        tmp = max(tmp, v[i][1]);
    }
    tmp = v[n][1];
    for(int i = n - 1; i > 0; i--){
        dp[i] = max(tmp, dp[i]);
        tmp = max(tmp, v[i][1]);
    }
    for(int i = 1; i <= n; i++){
        long long res = (long long)dp[i] * (maxx - v[i][0]);
        cout<<res<<" ";
    }
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