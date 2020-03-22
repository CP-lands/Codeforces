#include<bits/stdc++.h>
 
//https://codeforces.com/contest/891/problem/A
using namespace std;
 
void Solve(){
    int n;
    cin>>n;
    vector<int> v(n);
    int onee = 0;
    for(int i = 0; i < n; i++){
        cin>>v[i];
        if(v[i] == 1) onee++;
    }
    if(n == 1){
        if(v[0] == 1) cout<<0<<'\n';
        else cout<<-1<<'\n';
        return;
    }
    if(onee > 0){
        cout<<n - onee<<'\n';
        return;
    }
    int k = __gcd(v[0], v[1]);
    for(int i = 2; i < n; i++)
        k = __gcd(k, v[i]);
    if(k > 1){
        cout<<-1<<'\n';
        return;
    }
    int res = INT_MAX;
    for(int i = 0; i < n - 1; i++){
        k = __gcd(v[i], v[i + 1]);
        if(k == 1){
            res = n;
        }
        for(int j = i + 2; j < n; j++){
            k = __gcd(k, v[j]);
            if(k == 1){
                int tmp = (j - i) + n - 1;
                if(res > tmp) res = tmp;
                //cout<<i<<" "<<j<<" "<<tmp<<'\n';
            }
        }
    }
    cout<<res<<'\n';
}
int main(){
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int q = 1;
    //cin>>q;
    while(q--){
    	Solve();
    }
}