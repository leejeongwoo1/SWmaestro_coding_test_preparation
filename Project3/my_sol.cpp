#include <iostream>





int main() {
	int nrof_test;
	std::cin >> nrof_test;
	int* arr = new int[nrof_test];
	for (int i = 0; i < nrof_test; i++) {
		int temp;
		std::cin >> temp;
		arr[i] = temp;
	}

	int factorial[11];
	factorial[0] = 1;
	for (int j = 1; j < 11; j++) {
		factorial[j] = j * factorial[j - 1];
	}

	int all_arr[11];
	for (int i = 1; i <= 10; i++) {
		int one = 0;
		int two = 0;
		int three = 0;
		int temp = i;
		int result = 0;
		three = i / 3;
		for (three; three >= 0; three--) {
			temp = i;
			temp = temp - 3 * three;
			two = temp / 2;
			for (two; two >= 0; two--) {
				int temp1;
				temp1 = temp - 2 * two;
				one = temp1 / 1;
				int  nrof_cases = factorial[three + two + one] / (factorial[three] * factorial[two] * factorial[one]);
				result += nrof_cases;
				}
			}
		all_arr[i] = result;
		}
	for (int i = 0; i < nrof_test; i++) {
		std::cout << all_arr[arr[i]];
		std::cout << "\n";
	}
}
	
