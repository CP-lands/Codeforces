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
void Anivia_kid(){
	int n, a, b, c;
	string t;
	cin>>n>>a>>b>>c>>t;
	int r = 0;
	int p = 0;
	int s = 0;
	for(auto x : t){
		if(x == 'R') r++;
		if(x == 'P') p++;
		if(x == 'S') s++;
	}
	int res = 0;
	res += min(a, s) + min(b, r) + min(c, p);
	if((n % 2 == 0 && res < n / 2) || (n % 2 != 0 && res <= n / 2)) cout<<"NO"<<endl;
	else{
		vector<char> ans(n);
		cout<<"YES"<<endl;
		for(int i = 0; i < t.size(); i++){
			if(t[i] == 'R' && b > 0){
				ans[i] = 'P';
				b--;
			}
			if(t[i] == 'P' && c > 0){
				ans[i] = 'S';
				c--;
			}
			if(t[i] == 'S' && a > 0){
				ans[i] = 'R';
				a--;
			}
		}
		for(int i = 0; i < n; i++){
			if(ans[i] != 'P' && ans[i] != 'S' && ans[i] != 'R'){
				if(a > 0){
					ans[i] = 'R';
					a--;
				}
				else if(b > 0){
					ans[i] = 'P';
					b--;
				}
				else if(c > 0){
					ans[i] = 'S';
					c--;
				}
			}
		}
		for(auto x : ans)
			cout<<x;
	}
	cout<<endl;
	return;
}
 
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