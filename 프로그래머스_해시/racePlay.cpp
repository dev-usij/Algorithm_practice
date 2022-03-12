//
//  racePlay.cpp
//  프로그래머스_해시
//  완주하지 못한 선수
// https://programmers.co.kr/learn/courses/30/lessons/42576
//  Created by 박지수 on 2022/03/10.
//

#include "racePlay.hpp"
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <unordered_map>
using namespace std;

int foo(int a)
{
    cout<< a <<endl;
    return 0;
}

//hash 사용시 O(n), sort 사용시 O(nlog₂n)
// 해시 사용이 시간 복잡도에선 좋다.

string solution_sort(vector<string> participant, vector<string> completion)
{
    string name ="";
    vector<string> vecResult;
    vecResult.resize(completion.size());
    
    sort(participant.begin(),participant.end());
    sort(completion.begin(),completion.end());
    
    auto iter = set_difference(participant.begin(), participant.end(), completion.begin(), completion.end(), vecResult.begin());

    vecResult.erase(iter,vecResult.end());
    //vecResult.resize(iter - vecResult.begin());
    
    return vecResult[0];
}


string solution_hash(vector<string> participant, vector<string> completion)
{
    unordered_map<string, int> hash;
    string name="";
    // 참가자 등록. 동명인 경우, 인원 수 +1
    for(auto elem : participant)
    {
        if(hash.find(elem) != hash.end())
        {
            hash[elem] += 1;
        }
        else
            hash[elem] = 1;
    }
    // 완료자 삭제.
    for(auto elem : completion)
    {
        if(hash.find(elem) != hash.end())
        {
            hash[elem] -=1;
        }
    }
    // 삭제가 되지 않은 이름은 완주하지 못함.
    for(auto elem : hash)
    {
        if(elem.second > 0)
        {
            name = elem.first;
            break;
        }
    }
    return name;
}

