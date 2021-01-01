#include<bits/stdc++.h>
 
//https://codeforces.com/contest/276/problem/D
using namespace std;
 
long long poww[61];
 
string binary_base(long long n){
	string ans = "";
	for(int i = 60; i >= 0; i--){
		if(n >= poww[i]){
			n -= poww[i];
			ans += '1';
		}
		else ans += '0';
	}
	reverse(ans.begin(), ans.end());
	return ans;
}
bool isValid(string ans, int pos, string l, string r){
	long long k = 0;
	long long low = 0, up = 0;
	for(int i = 60; i >= pos; i--){
		if(ans[i] == '1') k += poww[i];
		if(l[i] == '1') low += poww[i];
		if(r[i] == '1') up += poww[i];
	}
	if(k >= low && k <= up) return true;
	else return false;
}
void Solve(){
	poww[0] = 1;
	for(int i = 1; i < 61; i++)
		poww[i] = poww[i - 1] * 2;
	long long low, high;
	cin>>low>>high;
	string l = binary_base(low);
	string r = binary_base(high);
	long long res = 0;
	string ans = "", ll = "", rr = "";
	for(int i = 0; i < 61; i++){
		ans += '1';
		ll += '1'; 
		rr += '1';
	}
	for(int i = 60; i >= 0; i--){
		//01
		ll[i] = '0';
		if(isValid(ll, i, l, r) && isValid(rr, i, l, r)) continue;
		//10
		ll[i] = '1';
		rr[i] = '0';
		if(isValid(ll, i, l, r) && isValid(rr, i, l, r)) continue;
		//11
		rr[i] = '1';
		ans[i] = '0';
		if(!isValid(ll, i, l, r) || !isValid(rr, i, l, r)){
			rr[i] = '0';
			ll[i] = '0';
		}
		else{
			ll[i] = '1';
			rr[i] = '1';
		}
	}
	for(int i = 0; i < 61; i++){
		if(ans[i] == '1') res += poww[i];
	}
	cout<<res<<'\n';
}
int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int T = 1;
	//cin>>T;
	while(T--){
		Solve();
	}
}