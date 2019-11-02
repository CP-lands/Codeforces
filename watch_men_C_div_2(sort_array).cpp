#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main()
{
	int n, temp, i = 0;
	long long tmp, less, count = 0, ans = 0;
	cin>>n;
	vector<vector<int>> res(n,vector<int>(2));
	for(i; i < n; i++)
		cin>>res[i][0]>>res[i][1];
	sort(res.begin(), res.end());
	i = 0;
	while(i < n - 1)
	{
		temp = 1;
		count = 1;
		tmp = 1;
		less = 0;
		while(i < n - 1 && res[i][0] == res[i + 1][0])
		{
			if(res[i][1] == res[i + 1][1])
				tmp++;
			else
			{
				less += ((tmp - 1) * tmp) / 2;
				tmp = 1;
			}
			count++;
			i++;
			temp = 0;
		}
		less += ((tmp - 1) * tmp) / 2;
		ans += ((count - 1) * count) / 2 - less;
		if(temp == 1) 
			i++;
	}
	//------swap_element_each_row----------------
	for(int i = 0; i < n; i++)
	{
		tmp = res[i][0];
		res[i][0] = res[i][1];
		res[i][1] = tmp;
	}
	sort(res.begin(), res.end());
	i = 0;
	while(i < n - 1)
	{
		count = 1;
		while(i < n - 1 && res[i][0] == res[i + 1][0])
		{
			count++;
			i++;
		}
		ans += (count * (count - 1)) / 2;
		i++;
	}
	cout<<ans<<endl;
	return 0;
}