//--------Anivia_kid---------//
//-------did you test n = 1 ?-------//
//https://codeforces.com/contest/1271/problem/B
#include<bits/stdc++.h>
 
using namespace std;
 
#define fi first
#define se second
#define pb push_back
 
typedef long long ll; 
const int MOD = 1e9 + 7;
 
void Anivia_kid(){
	int n;
	string s;
	cin>>n>>s;
	vector<int> res;
	int i = 1;
	char c = s[0];
	while(i < s.size() - 1){
		if(s[i] != c){
			res.pb(i + 1);
			s[i] = c;
			if(s[i + 1] == 'B') s[i + 1] = 'W';
			else s[i + 1] = 'B';
		}
		i++;
	}
	if(s[n - 1] == c){
		cout<<res.size()<<"\n";
		for(auto x: res)
			cout<<x<<" ";
		cout<<"\n";
		return;
	}
	else{
		if(s.size() % 2 != 0){
			for(int i = 1; i < s.size(); i = i + 2)
				res.pb(i);
			cout<<res.size()<<"\n";
			for(auto x: res)
				cout<<x<<" ";
			return;
		}
	}
	cout<<-1<<"\n";
 
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