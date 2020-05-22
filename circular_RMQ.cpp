#include<bits/stdc++.h>
 
//https://codeforces.com/problemset/problem/52/C
using namespace std;

const int N = 2e5 + 1;
int v[N];
long long tree[4 * N];
long long lazy[4 * N];

long long minn(long long a, long long b){
    if(a <= b) return a;
    else return b;
}
void build(int u, int a, int b){
    if(a == b){
        tree[u] = v[a];
        lazy[u] = 0;
        return;
    }
    int mid = a + (b - a) / 2;
    build(2 * u, a, mid);
    build(2 * u + 1, mid + 1, b);
    tree[u] = minn(tree[2 * u], tree[2 * u + 1]);
    lazy[u] = 0;
}
void update(int u, int a, int b, int l, int r, int val){
    if(lazy[u]){
        tree[u] += lazy[u];
        if(a != b){
            lazy[2 * u] += lazy[u];
            lazy[2 * u + 1] += lazy[u];
        }
        lazy[u] = 0;
    }
    if(a > r || b < l) return;
    if(a >= l && b <= r){
        if(a != b){
            lazy[2 * u] += val;
            lazy[2 * u + 1] += val;
        }
        tree[u] += val;
        return;
    }
    int mid = a + (b - a) / 2;
    update(2 * u, a, mid, l, r, val);
    update(2 * u + 1, mid + 1, b, l, r, val);
    tree[u] = minn(tree[2 * u], tree[2 * u + 1]);
}
long long getRes(int u, int a, int b, int l, int r){
    if(lazy[u]){
        tree[u] += lazy[u];
        if(a != b){
            lazy[2 * u] += lazy[u];
            lazy[2 * u + 1] += lazy[u];
        }
        lazy[u] = 0;
    }
    if(a > r || b < l) return LLONG_MAX;
    if(a >= l && b <= r){
        return tree[u];
    }
    int mid = a + (b - a) / 2;
    return minn(getRes(2 * u, a, mid, l, r), getRes(2 * u + 1, mid + 1, b, l, r));
}
void Solve(){
    int n;
    cin>>n;
    for(int i = 0; i < n; i++)
        cin>>v[i];
    build(1, 0, n - 1);
    int q;
    cin>>q;
    string tmp;
    getline(cin, tmp);
    while(q--){
        string line;
        getline(cin, line);
        vector<int> k(3);
        int i = 0;
        istringstream type(line);
        int val;
        while(type>>val){
            k[i++] = val;
        }
        if(i == 2){
            int l = k[0];
            int r = k[1];
            if(l <= r) cout<<getRes(1, 0, n - 1, l, r)<<'\n';
            else{
                cout<<minn(getRes(1, 0, n - 1, l, n - 1), getRes(1, 0, n - 1, 0, r))<<'\n';
            }
        }
        else{
            int l = k[0];
            int r = k[1];
            int val = k[2];
            if(l <= r) update(1, 0, n - 1, l, r, val);
            else{
                update(1, 0, n - 1, l, n - 1, val);
                update(1, 0, n - 1, 0, r, val);
            }
        }
    }
}
int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    Solve();
}