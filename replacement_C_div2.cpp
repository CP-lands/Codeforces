//--------Anivia_kid---------//
#include<bits/stdc++.h>
 
using namespace std;
 
#define fi first
#define se second
#define pb push_back
typedef long long ll; 
const int MOD = 1e9 + 7;
const int MAXN = 1e5 + 100;
 
bool isPrime(ll n)
{
	if(n < 2) return false;
	if(n == 2) return true;
	for(ll i = 2; i * i <= n; i++)
		if(n % i == 0) return false;
	return true;
}
ll power(ll a, ll k)
{
	if (k == 0) return 1;
	if (k == 1) return a;
	ll tmp = power(a, k >> 1);
	tmp = (tmp * tmp) % MOD;
	return k % 2 ? (tmp * a) % MOD : tmp;
}
string int_to_string(int n)
{
	string res = "";
	while(n / 10 > 0)
	{
		res += n % 10 + '0';
		n /= 10;
	}
	res += n % 10 + '0';
	string ans = "";
	for(int i = res.size() - 1; i >= 0; i--)
		ans += res[i];
	return ans;
}
ll string_to_int(string s)
{
	ll res = 0;
	for(int i = 0; i < s.size(); i++)
		res += (s[i] - '0') * power(10, s.size() - 1- i);
	return res;
}
int get_gcd(int a, int b)
{
	if(b == 0) return a;
	return get_gcd(b, a % b);
}
 
void Anivia_kid(){
	int n;
	cin>>n;
	vector<int> v(n);
	for(int i = 0; i < n; i++)
		cin>>v[i];
	sort(v.begin(), v.end());
	if(n == 1){
		if(v[0] != 1){
			cout<<1<<endl;
			return;
		}
		else{
			cout<<2<<endl;
			return;
		}
	}
	vector<int> res(n);
	res[0] = 1;
	for(int i = 1; i < n; i++){
		if(v[i] != v[i - 1]) res[i] = v[i - 1];
		else if((i == n - 1 && v[i] == 1)) res[i] = 2;
		else res[i] = v[i - 1];
	}
	for(auto x : res)
		cout<<x<<" ";
 
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