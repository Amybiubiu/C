class Solution {
public:
    int lastStoneWeightII(vector<int>& stones) {
        int sum = 0;
        for (int i : stones) {
            sum += i;
        }
        int maxCap = sum/2;
        int* dp = new int[maxCap+1];
        for(int i = 0; i < maxCap; i++){
            dp[i] = 0;
        }
        for(int i = 0; i< stones.size(); i++){
            int cur = stones[i];
            for(int j = maxCap; j >= cur; j--){
                dp[j] = max(dp[j],dp[j-cur]+cur);
            }
        }
        return sum-2*dp[maxCap];
    }
};
