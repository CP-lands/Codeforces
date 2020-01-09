//--------Anivia_kid---------//
//-------did you test n = 1 ?-------//
//https://codeforces.com/contest/1278/problem/C
#include<bits/stdc++.h>
 
using namespace std;
 
#define fi first
#define se second
#define pb push_back
#define eb emplace_back
 
typedef long long ll; 
const int MOD = 1e9 + 7;

void Anivia_kid(){
	map<int, int> mpl, mpr;
	int n;
	cin>>n;
	int one = 0, two = 0;
	vector<int> l(n + 1), r(n + 1), k(n + 1);
	int count = 0;
	for(int i = 1; i <= n; i++){
		int x;
		cin>>x;
		if(x == 1){
			one++;
			count++;
		}
		else{
			count--;
			two++;
		}
		l[i] = count;
		mpl[count] = i;
	}
	for(int i = n; i > 0; i--)
		cin>>k[i];
	count = 0;
	for(int i = 1; i <= n; i++){
		if(k[i] == 1){
			one++;
			count++;
		}
		else{
			two++;
			count--;
		}
		r[i] = count;
		mpr[count] = i;
	}
	if(one == 0 || two == 0){
		cout<<2 * n<<'\n';
		return;
	}
	if(one == two){
		cout<<0<<'\n';
		return;
	}
	int res = INT_MAX;
	for(auto x: mpl){
		if(mpr[-x.fi] != 0){
			int tmp = n - x.se + n - mpr[-x.fi];
			if(res > tmp) res = tmp;
		}
		else if(x.fi == 0){
			int tmp = n - x.se + n;
			if(res > tmp) res = tmp;
		}
	}
	for(auto x: mpr){
		if(x.fi == 0 && x.se > 0){
			int tmp = n - x.se + n;
			if(res > tmp) res = tmp;
		}
	}
	if(res == INT_MAX) cout<<2 * n<<'\n';
	else cout<<res<<'\n';

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