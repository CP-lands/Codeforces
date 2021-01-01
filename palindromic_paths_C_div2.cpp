#include<bits/stdc++.h>
 
//https://codeforces.com/contest/1366/problem/C
using namespace std;
 
void Solve(){
	int n, m;
	cin>>n>>m;
	vector<vector<int>> v(n, vector<int>(m));
	vector<int> one(1000), zero(1000);
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			cin>>v[i][j];
			int x = i + j;
			int y = n - i - 1 + m - j - 1;
			if(x == y) continue;
			if(v[i][j] == 0) zero[x]++;
			else one[x]++;
		}
	}
	int res = 0;
	int low = 0, high = m + n - 2;
	while(low < high){
		int onee = zero[low] + zero[high];
		int zeroo = one[low] + one[high];
		res += min(onee, zeroo);
		low++;
		high--;
	}
	cout<<res<<'\n';
}
int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int T = 1;
	cin>>T;
	while(T--){
		Solve();
	}
}