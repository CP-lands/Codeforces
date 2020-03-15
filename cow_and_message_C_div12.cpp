//--------Anivia_kid---------//
//-------did you test n = 1 ?-------//
//https://codeforces.com/contest/1307/problem/C
#include<bits/stdc++.h>
 
using namespace std;
 
#define fi first
#define se second
#define pb push_back
 
typedef long long ll; 
const int MOD = 1e9 + 7;
const int MAXN = 1e5 + 100;
 
void Anivia_kid(){
	string s;
	cin>>s;
	map<char, int> mppp;
	int n = s.size();
	for(int i = 0; i < n; i++){
		++mppp[s[i]];
	}
	int maxx = 1;
	for(auto x: mppp){
		if(maxx < x.se) maxx = x.se;
	}
	map<char, int> mp;
	for(char c = 'a'; c <= 'z'; c++)
		mp[c] = 0;
	for(int i = 0; i < n; i++){
		mp[s[i]]++;
	}
	int i = 0;
	ll res = 1;
	map<string, ll> mm;
	while(i < n){
		mp[s[i]]--;
		for(char j = 'a'; j <= 'z'; j++){
			string tmp = "";
			tmp += s[i];
			tmp += j;
			mm[tmp] += mp[j];
		}
		i++;
	}
	for(auto x: mm){
		if(res < x.se) res = x.se;
	}
	if(res < maxx) res = maxx;
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