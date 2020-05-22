#include<bits/stdc++.h>
 
//https://codeforces.com/contest/1108/problem/E1
using namespace std;
 
const int N = 1e5;
 
int v[N];
int tree[4 * N][2];
int lazy[4 * N];
 
void build(int u, int a, int b){
    lazy[u] = 0;
    if(a == b){
        tree[u][0] = tree[u][1] = v[a];
        return;
    }
    int mid = a + (b - a) / 2;
    build(2 * u, a, mid);
    build(2 * u + 1, mid + 1, b);
    tree[u][0] = max(tree[2 * u][0], tree[2 * u + 1][0]);
    tree[u][1] = min(tree[2 * u][1], tree[2 * u + 1][1]);
}
void update(int u, int a, int b, int l, int r){
    if(lazy[u]){
        if(a != b){
            lazy[2 * u] += lazy[u];
            lazy[2 * u + 1] += lazy[u];
        }
        tree[u][0] += lazy[u];
        tree[u][1] += lazy[u];
        lazy[u] = 0;
    }
    if(a > r || b < l) return;
    if(a >= l && b <= r){
        lazy[u]--;
        if(a != b){
            lazy[2 * u]--;
            lazy[2 * u + 1]--;
        }
        tree[u][0]--;
        tree[u][1]--;
        lazy[u] = 0;
        return;
    }
    int mid = a + (b - a) / 2;
    update(2 * u, a, mid, l, r);
    update(2 * u + 1, mid + 1, b, l, r);
    tree[u][0] = max(tree[2 * u][0], tree[2 * u + 1][0]);
    tree[u][1] = min(tree[2 * u][1], tree[2 * u + 1][1]);
}
void update2(int u, int a, int b, int l, int r){
    if(lazy[u]){
        if(a != b){
            lazy[2 * u] += lazy[u];
            lazy[2 * u + 1] += lazy[u];
        }
        tree[u][0] += lazy[u];
        tree[u][1] += lazy[u];
        lazy[u] = 0;
    }
    if(a > r || b < l) return;
    if(a >= l && b <= r){
        lazy[u]++;
        if(a != b){
            lazy[2 * u]++;
            lazy[2 * u + 1]++;
        }
        tree[u][0]++;
        tree[u][1]++;
        lazy[u] = 0;
        return;
    }
    int mid = a + (b - a) / 2;
    update2(2 * u, a, mid, l, r);
    update2(2 * u + 1, mid + 1, b, l, r);
    tree[u][0] = max(tree[2 * u][0], tree[2 * u + 1][0]);
    tree[u][1] = min(tree[2 * u][1], tree[2 * u + 1][1]);
}
void Solve(){
    int n, q;
    cin>>n>>q;
    for(int i = 0; i < n; i++)
        cin>>v[i];
    vector<pair<int, int>> p(q);
    build(1, 0, n - 1);
    for(int i = 0; i < q; i++){
        int x, y;
        cin>>x>>y;
        x--; y--;
        p[i] = {x, y};
    }
    int res = 0;
    vector<int> ans;
    for(int i = 0; i < n; i++){
        vector<int> index1, index2;
        for(int j = 0; j < q; j++){
            if(p[j].second <= i){
                update(1, 0, n - 1, p[j].first, p[j].second);
                index1.push_back(j + 1);
            }
            if(p[j].first > i) index2.push_back(j + 1);
        }
        if(tree[1][0] - tree[1][1] > res){
            res = tree[1][0] - tree[1][1];
            ans = index1;
        }
        for(auto x: index1) update2(1, 0, n - 1, p[x - 1].first, p[x - 1].second);
        for(auto x: index2) update(1, 0, n - 1, p[x - 1].first, p[x - 1].second);
        if(tree[1][0] - tree[1][1] > res){
            res = tree[1][0] - tree[1][1];
            ans = index2;
        }
        for(auto x: index2) update2(1, 0, n - 1, p[x - 1].first, p[x - 1].second);
    }
    cout<<res<<'\n';
    cout<<ans.size()<<'\n';
    for(auto x: ans) cout<<x<<" ";
}
int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int tt = 1;
    //cin>>tt;
    while(tt--){
        Solve();
    }
}