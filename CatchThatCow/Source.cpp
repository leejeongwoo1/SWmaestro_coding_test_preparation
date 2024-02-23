#include <iostream>
#include <queue>

int main() {
	int N, K,min=0;
	int level=0;
	int prev_length = 0;
	int aft_length = 0;
	bool visited[100001] = { false };
	std::cin >> N >> K;
	std::queue<int> queue;
	queue.push(N);
	visited[N] = true;
	prev_length += 1;
	while (queue.front() != K) {
		int front = queue.front();
		queue.pop();
		prev_length -= 1;
		

		if (!visited[front + 1]&& front+1 >= 0 && front+1 <= 100000) {
			queue.push(front + 1);
			visited[front + 1] = true;
			aft_length += 1;
		}
		if (!visited[front - 1]&& front-1 >= 0 && front-1 <= 100000) {
			queue.push(front - 1);
			visited[front - 1] = true;
			aft_length += 1;
		}
		if (!visited[front * 2]&& front*2 >= 0 && front*2 <= 100000) {
			queue.push(front * 2);
			aft_length += 1;
			visited[front * 2] = true;
		}
		if (prev_length == 0) {
			//std::cout << "1";
			level += 1;
			prev_length = aft_length;
			aft_length = 0;
		}
	}

	std::cout << level;
}