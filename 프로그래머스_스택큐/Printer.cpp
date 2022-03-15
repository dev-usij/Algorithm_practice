// Printer.cpp
// 프린터
// https://programmers.co.kr/learn/courses/30/lessons/42587
// Created by 박지수 on 2022/03/14.

#include <iostream>
#include <algorithm>
#include <string>
#include <queue>
#include <unordered_map>
#include <vector>
using namespace std;

// 처음 문제 이해를 잘못함.
/*
['1',2,3] => 3

- [2,3,'1'] =>3 제거 
- ['1', 2] => 2가 우선순위가 더 큼   [3]
- [2,'1'] 
- ['1'] => [3,2]
- [] => [3,2,'1'] 
==> answer : 3  
*/
int solution_printer(vector<int> priorities, int location)
{
	int answer = 0;  // 차례
	queue<pair<int,int>> queue; // value : index
	priority_queue<int> pq; // 우선순위 큐
	size_t priorSize = priorities.size();
	for (int i = 0; i < priorSize; ++i)
	{
		int value = priorities[i];
		int idx = i;
		queue.push({ value, idx});
		pq.push(value);
	}
	while (!queue.empty())
	{
		int value = queue.front().first;
		int index = queue.front().second;
		queue.pop();
		if (pq.top() == value)
		{
			++answer;
			pq.pop();
			if (location == index)
			{
				return answer;
			}
		}
		else
		{
			queue.push({ value, index });
		}
	}

	return answer;
}