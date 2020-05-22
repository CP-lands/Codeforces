#include<bits/stdc++.h>
 
//https://codeforces.com/contest/1337/problem/D
using namespace std;
 
void Solve(){
    int aa, bb, cc;
    cin>>aa>>bb>>cc;
    vector<int> a(aa), b(bb), c(cc);
    for(int i = 0; i < aa; i++)
        cin>>a[i];
    for(int i = 0; i < bb; i++)
        cin>>b[i];
    for(int i = 0; i < cc; i++)
        cin>>c[i];
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    sort(c.begin(), c.end());
    long long res = 2e18;
    for(int i = 0; i < aa; i++){
        //rr
        int x = lower_bound(b.begin(), b.end(), a[i]) - b.begin();
        int y = lower_bound(c.begin(), c.end(), a[i]) - c.begin();
        int n = x, m = y;
        if(x >= bb) x--;
        if(y >= cc) y--;
        long long tmp = (long long)(a[i] - b[x]) * (a[i] - b[x]) + (long long)(a[i] - c[y]) * (a[i] - c[y]) + (long long)(b[x] - c[y]) * (b[x] - c[y]);
        if(tmp < res) res = tmp;
        //ll
        x = n; y = m;
        if(x > 0) x--;
        if(y > 0) y--;
        tmp = (long long)(a[i] - b[x]) * (a[i] - b[x]) + (long long)(a[i] - c[y]) * (a[i] - c[y]) + (long long)(b[x] - c[y]) * (b[x] - c[y]);
        if(tmp < res) res = tmp;
        //rl
        x = n; y = m;
        if(y > 0) y--;
        if(x >= bb) x--;
        tmp = (long long)(a[i] - b[x]) * (a[i] - b[x]) + (long long)(a[i] - c[y]) * (a[i] - c[y]) + (long long)(b[x] - c[y]) * (b[x] - c[y]);
        if(tmp < res) res = tmp;
        //lr
        x = n; y = m;
        if(x > 0) x--;
        if(y >= cc) y--;
        tmp = (long long)(a[i] - b[x]) * (a[i] - b[x]) + (long long)(a[i] - c[y]) * (a[i] - c[y]) + (long long)(b[x] - c[y]) * (b[x] - c[y]);
        if(tmp < res) res = tmp;
 
    }
    for(int i = 0; i < bb; i++){
        //rr
        int x = lower_bound(a.begin(), a.end(), b[i]) - a.begin();
        int y = lower_bound(c.begin(), c.end(), b[i]) - c.begin();
        int n = x, m = y;
        if(x >= aa) x--;
        if(y >= cc) y--;
        long long tmp = (long long)(b[i] - a[x]) * (b[i] - a[x]) + (long long)(b[i] - c[y]) * (b[i] - c[y]) + (long long)(a[x] - c[y]) * (a[x] - c[y]);
        if(tmp < res) res = tmp;
        //ll
        x = n; y = m;
        if(x > 0) x--;
        if(y > 0) y--;
        tmp = (long long)(b[i] - a[x]) * (b[i] - a[x]) + (long long)(b[i] - c[y]) * (b[i] - c[y]) + (long long)(a[x] - c[y]) * (a[x] - c[y]);
        if(tmp < res) res = tmp;
        //rl
        x = n; y = m;
        if(y > 0) y--;
        if(x >= aa) x--;
        tmp = (long long)(b[i] - a[x]) * (b[i] - a[x]) + (long long)(b[i] - c[y]) * (b[i] - c[y]) + (long long)(a[x] - c[y]) * (a[x] - c[y]);
        if(tmp < res) res = tmp;
        //lr
        x = n; y = m;
        if(x > 0) x--;
        if(y >= cc) y--;
        tmp = (long long)(b[i] - a[x]) * (b[i] - a[x]) + (long long)(b[i] - c[y]) * (b[i] - c[y]) + (long long)(a[x] - c[y]) * (a[x] - c[y]);
        if(tmp < res) res = tmp;
 
    }
    for(int i = 0; i < cc; i++){
        //rr
        int x = lower_bound(b.begin(), b.end(), c[i]) - b.begin();
        int y = lower_bound(a.begin(), a.end(), c[i]) - a.begin();
        int n = x, m = y;
        if(x >= bb) x--;
        if(y >= aa) y--;
        long long tmp = (long long)(c[i] - b[x]) * (c[i] - b[x]) + (long long)(c[i] - a[y]) * (c[i] - a[y]) + (long long)(b[x] - a[y]) * (b[x] - a[y]);
        if(tmp < res) res = tmp;
        //ll
        x = n; y = m;
        if(x > 0) x--;
        if(y > 0) y--;
        tmp = (long long)(c[i] - b[x]) * (c[i] - b[x]) + (long long)(c[i] - a[y]) * (c[i] - a[y]) + (long long)(b[x] - a[y]) * (b[x] - a[y]);
        if(tmp < res) res = tmp;
        //rl
        x = n; y = m;
        if(y > 0) y--;
        if(x >= bb) x--;
        tmp = (long long)(c[i] - b[x]) * (c[i] - b[x]) + (long long)(c[i] - a[y]) * (c[i] - a[y]) + (long long)(b[x] - a[y]) * (b[x] - a[y]);
        if(tmp < res) res = tmp;
        //lr
        x = n; y = m;
        if(x > 0) x--;
        if(y >= aa) y--;
        tmp = (long long)(c[i] - b[x]) * (c[i] - b[x]) + (long long)(c[i] - a[y]) * (c[i] - a[y]) + (long long)(b[x] - a[y]) * (b[x] - a[y]);
        if(tmp < res) res = tmp;
 
    }
    cout<<res<<'\n';
}
int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int tt = 1;
    cin>>tt;
    while(tt--){
        Solve();
    }
}