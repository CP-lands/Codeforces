
//--------Anivia_kid---------//
//-------did you test n = 1 ?-------//
//https://codeforces.com/contest/1178/problem/C
#include<bits/stdc++.h>
 
using namespace std;
 
#define fi first
#define se second
#define pb push_back
#define eb emplace_back
 
typedef long long ll; 
const int MOD = 1e9 + 7;
 
void Anivia_kid(){
	ll w, h;
	cin>>w>>h;
	ll res = 4;
	for(int i = 2; i <= h; i++){
		res *= 2;
		if(res >= 998244353) res -= 998244353;
	}
	for(int i = 2; i <= w; i++){
		res *= 2;
		if(res >= 998244353) res -= 998244353;
	}
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