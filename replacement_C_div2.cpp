//--------Anivia_kid---------//
#include<bits/stdc++.h>
 
//https://codeforces.com/problemset/problem/136/C?locale=en
using namespace std;
 
#define fi first
#define se second
#define pb push_back
typedef long long ll; 
const int MOD = 1e9 + 7;
const int MAXN = 1e5 + 100;
 
void Anivia_kid(){
	int n;
	cin>>n;
	vector<int> v(n);
	for(int i = 0; i < n; i++)
		cin>>v[i];
	sort(v.begin(), v.end());
	if(n == 1){
		if(v[0] != 1){
			cout<<1<<endl;
			return;
		}
		else{
			cout<<2<<endl;
			return;
		}
	}
	vector<int> res(n);
	res[0] = 1;
	for(int i = 1; i < n; i++){
		if(v[i] != v[i - 1]) res[i] = v[i - 1];
		else if((i == n - 1 && v[i] == 1)) res[i] = 2;
		else res[i] = v[i - 1];
	}
	for(auto x : res)
		cout<<x<<" ";
 
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
	return 0;
}
