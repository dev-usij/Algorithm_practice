//
//  Carpet.cpp
//  프로그래머스_완전탐색
//
//  Created by 박지수 on 2022/04/17.
//

#include "Carpet.hpp"
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <math.h>
using namespace std;
vector<pair<int,int>> GetDivisor(int num)
{
    // return : first <= second
    vector<pair<int,int>> vecDivisor;
    
    for(int i = 1; i<= sqrt(num) ;++i)
    {
        if(num % i == 0)
        {
            vecDivisor.push_back({i, num/i});
        }
    }
    return vecDivisor;
}
vector<int> solution(int brown, int yellow)
{
    vector<int> answer;
    int row = 0;
    int col = 0;
    vector<pair<int,int>> vecDivisors;
    int total = 0;
    
    vecDivisors = GetDivisor(yellow);
    
    for(auto elem : vecDivisors)
    {
        row = elem.first + 2;
        col = elem.second + 2;
        total = row * col;
        if(total - (elem.first * elem.second) == brown )
        {
            return {col, row};
        }
    }
    answer = {0,0};
    return answer;
}
