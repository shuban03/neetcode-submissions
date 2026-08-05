class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n=cost.size();
        vector<int> dp(n+1);  //each position stores the minimum cost to reach the top from that step
        dp[n]=0;              //top has no cost
        dp[n-1]=cost[n-1];    //last stair cost
        for(int i=n-2;i>=0;i--){
            dp[i]=cost[i]+min(dp[i+1],dp[i+2]);
        }
        return min(dp[0],dp[1]);   //return the min cost that can be in 0 or 1 (starting points)
    }
};