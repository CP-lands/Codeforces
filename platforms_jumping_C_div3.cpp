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
	int n, m, d;
	cin>>n>>m>>d;
	vector<int> l(m), res(n);
	int sum = 0;
	for(int i = 0; i < m; i++){
		cin>>l[i];
		sum += l[i];
	}
	if((d - 1) * (m + 1) < n - sum){
		cout<<"NO"<<endl;
		return;
	}
	int blank = n - sum;
	int i = 0;
	int j = 0;
	int k = 0;
	while(i < n){
		
		int tmp;
		if(blank > 0){
			tmp = min(blank + 1, d) - 1;
			blank -= tmp;
			while(tmp--){
				res[i++] = 0;
			}
		}
		if(i < n){
			tmp = l[k];
			while(tmp--){
				res[i++] = j + 1;
			}
		}
		j++;
		k++;
	}

	cout<<"YES"<<endl;
	for(i = 0; i < n; i++)
		cout<<res[i]<<" ";
	return;
}

int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	ios_base::sync_with_stdio(0);
	int q = 1;
	//cin>>q;
	while(q--){
		Anivia_kid();
	}
	return 0;
}
