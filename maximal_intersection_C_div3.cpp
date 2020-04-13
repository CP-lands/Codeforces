#include<bits/stdc++.h>
 
//https://codeforces.com/contest/1029/problem/C
using namespace std;
 
void Solve(){
    int n;
    cin>>n;
    vector<vector<int>> v(n, vector<int>(2));
    for(int i = 0; i < n; i++){
        cin>>v[i][0]>>v[i][1];
    }
    vector<vector<int>> dp(n, vector<int>(2));
    int low = v[0][0], high = v[0][1];
    dp[0][0] = INT_MIN;
    dp[0][1] = INT_MAX;
    for(int i = 1; i < n; i++){
        dp[i][0] = low;
        dp[i][1] = high;
        low = max(low, v[i][0]);
        high = min(high, v[i][1]);
    }
    int res = max(0, dp[n - 1][1] - dp[n - 1][0]);
    low = v[n - 1][0], high = v[n - 1][1];
    for(int i = n - 2; i >= 0; i--){
        int x = max(dp[i][0] , low);
        int y = min(high, dp[i][1]);
        res = max(res, y - x);
        low = max(low, v[i][0]);
        high = min(high, v[i][1]);
        //cout<<x<<" "<<y<<" "<<low<<" "<<high<<endl;
    }
    cout<<res<<'\n';
}
 
int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int q = 1;
    //cin>>q;
    while(q--){
        Solve();
    }
}