#include <iostream>
#include <stack>
#include <vector>

class point {
public:
	int x;
	int y;
	point(int x, int y) :x(x), y(y) {};
};

point surrounding(int** arr, point p, std::vector<std::vector<bool>> visited) {
	if (p.x + 1 <= visited.size() - 1) {

		if (arr[p.y][p.x + 1] && !visited[p.y][p.x + 1]) {
			return point(p.x + 1, p.y);
		}
	}
	if (p.y + 1 <= visited.size() - 1) {
		if (arr[p.y + 1][p.x] && !visited[p.y + 1][p.x]) {
			return point(p.x, p.y+1);
		}
	}
	if (p.x - 1 >= 0) {
		if (arr[p.y][p.x - 1] && !visited[p.y][p.x - 1]) {
			return point(p.x-1, p.y);
		}
	}
	if (p.y - 1 >= 0) {
		if (arr[p.y - 1][p.x] && !visited[p.y - 1][p.x]) {
			return point(p.x, p.y-1);
		}
	}
	return point(-1, -1);
}

int main() {
	int N;
	std::cin >> N;
	int** arr = new int* [N];
	for (int i = 0; i < N; i++) {
		arr[i] = new int[N];
		for (int j = 0; j < N; j++) {
			char ch = std::cin.get();
			if (ch == '\n') {
				ch = std::cin.get();
			}
			arr[i][j] = ch -'0';
		}
	}
	std::vector<std::vector<bool>> visited(N,std::vector<bool>(N,false));
	int nrof_apt = 0;
	std::vector<int> size_vec;
	std::stack<point> stack;
	for (int y = 0; y < N; y++) {
		for (int x = 0; x < N; x++) {
			if (arr[y][x] == 1&&!visited[y][x]) {
				int size = 0;
				stack.push(point(x, y));
				visited[y][x] = true;
				nrof_apt += 1;
				size += 1;
				while (!stack.empty()) {
					point temp(-1,0);
					temp = surrounding(arr, stack.top(), visited);
					if (temp.x == -1) {
						stack.pop();
					}
					else {
						stack.push(temp);
						visited[temp.y][temp.x] = true;
						size += 1;
					}
				}
				size_vec.push_back(size);
			}
		}
	}
	std::cout << nrof_apt << "\n";
	for (int i = size_vec.size()-1; i >0; i--) {
		for (int j = 0; j <i; j++) {
			if (size_vec[j] >= size_vec[j + 1]) {
				int temp = size_vec[j];
				size_vec[j] = size_vec[j + 1];
				size_vec[j + 1] = temp;
			}
		}
	}
	for (auto& ele: size_vec) {
		std::cout << ele<<"\n";
	}
}