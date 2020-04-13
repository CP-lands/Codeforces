#include<bits/stdc++.h>

//https://codeforces.com/contest/274/problem/B
using namespace std;

vector<int> g[100001];
long long v[100001];
long long res[100001];
long long nega[100001];
long long poss[100001];

long long abss(long long n){
    if(n >= 0) return n;
    else return -n;
}
long long mx(long long a, long long b){
    if(a >= b) return a;
    else return b;
}
long long mi(long long a, long long b){
    if(a < b) return a;
    else return b;
}
void dfs(int u, int p = 0){
    for(auto x: g[u]){
        if(x == p) continue;
        dfs(x, u);
        nega[u] = mi(nega[u], nega[x]);
        poss[u] = mx(poss[u], poss[x]);
    }
    if(nega[u] < 0){
        v[u] += nega[u];
        res[u] += -nega[u];
    }
    if(poss[u] > 0){
        v[u] += poss[u];
        res[u] += poss[u];
    }
    if(v[u] >= 0){
        nega[u] += -v[u];
    }
    else{
        poss[u] += -v[u];
    }
    res[u] += abss(v[u]);

    //cout<<u<<" "<<nega[u]<<" "<<poss[u]<<" "<<res<<endl;
}
void Solve(int a){
    int n;
    cin>>n;
    for(int i = 0; i < n - 1; i++){
        int u, v;
        cin>>u>>v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    for(int i = 1; i <= n; i++)
        cin>>v[i];
    memset(nega, 0, n + 1);
    memset(res, 0, n + 1);
    memset(poss, 0, n + 1);
    dfs(1);
    cout<<res[1]<<'\n';

}
int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int q = 1;
    //cin>>q;
    for(int a = 1; a <= q; a++){
        Solve(a);
    }
}