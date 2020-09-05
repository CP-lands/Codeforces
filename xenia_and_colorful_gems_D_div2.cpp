#include<bits/stdc++.h>

//https://codeforces.com/contest/1337/problem/D
using namespace std;

long long form(int x, int y, int z){
	long long res = (long long)(x - y) * (x - y) + (long long)(y - z) * (y - z) + (long long)(z - x) * (z - x);
	return res;
}
long long minn(long long a, long long b){
	if(a <= b) return a;
	else return b;
}
long long get(vector<int> &a, vector<int> &b, vector<int> &c){
	int da = a.size(), db = b.size(), dc = c.size();
	long long res = LLONG_MAX;
	for(int i = 0; i < da; i++){
		int mid = a[i];
		int it = lower_bound(b.begin(), b.end(), mid) - b.begin();
		if(it == db) --it;
		int it2 = lower_bound(c.begin(), c.end(), mid) - c.begin();
		if(it2 == dc) --it2;
		res = minn(res, form(mid, b[it], c[it2]));
		int k;
		if(it > 0){
			k = it - 1;
			res = minn(res, form(mid, b[k], c[it2]));
		}
		if(it < db - 1){
			k = it + 1;
			res = minn(res, form(mid, b[k], c[it2])); 
		}
		if(it2 > 0){
			k = it2 - 1;
			res = minn(res, form(mid, b[it], c[k]));
		}
		if(it2 < dc - 1){
			k = it2 + 1;
			res = minn(res, form(mid, b[it], c[k]));
		}
	}
	return res;
}
void Solve(){
	int a, b, c;
	cin>>a>>b>>c;
	vector<int> va(a), vb(b), vc(c);
	for(int i = 0; i < a; i++)
		cin>>va[i];
	for(int i = 0; i < b; i++)
		cin>>vb[i];
	for(int i = 0; i < c; i++)
		cin>>vc[i];
	sort(va.begin(), va.end());
	sort(vb.begin(), vb.end());
	sort(vc.begin(), vc.end());
	long long ans = minn(get(va, vb, vc), get(vb, va, vc));
	ans = minn(ans, get(vc, va, vb));
	cout<<ans<<'\n';

}
int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int T = 1;
	cin>>T;
	while(T--){
		Solve();
	}
}