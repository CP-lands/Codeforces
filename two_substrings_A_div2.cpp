//--------Anivia_kid---------//
//-------did you test n = 1 ?-------//
//https://codeforces.com/problemset/problem/550/A
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
	bool ab = false;
	bool ba = false;
	//case1: ab left and ba right
	for(int i = 0; i < s.size() - 1; i++){
		if(!ab && s[i] == 'A' && s[i + 1] == 'B'){
			ab = true;
			i++;
		}
		else if(ab && s[i] == 'B' && s[i + 1] == 'A'){
			ba = true;
		}
	}
	if(ab && ba){
		cout<<"YES\n";
		return;
	}
	//case2:
	ab = false;
	ba = false;
	for(int i = 0; i < s.size() - 1; i++){
		if(!ba && s[i] == 'B' && s[i + 1] == 'A'){
			ba = true;
			i++;
		}
		else if(ba && s[i] == 'A' && s[i + 1] == 'B'){
			ab = true;
		}
	}
	if(ab && ba) cout<<"YES\n";
	else cout<<"NO\n";

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
