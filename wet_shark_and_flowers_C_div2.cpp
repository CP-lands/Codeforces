//___1 WA == 5 Push up___
#include<iostream>
#include<math.h>
#include<stack>
#include<queue>
#include<algorithm>
#include<vector>
#include<set>
#include<string.h>
#include<map>
#include<iomanip>


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
	return (n * comb(n - 1, k)) / (n - k);
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
ll pow(int a, int b)
{
	if(b == 0) return 1;
	if(b == 1) return a;
	ll res = 1;
	for(int i = 0; i < b; i++)
		res *= a;
	return res;
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
		res += (s[i] - '0') * pow(10, s.size() - 1- i);
	return res;
}
int get_gcd(int a, int b)
{
	if(b == 0) return a;
	return get_gcd(b, a % b);
}
int main()
{
	int n, p, low, high;
	cin>>n>>p;
	vector<vector<int>> res(n, vector<int>(2));
	for(int i = 0; i < n; i++)
	{
		cin>>low>>high;
		if(low % p == 0) res[i][0] = high / p - low / p + 1;
		else res[i][0] = high / p - low / p;
		res[i][1] = high - low + 1;
	}

	double sum = 0;
	for(int i = 0; i < n - 1; i++)
		sum += 1 - (((double)res[i][1] - res[i][0]) / res[i][1]) * (((double)res[i + 1][1] - res[i + 1][0]) / res[i + 1][1]);
	sum += 1 - (((double)res[0][1] - res[0][0]) / res[0][1]) * (((double)res[n - 1][1] - res[n - 1][0]) / res[n - 1][1]);
	cout<<fixed<<setprecision(6)<<sum * 2000<<endl;
	return 0;
}

/*
int main()
{
	int n;
	cin>>n;
	vector<int> exit(n), enter(n);
	for(int i = 0 ; i < n; i++)
		cin>>enter[i];
	for(int i = 0; i < n; i++)
		cin>>exit[i];
	int count = 0;
	std::vector<int>::iterator pend; 
  
    // std :: remove function call 
    int index = 0;
    int count2 = 0;
    while(count2 < n)
    {
    	if(enter[0] != exit[0])
    	{
    		count++;
    		int tmp = exit[0];
    		pend = std::remove(exit.begin(), exit.end(), tmp);
    		exit.pop_back();
    		pend = std::remove(enter.begin(), enter.end(), tmp);
    		enter.pop_back();
    	}
    	else
    	{
    		int tmp = exit[0];
    		pend = std::remove(exit.begin(), exit.end(), tmp);
    		exit.pop_back();
    		pend = std::remove(enter.begin(), enter.end(), tmp);
    		enter.pop_back();
    	}
    	count2++;

    }
	cout<<count<<endl;
	return 0;
}*/