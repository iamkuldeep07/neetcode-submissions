class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> mpp;
        int maxLength = 0; 
        int i = 0, j = 0;

        while(j < s.size()) {
            
            while(mpp.find(s[j]) != mpp.end()) {
                mpp[s[i]]--;
                if(mpp[s[i]] == 0) mpp.erase(s[i]);
                i++;
            }
            
            mpp[s[j]]++;
            maxLength = max(maxLength, j - i + 1);
            
            j++;
        }
        return maxLength;
    }
};
