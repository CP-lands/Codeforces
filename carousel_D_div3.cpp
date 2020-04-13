#include<bits/stdc++.h>

//https://codeforces.com/contest/1328/problem/D
using namespace std;

int swi(int a){
    if(a == 1) return 2;
    else return 1;
}
void Solve(){
    int n;
    cin>>n;
    vector<int> v(n);
    for(int i = 0; i < n; i++)
        cin>>v[i];
    vector<vector<int>> dp(n, vector<int> (2));
    dp[0][0] = dp[0][1] = 1;
    int color = 1;
    for(int i = 1; i < n - 1; i++){
        if(v[i] != v[i - 1]){
            dp[i][0] = swi(dp[i - 1][0]);
            dp[i][1] = swi(dp[i - 1][1]);
            color = 2;
        }
        else{
            if(dp[i - 1][0] == dp[i - 1][1]){
                dp[i][0] = swi(dp[i - 1][0]);
                dp[i][1] = dp[i - 1][1];
            }
            else{
                dp[i][0] = dp[i - 1][0];
                dp[i][1] = dp[i - 1][1];
            }
        }
    }
    bool good = true;
    dp[n - 1][1] = 1;
    if(v[n - 1] != v[0] || (v[n - 1] != v[n - 2] && dp[n - 1][1] == dp[n - 2][1])) good = false;
    if(good){
        cout<<color<<'\n';
        for(int i = 0; i < n; i++) cout<<dp[i][1]<<" ";
        cout<<'\n';
        return;
    }
    good = true;
    dp[n - 1][0] = 1;
    if(v[n - 1] != v[0] || (v[n - 1] != v[n - 2] && dp[n - 1][0] == dp[n - 2][0])) good = false;
    if(good){
        cout<<color<<'\n';
        for(int i = 0; i < n; i++) cout<<dp[i][0]<<" ";
        cout<<'\n';
        return;
    }
    good = true;
    dp[n - 1][0] = 2;
    if(v[n - 1] != v[n - 2] && dp[n - 1][0] == dp[n - 2][0]) good = false;
    if(good){
        cout<<2<<'\n';
        for(int i = 0; i < n; i++) cout<<dp[i][0]<<" ";
        cout<<'\n';
        return;
    }
    good = true;
    dp[n - 1][1] = 2;
    if(v[n - 1] != v[n - 2] && dp[n - 1][1] == dp[n - 2][1]) good = false;
    if(good){
        cout<<2<<'\n';
        for(int i = 0; i < n; i++) cout<<dp[i][1]<<" ";
        cout<<'\n';
        return;
    }
    dp[n - 1][0] = 3;
    cout<<3<<'\n';
    for(int i = 0; i < n; i++) cout<<dp[i][0]<<" ";
    cout<<'\n';
    return;
}
int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int tt = 1;
    cin>>tt;
    while(tt--){
        Solve();
    }
}