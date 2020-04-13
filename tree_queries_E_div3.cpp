#include<bits/stdc++.h>
 
//https://codeforces.com/contest/1328/problem/E
using namespace std;

vector<int> g[200001];
int parent[200001];
int tin[200001];
int tout[200001];
int level[200001];
int countt = 0;
int n;

void dfs(int u, int v = -1){
    tin[u] = countt++;
    for(auto x: g[u]){
        if(x == v) continue;
        parent[x] = u;
        level[x] = level[u] + 1;
        dfs(x, u);
    }
    tout[u] = countt++;
}

void Solve(){
    int q;
    cin>>n>>q;
    for(int i = 0; i < n - 1; i++){
        int u, v;
        cin>>u>>v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    parent[1] = 0;
    level[1] = 0;
    dfs(1);
    while(q--){
        int k;
        cin>>k;
        int max_depth = 0;
        int last_node = 0;
        vector<int> v(k);
        for(int i = 0; i < k; i++){
            cin>>v[i];
            if(level[v[i]] >= max_depth){
                max_depth = level[v[i]];
                last_node = v[i];
            }
        }
        bool res = true;
        for(int i = 0; i < k; i++){
            if(v[i] == 1) continue;
            int x = tin[parent[v[i]]];
            int y = tout[parent[v[i]]];
            if(x > tin[last_node] || y < tout[last_node]){
                res = false;
                break;
            }
        }
        if(res) cout<<"YES\n";
        else cout<<"NO\n";
    }
}
 
int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t = 1;
    //cin>>q;
    while(t--){
        Solve();
    }
}