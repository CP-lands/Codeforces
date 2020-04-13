#include<bits/stdc++.h>

//https://codeforces.com/contest/796/problem/D
using namespace std;
const int N = 300001;

vector<int> g[N];
map<pair<int, int>, int> mm;
bool vst[N];
int parent[N];
bool check[N];

void Solve(){
    int n, k, d;
    cin>>n>>k>>d;
    queue<int> pol;
    memset(vst, 0, N);
    memset(check, 0, N);
    vector<int> res;
    for(int i = 0; i < k; i++){
        int a;
        cin>>a;
        if(!vst[a]) pol.push(a);
        vst[a] = true;
        parent[a] = 0;
    }
    for(int i = 1; i < n; i++){
        int u, v;
        cin>>u>>v;
        g[u].push_back(v);
        g[v].push_back(u);
        mm[{u, v}] = mm[{v, u}] = i;
    }    
    while(!pol.empty()){
        int current = pol.front();
        pol.pop();
        for(auto x: g[current]){
            if(x == parent[current]) continue;
            if(!vst[x]){
                vst[x] = true;
                pol.push(x);
                parent[x] = current;
            }
            else if(!check[mm[{x, current}]]){
                res.push_back(mm[{x, current}]);
                check[mm[{x, current}]] = true;
            }
        }
    }
    cout<<res.size()<<'\n';
    for(auto x: res) cout<<x<<" ";

}
int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int q = 1;
    //cin>>q;
    while(q--){
        Solve();
    }
}