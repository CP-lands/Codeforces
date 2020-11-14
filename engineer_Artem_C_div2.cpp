#include<bits/stdc++.h>
 
//https://codeforces.com/contest/1438/problem/C
using namespace std;
 
void Solve(){
    int n, m;
    cin>>n>>m;
    vector<vector<int>> v(n, vector<int> (m));
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++)
            cin>>v[i][j];
    }
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(i % 2){
                if(j % 2){
                    if(v[i][j] % 2) v[i][j]++;
                }
                else{
                    if(!(v[i][j] % 2))v[i][j]++;
                }
            }
            else{
                if(!(j % 2)){
                    if(v[i][j] % 2) v[i][j]++;
                }
                else{
                    if(!(v[i][j] % 2))v[i][j]++;
                }              
            }
            cout<<v[i][j]<<" ";
        }
        cout<<'\n';
    }
 
}
int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T = 1;
    cin>>T;
    while(T--){
        Solve();
    }
}