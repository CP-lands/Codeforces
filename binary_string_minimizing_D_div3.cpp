//------Anivia_kid----------
#include<bits/stdc++.h>
 
//https://codeforces.com/problemset/problem/1256/D
using namespace std;
 
#define fi first
#define se second
typedef long long ll; 
const int MOD = 1e9 + 7;

int v[101];
void Anivia_kid(){
	ll n, k;
	string s;
	cin>>n>>k>>s;
	int ini;
	int i = 0;
	while(i < n && s[i] == '0') i++;
	ini = i;
	while(i < n){
		while(i < n && s[i] == '1') i++;
		if(i >= n) break;
		if(k >= i - ini){
			k -= i - ini;
			s[ini] = '0';
			s[i] = '1';
		}
		else if(k < i - ini){
			s[i] = '1';
			s[i - k] = '0';
			break;
		}
		ini++;
		if(k <= 0) break;
	}
	cout<<s<<endl;

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
	return 0;
}
