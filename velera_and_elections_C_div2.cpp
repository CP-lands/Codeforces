#include<bits/stdc++.h>

//https://codeforces.com/contest/369/problem/C
using namespace std;
 
vector<int> g[100001];
map<pair<int, int>, int> mm;
int dp[100001];
 
void dfs(int u, int v = -1){
    for(auto x: g[u]){
        if(x == v) continue;
        if(mm[{u, x}] == 2) dp[x] = 1;
        dfs(x, u);
        if(dp[x] == 1 || dp[x] == 2) dp[u] = 2;
    }
}
 
void Solve(){
    int n;
    cin>>n;
    memset(dp, 0, n + 1);
    for(int i = 0; i < n - 1; i++){
        int u, v, x;
        cin>>u>>v>>x;
        g[u].push_back(v);
        g[v].push_back(u);
        mm[{u, v}] = mm[{v, u}] = x;
    }
    dfs(1);
    int count = 0;
    vector<int> res;
    for(int i = 1; i <= n; i++){
        if(dp[i] == 1){
            count++;
            res.push_back(i);
        }
    }
    cout<<count<<'\n';
    for(auto x: res) cout<<x<<" ";
}
int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int q = 1;
    //cin>>q;
    while(q--){
    	Solve();
    }
}