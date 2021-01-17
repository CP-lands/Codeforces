//--------------my brain isn't at home right now------------------
#include<bits/stdc++.h>  
 
using namespace std; 
//https://codeforces.com/contest/519/problem/E
 
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
vector<int> childs(N);
vector<int> tin(N), tout(N);
vector<int> depth(N);
vector<int> g[N];
vector<int> deg[N];
int index = 0;
void dfs(int u, int v = -1){
    deg[depth[u]].pb(u);
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
    childs[u] = 1;
    tin[u] = index++;
    for(auto x: g[u]){
        if(x == v) continue;
        dfs2(x, u);
        childs[u] += childs[x];
    }
    tout[u] = index++;
}
int getRes(int u, int d){
    d = depth[u] - d;
    int low = 0;
    int high = deg[d].size() - 1;
    int exit = 0;
    int res = deg[d][0];
    while(low < high){
        int mid = low + (high - low) / 2;
        if(exit == 2) mid = high;
        if(tin[deg[d][mid]] <= tin[u] && tout[deg[d][mid]] >= tout[u]){
            res = deg[d][mid];
            break;
        }
        if(tout[deg[d][mid]] < tin[u]){
            low = mid;
        }
        if(tin[deg[d][mid]] > tout[u]){
            high = mid;
        }
        if(high - low == 1) exit++;
        if(exit == 3) break;
    }
    return res;
}
void Solve(){
    int n;
    cin>>n;
    for(int i = 1; i < n; i++){
        int u, v;
        cin>>u>>v;
        g[u].pb(v);
        g[v].pb(u);
    }
    dfs(1);
    index = 0;
    dfs2(1);
    build(1, 0, 2 * n - 2);
    int q;
    cin>>q;
    while(q--){
        int u, v;
        cin>>u>>v;
        if(u == v){
            cout<<n<<nl;
            continue;
        }
        int l = ver[u];
        int r = ver[v];
        if(l > r) swap(l, r);
        int anc = lca(1, 0, 2 * n - 2, l, r);
        int dist = depth[u] + depth[v] - 2 * depth[anc];
        int mid = dist / 2;
        if(dist % 2) cout<<0<<nl;
        else if(depth[u] != depth[v]){
            if(depth[u] > depth[v]){
                int a = getRes(u, mid);
                int b = getRes(u, mid - 1);
                cout<<childs[a] - childs[b]<<nl;
            }
            else{
                int a = getRes(v, mid);
                int b = getRes(v, mid - 1);
                cout<<childs[a] - childs[b]<<nl;
            }
        }
        else{
            int a = getRes(u, mid - 1);
            int b = getRes(v, mid - 1);
            int ans = childs[1] - childs[anc];
            cout<<childs[anc] - childs[a] - childs[b] + ans<<nl;
        }
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