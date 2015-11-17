class Solution {
public:
    int maxArea(vector<int>& height) {
        // two pointers
        int left = 0;
        int right = height.size() - 1;
        int max = (right - left) * min(height[left], height[right]);
        int tmp = 0;
        
        while( left != right ){
            if(height[left] >= height[right]) {
                int hr = height[right];
                while( hr >= height[right] && left != right )
                    --right;
            }
            else {
                int hl = height[left];
                while( hl >= height[left] && left != right )
                    ++left;
            }
            tmp = (right - left) * min(height[left], height[right]);
            max = max > tmp ? max : tmp;
        }
        return max;
    }
};
