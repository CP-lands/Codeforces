//--------Anivia_kid---------//
//-------did you test n = 1 ?-------//
//https://codeforces.com/contest/1263/problem/A
#include<bits/stdc++.h>
 
using namespace std;
 
#define fi first
#define se second
#define pb push_back
#define mp make_pair
typedef long long ll; 
const int MOD = 1e9 + 7;
const int MAXN = 1e5 + 100;
 
void Anivia_kid(){
	vector<int> v(3);
	for(int i = 0; i < 3; i++)
		cin>>v[i];
	sort(v.begin(), v.end());
	ll res = 0;
	res += v[0];
	int tmp = v[2] - v[1];
	if(tmp <= v[0]){
		v[2] -= tmp;
		v[0] -= tmp;
		res += (v[1] + v[2] - v[0]) / 2;
		cout<<res<<endl;
		return;
	}
	else{
		v[2] -= v[0];
		res += v[1];
		cout<<res<<endl;
		return;
	}
 
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