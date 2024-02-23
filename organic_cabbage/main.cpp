#include <iostream>
void check_visit(int x, int y, int** arr, int len_x, int len_y);
int main() {
	int T;
	std::cin >> T;
	int* result = new int[T];
	for (int i = 0; i < T; i++) {
		int X, Y, K;
		int total=0;
		std::cin >> X >> Y >> K;
		int** arr = new int* [Y];
		for (int j = 0; j < Y; j++) {
			arr[j] = new int[X];
			for (int k = 0; k < X; k++) {
				arr[j][k] = 0;
			}
		}
		for (int j = 0; j < K; j++) {
			int x, y;
			std::cin >> x >> y;
			arr[y][x] = 1;
		}

		for (int y_ = 0; y_ < Y; y_++) {

			for (int x_ = 0; x_ < X; x_++) {
				if (arr[y_][x_] == 1) {
					check_visit(x_, y_, arr, X, Y);
					total += 1;
				}
			}
		}
		result[i] = total;
	}
	for (int i = 0; i < T;i++) {
		std::cout << result[i] << "\n";
	}
}

void check_visit(int x, int y, int** arr, int len_x, int len_y) {
	arr[y][x] = 2;
	if (x + 1 < len_x && arr[y][x + 1] == 1) {
		check_visit(x + 1, y, arr, len_x, len_y);
	}
	if (y + 1 < len_y && arr[y + 1][x] == 1) {
		check_visit(x, y + 1, arr, len_x, len_y);
	}
	if (x - 1 >= 0 && arr[y][x - 1] == 1) {
		check_visit(x - 1, y, arr, len_x, len_y);
	}
	if (y - 1 >= 0 && arr[y - 1][x]==1) {
		check_visit(x, y - 1, arr, len_x, len_y);
	}
}