//___1 WA == 5 Push up___
//------Anivia_kid----------
#include<bits/stdc++.h>
 
using namespace std;
 
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
ll comb(int n, int k)
{
	if(n == k) return 1;
	return ((n * comb(n - 1, k)) / (n - k)) % 1000000007;
}
bool isPrime(int n)
{
	if(n < 2) return false;
	for(int i = 2; i < n; i++)
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
bool isPossible(vector<vector<int>> &v, int p, ll current, int n){
	int count = 0;
	for(int i = n - 1; i >= 0; i--){
		if(v[i][0] >= p) count++;
		else if(v[i][0] < p){
			if(v[i][1] >= p){
				if(current >= p - v[i][0])
				{
					current -= (p - v[i][0]);
					count++;
				}
				else break;
			}
		}
	}
	if(count > n / 2) return true;
	return false;
}
void Anivia_kid(){
	ll n, s;
	ll min_money = 0;
	cin>>n>>s;
	vector<vector<int>> v(n, vector<int>(2));
	vector<int> v1(n);
	for(int i = 0; i < n; i++)
	{
		cin>>v[i][0]>>v[i][1];
		v1[i] = v[i][1];
		min_money += v[i][0];
	}
	ll current = s - min_money;
	sort(v.begin(), v.end());
	sort(v1.begin(), v1.end());
	int low = v[n / 2][0];
	int high = v1[n / 2]; 

	while(high > low){
		int mid = low + (high - low) / 2;
		if(isPossible(v, mid, current, n)) low = mid;
		else high = mid - 1;
		if(high - low == 1){
			if(isPossible(v, high, current, n)){
				cout<<high<<endl;
				return;
			}
			cout<<low<<endl;
			return;
		}
	}
	cout<<low<<endl;
	return;
}
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int q;
	cin>>q;
	while(q--){
		Anivia_kid();
	}

	return 0;
}