//--------my brain isn't at home right now------------------
#include<bits/stdc++.h>  

//https://codeforces.com/contest/734/problem/D
 
using namespace std; 
 
#define pb push_back
#define fi first
#define se second
#define nl '\n'
typedef long long ll;
 
void Solve(){
    int n, x0, y0;
    cin>>n>>x0>>y0;
    vector<int> hori, verti, drag1, drag2;
    vector<pair<char, pair<int, int>>> v(n);
    for(int i = 0; i < n; i++){
        char c;
        int x, y;
        cin>>c>>x>>y;
        v[i] = {c, {x, y}};
        if(x == x0) verti.pb(y);
        if(y == y0) hori.pb(x);
        int xx = x - x0;
        int yy = y - y0;
        if(abs(xx) != abs(yy)) continue;
        if((ll)xx * yy < 0) drag2.pb(x);
        else drag1.pb(x);
    }
    bool check = false;
    drag1.pb(-1000000001);
    drag1.pb(1000000001);
    drag2.pb(-1000000001);
    drag2.pb(1000000001);
    verti.pb(-1000000001);
    verti.pb(1000000001);
    hori.pb(-1000000001);
    hori.pb(1000000001);
    sort(drag1.begin(), drag1.end());
    sort(drag2.begin(), drag2.end());
    sort(verti.begin(), verti.end());
    sort(hori.begin(), hori.end());
    //for(auto x: drag1) cout<<x<<nl;
    for(int i = 0; i < n; i++){
        char c = v[i].fi;
        int x = v[i].se.fi;
        int y = v[i].se.se;
        if(c == 'R'){
            if(x != x0 && y != y0) continue;
            if(x == x0){
                vector<int>::iterator p = upper_bound(verti.begin(), verti.end(), y0);
                if(*p == y) check = true;
                p--;
                if(*p == y) check = true;
            }
            else{
                vector<int>::iterator p = upper_bound(hori.begin(), hori.end(), x0);
                if(*p == x) check = true;
                p--;
                if(*p == x) check = true;
            }
        }
        if(c == 'B'){
            if(abs(x - x0) != abs(y - y0)) continue;
            if((long long)(x - x0) * (y - y0) > 0){
                vector<int>::iterator p = upper_bound(drag1.begin(), drag1.end(), x0);
                if(*p == x) check = true;
                p--;
                if(*p == x) check = true;
            }
            else{
                vector<int>::iterator p = upper_bound(drag2.begin(), drag2.end(), x0);
                if(*p == x) check = true;
                p--;
                if(*p == x) check = true;
            }
        }
        if(c == 'Q'){
            if(x == x0){
                vector<int>::iterator p = upper_bound(verti.begin(), verti.end(), y0);
                if(*p == y) check = true;
                p--;
                if(*p == y) check = true;
            }
            if(y == y0){
                vector<int>::iterator p = upper_bound(hori.begin(), hori.end(), x0);
                if(*p == x) check = true;
                p--;
                if(*p == x) check = true;
            }
            if(abs(x - x0) != abs(y - y0)) continue;
            if((long long)(x - x0) * (y - y0) > 0){
                vector<int>::iterator p = upper_bound(drag1.begin(), drag1.end(), x0);
                if(*p == x) check = true;
                p--;
                if(*p == x) check = true;
            }
            else{
                vector<int>::iterator p = upper_bound(drag2.begin(), drag2.end(), x0);
                if(*p == x) check = true;
                p--;
                if(*p == x) check = true;
            }
        }
    }
    if(check) cout<<"YES"<<nl;
    else cout<<"NO"<<nl;
    
}
int main(){  
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T = 1;
    //cin>>T;
    while(T--){
        Solve();
    }
}