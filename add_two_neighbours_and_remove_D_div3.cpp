#include<bits/stdc++.h>  
 
//https://codeforces.com/contest/1462/problem/D
using namespace std; 
 
#define pb push_back
#define fi first
#define se second
#define nl '\n'
typedef long long ll;
 
bool isPossible(vector<int> &v, int k){
    int n = v.size();
    int i = 0;
    while(i < n){
        int s = 0;
        while(i < n && s + v[i] <= k){
            s += v[i];
            i++;
        }
        if(s == k){
            s = 0;
        }
        else{
            return false;
        }
    }
    return true;
}
void Solve(){
    int n;
    cin>>n;
    vector<int> v(n);
    for(int i = 0; i < n; i++)
        cin>>v[i];
    ll sum = 0;
    for(auto x: v) sum += x;
 
    vector<int> d;
    for(ll i = 1; i * i <= sum; i++){
        if(sum % i == 0){
            d.pb(i);
            if(i != sum / i) d.pb(sum / i);
        }
    }
    sort(d.begin(), d.end());
    for(auto x: d){
        if(isPossible(v, x)){
            cout<<n - sum / x<<nl;
            return;
        }
    }
 
}
int main(){  
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T = 1;
    cin>>T;
    while(T--){
        Solve();
    }
}