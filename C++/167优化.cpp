#include<cstdio>
#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        vector<int> res;
        int i = 0, j = numbers.size()-1;
        int n = numbers[i] + numbers[j];
        while(n != target) {
            n = (n > target) ? (numbers[i] + numbers[--j]) : (numbers[++i] + numbers[j]);
        }
        res.push_back(i + 1);
        res.push_back(j + 1);
        return res;
    }
};

int main()
{
    Solution sol;
    vector<int> v, rr;
    int n;
    scanf("%d", &n);
    for(int i = 0; i < n; i++) {
        int num;
        scanf("%d", &num);
        v.push_back(num);
    }
    int tar;
    scanf("%d", &tar);
    rr = sol.twoSum(v, tar);
    for(int i = 0; i < rr.size(); i++) {
        printf("%d ", rr[i]);
    }
    return 0;
}
