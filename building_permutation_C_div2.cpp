#include<bits/stdc++.h>

//https://codeforces.com/contest/285/problem/C 
using namespace std;
 
long long abss(long long a, long long b){
    if(a >= b) return a - b;
    else return b - a;
}
 
void Solve(){
    int n;
    cin>>n;
    vector<int> v(n);
    for(int i = 0; i < n; i++)
        cin>>v[i];
    sort(v.begin(), v.end());
    long long res = 0;
    for(int i = 0; i < n; i++){
        res += abss(i + 1, v[i]);
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