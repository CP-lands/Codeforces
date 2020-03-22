#include<bits/stdc++.h>
 
//https://codeforces.com/contest/788/problem/A
using namespace std;
 
long long abss(long long a, long long b){
    long long res = a - b;
    if(res >= 0) return res;
    else return -res;
}
long long maxx(long long a, long long b){
    if(a >= b) return a;
    else return b;
}
 
void Solve(){
    int n;
    cin>>n;
    vector<int> v(n), a(n - 1);
    for(int i = 0; i < n; i++){
        cin>>v[i];
        if(i > 0) a[i - 1] = abss(v[i], v[i - 1]);
    }
    vector<long long> dp1(n - 1),  dp2(n - 1);
    dp1[0] = a[0];
    for(int i = 1; i < n - 1; i++){
        if(i % 2 == 0) dp1[i] = maxx(dp1[i - 1] + a[i], 0);
        else dp1[i] = maxx(dp1[i - 1] - a[i], 0);
    }
    dp2[0] = 0;
    for(int i = 1; i < n - 1; i++){
        if(i % 2 == 0) dp2[i] = maxx(dp2[i - 1] - a[i], 0);
        else dp2[i] = maxx(dp2[i - 1] + a[i], 0);
    }
    long long res = 0;
    for(auto x: dp1){
        if(res < x) res = x;
    }
    for(auto x: dp2){
        if(res < x) res = x;
    }
    cout<<res<<'\n';
}
int main(){
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int q = 1;
    //cin>>q;
    while(q--){
    	Solve();
    }
}