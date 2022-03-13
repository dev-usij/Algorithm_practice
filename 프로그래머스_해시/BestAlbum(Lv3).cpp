//
//  BestAlbum(Lv.cpp
//  algo2022
//  베스트 앨범
//  https://programmers.co.kr/learn/courses/30/lessons/42579
//  Created by 박지수 on 2022/03/13.
//

#include "BestAlbum(Lv3).hpp"
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <unordered_map>
using namespace std;
/*
 
 */
bool cmp(const pair<string,int>& a, const pair<string,int>& b)
{
    if(a.second == b.second)
        return a.first < b.first;
    return a.second > b.second;
}
bool cmp2(const pair<int,int>& a, const pair<int,int>& b)
{
    if(a.second == b.second)
        return a.first < b.first;
    return a.second > b.second;
}
vector<int> solution(vector<string> genres, vector<int> plays)
{
    vector<int> answer;
    unordered_map<string, int> hashMap_totalPlays; // genre : totalPlays
    unordered_map<string, vector<pair<int, int>>> hashMap_index; // genre : index/plays
    size_t vecSize = genres.size();
    
    // setting Hash
    for(size_t i =0; i<vecSize; ++i)
    {
        string genre = genres[i];
        if(hashMap_totalPlays.find(genre) != hashMap_totalPlays.end())
        {
            hashMap_totalPlays[genre] += plays[i];
        }
        else
        {
            vector<pair<int,int>> v2;
            hashMap_totalPlays[genre] = plays[i];
            hashMap_index[genre] = v2;
        }
        hashMap_index[genre].push_back({(int)i, plays[i] });
    }
    
    // sorting by total plays
    vector<pair<string, int>> vec(hashMap_totalPlays.begin(),hashMap_totalPlays.end());
    sort(vec.begin(),vec.end(),cmp);
    
    int cnt=0;
    for(auto elem : vec)
    {
        if(cnt >= 2)
            break;
        auto genre = elem.first;
        if(hashMap_index.find(genre)== hashMap_index.end())
            continue;
        
        auto vecList = hashMap_index[genre];
        sort(vecList.begin(),vecList.end(),cmp2); // sorting by plays
        answer.push_back(vecList[0].first);
        if(vecList.size()>1)
            answer.push_back(vecList[1].first);
    }
    
    return answer;
}
