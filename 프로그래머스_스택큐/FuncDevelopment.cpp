// FuncDevelopment.cpp
// ��� ����
// https://programmers.co.kr/learn/courses/30/lessons/42586
// Created by ������ on 2022/03/14.
#include <iostream>
#include <algorithm>
#include <string>
#include <queue>
#include <unordered_map>
using namespace std;

int testFunc()
{
	return 1;
}

vector<int> solution(vector<int> progresses, vector<int> speeds)
{
	vector<int> answer;
	queue<int> queue; // �����ؾ��� �� (100 - progress)
	int date = 1;
	int max = 100;
	size_t progressesSize = progresses.size();
	for (size_t i = 0; i < progressesSize; ++i)
	{
		int cal = (100 - progresses[i]) / speeds[i];
		int mod = (100 - progresses[i]) % speeds[i];
		if (mod != 0)
			++cal;
		queue.push(cal);
	}

	// ����ó�� size 1 or 0�϶�
	if (queue.size() == 1)
		return { 1 };
	else if (queue.size() == 0)
		return { 0 };

	int refrencPoint = queue.front(); // ������.
	queue.pop();
	while (!queue.empty())
	{
		int curr = queue.front();
		queue.pop();

		if (refrencPoint >= curr)
		{
			++date;
		}
		else // ���������� ū ���, ������ ���� �� ��¥ �ʱ�ȭ
		{
			answer.push_back(date);
			date = 1;
			refrencPoint = curr; 
		}

	}
	answer.push_back(date);
	return answer;
}