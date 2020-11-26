#include<bits/stdc++.h>
 
//https://codeforces.com/problemset/problem/242/E
using namespace std;

const int N = 100001;
int v[N];
int tree[20][4 * N];
int lazy[20][4 * N];

void build(int u, int a, int b){
    if(a == b){
        for(int i = 19; i >= 0; i--){
            if(v[a] >= pow(2, i)){
                v[a] -= pow(2, i);
                tree[i][u] = 1;
            }
            else tree[i][u] = 0;
        }
        return;
    }
    int mid = a + (b - a) / 2;
    build(2 * u, a, mid);
    build(2 * u + 1, mid + 1, b);
    for(int i = 0; i < 20; i++)
        tree[i][u] = tree[i][2 * u] + tree[i][2 * u + 1];
}
void update(int no, int u, int a, int b, int l, int r){
    if(lazy[no][u]){
        tree[no][u] = (b - a + 1) - tree[no][u];
        if(a != b){
            lazy[no][2 * u] ^= 1;
            lazy[no][2 * u + 1] ^= 1;
        }
        lazy[no][u] = 0;
    }
    if(a > r || b < l) return;
    if(a >= l && b <= r){
        tree[no][u] = (b - a + 1) - tree[no][u];
        if(a != b){
            lazy[no][2 * u] ^= 1;
            lazy[no][2 * u + 1] ^= 1;
        }
        lazy[no][u] = 0;
        return;
    }
    int mid = a + (b - a) / 2;
    update(no, 2 * u, a, mid, l, r);
    update(no, 2 * u + 1, mid + 1, b, l, r);
    tree[no][u] = tree[no][2 * u] + tree[no][2 * u + 1];
}
long long getRes(int no, int u, int a, int b, int l, int r){
    if(lazy[no][u]){
        tree[no][u] = (b - a + 1) - tree[no][u];
        if(a != b){
            lazy[no][2 * u] ^= 1;
            lazy[no][2 * u + 1] ^= 1;
        }
        lazy[no][u] = 0;
    }
    if(a > r || b < l) return 0;
    if(a >= l && b <= r){
        if(lazy[no][u]){
            tree[no][u] = (b - a + 1) - tree[no][u];
            if(a != b){
                lazy[no][2 * u] ^= 1;
                lazy[no][2 * u + 1] ^= 1;
            }
            lazy[no][u] = 0;
        }
        long long res = (long long)tree[no][u] * pow(2, no);
        return res;
    }
    int mid = a + (b - a) / 2;
    return getRes(no, 2 * u, a, mid, l, r) + getRes(no, 2 * u + 1, mid + 1, b, l, r);
}
void Solve(){
    int n;
    cin>>n;
    for(int i = 0; i < n; i++)
        cin>>v[i];
    build(1, 0, n - 1);
    int q;
    cin>>q;
    while(q--){
        int typee;
        cin>>typee;
        if(typee == 1){
            int l, r;
            cin>>l>>r;
            l--; r--;
            long long res = 0;
            for(int i = 0; i < 20; i++){
                res += getRes(i, 1, 0, n - 1, l, r);
            }
            cout<<res<<'\n';
        }
        else{
            int l, r, val;
            cin>>l>>r>>val;
            l--; r--;
            for(int i = 19; i >= 0; i--){
                if(val >= pow(2, i)){
                    val -= pow(2, i);
                    update(i, 1, 0, n - 1, l, r);
                }
            }
        }
    }
}
int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    Solve();
}
