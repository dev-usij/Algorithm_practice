// FuncDevelopment.cpp
// 기능 개발
// https://programmers.co.kr/learn/courses/30/lessons/42586
// Created by 박지수 on 2022/03/14.
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
	queue<int> queue; // 수행해야할 양 (100 - progress)
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

	// 예외처리 size 1 or 0일때
	if (queue.size() == 1)
		return { 1 };
	else if (queue.size() == 0)
		return { 0 };

	int refrencPoint = queue.front(); // 기준점.
	queue.pop();
	while (!queue.empty())
	{
		int curr = queue.front();
		queue.pop();

		if (refrencPoint >= curr)
		{
			++date;
		}
		else // 기준점보다 큰 경우, 기준점 변경 및 날짜 초기화
		{
			answer.push_back(date);
			date = 1;
			refrencPoint = curr; 
		}

	}
	answer.push_back(date);
	return answer;
}