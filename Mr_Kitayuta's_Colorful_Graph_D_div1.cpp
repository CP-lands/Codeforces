#include<bits/stdc++.h>  
 
//https://codeforces.com/contest/506/problem/D
using namespace std; 
 
#define pb push_back
#define fi first
#define se second
#define nl '\n'
typedef long long ll;
 
const int N = 1e5 + 5;
 
struct uf{
    int parent[2 * N];
    int size[2 * N];
    void init(){
        for(int i = 0; i < 2 * N; i++){
            size[i] = 1;
            parent[i] = -1;
        }
    }
    int root(int a){
        if(parent[a] == -1) return a;
        return parent[a] = root(parent[a]);
    }
    void uni(int a, int b){
        a = root(a);
        b = root(b);
        if(a == b) return;
        if(size[a] < size[b]) swap(a, b);
        parent[b] = a;
        size[a] += size[b];
    }
    bool same(int a, int b){
        return root(a) == root(b);
    }
};
int deg[N];
vector<int> g[N];
 
void Solve(){
    int n, m;
    cin>>n>>m;
    vector<pair<pair<int, int>, int>> ed(m);
    for(int i = 0; i < m; i++){
        int u, v, c;
        cin>>u>>v>>c;
        g[u].pb(c);
        g[v].pb(c);
        ed[i] = {{u, v}, c};
    }
    uf k;
    k.init();
    for(int i = 0; i <= n; i++){
        sort(g[i].begin(), g[i].end());
        g[i].erase(unique(g[i].begin(), g[i].end()), g[i].end());
        deg[i] = g[i].size();
        if(i > 1) deg[i] += deg[i - 1];
    }
    for(int i = 0; i < m; i++){
        int u = ed[i].fi.fi;
        int v = ed[i].fi.se;
        int c = ed[i].se;
        int a = deg[u - 1] + lower_bound(g[u].begin(), g[u].end(), c) - g[u].begin();
        int b = deg[v - 1] + lower_bound(g[v].begin(), g[v].end(), c) - g[v].begin();
        k.uni(a, b);
    }
    int q;
    cin>>q;
    map<pair<int, int>, int> myMap;
    while(q--){
        int u, v;
        cin>>u>>v;
        if(myMap.count({u, v})){
            cout<<myMap[{u, v}]<<nl;
            continue;
        }
        int res = 0;
        if(g[u].size() > g[v].size()) swap(u, v);
        for(int i = 0; i < g[u].size(); i++){
            if(binary_search(g[v].begin(), g[v].end(), g[u][i])){
                int a = deg[u - 1] + i;
                int b = deg[v - 1] + lower_bound(g[v].begin(), g[v].end(), g[u][i]) - g[v].begin();
                if(k.same(a, b)) res++;
            }
        }
        myMap[{u, v}] = res;
        myMap[{v, u}] = res;
        cout<<res<<nl;
    }
}
int main(){  
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    Solve();
}