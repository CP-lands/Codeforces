#include<bits/stdc++.h>  
 
//https://codeforces.com/contest/1236/problem/D
using namespace std; 
 
#define pb push_back
#define fi first
#define se second
#define nl '\n'
typedef long long ll;
 
vector<int> g[100005];
vector<int> gg[100005];
 
void Solve(){
    ll n, m, k;
    cin>>n>>m>>k;
    ll need = n * m - k;
    while(k--){
        int x, y;
        cin>>x>>y;
        g[x].pb(y);
        gg[y].pb(x);
    }
    for(int i = 1; i < 1e5 + 1; i++){
        g[i].pb(0);
        g[i].pb(m + 1);
        gg[i].pb(0);
        gg[i].pb(n + 1);
        sort(g[i].begin(), g[i].end());
        sort(gg[i].begin(), gg[i].end());
    }
    bool one = true, two = false, three = false, four = false;
    int left = 1, right = m, top = 2, bot = n;
    ll res = 1;
    int x = 1, y = 1;
    while(true){
        if(one){
            vector<int>::iterator p = upper_bound(g[x].begin(), g[x].end(), y);
            right = min(right, *p - 1);
            if(right == y && res != 1) break;
            res += right - y;
            y = right--;
            one = false;
            two = true;
        }   
        else if(two){
            vector<int>::iterator p = upper_bound(gg[y].begin(), gg[y].end(), x);
            bot = min(bot, *p - 1);
            if(bot == x) break;
            res += bot - x;
            x = bot--;
            two = false;
            three = true;
        }
        else if(three){
            vector<int>::iterator p = lower_bound(g[x].begin(), g[x].end(), y);
            p--;
            left = max(left, *p + 1);
            if(left == y) break;
            res += y - left;
            y = left++;
            three = false;
            four = true;   
        }
        else if(four){
            vector<int>::iterator p = lower_bound(gg[y].begin(), gg[y].end(), x);
            p--;
            top = max(top, *p + 1);
            if(top == x) break;
            res += x - top;
            x = top++;
            four = false;
            one = true;
        }
    }
    if(res == need) cout<<"Yes"<<nl;
    else cout<<"No"<<nl;
 
}
int main(){  
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T = 1;
    //cin>>T;
    while(T--){
        Solve();
    }
}