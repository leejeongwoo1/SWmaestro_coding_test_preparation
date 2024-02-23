#include <iostream>

int main() {
	int N;

	std::cin >> N;
	int* arr = new int[N + 1];
	int* max_arr = new int[N + 1];

	arr[0] = 0;
	max_arr[0] = 0;
	for (int i = 1; i < N+1; i++) {
		int temp;
		std::cin >> temp;
		arr[i] = temp;
	}
	for (int i = 1; i < N + 1; i++) {
		int max = 0;
		for (int j = 1; j <= i; j++) {
			if (arr[j] + max_arr[i - j]>max) {
				max = arr[j] + max_arr[i - j];
			}
		}
		max_arr[i] = max;
	}
	std::cout << max_arr[N];

}