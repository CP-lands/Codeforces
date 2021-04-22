#include<bits/stdc++.h>
//https://codeforces.com/contest/1485/problem/D
 
using namespace std;
 
#define fi first
#define se second
#define pb push_back
#define nl '\n'
#define bug cout<<"bug here"<<nl
typedef long long ll;
 
const int N = 720720;
 
void Solve(){
	int n, m;
	cin>>n>>m;
	vector<vector<int>> v(n, vector<int> (m));
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			cin>>v[i][j];
			if((i + j) % 2) v[i][j] = N;
			else v[i][j] = N + pow(v[i][j], 4);
		}
	}
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			cout<<v[i][j]<<" ";
		}
		cout<<nl;
	}
	
}
int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int T = 1;
	//cin>>T;
	while(T--){
		Solve();
	}
}