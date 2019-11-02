#include<bits/stdc++.h>

using namespace std;

int poww(int j)
{
	int k = 1;
	for(int i = 0; i < j; i++)
		k = k * 10;
	return k;
}

bool solution(int a)
{
	vector<int> res;
	int tmp;
	int count = 0;
	for(int i = 4; i >= 0; i--)
	{
		tmp = a / poww(i);
		a = a % poww(i);
		if(count == 0 && tmp == 0)
			continue;
		res.push_back(tmp);
		count++;
	}
	sort(res.begin(), res.end());
	for(int i = 0; i < res.size() - 1; i++)
	{
		if(res[i] == res[i + 1])
			return false;
	}
	return true;
}

int main()
{
	int l, r;
	cin>>l>>r;
	//------------
	vector<int> res;
	int tmp;
	for(int i = l; i <= r; i++)
	{
		if(solution(i))
		{
			cout<<i<<endl;
			return 0;
		}
	}
	cout<<-1<<endl; 
	return 0;
}