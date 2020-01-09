//--------Anivia_kid---------//
//-------did you test n = 1 ?-------//
//https://codeforces.com/contest/1178/problem/E
#include<bits/stdc++.h>
 
using namespace std;
 
#define fi first
#define se second
#define pb push_back
#define eb emplace_back
 
typedef long long ll; 
const int MOD = 1e9 + 7;

void Anivia_kid(){
	string s;
	cin>>s;
	int i = 0;
	int j = s.size() - 1;
	string left = "";
	int sub = 0;
	while(j >= i){
		if(s[i] == s[j]){
			if(i == j) sub++;
			left += s[i];
			i++;
			j--;
		}
		else if(j - 1 >= i && s[i] == s[j - 1]){
			if(j - 1 == i) sub++;
			left += s[i];
			i++;
			j -= 2;
		}
		else if(i + 1 <= j && s[i + 1] == s[j]){
			if(i + 1 == j) sub++;
			left += s[i + 1];
			i += 2;
			j--;
		}
		else{
			i++;
			j--;
		}
	}
	if(left.size() * 2 - sub >= s.size() / 2){
		cout<<left;
		if(sub == 0){
			for(int i = left.size() - 1; i >= 0; i--)
				cout<<left[i];
		}
		else{
			for(int i = left.size() - 2; i >= 0; i--)
				cout<<left[i];
		}
	}
	else cout<<"IMPOSSIBLE\n";

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