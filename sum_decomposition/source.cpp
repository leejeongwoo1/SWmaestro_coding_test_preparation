#include <iostream>

int main() {
	int N, K;
	std::cin >> N >> K;

	int** arr = new int* [N+1];
	for (int i = 0; i < N+1; i++) {
		arr[i] = new int[K+1];
	}
	for (int i = 1; i < N + 1; i++) {
		arr[i][1] = 1;
	}
	for (int i = 1; i < K + 1; i++) {
		arr[1][i] = i;
	}
	for (int i = 2; i < K + 1; i++) {
		for (int j = 2; j < N + 1; j++) {
			arr[j][i] = (arr[j - 1][i] + arr[j][i - 1])%1000000000;
		}
	}
	std::cout << arr[N][K];
}