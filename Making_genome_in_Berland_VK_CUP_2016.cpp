//--------Anivia_kid---------//
//-------did you test n = 1 ?-------//
//https://codeforces.com/contest/638/problem/B
#include<bits/stdc++.h>
 
using namespace std;
 
#define fi first
#define se second
#define pb push_back

typedef long long ll; 
const int MOD = 1e9 + 7;

void Anivia_kid(){
	int n;
	cin>>n;
	vector<int> val(123);
	int in[123];
	int out[123];
	for(int i = 97; i < 123; i++){
		in[i] = -1;
		out[i] = -1;
	}
	for(int i = 0; i < n; i++){
		string s;
		cin>>s;
		if(s.size() == 1){
			int k = s[0];
			if(in[k] == -1) in[k] = 0;
			if(out[k] == -1) out[k] = 0;
		}
		for(int i = 0; i < s.size() - 1; i++){
			int u = s[i];
			int v = s[i + 1];
			val[u] = v;
			in[v] = 1;
			out[u] = 1;
		}
	}
	vector<int> beginn;
	vector<int> alone;
	for(int i = 97; i < 123; i++){
		if(out[i] == 1 && in[i] != 1) beginn.pb(i);
		if(in[i] == 0 && out[i] == 0) alone.pb(i);
	}

	string res = "";
	for(auto x: beginn){
		char c = x;
		res += c;
		while(out[x] == 1){
			c = val[x];
			res += c;
			x = val[x];
		}
	}
	for(auto x: alone){
		char c = x;
		res += c;
	}
	cout<<res<<"\n";

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
