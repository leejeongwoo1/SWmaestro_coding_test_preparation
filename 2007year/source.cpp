#include <iostream>
#include <vector>

int main() {
	std::vector<std::string> day = {"SUN","MON","TUE","WED","THU","FRI","SAT"};
	int arr[13] = { 0,31,28,31,30,31,30,31,31,30,31,30,31 };
	int num = 0;
	int x, y;
	std::cin >> x >> y;
	for (int i = 0; i < x; i++) {
		num += arr[i];
	}
	num += y;
	//나머지 0 => 일,나머지 1 => 월, 2=>화
	num = num % 7;
	std::cout << day[num];
}