//------Anivia_kid----------
#include<bits/stdc++.h>
 
//https://codeforces.com/problemset/problem/1242/A
using namespace std;
 
#define fi first
#define se second
typedef long long ll; 
const int MOD = 1e9 + 7;
 
bool isPrime(ll n) {
	if(n < 2) return false;
	if(n == 2) return true;
	for(ll i = 2; i * i <= n; i++)
		if(n % i == 0) return false;
	return true;
}
ll get_smallest(ll n){
	ll i = 2;
	for(i; i * i <= n; i++){
		if(n % i == 0) return i;
	}
}
ll solution(ll n){
	int res = 0;
	ll i = 2;
	ll tmp = n;
	while(i * i <= tmp && n > 1){
		if(n % i == 0) res++;
		while(n % i == 0)
			n /= i;
		i++;
	}
	if(res > 1) return 1;
	if(res == 1 && n > 1) return 1;
	return get_smallest(tmp);
}
void Anivia_kid(){
	ll n;
	cin>>n;
	if(n == 1){
		cout<<1<<endl;
		return;
	}
	if(isPrime(n)) {
		cout<<n<<endl;
		return;
	}
	cout<<solution(n)<<endl;
 
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
	return 0;
}
