#include <iostream>

int main() {
	int n, k;
	std::cin >> n >> k;
	int* coin = new int[n];
	for (int i = 0; i < n; i++) {
		int temp;
		std::cin >> temp;
		coin[i] = temp;
	}
	int* arr = new int[k+1];
	arr[0] = 1;
	for (int i = 1; i < k + 1; i++) {
		arr[i] = 0;
	}
	for (int j = 0; j < n; j++) {
		for (int i = coin[j]; i < k + 1; i++) {
			arr[i] += arr[i - coin[j]];
		}
	}
	std::cout << arr[k];
}