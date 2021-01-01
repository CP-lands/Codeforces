#include<bits/stdc++.h>  
 
//https://codeforces.com/contest/545/problem/D
using namespace std; 
 
#define pb push_back
#define fi first
#define se second
#define nl '\n'
typedef long long ll;
 
void Solve(){
    int n;
    cin>>n;
    vector<int> v(n);
    for(int i = 0; i < n; i++)
        cin>>v[i];
    sort(v.begin(), v.end());
    vector<ll> pre(n);
    for(int i = 0; i < n; i++){
        pre[i] = v[i];
        if(i > 0) pre[i] += pre[i - 1];
    }
    int res = 1;
    ll sub = 0;
    for(int i = 1; i < n; i++){
        if(v[i] >= pre[i - 1] - sub) res++;
        else sub += v[i];
    }
    cout<<res<<nl;
    
}
int main(){  
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T = 1;
    //cin>>T;
    while(T--){
        Solve();
    }
}