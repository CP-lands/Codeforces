#include<bits/stdc++.h>  

//https://codeforces.com/contest/723/problem/D
 
using namespace std; 
 
#define pb push_back
#define fi first
#define se second
#define nl '\n'
typedef long long ll;
 
int movee[4][2] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
 
void Solve(){
    int n, m, k;
    cin>>n>>m>>k;
    vector<vector<char>> v(n, vector<char> (m));
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin>>v[i][j];
        }
    }
    vector<int> lakes;
    vector<vector<bool>> vst(n, vector<bool> (m));
    for(int i = 1; i < n - 1; i++){
        for(int j = 1; j < m - 1; j++){
            if(v[i][j] == '*' || vst[i][j]) continue;
            bool ok = true;
            queue<pair<int, int>> q;
            q.push({i, j});
            vst[i][j] = true;
            int area = 1;
            while(!q.empty()){
                pair<int, int> p = q.front();
                if(p.fi == 0 || p.fi == n - 1 || p.se == 0 || p.se == m - 1) ok = false;
                q.pop();
                for(int t = 0; t < 4; t++){
                    int x = p.fi + movee[t][0];
                    int y = p.se + movee[t][1];
                    if(x >= 0 && x < n && y >= 0 && y < m && !vst[x][y] && v[x][y] == '.'){
                        area++;
                        q.push({x, y});
                        vst[x][y] = true;
                    }
                }
            }
            if(ok){
                lakes.pb(area);
            }
        }
    }
    sort(lakes.begin(), lakes.end());
    int del = lakes.size() - k;
    if(del == 0){
        cout<<0<<nl;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                cout<<v[i][j];
            }
            cout<<nl;
        }
        return;
    }
    int sum = 0;
    map<int, int> mm;
    for(int i = 0; i < del; i++){
        sum += lakes[i];
        ++mm[lakes[i]];
    }
    //cout<<lakes.size()<<nl;
    cout<<sum<<nl;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            vst[i][j] = false;
        }
    }
    int count = 0;
    for(int i = 1; i < n - 1; i++){
        for(int j = 1; j < m - 1; j++){
            if(v[i][j] == '*' || vst[i][j]) continue;
            int area = 1;
            bool ok = true;
            queue<pair<int, int>> q;
            vector<pair<int, int>> tmp;
            q.push({i, j});
            tmp.pb({i, j});
            vst[i][j] = true;
            while(!q.empty()){
                pair<int, int> p = q.front();
                if(p.fi == 0 || p.fi == n - 1 || p.se == 0 || p.se == m - 1) ok = false;          
                q.pop();
                for(int t = 0; t < 4; t++){
                    int x = p.fi + movee[t][0];
                    int y = p.se + movee[t][1];
                    if(x >= 0 && x < n && y >= 0 && y < m && !vst[x][y] && v[x][y] == '.'){
                        vst[x][y] = true;
                        q.push({x, y});
                        tmp.pb({x, y});
                        area++;
                    }
                }
            }
            if(mm[area] > 0 && ok){
                count++;
                for(auto x: tmp){
                    v[x.fi][x.se] = '*';
                }
                --mm[area];
            }
        }
    }
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cout<<v[i][j];
        }
        cout<<nl;
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