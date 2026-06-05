class Solution {
public:
    int trap(vector<int>& height) {
        int water = 0, i = 0, j = height.size() - 1;
        int leftMax = height[i], rightMax = height[j];

        while(i < j) {
            if(leftMax <= rightMax) {
                i++;
                leftMax = max(leftMax, height[i]);
                water += leftMax - height[i];
            }
            else {
                j--;
                rightMax = max(rightMax, height[j]);
                water += rightMax - height[j];
            }
        }
        return water;
    }
};
