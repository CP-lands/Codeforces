#include<bits/stdc++.h>
 
using namespace std;

const int N = 200001;
map<pair<int, int>, int> mm;
int dp[N];
vector<int> g[N];

void dfs(int u, int v = -1){
    for(auto x: g[u]){
        if(x == v) continue;
        if(mm[{u, x}] != 1) dp[u]++;
        dfs(x, u);
        dp[u] += dp[x];
    }
}
void dfs2(int u, int v = -1){
    for(auto x: g[u]){
        if(x == v) continue;
        if(mm[{x, u}] == 1) dp[x] = dp[u] - 1;
        else dp[x] = dp[u] + 1;
        dfs2(x, u);
    }
}

void Solve(){
    int n;
    cin>>n;
    for(int i = 0; i < n - 1; i++){
        int u, v;
        cin>>u>>v;
        g[u].push_back(v);
        g[v].push_back(u);
        mm[{u, v}] = 1;
    }
    for(int i = 1; i <= n; i++) dp[i] = 0;
    dfs(1);
    dfs2(1);
    int minn = INT_MAX;
    for(int i = 1; i <= n; i++){
        if(minn > dp[i]) minn = dp[i];
    }
    vector<int> res;
    for(int i = 1; i <= n; i++){
        if(dp[i] == minn) res.push_back(i);
    }
    cout<<minn<<'\n';
    for(auto x: res) cout<<x<<" ";
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