# If you want to use map data structure for a *struct* object you have to define operators(==, <, ..) for it.

```C++
#include <iostream>
#include <map>

struct Point {
	int x, y;

	bool operator==(const Point& o) const {
		return x == o.x && y == o.y;
	}

	bool operator<(const Point& o)  const {
		return x < o.x || (x == o.x && y < o.y);
	}
};

int main()
{
	std::map<Point, int> P;
	std::pair<Point, int> m;
	P.insert(m);
	int n;
	Point temp;
	std::cin >> n;
	while (n--)
	{
		std::cin >> temp.x >> temp.y;
		++P[temp];
	}
	for (auto& x : P)
		if (x.second > 1)
		{
			std::cout << "YES";
			return 0;
		}
	std::cout << "NO";
	return 0;
}
```