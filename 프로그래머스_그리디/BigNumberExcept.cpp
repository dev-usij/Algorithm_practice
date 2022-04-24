#include "BigNumberExcept.h"
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

string solution(string number, int k)
{
	string answer = "";
	int answerLength = number.length() - k;
	int max = -1;
	int index = -1;
	for (int i = 0; i < answerLength; ++i)
	{
		for (int j = index + 1; j < number.length() - (answerLength-i)+1; ++j)
		{
			if (max < number[j] - '0')
			{
				max = number[j] - '0';
				index = j;
			}
		}
		answer += to_string(max);
		max = -1;
	}
	return answer;
}