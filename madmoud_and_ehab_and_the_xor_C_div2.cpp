#include<bits/stdc++.h>
 
//https://codeforces.com/contest/862/problem/C
using namespace std;
 
void Solve(){
    int n, x;
    cin>>n>>x;
    vector<int> v(n);
    if(n == 2 && x == 0){
        cout<<"NO\n";
        return;
    }
    cout<<"YES\n";
    if(n == 1) cout<<x<<'\n';
    if(n == 2){
        cout<<0<<" "<<x<<'\n';
    }
    if(n >= 3){
        int k = 0;
        for(int i = 0; i < n - 3; i++){
            v[i] = i + 1;
            k = k ^ v[i];
        }
        if(k == x){
            v[n - 3] = 1<<17;
            v[n - 2] = 1<<18;
            v[n - 1] = v[n - 2] ^ v[n - 3];
        }
        else{
            v[n - 3] = 0;
            v[n - 2] = 1<<17;
            v[n - 1] = v[n - 2] ^ k;
            v[n - 1] = v[n - 1] ^ x;
        }
        for(auto y: v) cout<<y<<" ";
    }
 
	return;
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