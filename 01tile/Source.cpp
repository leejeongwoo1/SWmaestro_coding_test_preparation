#include <iostream>

int main() {
	int N;
	std::cin >> N;
	int* arr = new int[N + 1];
	if (N == 1){
		std::cout << 1;
		return 0;
	}
	if (N == 2) {
		std::cout << 2;
		return 0;
	}
	arr[0] = 0;
	arr[1] = 1;
	arr[2] = 2;
	for (int i = 3; i < N + 1; i++) {
		arr[i] = (arr[i - 1] + arr[i - 2])%15746;
	}
	std::cout << arr[N];
}