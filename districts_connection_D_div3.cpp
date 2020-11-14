#include<bits/stdc++.h>
 
//https://codeforces.com/contest/1433/problem/D
using namespace std;
 
void Solve(){
    int n;
    cin>>n;
    vector<int> v(n);
    map<int, int> myMap;
    for(int i = 0; i < n; i++){
        cin>>v[i];
        ++myMap[v[i]];
    }
    if(myMap.size() == 1){
        cout<<"NO\n";
        return;
    }
    cout<<"YES\n";
    vector<pair<int, int>> res;
    int ans;
    int count = INT_MAX;
    for(auto x: myMap){
        if(x.second < count){
            count = x.second;
            ans = x.first;
        }
    }
    int root = 0;
    queue<int> rest;
    for(int i = 0; i < n; i++){
        if(v[i] == ans && !root){
            root = i + 1;
        }
        else if(v[i] == ans) rest.push(i + 1);
    }
    //cout<<ans<<" "<<root<<"---"<<endl;
    for(int i = 0; i < n; i++){
        if(v[i] != ans){
            res.push_back({root, i + 1});
            if(!rest.empty()){
                int current = rest.front();
                rest.pop();
                res.push_back({i + 1, current});
            }
        }
    }
    for(auto x: res) cout<<x.first<<" "<<x.second<<'\n';
 
}
int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T = 1;
    cin>>T;
    while(T--){
        Solve();
    }
}