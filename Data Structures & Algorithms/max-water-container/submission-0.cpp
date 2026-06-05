class Solution {
public:
    int maxArea(vector<int>& heights) {
        int maxArea = 0, i = 0, j = heights.size() - 1;

        while(i < j) {
            int length = j - i;
            int bredth = heights[i] > heights[j] ? heights[j--] : heights[i++];
            maxArea = max(maxArea, length * bredth);
            
        }
        return maxArea;
    }
};
