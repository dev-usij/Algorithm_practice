#include "LinkIsland.h"
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <memory.h>
using namespace std;
struct Edge
{
	int s, t, w;
	Edge(int _s, int _t, int _w) : s(_s), t(_t), w(_w) {}
};
//bool compare(const Edge& a, const Edge& b)
//{
//	return a.w > b.w;
//}

struct  cmp
{
	/*bool operator()(Edge& a, Edge& b)
	{
		return a.w > b.w;
	}*/
	bool operator()(pair<int, int>& a, pair<int, int>& b)
	{
		return a.second > b.second;
	}
};
struct compare {
	bool operator()(pair<int, int>a, pair<int, int>b) {
		return a.second > b.second;
	}
};

int solution(int n, vector<vector<int>> costs)
{
	int answer = 0;
	int cnt = 0;
	//vector<Edge> adj[100];
	vector<pair<int, int>> adj[100];
	bool visited[100];
	memset(visited, false, sizeof(visited));

	for (int i = 0; i < n; ++i)
		adj[i].clear();

	for (auto elem : costs)
	{
		vector<int> e = elem;
		adj[e[0]].push_back(make_pair(e[1], e[2]));
		adj[e[1]].push_back(make_pair(e[0], e[2]));
	}
	priority_queue<pair<int, int> > pq;	// -비용 / 인접노드
	for (auto elem : adj[0])
	{
		pq.push({ -elem.second, elem.first });
	}
	visited[0] = true;
	cnt = 1;
	while (!pq.empty())
	{
		pair<int, int> elem = pq.top();
		pq.pop();
		if (visited[elem.second] == true)
			continue;
		visited[elem.second] = true;
		answer += -elem.first;
		for (auto e : adj[elem.second])
		{
			pq.push({ -e.second, e.first });
		}
		++cnt;
		if (cnt == n)
			break;
	}

	return answer;
}

/*
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
int d[101];

int getParent(int node){
	if(node == d[node]){
		return node;
	}
	else return d[node] = getParent(d[node]);
}

bool compare(vector<int> a, vector<int> b){
	return a[2] < b[2];
}

int solution(int n, vector<vector<int>> costs) {

	int answer = 0;
	for(int i =0; i<n; i++){
		d[i] = i;
	}
	sort(costs.begin(), costs.end(), compare);
	for(int i=0; i<costs.size(); i++){
		int start = getParent(costs[i][0]);
		int end = getParent(costs[i][1]);
		int cost = costs[i][2];

		if(start != end){
			d[end] = start;

			answer += cost;
		}
	}


	return answer;
}

*/