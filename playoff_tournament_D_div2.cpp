//---------------my brain isn't at home right now------------------
#include<bits/stdc++.h>  
 
using namespace std; 
//https://codeforces.com/contest/1535/problem/D
 
#define pb push_back
#define fi first
#define se second
#define nl '\n'
#define bug cout<<"Bug here!\n"
typedef long long ll;
 
const int N = 270000;
int tree[N];
int pos[N];
int order[N];
int abc[N];
int cnt = 0;
string s;
int endd;
 
void build(int u, int low, int high){
    //cout<<low<<" "<<high<<" "<<u<<nl;
    if(low == high){
        if(s[pos[u]] == '?') tree[u] = 2;
        else tree[u] = 1;
        order[u] = cnt++;
        abc[pos[u]] = u;
        return;
    }
    int mid = low + (high - low) / 2;
    build(2 * u, low, mid);
    build(2 * u + 1, mid + 1, high);
    if(s[pos[u]] == '?') tree[u] = tree[2 * u] + tree[2 * u + 1];
    else if(s[pos[u]] == '0') tree[u] = tree[2 * u];
    else tree[u] = tree[2 * u + 1];
    order[u] = cnt++;
    abc[pos[u]] = u;
    //cout<<u<<" "<<tree[u]<<nl;
}
void update(int u, int low, int high, int idx, char val){
    //cout<<u<<" "<<order[u]<<" "<<pos[u]<<" "<<idx<<nl;
    if(pos[u] == idx){
        s[idx] = val;
        //cout<<idx<<" "<<val<<" "<<u<<" "<<pos[u]<<nl;
        if(s[pos[u]] == '?'){
            if(2 * u + 1 <= endd){
                tree[u] = tree[2 * u] + tree[2 * u + 1];
            }
            else tree[u] = 2;
        }
        else{
            if(2 * u + 1 <= endd){
                if(s[pos[u]] == '0') tree[u] = tree[2 * u];
                else tree[u] = tree[2 * u + 1];
            }
            else
                tree[u] = 1;
        }
        //cout<<tree[u]<<nl;
        return;
    }
    //cout<<u<<" "<<order[u]<<" "<<order[abc[idx]]<<nl;
    if(2 * u >= endd) return;
    int mid = low + (high - low) / 2;
    if(order[abc[idx]] <= order[2 * u]) update(2 * u, low, mid, idx, val);
    else update(2 * u + 1, mid + 1, high, idx, val);
    if(s[pos[u]] == '?') tree[u] = tree[2 * u] + tree[2 * u + 1];
    else if(s[pos[u]] == '0') tree[u] = tree[2 * u];
    else tree[u] = tree[2 * u + 1];
    //cout<<tree[u]<<nl;
}
void Solve(){
    int k, q;
    cin>>k>>s>>q;
    s = '*' + s;
    int current = pow(2, k - 1);
    int l = 0;
    int r = current - 1;
    //cout<<l<<" "<<r<<nl;
    int idx = 1;
    endd = pow(2, k) - 1;
    while(current > 0){
        for(int i = 0; i < current; i++){
            pos[current + i] = idx++;
        }
        current /= 2;
    }
    build(1, l, r);
    //cout<<order[6]<<nl;
    while(q--){
        int index;
        char c;
        cin>>index>>c;
        //cout<<pos[index]<<" ";
        update(1, l, r, index, c);
        cout<<tree[1]<<nl;
        //bug;
    }
    
}
int main(){  
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    Solve();
}