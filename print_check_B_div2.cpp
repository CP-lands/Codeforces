//------Anivia_kid----------
#include<bits/stdc++.h>
 
//https://codeforces.com/problemset/problem/271/B
using namespace std;
 
#define fi first
#define se second
typedef long long ll; 
const int MOD = 1e9 + 7;

void Anivia_kid(){
	int n, m, k;
	cin>>n>>m>>k;
	vector<vector<int>> x(n, vector<int>(2));
	vector<vector<int>> y(m, vector<int>(2));
	for(int j = 0; j < k; j++){
		int a, b, c;
		cin>>a>>b>>c;
		if(a == 1){
			x[b - 1][0] = c;
			x[b - 1][1] = j + 1;
		}
		else{
			y[b - 1][0] = c;
			y[b - 1][1] = j + 1;
		}
	}
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			if(x[i][1] > y[j][1])
				cout<<x[i][0]<<" ";
			else
				cout<<y[j][0]<<" ";
		}
		cout<<endl;
	}

	return;
}

int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	ios_base::sync_with_stdio(0);
	int q = 1;
	//cin>>q;
	while(q--){
		Anivia_kid();
	}
	return 0;
}
