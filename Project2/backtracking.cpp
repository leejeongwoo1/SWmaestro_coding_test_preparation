#include <iostream>
#include <vector>
#include <chrono>


class node {
public:
	int order;
	int sum;
	int num;
	int back;
	bool step;
	node(int _order, int _sum, int _num, int _back,bool _step)
		: order(_order), sum(_sum), num(_num), back(_back), step(_step) {}
};

bool promising(int i,int weight,int* result,std::vector<node> total) {
	int max = weight;
	for (int j = i + 1; j < total.size(); j++) {
		max += total[j].num;
	}
	if (total.size() <= i || total[i].back == 2 || (i == total.size() - 2 && total[i].back == 1)) {
		return false;
	}
	else if (i == total.size() - 1 && *result > weight) {
		return false;
	}
	else if (max <= *result) {
		return false;
	}
	else {
 		return true;
	}
}

 void sum_of_stairs(int i,int weight, std::vector<node> total,int *result) {
	if (promising(i, weight, result,total)) {
		total[i].step = 1;
		if (i == total.size()-1) {
			*result = weight;
		}
		else {
			if (i == 0) {
				total[i + 1].back = 0;
			}
			else if (i == total.size() - 2) {
				total[i + 1].back = total[i].back + 1;
			}
			else {
				total[i + 1].back = total[i].back + 1;
			}
			sum_of_stairs(i + 1, weight+total[i+1].num, total, result);
			sum_of_stairs(i + 2, weight+total[i+2].num, total, result);
		}
	}
}

int main() {
	//auto start_time = std::chrono::high_resolution_clock::now();
	int nrof_stair;
	std::vector<node> stairs;
	std::cin >> nrof_stair;
	node zero(0, 0, 0, 0, false);
	stairs.push_back(zero);
	for (int i = 0; i < nrof_stair; i++) {
		int temp;
		std::cin >> temp;
		stairs.push_back(node(i+1,0,temp,0,0));
	}
	//std::vector<bool> include(nrof_stair+1);
	int result=0;
	sum_of_stairs(0, 0, stairs, &result);
	std::cout << result;
	//auto end_time = std::chrono::high_resolution_clock::now();

	// 실행 시간 계산
	//auto duration = std::chrono::duration_cast<std::chrono::microseconds>(end_time - start_time);

	// 결과 출력
	//std::cout << "\nExecution time: " << duration.count()*1e-6 << " microseconds" << std::endl;

	return 0;
}

