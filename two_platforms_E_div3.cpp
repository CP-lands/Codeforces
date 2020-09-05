#include<bits/stdc++.h>

//https://codeforces.com/contest/1409/problem/E
using namespace std;

void Solve(){
    int n, k;
    cin>>n>>k;
    vector<int> v(n), y(n);
    for(int i = 0; i < n; i++)
        cin>>v[i];
    for(int i = 0; i < n; i++)
        cin>>y[i];
    sort(v.begin(), v.end());
    map<int, int> mm;
    for(auto x: v)
        ++mm[x];
    map<int, int> prefix;
    vector<int> a;
    for(auto x: mm)
        a.push_back(x.first);
    int pre = 0;
    for(auto x: mm){
        prefix[x.first] = x.second + pre;
        pre = prefix[x.first];
    }
    int res = 0;
    map<int, int> mx;
    int maxx = 0;
    for(int i = a.size() - 1; i >= 0; i--){
        int pr = 0;
        if(i > 0) pr = prefix[a[i - 1]];
        int suf = 0;
        int b = a[i] + k;
        int x = upper_bound(a.begin(), a.end(), b) - a.begin();
        x--;
        suf = prefix[a[x]];
        maxx = max(maxx, suf - pr);
        mx[a[i]] = maxx;
        //cout<<a[i]<<" "<<mx[a[i]]<<endl;
    }
    for(int i = 0; i < a.size(); i++){
        int pr = 0;
        if(i > 0){
            pr = prefix[a[i - 1]];
        }
        int suf = 0;
        int x = upper_bound(a.begin(), a.end(), a[i] + k) - a.begin();
        x--;
        suf = prefix[a[x]];
        int ans = suf - pr;
        x++;
        if(x < a.size())
            ans += mx[a[x]];
        res = max(res, ans);
    }
    cout<<res<<'\n';
}
int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T = 1;
    cin>>T;
    while(T--){
        Solve();
    }
}