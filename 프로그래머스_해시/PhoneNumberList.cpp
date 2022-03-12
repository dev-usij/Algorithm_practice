//
//  PhoneNumberList.cpp
//  algo2022
//  프로그래머스_해시
//  전화번호 목록
//  https://programmers.co.kr/learn/courses/30/lessons/42577
//  Created by 박지수 on 2022/03/12.
//

#include "PhoneNumberList.hpp"
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <unordered_map>
#include <queue>
using namespace std;

void phoneTest()
{
    cout<<"hi"<<endl;
}
bool cmp(string a, string b)
{
    if(a.length() == b.length())
        return a.length() > b.length();
    return a.length() < b.length();
}

// 정확성은 모두 통과 but, 효율성 : 시간초과
bool solution_sortAndSub(vector<string> phone_book)
{
    sort(phone_book.begin(),phone_book.end());
    
    size_t cnt =phone_book.size();
    for(size_t i=0; i<cnt-1; ++i)
    {
        if(i+1 >= cnt)
            break;
        size_t cutSize = phone_book[i].size();
        for(size_t j=i+1; j<cnt; ++j)
        {
            string str = phone_book[j].substr(0, cutSize);
            if(phone_book[i].compare(str) == 0)
            {
                return false;
            }
        }
    }
    return true;
}

// pass
bool solution_priorityQueue(vector<string> phone_book)
{
    priority_queue<string,vector<string>,greater<string>> pq;
    for(auto elem : phone_book)
        pq.push(elem);
    
    string prev = pq.top();
    pq.pop();
    while(!pq.empty())
    {
        string curr =pq.top();
        pq.pop();
        if(curr.find(prev)==0)
            return false;
        prev = curr;
        
    }
    return true;
}

// 해시로 이용한 방법
bool solution_hashMap(vector<string> phone_book) {
    bool answer = true;

    unordered_map<string, int> hash;
    size_t bookSize = phone_book.size();
    for(int i = 0; i < bookSize; i++)
        hash[phone_book[i]] = 1;

    
    for(int i = 0; i < bookSize; i++) {
        string phone_number = "";
        for(int j = 0; j < phone_book[i].size(); j++) {
            phone_number += phone_book[i][j];
            if(hash[phone_number] && phone_number != phone_book[i])
                answer = false;
        }
    }

    return answer;
}
