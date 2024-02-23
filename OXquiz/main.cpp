#include <iostream>
#include <vector>
#include <string>
int main() {
	int N;
	std::cin >> N;
	std::vector<std::string> v(N, "");
	for(int i = 0;i<N;i++){
		std::string str;
		std::cin >> str;
		v[i] = str;
	}
	for (int i = 0; i < N; i++) {
		int score = 0;
		int total = 0;
		for (int j = 0; j < v[i].size(); j++) {
			if (v[i][j] == 'O') {
				score += 1;
				total += score;
			}
			else {
				score = 0;
			}
		}
		std::cout << total<<std::endl;
	}
}