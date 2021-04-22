//----------------just-trying-to-keep-this-happiness-----------------------
#include<bits/stdc++.h>
 
using namespace std;
//https://codeforces.com/contest/639/problem/B
 
#define fi first
#define se second
#define pb push_back
#define nl '\n'
#define bug cout<<"bug here!"<<nl
typedef long long ll;
 
void Alice(){
    int n, d, h;
    cin>>n>>d>>h;
    if(d > 2 * h || (h == 1 && n > 2 && d == 1)){
        cout<<-1<<nl;
        return;
    }
    vector<pair<int, int>> res;
    int ver = 2;
    for(int i = 0; i < h; i++){
        res.pb({ver - 1, ver});
        ver++;
    }
    int ver_left = d - h;
    if(ver_left == 0){
        while(ver <= n){
            res.pb({2, ver++});
        }
    }
    else{
        res.pb({1, ver++});
        for(int i = 1; i < ver_left; i++){
            res.pb({ver - 1, ver++});
        }
        while(ver <= n){
            res.pb({1, ver++});
        }
    }
    for(auto x: res)
        cout<<x.fi<<" "<<x.se<<nl;
    
}
int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T = 1;
    //cin>>T;
    while(T--){
        Alice();
    }
}