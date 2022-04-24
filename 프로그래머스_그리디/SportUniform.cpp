#include "SportUniform.h"

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
/*
���� ü������ ������ �л��� ü������ ���������� �� �ֽ��ϴ�. 
�̶� �� �л��� ü������ �ϳ��� �������ߴٰ� �����ϸ�, 
���� ü������ �ϳ��̱⿡ �ٸ� �л����Դ� ü������ ������ �� �����ϴ�.
*/
int solution(int n, vector<int> lost, vector<int> reserve)
{
	int answer = 0;
	vector<int> students;
	// -1: ü���� ����, 0: ���� ü���� , 1:������ ü����
	students.assign(n, 0);

	for (auto elem : lost)
	{
		students[elem - 1] -=1;
	}
	for (auto elem : reserve)
	{
		students[elem - 1] += 1;
	}

	for (int i = 0; i < n; ++i)
	{
		if (students[i] < 0)
		{
			if (i - 1 >= 0 && students[i - 1] > 0)
			{
				students[i] += 1;
				students[i - 1] -= 1;
				continue;
			}
			else if (i + 1 < n && students[i + 1] >0)
			{
				students[i] +=1;
				students[i + 1] -=1;
				continue;
			}
		}
	}
	for (auto elem : students)
	{
		if (elem >=0)
			++answer;
	}
	return answer;
}

/*

int answer = 0;
	vector<ActionType> _students;
	_students.assign(n, ActionType::None);

	for (int i = 0; i < _students.size(); ++i)
	{
		if (find(lost.begin(), lost.end(), i + 1) != lost.end())
		{
			_students[i] = ActionType::Lost;
		}
		else if (find(reserve.begin(), reserve.end(), i + 1) != reserve.end())
		{
			_students[i] = ActionType::Reserve;
		}
		else
			_students[i] = ActionType::None;
	}

	for (int i = 0; i < _students.size(); ++i)
	{
		if (_students[i] == ActionType::Lost)
		{
			if (i - 1 >= 0 && _students[i - 1] == ActionType::Reserve)
			{
				_students[i] = ActionType::None;
				_students[i - 1] = ActionType::None;
			}
			else if (i + 1 < _students.size() && _students[i + 1] == ActionType::Reserve)
			{
				_students[i] = ActionType::None;
				_students[i + 1] = ActionType::None;
			}
		}
	}

	for (auto stu : _students)
	{
		if (stu != ActionType::Lost)
			++answer;
	}

	return answer;*/