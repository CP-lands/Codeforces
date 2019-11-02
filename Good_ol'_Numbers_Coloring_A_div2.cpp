//------Anivia_kid----------
#include<bits/stdc++.h>
 
using namespace std;
 
#define fi first
#define se second
typedef long long ll; 
const int MOD = 1e9 + 7;
 
ll fact(int n)
{
	if(n == 0 || n == 1) return 1;
	ll res = 1;
	for(int i = 2; i <= n; i++)
		res *= i;
	return res;
}
ll comb(ll n, ll k)
{
	if(n == k) return 1;
	return ((n * comb(n - 1, k)) / (n - k));
}
bool isPrime(int n)
{
	if(n < 2) return false;
	if(n == 2) return true;
	for(int i = 2; i <= sqrt(n); i++)
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
vector<int> common_divisors(int a, int b)
{
	int tmp = get_gcd(a, b);
	vector<int> res;
	for(int i = 1; i <= sqrt(tmp); i++)
		if(tmp % i == 0)
		{
			if(i * i == tmp) res.push_back(i);
			else
			{
				res.push_back(i);
				res.push_back(tmp / i);
			}
		}
	return res;
}
ll solution(int n){
	ll res = 0;
	ll tmp1 = 2;
	ll tmp2 = 3;
	if(n == 2) return 2;
	if(n == 3) return 3;
	for(int i = 4; i <= n; i++){
		res = tmp1;
		res += tmp2;
		tmp1 = tmp2;
		tmp2 = res;
	}
	return res % MOD;
}
void Anivia_kid(){
	int a, b;
	cin>>a>>b;
	int m = get_gcd(a, b);
	if(m == 1) cout<<"Finite"<<endl;
	else cout<<"Infinite"<<endl;
	return;
}
/*
void Anivia_kid(){
	string s;
	cin>>s;
	ll res = 1;
	int tmp = 0;
	int i = 0;
	while(i < s.size()){
		tmp = 1;
		if(s[i] == 'w' || s[i] == 'm'){
			cout<<0<<endl;
			return;
		}
 
		while(i < s.size() - 1 && s[i] == 'u' && s[i + 1] == 'u'){
			tmp++;
			i++;
		}
		if(tmp > 1)
			res *= solution(tmp) % MOD;
		tmp = 1;
		while(i < s.size() - 1 && s[i] == 'n' && s[i + 1] == 'n'){
			tmp++;
			i++;
		}
		
		if(tmp > 1)
			res *= solution(tmp) % MOD;
		i++;
	}
	cout<<res % MOD<<endl;
 
	return;
}
*/
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	ios_base::sync_with_stdio(0);
	int q;
	cin>>q;
	while(q--){
		Anivia_kid();
	}
	return 0;
}