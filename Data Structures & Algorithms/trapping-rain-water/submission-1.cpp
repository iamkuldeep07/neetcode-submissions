class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        if (n == 0) return 0;

        int i = 0, j = n - 1;
        int leftMax = height[i];
        int rightMax = height[j];
        int water = 0;

        while (i < j) {
            if (leftMax <= rightMax) {
                i++;
                leftMax = max(leftMax, height[i]);
                water += leftMax - height[i];
            } else {
                j--;
                rightMax = max(rightMax, height[j]);
                water += rightMax - height[j];
            }
        }

        return water;
    }
};