#include<iostream>
#include<string.h>

using namespace std;

int main()
{
	int n;
	string str;
	string result = "";
	cin>>n>>str;
	int temp1, temp2;
	for(int i = 0; i < n; i++)
	{
		if(n % 2 == 1)
		{
			if(i % 2 == 0)
				result = result + str[i];
			else
				result = str[i] + result;
		}
		else
			if(i % 2 == 1)
				result = result + str[i];
			else
				result = str[i] + result;
	}
	cout<<result<<endl;
	return 0;
}