#include<bits/stdc++.h>
 
//https://codeforces.com/contest/1342/problem/C
using namespace std;
 
void Solve(){
    int a, b, q;
    cin>>a>>b>>q;
    int lcm = 1;
    for(int i = 1; i <= 40000; i++){
        if(i % a == 0 && i % b == 0){
            lcm = i;
            break;
        }
    }
    int count = 0;
    for(int i = 1; i <= lcm; i++){
        if((i % a) % b != (i % b) % a) count++;
    }
    vector<int> dp(40001);
    for(int i = 1; i <= lcm; i++){
        dp[i] = dp[i - 1];
        if((i % a) % b != (i % b) % a) dp[i]++;
    }
    while(q--){
        long long l, r, res = 0;
        cin>>l>>r;
        while(l <= 200 && l < r){
            if((l % a) % b != (l % b) % a) res++;
            l++;
        }
        long long k, k2;
        if(l % lcm == 0) k = l / lcm;
        else{
            k = l / lcm + 1;
            res += dp[lcm] - dp[l % lcm - 1];
        }
        if(r % lcm == 0) k2 = r / lcm;
        else{
            k2 = r / lcm + 1;
            res -= dp[lcm] - dp[r % lcm];
        }
        res += (k2 - k) * count;
        cout<<res<<' ';
    }
    cout<<'\n';
}
int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T = 1;
    cin>>T;
    while(T--){
        Solve();
    }
}