#include<bits/stdc++.h>  
 
//https://codeforces.com/contest/1459/problem/C
using namespace std; 
 
#define pb push_back
#define fi first
#define se second
#define nl '\n'
typedef long long ll;
 
void Solve(){
    int n, m;
    cin>>n>>m;
    vector<ll> a(n), b(m);
    for(int i = 0; i < n; i++)
        cin>>a[i];
    for(int i = 0; i < m; i++)
        cin>>b[i];
    if(n == 1){
        for(auto x: b){
            cout<<x + a[0]<<" ";
        }
        return;
    }
    sort(a.begin(), a.end());
    ll k = a[1] - a[0];
    for(int i = 2; i < n; i++){
        k = __gcd(k, a[i] - a[i - 1]);
    }
    for(auto x: b){
        cout<<__gcd(k, a[0] + x)<<" ";
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