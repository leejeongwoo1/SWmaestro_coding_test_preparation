#include <iostream>

int main() {
	int N;
	std::cin >> N;
	long long** arr = new long long* [N];
	for (int i = 0; i < N; i++) {
		arr[i] = new long long[10];
	}
	arr[0][0] = 0;
	for (int i = 1; i < 10; i++) {
		arr[0][i] = 1;
	}
	for (int i = 1; i < N; i++) {
		for (int j = 0; j < 10; j++) {
			if (j == 0) {
				arr[i][j] = arr[i - 1][j + 1];
			}
			else if (j == 9) {
				arr[i][j] = arr[i - 1][j - 1];
			}
			else {
				arr[i][j] = (arr[i - 1][j - 1] + arr[i - 1][j + 1])%1000000000;
			}
		}
	}
	long long result = 0;
	for(int i=0;i<10;i++){
		result = (result+arr[N-1][i])%1000000000;
	}
	std::cout << result;
}