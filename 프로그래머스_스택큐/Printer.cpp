// Printer.cpp
// ������
// https://programmers.co.kr/learn/courses/30/lessons/42587
// Created by ������ on 2022/03/14.

#include <iostream>
#include <algorithm>
#include <string>
#include <queue>
#include <unordered_map>
#include <vector>
using namespace std;

// ó�� ���� ���ظ� �߸���.
/*
['1',2,3] => 3

- [2,3,'1'] =>3 ���� 
- ['1', 2] => 2�� �켱������ �� ŭ   [3]
- [2,'1'] 
- ['1'] => [3,2]
- [] => [3,2,'1'] 
==> answer : 3  
*/
int solution_printer(vector<int> priorities, int location)
{
	int answer = 0;  // ����
	queue<pair<int,int>> queue; // value : index
	priority_queue<int> pq; // �켱���� ť
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