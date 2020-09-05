#include<bits/stdc++.h>
 
 //https://codeforces.com/contest/1399/problem/D
using namespace std;
 
void Solve(){
    int n;
    string s;
    cin>>n>>s;
    vector<int> res(n);
    int ans = 0;
    set<int> s1, s0;
    for(int i = 0; i < n; i++){
        if(s[i] == '0'){
            if(s1.empty()){
                s1.insert(++ans);
            }
            int k = *s1.begin();
            s1.erase(s1.begin());
            s0.insert(k);
            res[i] = k;
        }
        else{
            if(s0.empty()){
                s0.insert(++ans);
            }
            int k = *s0.begin();
            s0.erase(s0.begin());
            s1.insert(k);
            res[i] = k;
        }
    }
    cout<<ans<<'\n';
    for(auto x: res) cout<<x<<" ";
    cout<<'\n';
 
}
int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T = 1;
    cin>>T;
    while(T--){
        Solve();
    }
}