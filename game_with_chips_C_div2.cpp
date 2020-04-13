#include<bits/stdc++.h>
 
//https://codeforces.com/contest/1327/problem/C
using namespace std;
 
void Solve(){
    int n, m, k;
    cin>>n>>m>>k;
    string res = "";
    for(int i = 0; i < n - 1; i++){
        res += 'U';
    }
    for(int i = 0; i < m - 1; i++){
        res += 'L';
    }
    int i = 0;
    int count = 0;
    while(i < n){
        for(int j = 0; j < m - 1; j++) res += 'R';
        count++;
        if(count == n) break;
        res += 'D';
        for(int j = m - 2; j >= 0; j--) res += 'L';
        count++;
        if(count == n) break;
        res += 'D';
        i++;
    }
    cout<<res.size()<<'\n';
    cout<<res<<'\n';
}
int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int q = 1;           
    //cin>>q;
    while(q--){
    	Solve();
    }
}