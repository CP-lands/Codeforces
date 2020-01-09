//--------Anivia_kid---------//
//-------did you test n = 1 ?-------//
//https://codeforces.com/contest/1269/problem/C
#include<bits/stdc++.h>
 
using namespace std;
 
#define fi first
#define se second
#define pb push_back
#define eb emplace_back
 
typedef long long ll; 
const int MOD = 1e9 + 7;

void Anivia_kid(){
	int n, k;
	string s;
	cin>>n>>k>>s;
	string res = s.substr(0, k);
	for(int i = k; i < n; i++)
		res += res[i - k];
	cout<<n<<'\n';
	if(res >= s){
		cout<<res<<'\n';
		return;
	}
	for(int i = k - 1; i >= 0; i--){
		if(res[i] != '9'){
			int tmp = res[i] - '0' + 1;
			for(int j = i; j < n; j = j + k){
				res[j] = tmp + '0';
			}
			cout<<res<<'\n';
			return;
		}
		if(res[i] == '9'){
			for(int j = i; j < n; j = j + k){
				res[j] = '0';
			}
		}
	}

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