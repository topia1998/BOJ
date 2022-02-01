#include <stdio.h>
#include<iostream>
#include<vector>
#include<queue>
using namespace std;
#define INF 1e9 

int n, m, start, finish;

vector<pair<int, int> > graph[100001];
int d[100001];

void dijkstra(int start)
{
    priority_queue<pair<int, int>>pq; 

    pq.push({ 0,start });
    d[start] = 0;

    while (!pq.empty()) {
        int dist = -pq.top().first;
        int now = pq.top().second;
        pq.pop();

        if (d[now] < dist)
            continue;

        for (int i = 0; i < graph[now].size(); i++) {
            int cost = dist + graph[now][i].second;

            if (cost < d[graph[now][i].first]) {
                d[graph[now][i].first] = cost;
                pq.push(make_pair(-cost, graph[now][i].first));
            }
        }
    }
}

int main(void) {
    int a, b, c;

    scanf("%d %d", &n, &m);

    for (int i = 0; i < m; i++) {
        scanf("%d %d %d", &a, &b, &c);
        graph[a].push_back({ b, c });
    }

    scanf("%d %d", &start, &finish);

    fill(d, d + 100001, INF);

    dijkstra(start);

    printf("%d\n", d[finish]);
}