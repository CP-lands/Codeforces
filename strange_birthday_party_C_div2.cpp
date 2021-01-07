#include<bits/stdc++.h>  
 
using namespace std; 
//https://codeforces.com/contest/1471/problem/C
 
#define pb push_back
#define fi first
#define se second
#define nl '\n'
typedef long long ll;
 
const int N = 3e5 + 1;
int tree[4 * N];
int index[4 * N];
int b[N];
 
void build(int u, int low, int high){
    if(low == high){
        tree[u] = b[low];
        index[u] = low;
        return;
    }
    int mid = low + (high - low) / 2;
    build(2 * u, low, mid);
    build(2 * u + 1, mid + 1, high);
    if(tree[2 * u] < tree[2 * u + 1]){
        tree[u] = tree[2 * u];
        index[u] = index[2 * u];
    }
    else{
        tree[u] = tree[2 * u + 1];
        index[u] = index[2 * u + 1];    
    }
}
void update(int u, int low, int high, int i){
    if(i < low || i > high) return;
    if(low == high){
        tree[u] = b[i] = INT_MAX;
        index[u] = i;
        return;
    }
    int mid = low + (high - low) / 2;
    update(2 * u, low, mid, i);
    update(2 * u + 1, mid + 1, high, i);
    if(tree[2 * u] < tree[2 * u + 1]){
        tree[u] = tree[2 * u];
        index[u] = index[2 * u];
    }
    else{
        tree[u] = tree[2 * u + 1];
        index[u] = index[2 * u + 1];    
    }
}
pair<int, int> get(int u, int low, int high, int l, int r){
    if(l > high || r < low) return {INT_MAX, u};
    if(l >= low && r <= high){
        return {tree[u], index[u]};
    }
    int mid = low + (high - low) / 2;
    pair<int, int> left = get(2 * u, low, mid, l, r);
    pair<int, int> right = get(2 * u + 1, mid + 1, high, l, r);
    if(left.fi < right.fi){
        return left;
    }
    else return right;
}
 
void Solve(){
    int n, m;
    cin>>n>>m;
    vector<int> a(n);
    for(int i = 0; i < n; i++){
        cin>>a[i];
    }
    for(int i = 0; i < m; i++){
        cin>>b[i];
    }
    build(1, 0, m - 1);
    ll res = 0;
    vector<pair<int, int>> v(n);
    for(int i = 0; i < n; i++){
        v[i] = {b[a[i] - 1], a[i] - 1};
    }
    sort(v.rbegin(), v.rend());
    for(int i = 0; i < n; i++){
        pair<int, int> p = get(1, 0, m - 1, 0, v[i].se);
        //cout<<p.fi<<" "<<p.se<<" "<<v[i].fi<<" "<<v[i].se<<nl;
        if(p.fi < v[i].fi){
            res += p.fi;
            update(1, 0, m - 1, p.se);
        }
        else res += v[i].fi;
    }
    cout<<res<<nl;
 
}
int main(){  
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T = 1;
    cin>>T;
    while(T--){
        Solve();
    }
}