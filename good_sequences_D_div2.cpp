//--------my brain isn't at home right now------------------
#include<bits/stdc++.h>  

//https://codeforces.com/contest/264/problem/B
 
using namespace std; 
 
#define pb push_back
#define fi first
#define se second
#define nl '\n'
typedef long long ll;
 
bool isPrime(int n){
    for(int i = 2; i * i <= n; i++){
        if(n % i == 0) return false;
    }
    return true;
}
void Solve(){
    int n;
    cin>>n;
    vector<int> v(n);
    for(int i = 0; i < n; i++){
        cin>>v[i];
    }
    vector<bool> prime(100001);
    for(int i = 1; i < 100001; i++){
        if(isPrime(i)) prime[i] = true;
        else prime[i] = false;
    }
    vector<int> dp(100001);
    vector<int> d(100001);
 
    for(int i = 0; i < n; i++){
        vector<int> tmp;
        for(int j = 2; j * j <= v[i]; j++){
            if(v[i] % j) continue;
            int a = v[i] / j;
            if(prime[j]){
                tmp.pb(j);
                dp[i] = max(dp[i], ++d[j]);
            }
            if(a != j && prime[a]){
                tmp.pb(a);
                dp[i] = max(dp[i], ++d[a]);
            }
        }
        if(prime[v[i]]) dp[i] = max(dp[i], ++d[v[i]]);
        for(auto x: tmp) d[x] = dp[i];
    }
    int res = 0;
    for(auto x: dp) res = max(res, x);
    cout<<res<<nl;
 
}
int main(){  
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    Solve();
}