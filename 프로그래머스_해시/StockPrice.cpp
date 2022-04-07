// StockPrice.cpp
// 주식가격
// https://programmers.co.kr/learn/courses/30/lessons/42584
// Created by 지수 on 2022/04/04. 

// 문제 이해도 필요
#include <iostream>
#include <algorithm>
#include <string>
#include <queue>
#include <unordered_map>
#include <vector>
#include <deque>
#include <stack>
using namespace std;
vector<int> solution(vector<int> prices)
{
	vector<int> answer;
	int size = prices.size();
	answer.assign(size, 0);
	for (int i = 0; i < size; ++i)
	{
		for (int j = i + 1; j < size; ++j)
		{
			if (prices[i] > prices[j])
			{
				answer[i] = j - i;
				break;
			}
			if (j == size - 1)
				answer[i] = j - i;
		}
	}
	return answer;
}
vector<int> solution1(vector<int> prices)
{ // queue
	vector<int> answer;
	queue<int> q;
	for (auto elem : prices)
		q.push(elem);

	int iSelect = 0;
	while (!q.empty())
	{
		int elem = q.front();
		q.pop();
		int value = 0;

		for (int i = ++iSelect; i < prices.size(); ++i)
		{
			if (prices[i] >= elem)
			{
				++value;
			}
			else
			{
				++value;
				break;
			}
		}
		answer.push_back(value);
	}
	return answer;
}