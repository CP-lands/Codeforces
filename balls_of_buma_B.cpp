//--------Anivia_kid---------//
//-------did you test n = 1 ?-------//
//https://codeforces.com/contest/1267/problem/B
#include<bits/stdc++.h>
 
using namespace std;
 
#define fi first
#define se second
#define pb push_back
 
typedef long long ll; 
const int MOD = 1e9 + 7;
 
void Anivia_kid(){
	string s;
	cin>>s;
	string sub = "";
	map<char, int> mp;
	vector<int> res;
 
	for(int i = 0; i < s.size() - 1; i++){
		if(s[i] != s[i + 1]){
			sub += s[i];
		}
	}
	sub += s[s.size() - 1];
	string s1 = "";
	for(int i = sub.size() - 1; i >= 0; i--)
		s1 += sub[i];
	if(sub != s1){
		cout<<0<<"\n";
		return;
	}
	//--------------------
	int i = 0;
	while(i < s.size() - 1){
		int tmp = 1;
		while(i < s.size() - 1 && s[i] == s[i + 1]){
			tmp++;
			i++;
		}
		res.pb(tmp);
		i++;
	}
	if(s[s.size() - 1] != s[s.size() - 2]) res.pb(1);
 
	for(int i = 0; i < res.size() / 2; i++){
		if(res[i] + res[res.size() - i - 1] < 3){
			cout<<0<<"\n";
			return;
		}
	}
	if(res[res.size() / 2] < 2){
		cout<<0<<"\n";
  		return;
	}
	cout<<res[res.size() / 2] + 1<<"\n";
 
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