//--------------my brain isn't at home right now------------------
#include<bits/stdc++.h>  
 
using namespace std; 
//https://codeforces.com/contest/191/problem/C
 
#define pb push_back
#define fi first
#define se second
#define nl '\n'
#define bug cout<<"bug here\n"
typedef long long ll;
 
const int N = 1e5 + 1;
 
int a[2 * N];
int ver[N];
int tree[8 * N];
vector<int> depth(N);
vector<int> g[N];
vector<int> anc(N);
vector<int> des(N);
int index = 0;
map<pair<int, int>, int> myMap;
vector<pair<int, int>> edge(N);
void dfs(int u, int v = -1){
    a[index] = u;
    ver[u] = index++;
    for(auto x: g[u]){
        if(x == v) continue;
        depth[x] = depth[u] + 1;
        dfs(x, u);
        a[index++] = u;
    }
}
void build(int u, int low, int high){
    if(low == high){
        tree[u] = a[low];
        return;
    }
    int mid = low + (high - low) / 2;
    build(2 * u, low, mid);
    build(2 * u + 1, mid + 1, high);
    if(depth[tree[2 * u]] < depth[tree[2 * u + 1]]) tree[u] = tree[2 * u];
    else tree[u] = tree[2 * u + 1];
}
int lca(int u, int low, int high, int l, int r){
    if(l > high || r < low) return INT_MAX;
    if(low >= l && high <= r) return tree[u];
    int mid = low + (high - low) / 2;
    int left = lca(2 * u, low, mid, l, r);
    int right = lca(2 * u + 1, mid + 1, high, l, r);
    if(left == INT_MAX) return right;
    if(right == INT_MAX) return left;
    if(depth[left] < depth[right]) return left;
    else return right;
} 
void dfs2(int u, int v = -1){
    for(auto x: g[u]){
        if(x == v) continue;
        dfs2(x, u);
        anc[u] += anc[x];
        int minn = min(u, x);
        int maxx = max(u, x);
        myMap[{minn, maxx}] = anc[x];
    }
    anc[u] -= des[u];
}
void Solve(){
    int n;
    cin>>n;
    for(int i = 1; i < n; i++){
        int u, v;
        cin>>u>>v;
        g[u].pb(v);
        g[v].pb(u);
        if(u > v) swap(u, v);
        edge[i] = {u, v};
    }
    dfs(1);
    build(1, 0, 2 * n - 2);
    int k;
    cin>>k;
    while(k--){
        int u, v;
        cin>>u>>v;
        int l = ver[u];
        int r = ver[v];
        if(l > r) swap(l, r);
        int m = lca(1, 0, 2 * n - 2, l, r);
        des[m] += 2;
        anc[u]++;
        anc[v]++;
 
    }
    dfs2(1);
    for(int i = 1; i < n; i++){
        cout<<myMap[edge[i]]<<" ";
    }
 
}
int main(){  
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T = 1;
    //cin>>T;
    while(T--){
        Solve();
    }
}