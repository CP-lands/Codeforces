#include<bits/stdc++.h>

//https://codeforces.com/contest/348/problem/A 
using namespace std;
 
void Solve(){
    int n;
    cin>>n;
    vector<int> v(n);
    int maxx = 0;
    for(int i = 0; i < n; i++){
        cin>>v[i];
        if(maxx < v[i]) maxx = v[i];
    }
    long long dif = 0;
    for(int i = 0; i < n; i++)
        dif += maxx - v[i];
    if(dif >= maxx){
        cout<<maxx<<'\n';
        return;
    }
    int need = maxx - dif;
    if(need % (n - 1) == 0) cout<<maxx + need / (n - 1)<<'\n';
    else cout<<maxx + need / (n - 1) + 1<<'\n';
    //cout<<dif<<" "<<need<<'\n';
}
int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int q = 1;
    //cin>>q;
    while(q--){
    	Solve();
    }
}