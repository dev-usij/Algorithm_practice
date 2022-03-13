//
//  Disguised.cpp
//  algo2022
//  위장
//  https://programmers.co.kr/learn/courses/30/lessons/42578
//  Created by 박지수 on 2022/03/13.
//


//{{"yellowhat", "headgear"}, {"bluesunglasses", "eyewear"}, {"green_turban", "headgear"}}
#include "Disguised.hpp"
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <unordered_map>

// 조합
// (n1+1C1 * n2+1C1 * ...  ) - 1;
int solution(vector<vector<string>> clothes)
{
    int sum = 1;
    unordered_map<string, int> hashMap;
    for(auto cloth : clothes)
    {
        auto type = cloth[1];
        if(hashMap.end()!= hashMap.find(type))
        {
            hashMap[type] += 1;
        }
        else
            hashMap[type] = 1;
    }
    
    for(auto type : hashMap)
    {
        int value = type.second +1;
        sum *= value;
    }
    
    return sum-1;
}
