#include<iostream>
#include<vector>
#include<map>
#include<algorithm>

using namespace std;

int main()
{
	int n, i = 0, temp;
	long long count, less = 0, res = 0;
	cin>>n;
	vector<vector<int>> v(n,vector<int>(2));
	map<long long,long long> mp;

	for(i; i < n; i++)
		cin>>v[i][0]>>v[i][1];
	sort(v.begin(), v.end());
	i = 0;
	while(i < n - 1)
	{
		count = 1;
		temp = 0;
		while(i < n - 1 && v[i][0] == v[i + 1][0])
		{
			if(v[i][1] == v[i + 1][1])
				++mp[v[i + 1][1]];
			count++;
			i++;
			temp = 1;
		}
		res += ((count - 1) * count) / 2;
		for(auto x : mp)
			less += ((x.second + 1) * x.second) / 2;
		mp.clear();
		if(temp == 0)
			i++;
	}
	for(i = 0; i < n; i++)
		++mp[v[i][1]];
	for(auto x : mp)
		res += ((x.second - 1) * x.second) / 2;
	cout<<res - less<<endl;
	return 0;
}