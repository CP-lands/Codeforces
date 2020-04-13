#include<bits/stdc++.h>
 
//https://codeforces.com/contest/251/problem/A
using namespace std;
 
long long comb(int n, int k)
{
    long long res = 1;
    for(int i = 1; i <= k; i++){
        res *= (n - i + 1);
        res /= i;
    }
    return res;
}
void Solve(){
    int n, d;
    cin>>n>>d;
    vector<int> v(n + 1);
    for(int i = 1; i <= n; i++)
        cin>>v[i];
    long long res = 0;
    for(int i = 1; i < n; i++){
        int x = v[i] + d;
        int p = lower_bound(v.begin(), v.end(), x) - v.begin();
        if(p <= n && v[p] > x) p--;
        p = min(p, n);
        long long k = p - i;
        if(k > 1 && p <= n) res += comb(k, 2);
        //cout<<v[i]<<" "<<p<<" "<<k<<" "<<res<<endl;
    }
    cout<<res<<'\n';
 
}
int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t = 1;
    //cin>>t;
    while(t--){
        Solve();
    }
}