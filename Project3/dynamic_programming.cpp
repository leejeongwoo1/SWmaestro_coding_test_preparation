#include <iostream>

int main() {
	int arr[11];
	arr[1] = 1;
	arr[2] = 2;
	arr[3] = 4;
	for (int i = 4; i < 11; i++) {
		arr[i] = arr[i-1] + arr[i-2] + arr[i-3];
	}
	int nrof_test;
	std::cin >> nrof_test;
	int* arr_req = new int[nrof_test];
	for (int i = 0; i < nrof_test; i++) {
		int temp = 0;
		std::cin >> temp;
		arr_req[i] = temp;
	}

	for (int i = 0; i < nrof_test; i++) {
		std::cout << arr[arr_req[i]]<<"\n";
	}
}