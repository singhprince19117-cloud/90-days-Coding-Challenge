#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
    public: 

    int stairCaseAnsTopDown(vector<int>& cost, int n, vector<int>& dp){
        if(n == 0){
            dp[0] = cost[0];
            return cost[0];
        }
        if(n == 1){
            dp[1] = cost[1];
            return cost[1];
        }

        if(dp[n] != -1){
            return dp[n];
        }

        dp[n] = min(stairCaseAnsTopDown(cost, n-1, dp), stairCaseAnsTopDown(cost, n-2, dp)) + cost[n];

        return dp[n];
    }

    int stairCaseTopDown(vector<int>& cost) {
        int n = cost.size();
        vector<int> dp(n+1, -1);

        if(n == 1){
            return cost[0];
        }

        int ans = min(stairCaseAnsTopDown(cost, n-1, dp), stairCaseAnsTopDown(cost, n-2, dp));

        return ans;
    }

    int stairCaseBottomUp(vector<int>& cost){
        int n = cost.size();
        vector<int> dp(n, -1);

        dp[0] = cost[0];
        dp[1] = cost[1];

        for(int i = 2; i<n; i++){
            dp[i] = min(dp[i-1], dp[i-2]) + cost[i];
        }

        return min(dp[n-1], dp[n-2]);
    }

    int stairCase(vector<int>& cost){

        int second = cost[0];
        int first = cost[1];
        int ans = -1;

        for(int i = 2; i < cost.size(); i++){
            ans = min(first, second) + cost[i];
            second = first;
            first = ans;
        }

        return min(first, second);
    }
};

int main(){
    vector<int> cost = {1, 100, 1, 1, 1, 100, 1, 1, 5, 1};
    // vector<int> cost = {10, 15, 20};

    Solution sol;

    cout<<sol.stairCaseTopDown(cost)<<endl;
    cout<<sol.stairCaseBottomUp(cost)<<endl;
    cout<<sol.stairCase(cost)<<endl;

    return 0;
}