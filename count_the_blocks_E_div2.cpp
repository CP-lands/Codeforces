#include<bits/stdc++.h>

//https://codeforces.com/contest/1327/problem/E
using namespace std;

const int MOD = 998244353;
long long f[200001];

void Solve(){
    int n;
    cin>>n;
    f[0] = 1;
    f[1] = 9;
    for(int i = 2; i <= n; i++){
        f[i] = f[i - 1] * 10;
        f[i] = f[i] % MOD;
    }
    for(int i = 1; i <= n; i++){
        if(i == n){
            cout<<10<<" ";
            continue;
        }
        long long res = 10;
        int k = n - i;
        res *= f[k] * 2;
        res = res % MOD;
        if(k > 1){
            long long ans = 10 * f[k - 1] * 9 * (k - 1);
            ans = ans % MOD;
            res += ans;
            res = res % MOD;
        }
        cout<<res<<" ";
    }

}
int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int q = 1;           
    //cin>>q;
    while(q--){
    	Solve();
    }
}