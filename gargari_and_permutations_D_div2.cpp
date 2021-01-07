//--------my brain isn't at home right now------------------
#include<bits/stdc++.h>  

//https://codeforces.com/contest/463/problem/D
 
using namespace std; 
 
#define pb push_back
#define fi first
#define se second
#define nl '\n'
typedef long long ll;
 
const int N = 1e3 + 1;
vector<int> g[N];
vector<int> l(N);
vector<bool> vst(N);
int res = 1;
 
void dfs(int u){
    vst[u] = true;
    for(auto x: g[u]){
        if(!vst[x]){
            dfs(x);
        }
        l[u] = max(l[u], l[x] + 1);
    }
    l[u] = max(l[u], 1);
    res = max(res, l[u]);
}
void Solve(){
    int n, k;
    cin>>n>>k;
    vector<vector<int>> v(k, vector<int> (n + 1));
    vector<vector<int>> pos(k, vector<int> (n + 1));
    vector<bool> take(n + 1);
    for(int i = 0; i < k; i++){
        for(int j = 0; j < n; j++){
            cin>>v[i][j];
            pos[i][v[i][j]] = j + 1;
        }
    }
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            if(j == i) continue;
            bool good = true;
            for(int t = 0; t < k; t++){
                if(pos[t][i] > pos[t][j]) good = false;
            }
            if(good){
                g[i].pb(j);
                take[j] = true;
            }
        }
    }
    for(int i = 1; i <= n; i++){
        if(take[i] || vst[i]) continue;
        dfs(i);
    }
    cout<<res<<nl;
 
}
int main(){  
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    Solve();
}