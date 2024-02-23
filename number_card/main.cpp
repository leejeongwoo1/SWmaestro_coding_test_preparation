#include <iostream>
#include <algorithm>
void quick_sort(long* data, long start, long end);
bool binary_search(long ele, long* data, long start, long end);
int main() {
	long N, M;
	std::cin >> N;
	long* arr1 = new long[N];
	for (int i = 0; i < N; i++) {
		long temp;
		std::cin >> temp;
		arr1[i] = temp;
	}
	std::cin >> M;
	long* arr2 = new long[M];
	for (int i = 0; i < M; i++) {
		long temp;
		std::cin >> temp;
		arr2[i] = temp;
	}
	
	std::sort(arr1, arr1+N);

	for (int i = 0; i < M; i++) {
		std::cout << binary_search(arr2[i], arr1, 0, N - 1) << " ";
	}
}

bool binary_search(long ele, long* data, long start, long end) {
	bool find = false;
	while (!find && start <= end) {
		long mid = (start + end) / 2;
		if (data[mid] == ele) {
			find = true;
			break;
		}
		else if (data[mid] > ele) {
			end = mid - 1;
		}
		else if (data[mid] < ele) {
			start = mid + 1;
		}
	}
	return find;
}
void quick_sort(long* data, long start, long end) {
	if (start >= end) {
		return;
	}
	long pivot = start;
	long i = pivot + 1;
	long j = end;
	long temp;

	while (i <= j) {
		while (i <= end && data[i] <= data[pivot]) {
			i++;
		}
		while (j > start && data[j] >= data[pivot]) {
			j--;
		}
		if (i > j) {
			temp = data[j];
			data[j] = data[pivot];
			data[pivot] = temp;
		}
		else {
			temp = data[i];
			data[i] = data[j];
			data[j] = temp;
		}
	}
	quick_sort(data, start, j - 1);
	quick_sort(data, j + 1, end);
}