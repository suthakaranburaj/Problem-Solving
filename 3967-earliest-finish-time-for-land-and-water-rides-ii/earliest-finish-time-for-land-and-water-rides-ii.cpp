class Solution {
public:
    int solve(vector<int>&at, vector<int>&ad, vector<int>&bt, vector<int>&bd){
        int mini = INT_MAX;
        for(int i = 0;i<at.size();i++){
            mini = min(mini, at[i]+ad[i]);
        }

        int ans = INT_MAX;
        for(int i = 0;i<bt.size();i++){
            ans = min(ans, max(mini, bt[i])+bd[i]);
        }

        return ans;
    }
    int earliestFinishTime(vector<int>& landStartTime, vector<int>& landDuration, vector<int>& waterStartTime, vector<int>& waterDuration) {
        return min(
            solve(landStartTime, landDuration, waterStartTime, waterDuration),
            solve(waterStartTime, waterDuration, landStartTime, landDuration)
        );
    }
};