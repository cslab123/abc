#include <bits/stdc++.h>
using namespace std;

int string_to_integer(char s[])
{
	int total=0, power=1;
	for(int i = strlen(s)-1; i >=0 ; i--)
	{
		if(s[i] == '1')
			total += power;
		power *= 2;
	}

	return total;
}

int main()
{
	char a[9], b[9], checksum[10];
	cout << "Enter first binary string: ";
	cin >> a;
	cout << "Enter second binary string: ";
	cin >> b;
	cout << "Enter checksum: ";
	cin >> checksum;

	int x = string_to_integer(a);
	int y = string_to_integer(b);
	int z = x + y;

	cout << x << " " << y << " " << z << endl;

	int len = strlen(a) + 1;
	char c[len];
	int i;
	for(i = 0; i < len;  i++)
		c[i] = '0';

	i = len-1;
	while(z != 0)
	{
		if(z%2 == 0)
			c[i--] = '0';
		else
			c[i--] = '1';

		z /= 2;
	}

	for(i = 0; i < len; i++)
		if(c[i] == checksum[i])
			break;

	if(i == len)
		cout << "No error" << endl;
	else
		cout << "Error" << endl;

	return 0;
}
