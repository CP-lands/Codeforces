#include<bits/stdc++.h>
 
//https://codeforces.com/contest/1118/problem/F1
using namespace std;
 
int color[300000];
int r[300000];
int b[300000];
vector<int> g[300000];
int res = 0, red = 0, blue = 0;
 
void dfs(int u, int v = -1){
    if(color[u] == 1) r[u] = 1;
    if(color[u] == 2) b[u] = 1;
    for(auto x: g[u]){
        if(x == v) continue;
        dfs(x, u);
        int k1 = red - r[x];
        int k2 = blue - b[x];
        bool good = true;
        if(k1 > 0 && k2 > 0) good = false;
        if(r[x] > 0 && b[x] > 0) good = false;
        if(good) res++;
        r[u] += r[x];
        b[u] += b[x];
    }
}
 
void Solve(){
    int n;
    cin>>n;
    for(int i = 0; i < n; i++){
        cin>>color[i];
        if(color[i] == 1) red++;
        if(color[i] == 2) blue++;
    }
    memset(r, 0, n);
    memset(b, 0, n);
    n--;
    while(n--){
        int u, v;
        cin>>u>>v;
        g[u - 1].push_back(v - 1);
        g[v - 1].push_back(u - 1);
    }
    dfs(0);
    cout<<res<<'\n';
    
}
int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int q = 1;
    //cin>>q;
    while(q--){
    	Solve();
    }
}