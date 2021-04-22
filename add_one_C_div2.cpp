//--------------------My dream = Phuong + Husky + Alaska-------------------------------
#include<bits/stdc++.h>
 
using namespace std;
//https://codeforces.com/contest/1513/problem/C
 
#define fi first
#define se second
#define pb push_back
#define nl '\n'
#define bug cout<<"bug here!"<<nl
typedef long long ll;
 
const int MOD = 1e9 + 7;
const int N = 2e5 + 1;
ll dp[N][10];
 
void Alice(){
    string s;
    int m;
    cin>>s>>m;
    vector<int> a(10);
    for(auto x: s){
        a[x - '0']++;
    }
    ll ans = 0;
    for(int i = 0; i < 10; i++){
        ans += (ll)a[i] * dp[m][i];
        //cout<<i<<" "<<ans<<nl;
        ans %= MOD;
    }
    cout<<ans<<nl;
 
}
int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    for(int i = 0; i < N; i++){
        for(int j = 0; j < 10; j++)
            dp[i][j] = 0;
    }
    for(int i = 0; i < 10; i++)
        dp[0][i] = 1;
    for(int i = 0; i < 10; i++){
        ll res = 1;
        vector<ll> v(10);
        v[i] = 1;
        ll pre = 0;
        for(int j = 1; j < N; j++){
            res += v[9];
            pre = v[9] + v[0];
            v[0] = v[9];
            for(int k = 1; k < 10; k++){
                ll tmp = v[k];
                v[k] = pre;
                v[k] %= MOD;
                pre = tmp;
            }
            dp[j][i] = res;
        }
    }
    int T = 1;
    cin>>T;
    while(T--){
        Alice();
    }
}