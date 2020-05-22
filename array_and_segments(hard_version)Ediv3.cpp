#include<bits/stdc++.h>

//https://codeforces.com/contest/1108/problem/E2
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
    int n, m;
    cin>>n>>m;
    for(int i = 0; i < n; i++)
        cin>>v[i];
    build(1, 0, n - 1);
    map<pair<int, int>, queue<int>> mm;
    vector<vector<int>> left(n), right(n);
    for(int i = 1; i <= m; i++){
        int x, y;
        cin>>x>>y;
        x--; y--;
        mm[{x, y}].push(i);
        left[y].push_back(x);
        right[x].push_back(y);
    }
    int res = 0;
    int index = 0;
    char ans = 'l';
    //from left
    for(int i = 0; i < n; i++){
        for(auto x: left[i]) update(1, 0, n - 1, x, i);
        if(tree[1][0] - tree[1][1] > res){
            res = tree[1][0] - tree[1][1];
            ans = 'l';
            index = i;
        }
    }
    for(int i = 0; i < n; i++){
        for(auto x: left[i]) update2(1, 0, n - 1, x, i);
    }
    //from left
    for(int i = n - 1; i >= 0; i--){
        for(auto x: right[i]) update(1, 0, n - 1, i, x);
        if(tree[1][0] - tree[1][1] > res){
            res = tree[1][0] - tree[1][1];
            ans = 'r';
            index = i;
        }
    }
    cout<<res<<'\n';
    if(ans == 'l'){
        vector<int> k;
        for(int i = 0; i <= index; i++){
            for(auto x: left[i]){
                k.push_back(mm[{x, i}].front());
                mm[{x, i}].pop();
            }
        }
        cout<<k.size()<<'\n';
        for(auto x: k) cout<<x<<" ";
    }
    else{
        vector<int> k;
        for(int i = n - 1; i >= index; i--){
            for(auto x: right[i]){
                k.push_back(mm[{i, x}].front());
                mm[{i, x}].pop();
            }
        }
        cout<<k.size()<<'\n';
        for(auto x: k) cout<<x<<" ";
    }
}
int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int tt = 1;
    //cin>>tt;
    while(tt--){
        Solve();
    }
}