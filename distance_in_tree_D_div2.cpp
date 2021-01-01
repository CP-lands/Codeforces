#include<bits/stdc++.h>  
 
//https://codeforces.com/contest/161/problem/D
using namespace std; 
 
#define pb push_back
#define fi first
#define se second
#define nl '\n'
typedef long long ll;
 
const int N = 5e4 + 5;
const int M = 505;
 
int n, k;
ll dp[N][M];
vector<int> g[N];
ll res = 0;
 
void dfs(int u, int v = -1){
    for(int i = 0; i < M; i++)
        dp[u][i] = 0;
    dp[u][0] = 1;
    for(auto x: g[u]){
        if(x == v) continue;
        dfs(x, u);
        for(int i = 0; i < k; i++){
            dp[u][i + 1] += dp[x][i];
        }
    }
    res += dp[u][k];
    ll tmp = 0;
    for(auto x: g[u]){
        if(x == v) continue;
        for(int i = 0; i < k - 1; i++){
            tmp += dp[x][i] * (dp[u][k - i - 1] - dp[x][k - i - 2]);
        }
    }
    res += tmp / 2;
 
}
void Solve(){
    cin>>n>>k;
    for(int i = 1; i < n; i++){
        int u, v;
        cin>>u>>v;
        g[u].pb(v);
        g[v].pb(u);
    }
    dfs(1);
    cout<<res<<nl;
 
}
int main(){  
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T = 1;
    //cin>>T;
    while(T--){
        Solve();
    }
}