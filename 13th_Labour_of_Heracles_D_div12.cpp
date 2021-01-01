#include<bits/stdc++.h>  
 
//https://codeforces.com/contest/1466/problem/D
using namespace std; 
 
#define pb push_back
#define fi first
#define se second
#define nl '\n'
typedef long long ll;
 
void Solve(){
    int n;
    cin>>n;
    vector<ll> v(n);
    vector<int> g[n];
    ll sum = 0;
    for(int i = 0; i < n; i++){
        cin>>v[i];
        sum += v[i];
    } 
    for(int i = 1; i < n; i++){
        int u, v;
        cin>>u>>v;
        u--; 
        v--;
        g[u].pb(v);
        g[v].pb(u);
    }
    vector<ll> k;
    for(int i = 0; i < n; i++){
        if(g[i].size() > 1){
            int x = g[i].size() - 1;
            while(x--){
                k.pb(v[i]);
            }
        }
    }
    sort(k.rbegin(), k.rend());
    cout<<sum<<" ";
    for(int i = 2; i < n; i++){
        cout<<sum + k[i - 2]<<" ";
        sum += k[i - 2];
    }
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