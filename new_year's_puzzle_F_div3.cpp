//--------------my brain isn't at home right now------------------
#include<bits/stdc++.h>  
 
using namespace std; 
//https://codeforces.com/contest/1472/problem/F
 
#define pb push_back
#define fi first
#define se second
#define nl '\n'
typedef long long ll;
 
void Solve(){
    int n, m;
    cin>>n>>m;
    vector<pair<int, int>> v(m);
    for(int i = 0; i < m; i++){
        int a, b;
        cin>>a>>b;
        v[i] = {b, a};
    }
    sort(v.begin(), v.end());
    vector<pair<int, int>> a;
    a.pb({0, 0});
    for(int i = 0; i < m; i++){
        if(i < m - 1 && v[i].fi == v[i + 1].fi){
            a.pb({v[i].fi, 0});
            i++;
        }
        else a.pb(v[i]);
    }
    //for(auto x: a) cout<<x.fi<<" "<<x.se<<nl;
    bool possible = true;
    for(int i = 1; i < a.size(); i++){
        if(a[i - 1].se == 0) continue;
        int d = a[i].fi - a[i - 1].fi - 1;
        if(a[i].se == 0) possible = false;
        if(a[i].se == a[i - 1].se){
            if(d % 2) possible = false;
            else a[i].se = 0;
        }
        else{
            if(d % 2) a[i].se = 0;
            else possible = false;
        }
    }
    if(a.back().se != 0) possible = false;
    if(possible) cout<<"Yes"<<nl;
    else cout<<"No"<<nl;
}
int main(){  
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T = 1;
    cin>>T;
    while(T--){
        Solve();
    }
}