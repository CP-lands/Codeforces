#include<bits/stdc++.h>
 
//https://codeforces.com/contest/1348/problem/C
using namespace std;
 
void Solve(){
    int n, k;
    string s;
    cin>>n>>k>>s;
    sort(s.begin(), s.end());
    if(k == 1){
        cout<<s<<'\n';
        return;
    }
    string res = "";
 
    if(s[k - 1] > s[0]){
        cout<<s[k - 1]<<'\n';
        return;
    }
    res += s[0];
    set<char> ss;
    for(int i = k; i < n; i++){
        ss.insert(s[i]);
        res += s[i];
    }
    if(ss.size() > 1){
        cout<<res<<'\n';
        return;
    }
    else{
        string ans = "";
        ans += s[0];
        int t;
        if((n - k) % k == 0) t = (n - k) / k;
        else t = (n - k) / k + 1;
        for(int i = k; i < k + t; i++) ans += s[i];
        cout<<ans<<'\n';
        return;
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