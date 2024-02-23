//#include <iostream>
//#include <cmath>
//
//int main() {
//	int N, M;
//	std::cin >> N >> M;
//	int* arr = new int[M + 1];
//	for (int i = 1; i <= M; i++) {
//		arr[i] = 1;
//	}
//	int it = std::pow(N, M);
//	for (int i = 0; i < it; i++) {
//		for (int j = 1; j <= M; j++) {
//			std::cout << arr[j] << " ";
//		}
//		std::cout << "\n";
//		int digit = M;
//		while (true&&digit>=1) {
//			if (arr[digit] == N) {
//				arr[digit] = 1;
//				digit -= 1;
//			}
//			else {
//				break;
//			}
//		}
//		if (digit == 0) {
//			break;
//		}
//		arr[digit] += 1;
//	}
//}

//#include <iostream>
//#define MAX 9
//using namespace std;
//
//int n, m;
//int arr[MAX] = { 0, };
//
//
//void dfs(int cnt)
//{
//    if (cnt == m)
//    {
//        for (int i = 0; i < m; i++)
//            cout << arr[i] << ' ';
//        cout << '\n';
//        return;
//    }
//    for (int i = 1; i <= n; i++)
//    {
//        arr[cnt] = i;
//        dfs(cnt + 1);
//    }
//}
//
//int main() {
//    cin >> n >> m;
//    dfs(0);
//}
#include <iostream>
int N, M;
int arr[9] = { 0, };
void n_m(int index) {
	if (index == M) {
		for (int i = 0; i < M; i++) {
			std::cout << arr[i] << " ";
		}
		std::cout << "\n";
		return;
	}
	for (int i = 1; i <= N; i++) {
		arr[index] = i;
		n_m(index + 1);
	};
}
int main() {
	std::cin >> N >> M;
	
	n_m(0);
}


