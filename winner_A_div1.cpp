#include<bits/stdc++.h>
 
//https://codeforces.com/contest/2/problem/A
using namespace std;
 
void Solve(){
    int n;
    cin>>n;
    map<string, int> mm;
    vector<pair<string, int>> v(n);
    for(int i = 0; i < n; i++){
        string k;
        int score;
        cin>>k>>score;
        mm[k] += score;
        v[i].first = k;
        v[i].second = mm[k];
    }
    int max_score = 0;
    for(auto x: mm){
        if(x.second > max_score) max_score = x.second;
    }
    for(auto x: v){
        if(mm[x.first] == max_score && x.second >= max_score){
            cout<<x.first<<'\n';
            return;
        }
    }
}
int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    Solve();
}