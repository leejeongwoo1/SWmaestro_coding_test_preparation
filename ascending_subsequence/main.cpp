#include <iostream>

int main() {
	int N;
	std::cin >> N;
	int* arr = new int[N];
	for (int i = 0; i < N; i++) {
		int temp = 0;
		std::cin >> temp;
		arr[i] = temp;
	}
	int* result = new int[N];
	result[0] = 1;
	for (int i = 1; i < N; i++) {
		int length = 1;
		for (int j = 0; j < i; j++) {
			if (arr[i] > arr[j]&&length<result[j]+1) {
				length = result[j] + 1;
			}
		}
		result[i] = length;
	}
	int max = 0;
	for (int i = 0; i < N; i++) {
		if (max < result[i]) {
			max = result[i];
		}
	}
	std::cout << max;
}