# Check a number is a primary number or not.

```C++
bool check(long long n) {
    long m, k;
    if (n < 2) return false;
    if (n == 2 || n == 3 || n == 5) return true;
    if (n % 2 == 0 || n % 3 == 0 || n % 5 == 0) return false;
    m = sqrt(n);
    k = 7;
    while (k <= m)
    {
        if (n % k == 0) return false;
        if (n % (k + 4) == 0) return false;
        k = k + 6;
    }
    return true;
}

```