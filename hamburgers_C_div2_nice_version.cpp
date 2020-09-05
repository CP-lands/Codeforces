#include<iostream>
#include<string.h>
#include<vector>

//https://codeforces.com/problemset/problem/371/C
using namespace std;
 
int main()
{
	string recipe;
	int br, sc, ch;
	int ratio_b = INT_MAX, ratio_s = INT_MAX, ratio_c = INT_MAX;
	int b = 0, s = 0, c = 0;
	int price[3];
	long long res = 0, rubles, tmp;
 
	cin>>recipe>>br>>sc>>ch;
	cin>>price[0]>>price[1]>>price[2]>>rubles;
 
	for(auto x : recipe)
	{
		if(x == 'B') b++;
		if(x == 'S') s++;
		if(x == 'C') c++;
	}
 
	while(true)
	{
		if(b != 0) ratio_b = br / b;
		else br = 0;
		if(s != 0) ratio_s = sc / s;
		else sc = 0;
		if(c != 0) ratio_c = ch / c;
		else ch = 0;
		res += min(ratio_b, min(ratio_s, ratio_c));
		if(b != 0) br -= min(ratio_b, min(ratio_s, ratio_c)) * b;
		if(s != 0) sc -= min(ratio_b, min(ratio_s, ratio_c)) * s;
		if(c != 0) ch -= min(ratio_b, min(ratio_s, ratio_c)) * c;
		
		if(br == 0 && sc == 0 && ch == 0)
		{
			tmp = rubles / (price[0] * b + price[1] * s + price[2] * c);
			res += tmp;
			rubles -= tmp * (price[0] * b + price[1] * s + price[2] * c);
		}
		if(br < b && rubles >= price[0])
		{
			rubles -= price[0];
			br++;
		}
		else if(sc < s && rubles >= price[1])
		{
			rubles -= price[1];
			sc++;
		}
		else if(ch < c && rubles >= price[2])
		{
			rubles -= price[2];
			ch++;
		}
		else
			break;
	}
	cout<<res<<endl;
	return 0;
}
