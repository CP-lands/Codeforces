//--------Anivia_kid---------//
//-------did you test n = 1 ?-------//
//https://codeforces.com/contest/1272/problem/B
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
	int l = 0, r = 0, u = 0, d = 0;
	for(int i = 0; i < s.size(); i++){
		if(s[i] == 'L') l++;
		if(s[i] == 'R') r++;
		if(s[i] == 'U') u++;
		if(s[i] == 'D') d++;
	}
	int lr = min(l, r);
	int ud = min(u, d);
	if(lr == 0 && ud == 0){
		cout<<0<<"\n";
		return;
	}
	if(lr == 0){
		cout<<2<<"\n";
		cout<<"UD\n";
		return;
	}
	if(ud == 0){
		cout<<2<<"\n";
		cout<<"RL\n";
		return;
	}
	ll res = lr * 2 + ud * 2;
	cout<<res<<"\n";
	for(int i = 0; i < lr; i++)
		cout<<"R";
	for(int i = 0; i < ud; i++)
		cout<<"U";
	for(int i = 0; i < lr; i++)
		cout<<"L";
	for(int i = 0; i < ud; i++)
		cout<<"D";
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