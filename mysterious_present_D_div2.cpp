//--------my brain isn't at home right now------------------
#include<bits/stdc++.h>  

//https://codeforces.com/contest/4/problem/D
 
using namespace std; 
 
#define pb push_back
#define fi first
#define se second
#define nl '\n'
typedef long long ll;
 
void Solve(){
    int n, w, h;
    cin>>n>>w>>h;
    vector<pair<pair<int, int>, int>> v(1);
    vector<int> dp(n + 1);
    vector<int> trace(n + 1);
    trace[0] = -1;
    v[0] = {{-1, -1}, -1};
    for(int i = 1; i <= n; i++){
        int a, b;
        cin>>a>>b;
        if(a > w && b > h) v.pb({{a, b}, i});
    }
    sort(v.begin(), v.end());
    v[0] = {{w, h}, 0};
    n = v.size() - 1;
 
    for(int i = 1; i <= n; i++){
        trace[i] = -1;
        for(int j = 0; j < i; j++){
            if(v[i].fi.fi > v[j].fi.fi && v[i].fi.se > v[j].fi.se && dp[i] <= dp[j]){
                dp[i] = dp[j] + 1;
                trace[i] = j;
            }
        }
    }
    int res = 0;
    int k = 0;
    for(int i = 0; i <= n; i++){
        if(res < dp[i]){
            res = dp[i];
            k = i;
        }
    }
    cout<<res<<nl;
    if(res){
        vector<int> a;
        a.pb(v[k].se);
        k = trace[k];
        while(trace[k] != -1){
            a.pb(v[k].se);
            k = trace[k];
        }
        for(int i = a.size() - 1; i >= 0; i--) cout<<a[i]<<" ";
    }
 
}
int main(){  
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    Solve();
}