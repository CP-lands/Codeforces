//--------Anivia_kid---------//
//-------did you test n = 1 ?-------//
#include<bits/stdc++.h>
 
//https://codeforces.com/problemset/problem/101/A
using namespace std;
 
#define fi first
#define se second
#define pb push_back
typedef long long ll; 
const int MOD = 1e9 + 7;
const int MAXN = 1e5 + 100;

 
void Anivia_kid(){
	int k;
	string s;
	cin>>s>>k;
	if(k >= s.size()){
		cout<<0<<endl;
		return;
	}
	map<char, int> mp;
	for(int i = 0; i < s.size(); i++){
		++mp[s[i]];
	}
 	vector<vector<int>> v(mp.size(), vector<int>(2));
 	int i = 0;
 	for(auto x : mp){
 		v[i][0] = x.se;
 		v[i++][1] = (int)x.fi;
 	}
 	sort(v.begin(), v.end());
 	set<char> rej;
 	for(i = 0; i < v.size(); i++){
 		if(k >= v[i][0]){
 			k -= v[i][0];
 			rej.insert((char)v[i][1]);
 		}
 		else break;
 	}
 	cout<<v.size() - rej.size()<<endl;
 	for(auto x : s)
 		if(rej.find(x) == rej.end())
 			cout<<x;

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
	return 0;
}
