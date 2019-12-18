//--------Anivia_kid---------//
//-------did you test n = 1 ?-------//
//https://codeforces.com/contest/1277/problem/C
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
	string a = "one";
	string b = "two";
	if(s.size() < 3){
		cout<<0<<"\n";
		return;
	}
	vector<int> res;
	string t = "";
	for(int i = 0; i < s.size() - 2; i++){
		t += s[i];
		t += s[i + 1];
		t += s[i + 2];
		if(t == "one"){
			res.pb(i + 2);
			i = i + 2;
		}
		else if(t == "two"){
			if(i + 3 < s.size() && s[i + 3] == 'o')
				res.pb(i + 2);
			else res.pb(i + 3);
			i = i + 2;
		}
		t = "";
	}
	cout<<res.size()<<"\n";
	for(auto x: res)
		cout<<x<<" ";
	cout<<"\n";
 
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