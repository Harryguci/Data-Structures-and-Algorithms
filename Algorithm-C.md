1. Find max element
```C++
iterator max_element(iterator-begin, iterator-end);	// *max_element will return the value;
```
2. Find the first element have value >= X
```C++
iterator lower_bound(iterator first, iterator last, X);
{
	// Will return the first element have value >= X	// X is a const value
}
```

3. Find the first element have value > X
```C++
iterator upper_bound(iterator first, iterator last, X);
{
	Will return the first element have value > X	// X is a const value
}
```

4. Power for large number :
```C++
long long Multi(long long a, long long b,
	long long mod)
{
	long long res = 0; 
	a %= mod;

	while (b) {
		if (b & 1)
			res = (res + a) % mod;
		a = (2 * a) % mod;
		b >>= 1; // b = b / 2
	}
	return res;
}
ll power(ll x, ll n, ll MOD)
{
	ll res = 1;
	while (n) {
		if (n % 2 != 0) {
			res = Multi(x, res, MOD);
		}
		n /= 2;
		x = Multi(x, x, MOD);
	}
	return res;
}
```
5. Modulo for Large numbers as a string :
```C++
ll mod(string num, ll a)
{
	ll res = 0;

	for (int i = 0; i < num.length(); i++)
		res = (res * 10 + (ll)num[i] - '0') % a;

	return res;
}
```
6. Fibonacci number
```C++
long f(long n) {
	if (F.count(n)) return F[n];
	long k = n / 2;
	if (n % 2 == 0) { // n=2*k
		return F[n] = (f(k) * f(k) + f(k - 1) * f(k - 1)) % M;
	}
	else { // n=2*k+1
		return F[n] = (f(k) * f(k + 1) + f(k - 1) * f(k)) % M;
	}
}
```

7.GCD
```C++
int _gcd(int a, int b) {
	if (b == 0) return a;
	else
		return _gcd(b, a % b);
}
```
8. BFS (Breath first search)
```C++
// Find the best way from 'startPoint' to 'endPoint'
// (startPoint and endPoint as edges in graph)
int Bfs(vector<vector<int>> arr, int startPoint, int endPoint) {
	queue<pair<int, int>> Queue;
	// map<int, int> visit;
	vector<bool> visit(arr.size() + 1);
	visit[startPoint] = true;

	Queue.push({ startPoint , 0 });
	cout << "PUSH " << startPoint << endl;

	while (Queue.size()) {
		auto current = Queue.front();
		Queue.pop();

		if (current.first == endPoint) {
			return current.second;
		}
		else {
			for (int i = 0; i < arr[current.first].size(); i++) {
				if (arr[current.first][i] == 1 && visit[i] == false) {
					visit[i] = true;
					Queue.push({ i, current.second + 1 });
				}
			}
		}
	}

	return -1;	// Not found
}
```
9. 