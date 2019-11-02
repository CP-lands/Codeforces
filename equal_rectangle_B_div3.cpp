#include <bits/stdc++.h> 

using namespace std;

int main()
{
	int t, temp;
	cin>>t;
	for(int i = 0; i < t; i++)
	{
		int n;
		cin>>n;
		int count = 0;
		map<int, int> mp;
		for(int j = 0; j < 4*n; j++)
		{
			int tmp;
			cin >> tmp;
			++mp[tmp];
		}
		
		bool good = true;
		for(auto x : mp)
		{
			if(x.second % 2 != 0)
			{
				good = false;
				break;
			}
		}
		if (!good) 
		{
			puts("NO");
			continue;
		}

		vector<int> a;
		for (auto x: mp)
		{
			for (int i = 0; i < x.second / 2; ++i)
				a.push_back(x.first);
		}

		int l = a.size();
		int area = a[0] * a.back();
		int res = 0;
		for(int i = 0; i < l/2; i ++)
		{
			if(a[i] * a[l - i - 1] ==  area)
				res++;
		}
		if(res == l/2)
			cout<<"YES"<<endl;
		else
			cout<<"NO"<<endl;
	}
	return 0;
}