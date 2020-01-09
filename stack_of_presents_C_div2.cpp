//--------Anivia_kid---------//
//https://codeforces.com/contest/1279/problem/C
#include<bits/stdc++.h>

using namespace std;
 
#define fi first
#define se second
#define pb push_back
#define eb emplace_back
 
typedef long long ll; 
const int MOD = 1e9 + 7;

int s[100005];

void Anivia_kid(){
	int n, m;
	cin>>n>>m;
	vector<int> v(n), pres(m);
	for(int i = 0; i < n; i++){
		cin>>v[i];
		s[v[i]] = i;
	}
	for(int i = 0; i < m; i++)
		cin>>pres[i];
	int max_index = 0;
	ll res = 0;
	int count = 0;
	for(int i = 0; i < m; i++){
		int x = s[pres[i]];
		if(x < max_index) res++;
		else{
			res += 2 * (x - count) + 1;
			max_index = x;
		}
		count++;
	}
	cout<<res<<'\n';

	return;
}
 
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int q;
	cin>>q;
	while(q--){
		Anivia_kid();
	}
}