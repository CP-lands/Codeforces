//------Anivia_kid----------
#include<bits/stdc++.h>
 
using namespace std;
 
#define fi first
#define se second
typedef long long ll; 
const int MOD = 1e9 + 7;
 
void Anivia_kid(){
	vector<ll> fibonaci(100001);
	fibonaci[1] = 1;
	fibonaci[2] = 2;
	for(int i = 3; i <= 100000; i++)
		fibonaci[i] = (fibonaci[i - 1] + fibonaci[i - 2]) % MOD;
	string s;
	cin>>s;
	ll res = 1;
	int tmp = 0;
	int i = 0;
	while(i < s.size()){
		tmp = 1;
		if(s[i] == 'w' || s[i] == 'm'){
			cout<<0<<endl;
			return;
		}
		while(i < s.size() - 1 && s[i] == 'u' && s[i + 1] == 'u'){
			tmp++;
			i++;
		}
		res *= fibonaci[tmp];
		res = res % MOD;
		tmp = 1;
		while(i < s.size() - 1 && s[i] == 'n' && s[i + 1] == 'n'){
			tmp++;
			i++;
		}
		
		res *= fibonaci[tmp];
		res = res % MOD;
		i++;
	}
	cout<<res<<endl;
 
	return;
}
 
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	ios_base::sync_with_stdio(0);
	int q = 1;
	//cin>>q;
	while(q--){
		Anivia_kid();
	}
	return 0;
}
