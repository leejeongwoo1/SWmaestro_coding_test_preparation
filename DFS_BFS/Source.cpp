#include <iostream>
#include <vector>
#include <stack>
#include <queue>

int main() {
	std::vector<int> DFS, BFS;
	int N, M, V;
	std::cin >> N >> M >> V;
	bool** graph = new bool* [N+1];
	for (int i = 0; i < N+1; i++) {
		graph[i] = new bool[N+1];
	}
	for (int i = 0; i < M; i++) {
		int left, right;
		std::cin >> left >> right;
		graph[left][right] = 1;
		graph[right][left] = 1;
	}
	bool* visited = new bool[N + 1]{ false };
	
	//stack
	std::stack<int> stack;
	stack.push(V);
	visited[V] = true;
	DFS.push_back(V);
	while (!stack.empty()) {
		int flag = false;
		for (int i = 1; i < N + 1; i++) {
			if (graph[stack.top()][i]&&!visited[i]) {
				flag = true;
				stack.push(i);
				visited[i] = true;
				DFS.push_back(i);
				break;
			}
		}
		if (!flag) {
			stack.pop();
		}
	}
	for (int i = 0; i < DFS.size(); i++) {
		std::cout << DFS[i]<<" ";
	}
	std::cout << '\n';
	//queue
	for (int i = 0; i < N + 1; i++) {
		visited[i] = false;
	}
	std::queue<int> queue;
	queue.push(V);
	visited[V] = true;
	BFS.push_back(V);
	while (!queue.empty()) {
		int front = queue.front();
		queue.pop();
		int flag = false;
		for (int i = 1; i < N + 1; i++) {
			if (graph[front][i] && !visited[i]) {
				flag = true;
				queue.push(i);
				visited[i] = true;
				BFS.push_back(i);

			}
		}
	}
	for (int i = 0; i < BFS.size(); i++) {
		std::cout << BFS[i]<<" ";
	}
}