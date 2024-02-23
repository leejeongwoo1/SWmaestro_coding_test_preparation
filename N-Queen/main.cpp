#include <iostream>
#include <vector>
#include <cmath>
//#include <ctime>

void n_queens(int,int*, int, int*);
bool promising(int*, int);

int main() {
	//clock_t start, finish;
	//double duration;

	//start = clock();

	int N,cnt;
	cnt = 0;
	std::cin >> N;

	int* vec = new int[N + 1];
	n_queens(N,vec, 0, &cnt);
	std::cout << cnt << std::endl;
	//finish = clock();
	//duration = (double)(finish - start) / CLOCKS_PER_SEC;
	//std::cout << duration << "ÃÊ" << std::endl;

}

void n_queens(int size,int* vec, int index,int* cnt) {
	if (promising(vec, index)) {
		if (index == size) {
			*cnt += 1;
		}
		else {
			for (int i = 1; i <= size; i++) {
				vec[index + 1] = i;
				n_queens(size,vec, index + 1, cnt);
			}
		}
	}
}

bool promising(int* vec, int index) {
	bool flag = true;
	int k = 1;
	while (k<index && flag) {
		if (vec[k] == vec[index] || index - k == abs(vec[index] - vec[k])) {
			flag = false;
		}
		k++;
	}
	return flag;
}