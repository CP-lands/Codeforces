#include <bits/stdc++.h> 
  
//https://codeforces.com/problemset/problem/1365/D
using namespace std; 

int movee[4][2] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
void Solve(){
    int n, m;
    cin>>n>>m;
    vector<vector<char>> v(n, vector<char>(m));
    int good = 0;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin>>v[i][j];
            if(v[i][j] == 'G') good++;
        }
    }
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(v[i][j] == 'B'){
                if(i > 0){
                    if(v[i - 1][j] == 'G'){
                        cout<<"No\n";
                        return;
                    }
                    else if(v[i - 1][j] == '.') v[i - 1][j] = '#';
                }
                if(i < n - 1){
                    if(v[i + 1][j] == 'G'){
                        cout<<"No\n";
                        return;
                    }
                    else if(v[i + 1][j] == '.') v[i + 1][j] = '#';
                }
                if(j > 0){
                    if(v[i][j - 1] == 'G'){
                        cout<<"No\n";
                        return;
                    }
                    else if(v[i][j - 1] == '.') v[i][j - 1] = '#';
                }
                if(j < m - 1){
                    if(v[i][j + 1] == 'G'){
                        cout<<"No\n";
                        return;
                    }
                    else if(v[i][j + 1] == '.') v[i][j + 1] = '#';
                }
            }
        }
    }
    vector<vector<bool>> vst(n, vector<bool> (m));
    queue<pair<int, int>> q;
    if(v[n - 1][m - 1] != '#') q.push({n - 1, m - 1});
    vst[n - 1][m - 1] = true;
    int res = 0;
    while(!q.empty()){
        pair<int, int> p = q.front();
        q.pop();
        for(int i = 0; i < 4; i++){
            int x = p.first + movee[i][0];
            int y = p.second + movee[i][1];
            if(x >= 0 && x < n && y >= 0 && y < m && !vst[x][y] && v[x][y] != '#'){
                if(v[x][y] == 'B'){
                    cout<<"No\n";
                    return;
                }
                vst[x][y] = true;
                q.push({x, y});
                if(v[x][y] == 'G') res++;
            }
        }
    }
    if(res < good) cout<<"No\n";
    else cout<<"Yes\n";

}
int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T = 1;
    cin>>T;
    while(T--){
        Solve();
    }
}