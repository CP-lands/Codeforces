#include<bits/stdc++.h>
 
//https://codeforces.com/contest/1362/problem/C
using namespace std;
 
void Solve(){
	long long n;
	cin>>n;
	long long x = n / 2;
	long long res = n / 2;
	if(n % 2) res++;
	long long k = 2;
	//cout<<res<<endl;
	while(x > 0){
		res += k * (x / 2);
		if(x % 2) res += k;
		k++;
		x /= 2;
		//cout<<res<<endl;
	}
	cout<<res<<'\n';
}
int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int T = 1;
	cin>>T;
	while(T--){
		Solve();
	}
}