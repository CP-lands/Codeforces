#include<bits/stdc++.h>
 
//https://codeforces.com/contest/1316/problem/C
using namespace std;
 
void Solve(){
	int n, m, p;
	cin>>n>>m>>p;
	vector<int> a(n), b(m);
	int res = -1;
	for(int i = 0; i < n; i++){
		cin>>a[i];
		if(res == -1 && a[i] % p != 0) res = i;
	}
	for(int i = 0; i < m; i++){
		cin>>b[i];
		if(b[i] % p != 0){
			res += i;
			break;
		}
	}
	cout<<res<<'\n';
 
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
    return 0;
}