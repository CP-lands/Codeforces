#include<bits/stdc++.h>  

//https://codeforces.com/problemset/problem/611/C
using namespace std; 

#define pb push_back
#define fi first
#define se second
#define nl '\n'
typedef long long ll;

void Solve(){
    int n, m;
    cin>>n>>m;
    vector<vector<char>> v(n + 1, vector<char> (m + 1));
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++)
            cin>>v[i][j];
    }
    vector<vector<int>> x(n + 1, vector<int> (m + 1));
    vector<vector<int>> y(n + 1, vector<int> (m + 1));
    for(int i = 1; i <= n; i++){
        int good = 0;
        for(int j = 1; j <= m; j++){
            if(v[i][j] == '.' && v[i][j - 1] == '.') good++;
            x[i][j] = good + x[i - 1][j];
        }
    }
    for(int i = 1; i <= m; i++){
        int good = 0;
        for(int j = 1; j <= n; j++){
            if(v[j][i] == '.' && v[j - 1][i] == '.') good++;
            y[j][i] = good + y[j][i - 1];
        }   
    }
    int q;
    cin>>q;
    while(q--){
        int r1, c1, r2, c2;
        cin>>r1>>c1>>r2>>c2;
        int res = x[r2][c2] - x[r2][c1] - x[r1 - 1][c2] + x[r1 - 1][c1];
        res += y[r2][c2] - y[r2][c1 - 1] - y[r1][c2] + y[r1][c1 - 1];
        cout<<res<<nl;
    }

}
int main(){  
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    Solve();
}