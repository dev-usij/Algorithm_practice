// Scoville.cpp
// ´õ ¸Ê°Ô

// Createad by Áö¼ö on 2022/04/06

#include <iostream>
#include <algorithm>
#include <string>
#include <queue>
#include <unordered_map>
#include <vector>
#include <deque>
#include <stack>

using namespace std;

int solution(vector<int> scoville, int K)
{
	// 2 <= scoville.Length
	int answer = 0;
	priority_queue<int, vector<int>, greater<int>> pq;
	int data1=0, data2=0, mix=0;
	for(auto elem : scoville)
	{
		pq.push(elem);
	}
	
	while (pq.top() < K)
	{
		if (pq.size() < 2)
			return -1;
		++answer;
		data1 = pq.top();
		pq.pop();
		data2 = pq.top();
		pq.pop();

		mix = data1 + data2 * 2;
		pq.push(mix);

	}

	return answer;
}