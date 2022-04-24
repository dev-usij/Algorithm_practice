//
//  DoublePriorityQueue.cpp
//  프로그래머스_힙
//
//  Created by 박지수 on 2022/04/16.
//

#include "DoublePriorityQueue.hpp"
#include <string>
#include <vector>
#include <queue>
#include <iostream>
// I : 삽입
// D 1: 최댓값 삭제
// D -1: 최솟값 삭제
using namespace std;
bool isValid(deque<int> &dq)
{
    if(dq.size() <= 0)
        return false;
    return true;
}
vector<int> solution(vector<string> operations)
{
    vector<int> answer;
    answer.reserve(2);
    deque<int> dq;
    for(size_t i =0; i<operations.size();++i)
    {
        string str = operations[i];
        if(str.rfind("I ", 0) == 0) // 처음 I
        {
            str.erase(0,2);
            
            dq.push_back(stoi(str));
            sort(dq.begin(), dq.end(), greater<int>()); // 내림차순 정렬
        }
        else if(str.rfind("D -", 0) == 0)  // 최솟값 삭제
        {
            if(isValid(dq))
                dq.pop_back();
        }
        else if(str.rfind("D ", 0) == 0) // 최댓값 삭제
        {
            if(isValid(dq))
                dq.pop_front();
        }
    }
    if(!isValid(dq))
        return {0,0};
    
    return {dq.front(), dq.back()};
}
