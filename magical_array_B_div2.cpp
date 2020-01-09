//--------Anivia_kid---------//
//https://codeforces.com/contest/84/problem/B
#include<bits/stdc++.h>
 
using namespace std;
 
#define fi first
#define se second
#define pb push_back
#define eb emplace_back
 
typedef long long ll; 
const int MOD = 1e9 + 7;

ll dp[100005];

void Anivia_kid(){
	int n;
	cin>>n;
	vector<int> v(n);
	for(int i = 0; i < n; i++) cin>>v[i];
	dp[0] = 0;
	for(int i = 1; i < 100005; i++){
		dp[i] = dp[i - 1] + i;
	}
	ll res = 0;
	int i = 0;
	while(i < n - 1){
		int count = 1;
		while(i < n - 1 && v[i] == v[i + 1]){
			i++;
			count++;
		}
		res += dp[count];
		i++;
	}
	if(n == 1 || v[n - 1] != v[n - 2]) res++;
	cout<<res<<'\n';

	return;
}
 
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int q = 1;
	//cin>>q;
	while(q--){
		Anivia_kid();
	}
}