//--------Anivia_kid---------//
//https://codeforces.com/contest/430/problem/B
#include<bits/stdc++.h>
 
using namespace std;
 
#define fi first
#define se second
#define pb push_back
#define eb emplace_back
 
typedef long long ll; 
const int MOD = 1e9 + 7;

void Anivia_kid(){
	int n, k, x;
	cin>>n>>k>>x;
	vector<int> v(n);
	for(int i = 0; i < n; i++)
		cin>>v[i];
	int i = 0;
	int res = 0;
	bool two = false;
	while(i < n - 1){
		if(v[i] != v[i + 1] || v[i] != x){
			i++;
			continue;
		}
		two = true;
		int tmp = 2;
		int a = i - 1;
		int b = i + 2;
		if(a < 0 || b >= n || v[a] != v[b]){
			i++;
			continue;
		}
		while(true){
			int t = tmp;
			int color = v[a];
			while(a >= 0 && v[a] == color){
				a--;
				tmp++;
			}
			while(b < n && v[b] == color){
				b++;
				tmp++;
			}
			if(tmp - t < 3){
				tmp = tmp - 2;
				break;
			}
			if(a < 0 || b >= n || v[a] != v[b]) break;
		}
		if(res < tmp) res = tmp;
		i++;
	}
	if(two) res = max(res, 2);
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