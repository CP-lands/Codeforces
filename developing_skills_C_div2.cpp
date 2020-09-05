//--------Anivia_kid---------//
//-------did you test n = 1 ?-------//
#include<bits/stdc++.h>
 
//https://codeforces.com/problemset/problem/581/C
using namespace std;
 
#define fi first
#define se second
#define pb push_back
typedef long long ll; 
const int MOD = 1e9 + 7;
const int MAXN = 1e5 + 100;
 
void Anivia_kid(){
	int n, k;
	cin>>n>>k;
	vector<int> v(n);
	for(int i = 0; i < n; i++)
		cin>>v[i];
	vector<vector<int>> a(n, vector<int>(2));
	for(int i = 0; i < n; i++){
		a[i][0] = (10 - v[i] % 10);
		a[i][1] = v[i] / 10;
	}
	sort(a.begin(), a.end());
	int res = 0;
	for(int i = 0; i < n; i++){
		if(k >= a[i][0]){
			k -= a[i][0];
			res += a[i][1] + 1;
		}
		else res += a[i][1];
	}
	if(k > 0){
		res += k / 10;
	}
	res = min(res, n * 10);
	cout<<res<<endl;

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
