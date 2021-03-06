#include <iostream>
#include <vector>
#include <queue>
using namespace std;
int main()
{
	int vertices, vertex_n;
	cin >> vertices >> vertex_n;
	--vertex_n;
	vector<vector<int>> graph(vertices);
	for (int i = 0; i < vertices; ++i) {
		vector<int>tmp(vertices);
		for (int j = 0; j < vertices; ++j) cin >> tmp[j];
		graph[i] = tmp;
	}
	vector<int> dist(vertices, -1);

	queue<int>q;
	q.push(vertex_n);
	dist[vertex_n] = 0;
	while (q.size() != 0) {
		int v = q.front();
		for (int i = 0; i < vertices; ++i) {
			if (graph[v][i] && dist[i] == -1) {
				dist[i] = dist[v] + 1;
				q.push(i);
			}
		}
		q.pop();
	}

	for (int e : dist) cout << e << ' ';
    return 0;
}

