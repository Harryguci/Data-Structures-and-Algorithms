# Example for BFS

```C++
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

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

	return -1;
}

// Display relationship among edges with matrix 0 1
vector<vector<int>> relationship(vector<pair<int, int>> input, int valueMax) {
	vector<vector<int>> matrix(valueMax + 1, vector<int>(valueMax + 1));
	for (int i = 0; i < input.size(); i++) {
		matrix[input[i].first][input[i].second] = 1;
		matrix[input[i].second][input[i].first] = 1;
	}

	return matrix;
}

// Print matrix
void display(vector<vector<int>> matrix) {
	for (int i = 0; i < matrix.size(); i++) {
		for (int j = 0; j < matrix[i].size(); j++) {
			cout << matrix[i][j] << " ";
		}
		cout << endl;
	}
}

// Demo Main
int main() {
	int n, valueMax;
	cout << "So luong quan he: ";
	cin >> n;
	vector<pair<int, int>> input;
	valueMax = 0;

	for (int i = 0; i < n; i++) {
		int x, y;
		cin >> x >> y;
		if (valueMax < x) valueMax = x;
		if (valueMax < y) valueMax = y;

		input.push_back({ x, y });
	}
	vector<vector<int>> matrix = relationship(input, valueMax);
	display(matrix);

	int startPoint, endPoint;
	cout << "\nStart: " << endl; cin >> startPoint;
	cout << "\End: " << endl; cin >> endPoint;
	cout << "\nThe best way is " << Bfs(matrix, startPoint, endPoint);
	return 0;
}
```
