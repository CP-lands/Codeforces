#include<bits/stdc++.h>

//https://codeforces.com/contest/1174/problem/D 
using namespace std;
 
void Solve(){
    int n, k;
    cin>>n>>k;
    vector<int> res;
    vector<bool> visited(1<<n);
    if(k >= (int)1<<n){
        for(int i = 0; i < (1<<n); i++) res.push_back(i);
    }
    else{
        for(int i = 0; i < (1<<n); i++){
            if(visited[i]) continue;
            res.push_back(i);
            visited[i] = true;
            visited[i ^ k] = true;
        }
    }
    cout<<res.size() - 1<<'\n';
    for(int i = 0; i < res.size() - 1; i++){
        int x = res[i + 1] ^ res[i];
        cout<<x<<" ";
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