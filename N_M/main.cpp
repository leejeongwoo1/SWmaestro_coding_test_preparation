#include <iostream>
#include <vector>

bool promising(std::vector<int> arr, int index, int num) {
	bool flag;
	int k;
	k = 1;
	flag = true;
	if (k < index) {
		for (int i = 1; i < index; i++) {
			if (arr[i] == num) {
				flag = false;
				break;
			}
		}
	}
	return flag;

}
void n_m(int N, int M, std::vector<int> arr, int index, int num) {
	if (promising(arr, index, num)) {
		if (index == M) {
			for (int i = 1; i <= M; i++) {
				std::cout << arr[i] << " ";
			}
			std::cout << "\n";
		}
		else {
			for (int i = 1; i <= N; i++) {
				arr[index + 1] = i;
				n_m(N, M, arr, index + 1, i);
			}
		}
	}
}


int main() {
	int N, M;
	std::cin >> N >> M;
	std::vector<int> arr(M+1, 0);
	n_m(N, M, arr, 0, 0);
}
