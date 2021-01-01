#include<bits/stdc++.h>  
 
//https://codeforces.com/contest/1443/problem/D
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
    vector<int> a(n);
    a[0] = v[0];
    v[0] = 0;
    bool good = true;
    for(int i = 1; i < n; i++){
        int left = v[i] - v[i - 1];
        if(left < 0) good = false;
        a[i] = min(left, a[i - 1]);
        v[i] -= a[i];
    }
    cout<<(good ? "YES" : "NO")<<nl;
    
}
int main(){  
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T = 1;
    cin>>T;
    while(T--){
        Solve();
    }
}
