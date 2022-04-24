//
//  PrimeNumber.cpp
//  프로그래머스_완전탐색
//
//  Created by 박지수 on 2022/04/17.
//

#include "PrimeNumber.hpp"
#include <string>
#include <vector>
#include <algorithm>
#include <math.h>
using namespace std;
bool isPrime(int n)
{
    //cout<<n<<endl;
    if(n<=1)
        return false;
    for (int i = 2; i <= sqrt(n); i++)
    {
        if (n % i == 0)
            return false;
    }
    return true;
}
int solution(string numbers) {
    int answer = 0;
    vector<int> vecNumbers;
    vector<int> data;
    vecNumbers.reserve(numbers.size());
    // string -> int
    for(auto number : numbers)
    {
        int num =stoi(&number);
        vecNumbers.push_back(num);
        data.push_back(num);
    }
    sort(vecNumbers.begin(), vecNumbers.end());
    
    do {
        string str;
        for (auto it = vecNumbers.begin(); it != vecNumbers.end(); ++it)
        {
            str += to_string(*it);
            data.push_back(stoi(str));
        }
            data.push_back(stoi(str));
        
    } while (next_permutation(vecNumbers.begin(), vecNumbers.end()));
    
    // for 중복 데이터 제거
    sort(data.begin(), data.end(), greater<int>());
    data.erase(unique(data.begin(),data.end()), data.end());
    for(auto d : data)
    {
        
        if(isPrime(d))
        {
            cout<<d<<" ";
            ++answer;
        }
        
    }
    cout<<endl;
    return answer;
}
