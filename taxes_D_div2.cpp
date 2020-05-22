#include<bits/stdc++.h>
 
//https://codeforces.com/contest/735/problem/D
using namespace std;
 
bool isPrime(int n){
	if(n < 2) return false;
	for(int i = 2; i * i <= n; i++){
		if(n % i == 0) return false;
	}
	return true;
}
void Solve(){
	int n;
	cin>>n;
	if(isPrime(n)){
		cout<<1<<'\n';
		return;
	}
	int exit = 0;
	int a = n - 2, b = 2;
	while(true){
		if(isPrime(a) && isPrime(b)){
			cout<<2<<'\n';
			return;
		}
		exit++;
		a--;
		b++;
		if(exit == 10000) break;
	}
	cout<<3<<'\n';
}
int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int T = 1;
	//cin>>T;
	while(T--){
		Solve();
	}
}