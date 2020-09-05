#include<bits/stdc++.h>

//https://codeforces.com/contest/1365/problem/E
using namespace std;

void Solve(){
	int n;
	cin>>n;
	vector<long long> v(n);
	for(int i = 0; i < n; i++)
		cin>>v[i];
	long long res = 0;
	for(int i = 0; i < n; i++){
		for(int j = i; j < n; j++){
			for(int k = j; k < n; k++){
				long long tmp = v[i] | v[j];
				tmp = tmp | v[k];
				res = max(res, tmp);
			}
		}
	}
	cout<<res<<'\n';
}
int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int T = 1;
	//cin>>T;
	while(T--){
		Solve();
	}
}