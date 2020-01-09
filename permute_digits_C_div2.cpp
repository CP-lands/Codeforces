//--------Anivia_kid---------//
//-------did you test n = 1 ?-------//
//https://codeforces.com/problemset/problem/915/C
#include<bits/stdc++.h>
 
using namespace std;
 
#define fi first
#define se second
#define pb push_back
#define eb emplace_back
 
typedef long long ll; 
const int MOD = 1e9 + 7;

void Anivia_kid(){
	string a, b;
	cin>>a>>b;
	sort(a.begin(), a.end());
	if(a.size() < b.size()){
		for(int i = a.size() - 1; i >= 0; i--){
			cout<<a[i];
		}
		return;
	}
	map<char, int> mp;
	for(int i = 0; i < a.size(); i++){
		++mp[a[i]];
	}
	string res = "";
	bool change = false;
	for(int i = 0; i < a.size(); i++){
		char c = b[i];
		char k = '0';
		for(auto x: mp){
			if(change){
				if(k < x.fi && x.se > 0) k = x.fi;
			}
			else{
				if(k < x.fi && x.fi <= c && x.se > 0){
					string tmp = "";
					for(auto y: mp){
						if(y.fi != x.fi){
							for(int i = 0; i < y.se; i++) tmp += y.fi;
						}
						else{
							for(int i = 0; i < y.se - 1; i++) tmp += y.fi;
						}
					}
					sort(tmp.begin(), tmp.end());
					tmp = res + x.fi + tmp;
					if(tmp <= b) k = x.fi;
				}
			}
		}
		mp[k]--;
		res += k;
		if(k < c) change = true;
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