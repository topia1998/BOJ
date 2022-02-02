#include <stdio.h>
#include <vector>
#include <algorithm>

using namespace std;

int check[10000];

class Edge {
public:
	int node[2];
	int distance;
	Edge(int a, int b, int distance) {
		this->node[0] = a;
		this->node[1] = b;
		this->distance = distance;
	}

	bool operator<(Edge& edge) {
		return this->distance < edge.distance;
	}
};

int getParent(int node) {
	if (check[node] == node) return node;
	return getParent(check[node]);
}

void unionParent(int node1, int node2) {
	node1 = getParent(node1);
	node2 = getParent(node2);
	if (node1 < node2) check[node2] = node1;
	else check[node1] = node2;
}

bool isCycle(int node1, int node2) {
	node1 = getParent(node1);
	node2 = getParent(node2);
	if (node1 == node2) return true;
	else return false;
}

int main() {
	int v, e;
	int a, b, c;
	scanf("%d %d", &v, &e);

	vector<Edge> tr;
	for (int i = 0; i < e; i++) {
		scanf("%d %d %d", &a, &b, &c);
		tr.push_back(Edge(a, b, c));
	}

	sort(tr.begin(), tr.end());

	for (int i = 0; i < v; i++) {
		check[i] = i;
	}

	int sum = 0;
	for (int i = 0; i < tr.size(); ++i) {
		if (!isCycle(tr[i].node[0], tr[i].node[1])) {
			sum += tr[i].distance;
			unionParent(tr[i].node[0], tr[i].node[1]);
		}
	}

	printf("%d\n", sum);
	return 0;
}