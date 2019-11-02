#include<iostream>
#include<vector>

using namespace std;

int main()
{
	int a,b,minn,maxx,tmp = 1,res = 0;
	vector<int> div;
	cin>>a>>b;
	while(true)
	{
		if(a % 5 == 0 && b % 5 == 0)
		{
			a /= 5;
			b /= 5;
		}
		else if(a % 3 == 0 && b % 3 == 0)
		{
			a /= 3;
			b /= 3;
		}
		else if(a % 2 == 0 && b % 2 == 0)
		{
			a /= 2;
			b /= 2;
		}
		else
			break;
	}
	minn = min(a, b);
	maxx = max(a, b);
	for(int i = 2; i <= minn / 2; i++)
	{
		if(minn % i == 0)
			div.push_back(i);
	}
	div.push_back(minn);
	for(int i = div.size() - 1; i >= 0; i--)
	{
		if(maxx % div[i] == 0)
		{
			tmp = div[i];
			break;
		}
	}
	minn = minn / tmp;
	maxx = maxx / tmp;
	while(true)
	{
		if(minn % 5 == 0)
		{
			minn /= 5;
			res++;
		}
		else if(minn % 3 == 0)
		{
			minn /= 3;
			res++;
		}
		else if(minn % 2 == 0)
		{
			minn /= 2;
			res++;
		}
		else if(minn > 1)
		{
			cout<<-1<<endl;
			return 0;
		}
		if(maxx % 5 == 0)
		{
			maxx /= 5;
			res++;
		}
		else if(maxx % 3 == 0)
		{
			maxx /= 3;
			res++;
		}
		else if(maxx % 2 == 0)
		{
			maxx /= 2;
			res++;
		}
		else if(maxx > 1)
		{
			cout<<-1<<endl;
			return 0;
		}
		if(maxx == 1 && minn == 1)
		{
			cout<<res<<endl;
			return 0;
		}
	}
}