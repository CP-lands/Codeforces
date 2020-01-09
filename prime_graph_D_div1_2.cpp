//--------Anivia_kid---------//
//-------did you test n = 1 ?-------//
//https://codeforces.com/contest/1178/problem/D
#include<bits/stdc++.h>
 
using namespace std;
 
#define fi first
#define se second
#define pb push_back
#define eb emplace_back
 
typedef long long ll; 
const int MOD = 1e9 + 7;

bool isPrime(int n){
	for(int i = 2; i * i <= n; i++){
		if(n % i == 0) return false;
	}
	return true;
}

void Anivia_kid(){
	int n;
	cin>>n;
	int sum = n;
	while(!isPrime(sum)){
		sum++;
	}
	cout<<sum<<'\n';
	for(int i = 1; i < n; i++){
		cout<<i<<" "<<i + 1<<'\n';
	}
	cout<<1<<" "<<n<<'\n';
	sum -= n;
	int ver = 1;
	for(int i = 0; i < sum; i++){
		cout<<ver<<" "<<n - ver<<'\n';
		ver += 1;
	}

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