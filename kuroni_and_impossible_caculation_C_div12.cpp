#include<bits/stdc++.h>
 
//https://codeforces.com/contest/1305/problem/C
using namespace std;
 
void Solve(){
	int n, m;
	cin>>n>>m;
	vector<int> v(n);
	for(int i = 0; i < n; i++)
		cin>>v[i];
	long long res = 1;
	if(n >= 1000){
		cout<<0<<'\n';
		return;
	}
	for(int i = 0; i < n; i++){
		for(int j = i + 1; j < n; j++){
			res *= abs(v[i] - v[j]);
			res = res % m;
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
}