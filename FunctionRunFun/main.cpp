#include <iostream>
//#include <format>
#include <vector>
int main() {
	int*** arr = new int** [21];
	for (int i = 0; i < 21; i++) {
		arr[i] = new int* [21];
	}
	for (int i = 0; i < 21; i++) {
		for (int j = 0; j < 21; j++) {
			arr[i][j] = new int[21];
		}
	}
	for (int c = 0; c < 21; c++) {
		for (int b = 0; b < 21; b++) {
			for (int a = 0; a < 21; a++) {
				if (a == 0 || b == 0 || c == 0) {
					arr[c][b][a] = 1;
				}
				else if (a < b and b < c) {
					arr[c][b][a] = arr[c - 1][b][a] + arr[c - 1][b - 1][a] - arr[c][b - 1][a];
				}
				else {
					arr[c][b][a] = arr[c][b][a - 1] + arr[c][b - 1][a - 1] + arr[c - 1][b][a - 1] - arr[c - 1][b - 1][a - 1];
				}
			}
		}
	}
	std::vector<std::vector<int>> vec;
	while (true) {
		int a, b, c;
		std::cin >> a >> b >> c;
		if(a==-1 && b==-1 && c==-1){
			break;
		}
		else {
			std::vector<int> v = { a,b,c };
			vec.push_back(v);
		}
	}
	for (int i = 0; i < vec.size(); i++) {
		int result;
		if (vec[i][0] <= 0 || vec[i][1] <= 0 || vec[i][2] <= 0) {
			result = 1;
		}
		else if (vec[i][0] > 20 || vec[i][1] > 20 || vec[i][2]>20) {
			result = arr[20][20][20];
		}
		else if (vec[i][0] < vec[i][1] && vec[i][1] < vec[i][2]) {
			result = arr[vec[i][2] - 1][vec[i][1]][vec[i][0]] + arr[vec[i][2] - 1][vec[i][1] - 1][vec[i][0]] - arr[vec[i][2]][vec[i][1] - 1][vec[i][0]];
		}
		else {
			result = arr[vec[i][2]][vec[i][1]][vec[i][0] - 1] + arr[vec[i][2]][vec[i][1] - 1][vec[i][0] - 1] + arr[vec[i][2] - 1][vec[i][1]][vec[i][0] - 1] - arr[vec[i][2] - 1][vec[i][1] - 1][vec[i][0] - 1];
		}
		printf("w(%d, %d, %d) = %d\n", vec[i][0], vec[i][1], vec[i][2], result);
	}
}