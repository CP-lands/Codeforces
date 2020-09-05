//------Anivia_kid----------
#include<bits/stdc++.h>
 
//https://codeforces.com/problemset/problem/271/B
using namespace std;
 
#define fi first
#define se second
typedef long long ll; 
const int MOD = 1e9 + 7;
 
void Anivia_kid(){
	int n, m;
	cin>>n>>m;
	vector<vector<int>> v(n, vector<int>(m));
	for(int i = 0; i < n; i++)
		for(int j = 0; j < m; j++)
			cin>>v[i][j];
	vector<int> prime;
	for(int i = 2; i < 100000; i++)
		if(isPrime(i))
			prime.push_back(i);
	int i = 100001;
	while(true){
		if(isPrime(i)){
			prime.push_back(i);
			break;
		}
		i++;
	}
	for(int i = 0; i < n; i++)
		for(int j = 0; j < m; j++){
			int p = lower_bound(prime.begin(), prime.end(), v[i][j]) - prime.begin();
			v[i][j] = prime[p] - v[i][j];
		}

	int res = INT_MAX;
	int tmp;
	for(int i = 0; i < n; i++){
		tmp = 0;
		for(int j = 0; j < m; j++){
			tmp += v[i][j];
		}
		if(res > tmp) res = tmp;
	}
	for(int i = 0; i < m; i++){
		tmp = 0;
		for(int j = 0; j < n; j++){
			tmp += v[j][i];
		}
		if(res > tmp) res = tmp;
	}
	cout<<res<<endl;
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
