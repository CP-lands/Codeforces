#include<bits/stdc++.h>
 
//https://codeforces.com/contest/1337/problem/C
using namespace std;
 
vector<int> g[200001];
int parent[200001];
int child[200001];
int happy[200001];
int tour[200001];
long long res = 0;
 
void dfs(int u, int v = 0){
    child[u] = 0;
    for(auto x: g[u]){
        if(x == v) continue;
        child[u]++;
        parent[x] += 1 + parent[u];
        dfs(x, u);
        child[u] += child[x];
    }
}
void dfs2(int u, int v = 0){
    if(happy[u] == 0) tour[u] = 1;
    for(auto x: g[u]){
        if(x == v) continue;
        dfs2(x, u);
        tour[u] += tour[x];
    }
    res += (long long)tour[u] * happy[u];
}
void Solve(){
    int n, k;
    cin>>n>>k;
    for(int i = 0; i < n - 1; i++){
        int u, v;
        cin>>u>>v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    memset(happy, 0, 200001);
    parent[1] = 0;
    dfs(1);
    vector<pair<int, int>> v(n + 1);
    for(int i = 1; i <= n; i++){
        v[i] = {child[i] - parent[i], i};
    }
    sort(v.rbegin(), v.rend());
    k = n - k;
    for(int i = 0; i <= n; i++){
        if(v[i].second == 0) continue;
        if(k <= 0) break;
        happy[v[i].second] = 1;
        k--;
    }
    dfs2(1);
    cout<<res<<'\n';
}
int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int tt = 1;
    //cin>>tt;
    while(tt--){
        Solve();
    }
}