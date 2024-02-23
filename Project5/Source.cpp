#include <iostream>
#include <algorithm>
int main() {
	int n;
	std::cin >> n;
	int** triangle = new int* [n];
	for (int i = 0; i < n; i++) {
		triangle[i] = new int[n];
		for (int j = 0; j <= i; j++) {
			int temp;
			std::cin >> temp;
			
			triangle[i][j] = temp;
		}
	}
	for (int i = n - 2; i >= 0; i--) {
		for (int j = 0; j <= n - 2; j++) {
			triangle[i][j] = std::max(triangle[i + 1][j], triangle[i + 1][j + 1])+triangle[i][j];
		}
		
	}
	std::cout << triangle[0][0];
}