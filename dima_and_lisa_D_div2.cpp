#include<bits/stdc++.h>
 
//https://codeforces.com/contest/584/problem/D
using namespace std;
 
bool isPrime(int n){
	if(n < 2) return false;
	for(int i = 2; i * i <= n; i++){
		if(n % i == 0) return false;
	}
	return true;
}
int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int n;
	cin>>n;
	if(isPrime(n)) cout<<1<<'\n'<<n<<'\n';
	else{
		int a = n - 2, b = 2;
		while(true){
			if(isPrime(a) && isPrime(b)){
				cout<<2<<'\n'<<a<<" "<<b<<'\n';
				return 0;
			}
			if(isPrime(a - 1) && isPrime(b - 1)){
				cout<<3<<'\n';
				cout<<a - 1<<" "<<b - 1<<" "<<2<<'\n';
				return 0;
			}
			if(isPrime(a - 2) && isPrime(b - 1)){
				cout<<3<<'\n';
				cout<<a - 2<<" "<<b - 1<<" "<<3<<'\n';
				return 0;
			}
			if(isPrime(a - 1) && isPrime(b - 2)){
				cout<<3<<'\n';
				cout<<a - 1<<" "<<b - 2<<" "<<3<<'\n';
				return 0;
			}
			a--;
			b++;
		}
	}
}