#include <iostream>
void n_m(int*, int, int, int);
bool promising(int*, int);

int main() {
	int N, M;
	std::cin >> N >> M;
	int* arr = new int[M + 1];
	n_m(arr, N, M, 0);
}

void n_m(int* arr, int N, int size, int index) {
	if (promising(arr, index)) {
		if (index == size) {
			for (int i = 1; i < size + 1; i++) {
				std::cout << arr[i] << " ";
			}
			std::cout << std::endl;
		}
		else {
			for (int i = 1; i <= N; i++) {
				arr[index + 1] = i;
				n_m(arr, N, size, index + 1);
			}
		}
	}
}

bool promising(int* arr, int index) {
	bool flag = true;
	if (index <= 1) {
		flag = true;
	}
	else if (arr[index - 1] > arr[index]) {
		flag = false;
	}
	return flag;
}