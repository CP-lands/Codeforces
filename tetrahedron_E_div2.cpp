#include<bits/stdc++.h>  
 
//https://codeforces.com/contest/166/problem/E
using namespace std; 
 
#define pb push_back
#define fi first
#define se second
#define nl '\n'
typedef long long ll;
 
const int MOD = 1e9 + 7;
 
void Solve(){
    int n;
    cin>>n;
    ll a = 0, b = 0, c = 0, d = 1;
    for(int i = 1; i <= n; i++){
        ll aa = b + c + d;
        ll bb = a + c + d;
        ll cc = a + b + d;
        ll dd = a + b + c;
        aa = aa % MOD;
        bb = bb % MOD;
        cc = cc % MOD;
        dd = dd % MOD;
        a = aa;
        b = bb;
        c = cc;
        d = dd;
    }
    cout<<d<<nl;
    
}
int main(){  
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T = 1;
    //cin>>T;
    while(T--){
        Solve();
    }
}