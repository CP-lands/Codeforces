//--------Anivia_kid---------//
//-------did you test n = 1 ?-------//
//https://codeforces.com/contest/729/problem/D
#include<bits/stdc++.h>
 
using namespace std;
 
#define fi first
#define se second
#define pb push_back

typedef long long ll; 
const int MOD = 1e9 + 7;

void Anivia_kid(){
	int n, m, d, k;
	string s;
	cin>>n>>m>>d>>k>>s;
	int i = 0;
	vector<pair<int, int>> v;
	while(i < s.size()){
		if(s[i] == 1) continue;
		int j = i + 1;
		int tmp = 0;
		while(i < s.size() && s[i] == '0'){
			tmp++;
			i++;
		}
		if(tmp >= d) v.pb({j, tmp});
		i++;
	}
	vector<int> res;
	for(auto x: v){
		for(i = 0; i < x.se / d; i++)
			res.pb(x.fi + d - 1 + i * d);
	}
	cout<<res.size() - m + 1<<"\n";
	for(i = 0; i < res.size() - m + 1; i++)
		cout<<res[i]<<" ";

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
