class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.size() != t.size()) return false;
        unordered_map<char, int> mpp;

        for(int num : s) mpp[num]++;

        for(int num : t) {
            mpp[num]--;
            if(mpp[num] == 0) mpp.erase(num);
        }

        return mpp.size() == 0;
    }
};
