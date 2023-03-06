# The biggest common sum of subsequences.

```C++
#include <iostream>
#include <vector>
#include <limits.h>

using namespace std;
typedef long long ll;

ll Res(vector<int> A, int n, vector<long long> F)
{
	ll total = F[n - 1];
	for (int i = 0; i < n; i++)
	{
		ll k = 1;
		if (total % F[i] == 0) {
			for (int j = i + 1; j < n; j++) {
				if (F[i] > F[j] * k) 
					break;
				if (F[j] % F[i] == 0)
					k++;
			}
		}
		if (F[i] * k == total) {
			return F[i];
		}
	}
}
int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);

	ll n, max = -INT_MAX, q, trash;
	cin >> q;
	while (q--) {
		cin >> trash >> n;
		vector<long long> F(n, 0);
		vector<int> A(n, 0);
		cin >> A[0];
		F[0] = A[0];
		for (int i = 1; i < n; i++)
		{
			cin >> A[i];
			F[i] = F[i - 1] + A[i];
		}

		cout << trash << " " << Res(A, n, F) << "\n";
	}
	return 0;
}

```