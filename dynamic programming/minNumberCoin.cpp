#include <iostream>
#include <vector>
#include <cmath>
#include<climits>
using namespace std;

class Solution
{
public:
    int minCoinMemo(vector<int> &coins, int X, vector<int> &dp){
        if(X == 0){
            return 0;
        }

        if(X < 0){
            return INT_MAX;
        }

        if(dp[X] != -1){
            return dp[X];
        }

        int mini = INT_MAX;
        for(int i = 0; i < coins.size(); i++){
            int ans = minCoinMemo(coins, X - coins[i], dp);

            if(ans != INT_MAX){
                mini = min(mini, ans + 1);
            }
        }

        return dp[X] = mini;
    }

    int minCoinTab(vector<int> &coins, int X, vector<int> &dp){
        dp[0] = 0;

        for(int i = 1; i<=X; i++){

            dp[i] = INT_MAX;
            for(int j = 0; j < coins.size(); j++){
                if(i - coins[j] >= 0){
                    int ans = dp[i - coins[j]] + 1;

                    if(dp[i] > ans){
                        dp[i] = ans;
                    }
                }
            }
        }

        return dp[X];
    }
};

int main()
{
    vector<int> coins = {1, 2, 3};
    int X = 700;
    vector<int> dp(X + 1, -1);

    Solution sol;

    cout << sol.minCoinTab(coins, X, dp)<<endl;

    return 0;
}