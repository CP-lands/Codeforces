#include<bits/stdc++.h>
 
using namespace std;
//https://codeforces.com/contest/1538/problem/D
 
#define fi first
#define se second
#define pb push_back
#define nl '\n'
#define bug cout<<"bug here!"<<nl
typedef long long ll;
 
void Solve(){
    int minn = 0;
    int a, b, k;
    cin>>a>>b>>k;
    int aa = a, bb = b;
    int c = __gcd(a, b);
    int k1 = 0, k2 = 0, k3 = 0, k4 = 0;
    int N = a;
    int tmp = N;
 
    if(a == b) minn = 0;
    else if(a > c && b > c) minn = 2;
    else minn = 1;
 
    for(int i = 2; i * i <= N; i++){
        while(a % i == 0){
            a /= i;
            k1++;
        }
    }
    if(a > 1) k1++;
    N = b;
    for(int i = 2; i * i <= N; i++){
        while(b % i == 0){
            b /= i;
            k2++;
        }
    }
    if(b > 1) k2++;
    if(k < minn || k > k1 + k2){
        cout<<"NO"<<nl;
        return;
    }
    if(k == 0 && a == b){
        cout<<"YES"<<nl;
        return;
    }
    if(k == 1 && ((aa == c && bb != c) || (aa != c && bb == c))){
        cout<<"YES"<<nl;
        return;
    }
 
    if(k >= 2 && k <= k1 + k2) cout<<"YES"<<nl;
    else cout<<"NO"<<nl;
 
 
}
int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T = 1;
    cin>>T;
    while(T--){
        Solve();
    }
}