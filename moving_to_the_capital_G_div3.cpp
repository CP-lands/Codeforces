//--------------my brain isn't at home right now------------------
#include<bits/stdc++.h>  
 
using namespace std; 
//https://codeforces.com/contest/1472/problem/G
 
#define pb push_back
#define fi first
#define se second
#define nl '\n'
typedef long long ll;
 
void Solve(){
    int n, m;
    cin>>n>>m;
    vector<int> g[n];
    while(m--){
        int u, v;
        cin>>u>>v;
        u--; v--;
        g[u].pb(v);
    }
    vector<int> que;
    que.pb(0);
    vector<int> dist(n, -1);
    dist[0] = 0;
    for(int i = 0; i < n; i++){
        int current = que[i];
        for(auto x: g[current]){
            if(dist[x] == -1){
                dist[x] = dist[current] + 1;
                que.pb(x);
            }
        }
    }
    vector<int> f(n);
    for(int i = 0; i < n; i++){
        f[i] = dist[i];
        for(auto x: g[i]){
            f[i] = min(f[i],  dist[x]);
        }
    }
    for(int i = n - 1; i >= 0; i--){
        int u = que[i];
        for(auto x: g[u]){
            if(dist[x] > dist[u]){
                f[u] = min(f[u], f[x]);
            }
        }
    }
    for(auto x: f) cout<<x<<" ";
    cout<<nl;
 
}
int main(){  
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T = 1;
    cin>>T;
    while(T--){
        Solve();
    }
}