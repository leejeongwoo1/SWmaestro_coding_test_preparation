#include <iostream>
#include <vector>
int main() {
	
	int T;
	std::cin >> T;
	int* arr = new int[T];
	for (int i = 0; i < T; i++) {
		int temp;
		std::cin >> temp;
		arr[i] = temp;
	}

	std::vector<unsigned long> v(101,0);
	v[0] = 0;
	v[1] = 1;
	v[2] = 1;
	v[3] = 1;
	v[4] = 2;
	for (int i = 5; i < 101; i++) {
		v[i] = long(v[i - 1]) + long(v[i - 5]);
	}

	for (int i = 0; i < T; i++) {
		std::cout <<v[arr[i]];
		if(i!=T-1){
			std::cout << "\n";
		}
	}
}