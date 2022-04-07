// PassingThroughBridge.cpp
// 다리를 지나는 트럭
// https://programmers.co.kr/learn/courses/30/lessons/42583
// Created by 박지수 on 2022/03/15.

#include <iostream>
#include <algorithm>
#include <string>
#include <queue>
#include <unordered_map>
#include <vector>
#include <deque>
using namespace std;

int solution(int bridge_length, int weight, vector<int> truck_weights)
{
	// 1<= truck_weights< 10,000
	int answer = 0;
	int idx = 0;
	int sum = 0;
	queue<int> q;
	
	while (true)
	{
		if (idx == truck_weights.size())
		{
			answer += bridge_length;
			break;
		}
		++answer;
		int tmp = truck_weights[idx];

		if (q.size() == bridge_length)
		{
			sum -= q.front();
			q.pop();
		}

		if (sum + tmp <= weight)
		{
			q.push(tmp);
			++idx;
			sum += tmp;
		}
		else
			q.push(0);
	}
	return answer;
}