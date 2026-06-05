class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> mpp;
        mpp[nums[0]] = 0;

        for(int i = 1; i < nums.size(); i++) {
            if(mpp.find(target - nums[i]) != mpp.end()) {
                return {mpp[target - nums[i]], i};
            }
            mpp[nums[i]] = i;
        }
        return{-1, -1};
    }
};
