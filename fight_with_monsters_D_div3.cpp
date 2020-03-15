//--------Anivia_kid---------//
//https://codeforces.com/contest/1296/problem/D
#include<bits/stdc++.h>
 
using namespace std;
 
#define fi first
#define se second
#define pb push_back
#define eb emplace_back
 
typedef long long ll; 
const int MOD = 1e9 + 7;
 
void Anivia_kid(){
	int n, a, b, k;
	cin>>n>>a>>b>>k;
	vector<int> v;
	int res = 0;
	for(int i = 0; i < n; i++){
		int x;
		cin>>x;
		if((x % (a + b) <= a) && (x % (a + b) > 0)) res++;
		else v.pb((x - a) % (a + b));
	}
	sort(v.begin(), v.end());
	for(int i = 0; i < v.size(); i++){
		if(k <= 0) break;
		if(v[i] / a < k){
			res++;
			if(v[i] % a == 0) k -= max(1, v[i] / a);
			else k -= v[i] / a + 1;
		}
		else if(v[i] / a == k){
			if(v[i] % a == 0){
				res++;
				k = 0;
			}
			else break;
		}
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