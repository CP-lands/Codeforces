#include<bits/stdc++.h>
 
using namespace std;
//https://codeforces.com/contest/1517/problem/B
 
#define fi first
#define se second
#define pb push_back
#define nl '\n'
#define bug cout<<"bug here!"<<nl
typedef long long ll;
 
void Solve(){
    int n, m;
    cin>>n>>m;
    vector<vector<int>> v(n, vector<int> (m));
    vector<int> k (n * m);
    int idx = 0;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin>>v[i][j];
            k[idx++] = v[i][j];
        }
        sort(v[i].begin(), v[i].end());
    }
    sort(k.begin(), k.end());
    map<int, int> cnt;
    for(int i = 0; i < m; i++){
        ++cnt[k[i]];
    }
 
    vector<vector<int>> res(n, vector<int> (m));
    vector<bool> vst(m);
    for(int i = 0; i < n; i++){
        int low = 0, high = m - 1;
        for(int j = 0; j < m; j++){
            if(vst[j]){
                cout<<v[i][high--]<<" ";
            }
            else{
                if(v[i][low] <= k[m - 1] && cnt[v[i][low]] > 0){
                    cnt[v[i][low]]--;
                    vst[j] = true;
                    cout<<v[i][low++]<<" ";
                }
                else{
                    cout<<v[i][high--]<<" ";
                }
            }
        }
        cout<<nl;
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