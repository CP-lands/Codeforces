#include<iostream>
#include<string.h>
#include<vector>

//https://codeforces.com/problemset/problem/371/C
using namespace std;

vector<int> ratio(vector<int> a, int x, int y, int z)
{
	vector<int> res(3);
	res[0] = a[0] / x;
	res[1] = a[1] / y;
	res[2] = a[2] / z;
	return res;
}
int minn(vector<int> a)
{
	int res = min(a[0], min(a[1], a[2]));
	return res;
}
int main()
{
	string recipe;
	vector<int> kitchen(3);
	vector<int> price(3);
	vector<int> ans(3);
	long long rubles, res = 0;
	int b = 0, s = 0, c = 0;

	cin>>recipe;
	cin>>kitchen[0]>>kitchen[1]>>kitchen[2];
	cin>>price[0]>>price[1]>>price[2];
	cin>>rubles;

	for(auto x : recipe)
	{
		if(x == 'B')
			b++;
		if(x == 'S')
			s++;
		if(x == 'C')
			c++;
	}
	while(b != 0 && c != 0 && s != 0)
	{
		ans = ratio(kitchen,b,s,c);
		res += minn(ans);
		kitchen[0] -= minn(ans) * b;
		kitchen[1] -= minn(ans) * s;
		kitchen[2] -= minn(ans) * c;
		if(kitchen[0] == 0 && kitchen[1] == 0 && kitchen[2] == 0)
		{
			res += rubles / (price[0] * b + price[1] * s + price[2] * c);
			rubles -= (rubles / (price[0] * b + price[1] * s + price[2] * c)) * (price[0] * b + price[1] * s + price[2] * c);
		}
		if(kitchen[0] < b)
		{
			if(rubles >= price[0])
			{
				rubles -= price[0];
				kitchen[0]++;
			}
			else
				break;
		}
		if(kitchen[1] < s)
		{
			if(rubles >= price[1])
			{
				rubles -= price[1];
				kitchen[1]++;
			}
			else
				break;
		}
		if(kitchen[2] < c)
		{
			if(rubles >= price[2])
			{
				rubles -= price[2];
				kitchen[2]++;
			}
			else
				break;
		}
	}
	while(b == 0 && s != 0 && c != 0)
	{
		ans[1] = kitchen[1] / s;
		ans[2] = kitchen[2] / c;
		res += min(ans[1], ans[2]);
		kitchen[1] -= min(ans[1], ans[2]) * s;
		kitchen[2] -= min(ans[1], ans[2]) * c;
		if(kitchen[1] == 0 && kitchen[2] == 0)
		{
			res += rubles / (price[1] * s + price[2] * c);
			if(rubles / (price[1] * s + price[2] * c) == 0)
				break;
			rubles -= (rubles / (price[1] * s + price[2] * c)) * (price[1] * s + price[2] * c);
		}
		if(kitchen[1] < s)
		{
			if(rubles >= price[1])
			{
				rubles -= price[1];
				kitchen[1]++;
			}
			else
				break;
		}
		if(kitchen[2] < c)
		{
			if(rubles >= price[2])
			{
				rubles -= price[2];
				kitchen[2]++;
			}
			else
				break;
		}
	}
	while(b != 0 && s == 0 && c != 0)
	{
		ans[0] = kitchen[0] / b;
		ans[2] = kitchen[2] / c;
		res += min(ans[0], ans[2]);
		kitchen[0] -= min(ans[0], ans[2]) * b;
		kitchen[2] -= min(ans[0], ans[2]) * c;
		if(kitchen[0] == 0 && kitchen[2] == 0)
		{
			res += rubles / (price[0] * b + price[2] * c);
			if(rubles / (price[0] * b + price[2] * c) == 0) 
				break;
			rubles -= (rubles / (price[0] * b + price[2] * c)) * (price[0] * b + price[2] * c);
		}
		if(kitchen[0] < b)
		{
			if(rubles >= price[0])
			{
				rubles -= price[0];
				kitchen[0]++;
			}
			else
				break;
		}
		if(kitchen[2] < c)
		{
			if(rubles >= price[2])
			{
				rubles -= price[2];
				kitchen[2]++;
			}
			else
				break;
		}
	}
	while(b != 0 && s != 0 && c == 0)
	{
		ans[0] = kitchen[0] / b;
		ans[1] = kitchen[1] / s;
		res += min(ans[0], ans[1]);
		kitchen[0] -= min(ans[0], ans[1]) * b;
		kitchen[1] -= min(ans[0], ans[1]) * s;
		if(kitchen[0] == 0 && kitchen[1] == 0)
		{
			res += rubles / (price[0] * b + price[1] * s);
			if(rubles / (price[0] * b + price[1] * s) == 0) 
				break;
			rubles -= (rubles / (price[0] * b + price[1] * s)) * (price[0] * b + price[1] * s);
		}
		if(kitchen[0] < b)
		{
			if(rubles >= price[0])
			{
				rubles -= price[0];
				kitchen[0]++;
			}
			else
				break;
		}
		if(kitchen[1] < s)
		{
			if(rubles >= price[1])
			{
				rubles -= price[1];
				kitchen[1]++;
			}
			else
				break;
		}
	}
	if(b == 0 && s == 0)
		res += (kitchen[2] + rubles / price[2]) / c;
	if(b == 0 && c == 0)
		res += (kitchen[1] + rubles / price[1]) / s;
	if(c == 0 && s == 0)
		res += (kitchen[0] + rubles / price[0]) / b;
	cout<<res<<endl;
	return 0;

}
