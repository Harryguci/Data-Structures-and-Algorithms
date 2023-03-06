# Find the number of consecutive non-empty subsequences of A that sum to 0.\

```C++
/*
 Print the number of consecutive non-empty subsequences of A that sum to 0.
*/

#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

int main() {
	int n;
	cin >> n;
	vector<int> a(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}

	unordered_map<long long, int> prefix_sum_counts;
	prefix_sum_counts[0] = 1; // for empty subsequence

	long long prefix_sum = 0;
	long long answer = 0;
	for (int i = 0; i < n; i++) {
		prefix_sum += a[i];
		answer += prefix_sum_counts[prefix_sum];
		prefix_sum_counts[prefix_sum]++;
	}


	cout << answer << endl;

	return 0;
}

```