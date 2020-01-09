//--------Anivia_kid---------//
//-------did you test n = 1 ?-------//
//https://codeforces.com/contest/1269/problem/B
#include<bits/stdc++.h>
 
using namespace std;
 
#define fi first
#define se second
#define pb push_back
#define eb emplace_back
 
typedef long long ll; 
const int MOD = 1e9 + 7;
 
void Anivia_kid(){
	int n, m;
	cin>>n>>m;
	vector<int> v1(n), v2(n);
	vector<int> change;
	change.eb(0);
	for(int i = 0; i < n; i++){
		cin>>v1[i];
	}
	for(int i = 0; i < n; i++)
		cin>>v2[i];
	sort(v1.begin(), v1.end());
	for(int i = 1; i < n; i++){
		if(v1[i] > v1[i - 1]) change.eb(i);
	}
	sort(v2.begin(), v2.end());
	int res = INT_MAX;
	for(auto x: change){
		vector<int> v3;
		for(int i = x; i < n; i++)
			v3.eb(v1[i]);
		for(int i = 0; i < x; i++)
			v3.eb(v1[i]);
		int tmp = 0;
		if(v3[0] <= v2[0]) tmp = v2[0] - v3[0];
		else tmp = m + v2[0] - v3[0];
		for(int i = 0; i < n; i++){
			v3[i] = (v3[i] + tmp) % m;
		}
		sort(v3.begin(), v3.end());
		if(v3 == v2 && res > tmp) res = tmp;
	}
	cout<<res<<'\n';
 
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