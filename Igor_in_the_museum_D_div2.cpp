#include<bits/stdc++.h>  
 
//https://codeforces.com/contest/598/problem/D
using namespace std; 
 
#define pb push_back
#define fi first
#define se second
#define nl '\n'
typedef long long ll;
 
int MOVE[4][2] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
 
void Solve(){
    int n, m, k;
    cin>>n>>m>>k;
    vector<vector<char>> v(n, vector<char> (m));
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++)
            cin>>v[i][j];
    }
    map<pair<int, int>, int> mm;
    vector<vector<bool>> vst(n, vector<bool> (m));
    for(int i = 1; i < n - 1; i++){
        for(int j = 1; j < m - 1; j++){
            if(vst[i][j] || v[i][j] == '*') continue;
            queue<pair<int, int>> q;
            q.push({i, j});
            vst[i][j] = true;
            vector<pair<int, int>> a;
            a.pb({i, j});
            int res = 0;
            while(!q.empty()){
                pair<int, int> p = q.front();
                q.pop();
                for(int i = 0; i < 4; i++){
                    int x = p.fi + MOVE[i][0];
                    int y = p.se + MOVE[i][1];
                    if(x >= 0 && x < n && y >= 0 && y < m && v[x][y] == '*') res++;
                    if(x >= 0 && x < n && y >= 0 && y < m && v[x][y] == '.' && !vst[x][y]){
                        vst[x][y] = true;
                        q.push({x, y});
                        a.pb({x, y});
                    }
                }
            }
            for(auto x: a){
                mm[{x.fi, x.se}] = res;
            }
        }
    }
    while(k--){
        int x, y;
        cin>>x>>y;
        x--; y--;
        if(v[x][y] == '*') cout<<0<<nl;
        else cout<<mm[{x, y}]<<nl;
    }
 
}
int main(){  
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T = 1;
    //cin>>T;
    while(T--){
        Solve();
    }
}