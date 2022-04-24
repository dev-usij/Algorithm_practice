//
//  MockTest.cpp
//  프로그래머스_완전탐색
//
//  Created by 박지수 on 2022/04/17.
//

#include "MockTest.hpp"
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
bool compare(pair<int,int>&a, pair<int,int>&b)
{
    if(a.first==b.first)
        return a.second < b.second; // 0 < 1
    return a.first > b.first;
}
vector<int> solution(vector<int> answers) {
    vector<int> answer;
    vector<int> vecA = {1,2,3,4,5};
    vector<int> vecB = {2, 1, 2, 3, 2, 4, 2, 5};
    vector<int> vecC = {3, 3, 1, 1, 2, 2, 4, 4, 5, 5};
    vector<vector<int>> vecABC = {vecA,vecB,vecC};
    vector<pair<int,int>> correctAnswers; // correctAnswer / index
    
    int index = 0;
    for(int i=0;i<3;++i)
    {
        pair<int, int> elem;
        elem.first = 0;
        elem.second = index++;
        correctAnswers.push_back(elem);
    }
    
    for(size_t i = 0;i<answers.size();++i)
    {
        for(size_t j=0;j<vecABC.size();++j)
        {
            int vecSize = (int)vecABC[j].size();
            //cout<< i%vecSize<< " ";
            if(answers[i] == vecABC[j][i%vecSize])
            {
                correctAnswers[j].first++;
            }
        }
    }
    
    sort(correctAnswers.begin(), correctAnswers.end(),compare);
    
    
    if(correctAnswers[0].first==0)
        return {};
    int max = correctAnswers[0].first;
    for(auto elem : correctAnswers)
    {
        if(elem.first == max)
        {
            answer.push_back(++elem.second);
        }
    }
    return answer;
}
