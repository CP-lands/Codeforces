#include<bits/stdc++.h>
 
//https://codeforces.com/contest/1294/problem/F
using namespace std;

vector<int> g[200000];
int countt = 0;
int n;
int tmp[200000];
int parents[200000];
bool vst[200000];

void bfs(int u){
    bool visited[200000];
    memset(visited, 0, n);
    queue<int> q;
    q.push(u);
    tmp[u] = countt++;
    visited[u] = true;
    while(!q.empty()){
        int cr = q.front();
        q.pop();
        for(auto x: g[cr]){
            if(!visited[x]){
                visited[x] = true;
                q.push(x);
                tmp[x] = countt++;
                parents[x] = cr;
            }
        }
    }
}
int getVertex(){
    int u = 0;
    int maxx = 0;
    for(int i = 0; i < n; i++){
        if(tmp[i] > maxx){
            maxx = tmp[i];
            u = i;
        }
    }
    return u;
}
void Solve(){
    cin>>n;
    for(int i = 0; i < n - 1; i++){
        int u, v;
        cin>>u>>v;
        g[u - 1].push_back(v - 1);
        g[v - 1].push_back(u - 1);
    }
    memset(parents, 0, n);
    bfs(0);
    int u = getVertex();
    countt = 0;
    bfs(u);
    int v = getVertex();
    parents[u] = -1;
    int i = v;
    vst[i] = true;
    int ans = 1;
    while(parents[i] != -1){
        vst[parents[i]] = true;
        i = parents[i];
        ans++;
    }
    i = v;
    int res = parents[i];
    int mx = 0;
    while(parents[i] != -1){
        int k = parents[i];
        queue<int> qq;
        qq.push(k);
        map<int, int> mm;
        mm[k] = 0;
        while(!qq.empty()){
            int cr = qq.front();
            qq.pop();
            for(auto x: g[cr]){
                if(!vst[x]){
                    vst[x] = true;
                    qq.push(x);
                    mm[x] = mm[cr] + 1;
                }
            }
        }
        int maxx = 0;
        int z = k;
        for(auto x: mm){
            if(maxx < x.second){
                maxx = x.second;
                z = x.first;
            }
        }
        if(maxx > mx){
            mx = maxx;
            res = z;
        }
        i = parents[i];
    }
    ans += mx;
    cout<<ans - 1<<'\n';
    cout<<u + 1<<" "<<v + 1<<" "<<res + 1<<'\n';
}
 
int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int q = 1;
    //cin>>q;
    while(q--){
        Solve();
    }
}