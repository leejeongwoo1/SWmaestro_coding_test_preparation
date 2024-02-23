#include <iostream>


int sum_of_stairs(int n,int* stairs) {
	if (n == 0) {
		return stairs[0];
	}else if(n < 0) {
		return 0;
	}
	return std::max(stairs[n] + stairs[n - 1] + sum_of_stairs(n - 3, stairs), stairs[n] + sum_of_stairs(n - 2, stairs));
}

int main() {
	int nrof_stairs=50;
	//std::cin >> nrof_stairs;

	int* arr_stair = new int[nrof_stairs];
	for (int i = 0; i < nrof_stairs; i++) {
		int temp=1;
		//std::cin >> temp;
		arr_stair[i] = temp;
	}
	
	std::cout<< sum_of_stairs(nrof_stairs - 1, arr_stair);
}