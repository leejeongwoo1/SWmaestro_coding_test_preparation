#include <iostream>
#include <algorithm>
int main() {
	int N;
	std::cin >> N;
	int** cost = new int*[N];
	for (int i = 0; i < N; i++) {
		cost[i] = new int[3];
	}
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < 3; j++) {
			std::cin >> cost[i][j];
		}
	}

	for (int i = 1; i < N; i++) {
		for (int j = 0; j < 3; j++) {
			cost[i][j] = std::min(cost[i - 1][(j + 1) % 3], cost[i - 1][(j + 2) % 3]) + cost[i][j];
		}
	}
	std::cout << std::min({ cost[N - 1][0], cost[N - 1][1], cost[N - 1][2] });
}