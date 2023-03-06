# Find the biggest total of all subsequences in an array.

```C++
#include <iostream>
#include <limits.h>
using namespace std;
int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0) ;cout.tie(0);
	long long temp, sum, x, max_am;
	x = sum = 0;
	max_am = -LONG_MAX;
	int n;
	cin >> n;
	while (n--)
	{
		cin >> temp;
		x += temp;
		if (temp == 0)
			max_am = 0;
		else if (sum == 0 && temp < 0 && temp > max_am)
			max_am = temp;
		if (x < 0)
			x = 0;
		else if (x > sum)
			sum = x;
	}
	if (sum != 0)
		cout << sum;
	else
		cout << max_am;
	return 0;
}
```