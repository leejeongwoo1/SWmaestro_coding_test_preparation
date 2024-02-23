#include <iostream>
#include <queue>
class node {
public:
	int num;
	int cnt;
	node() {
		num = 0;
		cnt = 0;
	}
	node(int _num, int _cnt) {
		num = _num;
		cnt = _cnt;
	}
};

int main() {
	std::queue<node> q;
	int input;
	node result;
	std::cin >> input;
	node start(input, 0);
	q.push(start);
	while (q.front().num != 1) {
		if (q.front().num % 3 == 0) {
			q.push(node(q.front().num/3,q.front().cnt+1));
		}
		if (q.front().num % 2 == 0) {
			q.push(node(q.front().num/2,q.front().cnt+1));
		}
		q.push(node(q.front().num - 1,q.front().cnt+1));
		q.pop();
	}
	std::cout << q.front().cnt;
}
