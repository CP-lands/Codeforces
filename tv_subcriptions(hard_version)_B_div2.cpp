//___1 WA == 5 Push up___
//------Anivia_kid----------
#include<bits/stdc++.h>
 
//https://codeforces.com/problemset/problem/1247/B2
using namespace std;
 
typedef long long ll; 
const int MOD = 1e9 + 7;
 
void Anivia_kid(){
	int n, k, d;
	cin>>n>>k>>d;
	vector<int> v(n);
	for(int i = 0; i < n; i++){
		cin>>v[i];
	}
	int res;
	map<int, int> mp;
	int count = 0;
	for(int i = 0; i < d; i++){
		++mp[v[i]];
	}
	res = mp.size();
	count = res;
	int tmp;
	for(int i = d; i < n; i++){
		tmp = v[i - d];
		if(tmp == v[i]) continue;
		else 
		{
			if(mp[tmp] == 1) mp.erase(tmp);
			else if(mp[tmp] > 1) mp[tmp]--;
		}
		++mp[v[i]];
		count = mp.size();
		if(res > count) res = count;
	}
	cout<<res<<endl;
 
	return;
}
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int q;
	cin>>q;
	while(q--){
		Anivia_kid();
	}
	return 0;
}
