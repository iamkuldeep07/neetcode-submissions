class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        unordered_map<int, int> mpp;
        for(int num : nums) {
            if(mpp.find(num) != mpp.end()) return true;
            mpp[num]++;
        }
        return false;
    }
};