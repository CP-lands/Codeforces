#include<bits/stdc++.h>  
 
//https://codeforces.com/contest/1462/problem/E1
using namespace std; 
 
#define pb push_back
#define fi first
#define se second
#define nl '\n'
typedef long long ll;
 
long long comb(int n, int k){
    long long res = 1;
    for(int i = 1; i <= k; i++){
        res *= (n - i + 1);
        res /= i;
    }
    return res;
}
void Solve(){
    int n;
    cin>>n;
    vector<int> v(n);
    vector<int> fre(n + 1);
    for(int i = 0; i < n; i++){
        cin>>v[i];
        ++fre[v[i]];
    }
    long long res = 0;
    for(int i = 2; i < n; i++){
        res += comb(fre[i] + fre[i + 1] + fre[i - 1], 3);
        if(i > 2) res -= comb(fre[i] + fre[i - 1], 3);
    }
    cout<<res<<nl;
 
}
int main(){  
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T = 1;
    cin>>T;
    while(T--){
        Solve();
    }
}