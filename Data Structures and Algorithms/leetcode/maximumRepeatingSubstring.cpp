#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int maxRepeating(string sequence, string word)
    {
        int result = 0;
        string wordSeq = word;
        while (strstr(sequence.c_str(), wordSeq.c_str()))
        {
            wordSeq += word;
            result++;
        }
        return result;
    }
};

int main()
{
    Solution s;
    string a = "ababc",
           b = "ab";
    int res;
    res = s.maxRepeating(a, b);
    cout << "result is: " << res;
    return 0;
}