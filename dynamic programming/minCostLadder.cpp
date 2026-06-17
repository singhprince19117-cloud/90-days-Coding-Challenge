#include<iostream>
#include<vector>
using namespace std;

class Solution {
    public: 

    int stairCaseAns(vector<int>& cost, int n){
        if(n == 0){
            return cost[0];
        }
        if(n == 1){
            return cost[1];
        }

        int ans = min(stairCaseAns(cost, n-1), stairCaseAns(cost, n-2)) + cost[n];

        return ans;
    }

    int stairCase(vector<int>& cost) {
        int n = cost.size();

        if(n == 1){
            return cost[0];
        }

        int ans = min(stairCaseAns(cost, n-1), stairCaseAns(cost, n-2));

        return ans;
    }
};

int main(){
    // vector<int> cost = {1, 100, 1, 1, 1, 100, 1};
    vector<int> cost = {10};

    Solution sol;

    cout<<sol.stairCase(cost);

    return 0;
}