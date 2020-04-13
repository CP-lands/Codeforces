#include<bits/stdc++.h>
 
//https://codeforces.com/contest/1339/problem/C
using namespace std;
 
void Solve(){
    int n;
    cin>>n;
    int mx = (int)-2e9;
    int val = 0;
    for(int i = 0; i < n; i++){
        int a;
        cin>>a;
        mx = max(mx, a);
        val = max(val, mx - a);
    }
    int res = 0;
    while(pow(2, res) - 1 < val){
        res++;
    }
    cout<<res<<'\n';
}
int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int tt = 1;
    cin>>tt;
    while(tt--){
        Solve();
    }
}