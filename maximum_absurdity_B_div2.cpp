#include<bits/stdc++.h>

//https://codeforces.com/contest/332/problem/B 
using namespace std;
 
long long mx(long long a, long long b){
    if(a >= b) return a;
    else return b;
}
 
void Solve(){
    int n, k;
    cin>>n>>k;
    vector<int> v(n);
    vector<long long> dp(n - k + 1), sum(n + 1);
    for(int i = 0; i < n; i++){
        cin>>v[i];
        sum[i + 1] = v[i] + sum[i];
    }
    long long maxx = 0;
    for(int i = n - k; i >= 0; i--){
        dp[i] = mx(maxx, sum[i + k] - sum[i]);
        maxx = dp[i];
    }
 
    long long res = 0, low = 0, high = 0;
    for(int i = 1; i + k - 1 < n - k + 1; i++){
        long long x = sum[i + k - 1] - sum[i - 1];
        long long y = dp[i + k - 1];
        if(x + y > res){
            res = x + y;
            low = x;
            high = y;
        }
    }
    int a = 0, b = 0;
    int i = 1;
    while(i < n){
        if(sum[i + k - 1] - sum[i - 1] == low){
            a = i;
            break;
        }
        i++;
    }
    i += k;
    while(true){
        if(sum[i + k - 1] - sum[i - 1] == high){
            b = i;
            break;
        }
        i++;
    }
    cout<<a<<" "<<b<<'\n';
}
int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int q = 1;
    //cin>>q;
    while(q--){
    	Solve();
    }
}