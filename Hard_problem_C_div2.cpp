#include<bits/stdc++.h>

//https://codeforces.com/problemset/problem/706/C 
using namespace std;

long long minn(long long a, long long b){
    if(a > b) return b;
    else return a;
}

void Solve(){
    int n;
    cin>>n;
    vector<int> c(n);
    for(int i = 0; i < n; i++)
        cin>>c[i];
    vector<string> v(n), r(n);
    for(int i = 0; i < n; i++){
        cin>>v[i];
        r[i] = v[i];
        reverse(r[i].begin(), r[i].end());
    }
    vector<vector<long long>> dp(n, vector<long long> (2, 1e18));
    dp[0][1] = c[0];
    dp[0][0] = 0;
    for(int i = 1; i < n; i++){
        if(v[i] >= v[i - 1]){
            dp[i][0] = dp[i - 1][0];
        }
        if(v[i] >= r[i - 1]){
            dp[i][0] = minn(dp[i - 1][1], dp[i][0]);
        }
        if(r[i] >= v[i - 1]){
            dp[i][1] = dp[i - 1][0] + c[i];
        }
        if(r[i] >= r[i - 1]){
            dp[i][1] = minn(dp[i][1], dp[i - 1][1] + c[i]);
        }
    }
    long long res = minn(dp[n - 1][0], dp[n - 1][1]);
    if(res == 1e18) cout<<-1<<'\n';
    else cout<<res<<'\n';
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