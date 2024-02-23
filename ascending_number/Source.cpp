#include <iostream>

int main() {
	int N;
	int arr[10] = {0,0,0,0,0,0,0,0,0,1};
	std::cin >> N;
	for (int i=0; i < N; i++) {
		for (int j = 0; j < 10; j++) {
			int temp = 0;
			for (int k = j; k < 10; k++) {
				
				temp += arr[k];
				arr[j] = temp%10007;
			}
		}
	}
	int result = 0;
	for (int i = 0; i < 10; i++) {
		result += arr[i];
	}
	std::cout << result%10007;
}