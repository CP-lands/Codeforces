#include<bits/stdc++.h>
 
//https://codeforces.com/contest/1330/problem/C
using namespace std;
 
long long maxx(long long a, long long b){
    if(a >= b) return a;
    else return b;
}
void Solve(int a){
    int n, m;
    cin>>n>>m;
    vector<int> v(m);
    long long sum = 0;
    for(int i = 0; i < m; i++){
        cin>>v[i];
        sum += v[i];
    }
    vector<int> res(m);
    int low = 0;
    for(int i = 0; i < m; i++){
        if(sum < n - low || v[i] > n - low){
            cout<<-1<<'\n';
            return;
        }
        res[i] = low + 1;
        int k = low + v[i];
        sum -= v[i];
        low = maxx(n - sum, low + 1);
    }
    for(auto x: res) cout<<x<<" ";
 
}
int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int q = 1;
    //cin>>q;
    for(int a = 1; a <= q; a++){
        Solve(a);
    }
}