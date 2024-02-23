#include <iostream>

int main() {
	int arr_sum[300];
	int nrof_stairs;
	std::cin >> nrof_stairs;
	int* arr_stair = new int[nrof_stairs];
	for (int i = 0; i < nrof_stairs; i++) {
		int temp;
		std::cin >> temp;
		arr_stair[i] = temp;
	}
	if (nrof_stairs == 1) {
		std::cout << arr_stair[0];
		return 0;
	}
	else if (nrof_stairs == 2) {
		std::cout << arr_stair[0] + arr_stair[1];
		return 0;
	}
	else if (nrof_stairs == 3) {
		std::cout << std::max(arr_stair[0] + arr_stair[2], arr_stair[2] + arr_stair[1]);
		return 0;
	}
	arr_sum[0] = arr_stair[0];
	arr_sum[1] = arr_stair[0] + arr_stair[1];
	arr_sum[2] = std::max(arr_stair[0] + arr_stair[2], arr_stair[2] + arr_stair[1]);
	for (int j = 3; j < 300; j++) {
		arr_sum[j] = std::max(arr_stair[j] + arr_sum[j - 2], arr_stair[j] + arr_stair[j - 1] + arr_sum[j - 3]);
	}
	std::cout << arr_sum[nrof_stairs - 1];
}