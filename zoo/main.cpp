#include <iostream>
#include <vector>
int main() {
	int N;
	std::cin >> N;

	std::vector<std::vector<int>> v(N, std::vector<int>(3, 0));
	v[0] = std::vector<int>(3, 1);
	for (int i = 1; i < N; i++) {
		v[i][0] = (v[i - 1][0] + v[i - 1][2])%9901;
		v[i][1] = v[i][0];
		v[i][2] = (v[i - 1][0] + v[i - 1][1] + v[i - 1][2])%9901;
	}
	std::cout << (v[N - 1][0] + v[N - 1][1] + v[N - 1][2])%9901;
}