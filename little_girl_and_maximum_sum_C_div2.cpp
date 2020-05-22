#include<bits/stdc++.h>
 
//https://codeforces.com/contest/276/problem/C
using namespace std;
 
void Solve(){
    int n, q;
    cin>>n>>q;
    vector<int> v(n);
    for(int i = 0; i < n; i++)
        cin>>v[i];
    vector<long long> flag(n);
    while(q--){
        int low, high;
        cin>>low>>high;
        low--; high--;
        flag[low]++;
        if(high < n - 1) flag[high + 1]--;
    }
    long long k = 0;
    for(int i = 0; i < n; i++){
        k += flag[i];
        flag[i] = k;
    }
    sort(flag.rbegin(), flag.rend());
    sort(v.rbegin(), v.rend());
    long long res = 0;
    for(int i = 0; i < n; i++)
        res += flag[i] * (long long)v[i];
    cout<<res<<'\n';
}
int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T = 1;
    //cin>>T;
    while(T--){
        Solve();
    }
}