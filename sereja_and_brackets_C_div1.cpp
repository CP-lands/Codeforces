#include<bits/stdc++.h>

//https://codeforces.com/problemset/problem/380/C
using namespace std;
#define N 1000001

int res[4 * N];
int l[4 * N];
int r[4 * N];
string s;

void build(int u, int a, int b){
    if(a == b){
        if(s[a] == '('){
            r[u] = 1;
            res[u] = 0;
            l[u] = 0;
            return;
        }
        else{
            l[u] = 1;
            res[u] = 0;
            r[u] = 0;
            return;
        }
    }
    int mid = a + (b - a) / 2;
    build(2 * u, a, mid);
    build(2 * u + 1, mid + 1, b);
    int k = min(r[2 * u], l[2 * u + 1]);
    res[u] = res[2 * u] + res[2 * u + 1] + 2 * k;
    r[u] = r[2 * u] + r[2 * u + 1] - k;
    l[u] = l[2 * u] + l[2 * u + 1] - k;
    return;
}
vector<int> getRes(int u, int a, int b, int low, int high){
    if(a > high || b < low){
        vector<int> v(3);
        return v;
    }
    if(a >= low && b <= high){
        vector<int> v(3);
        v[0] = res[u];
        v[1] = r[u];
        v[2] = l[u];
        return v;
    }
    int mid = a + (b - a) / 2;
    vector<int> v1 = getRes(2 * u, a, mid, low, high);
    vector<int> v2 = getRes(2 * u + 1, mid + 1, b, low, high);
    vector<int> v(3);
    v[0] = v1[0] + v2[0] + min(v1[1], v2[2]) * 2;
    v[1] = v1[1] + v2[1] - min(v1[1], v2[2]);
    v[2] = v2[2] + v1[2] - min(v1[1], v2[2]);
    return v;
}

void Solve(){
    int q;
    cin>>s>>q;
    int n = s.size();
    build(1, 0, n - 1);
    while(q--){
        int low, high;
        cin>>low>>high;
        low--; high--;
        vector<int> v = getRes(1, 0, n - 1, low, high);
        cout<<v[0]<<'\n';
    }
}
int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int q = 1;
    //cin>>q;
    while(q--){
        Solve();
    }
}