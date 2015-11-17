class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> vec;
        if(nums.size() < 3)
            return vec;

        sort( nums.begin(), nums.end() );
        for( int i = 0; i < nums.size() - 2; ++i) {
            //去重
            if( i >= 1 && nums[i] == nums[i-1] )
                continue;
            int tmp = -nums[i];
            for( int j = i + 1, k = nums.size() - 1; j < k; ) {
                if(nums[j] + nums[k] > tmp){
                    --k;
                    //去重
                    while( nums[k] == nums[k+1] )
                        --k;                    
                }
                else if(nums[j] + nums[k] < tmp){
                    ++j;
                    //去重
                    while( nums[j] == nums[j-1] )
                        ++j;                    
                }
                else{
                    vec.push_back( {nums[i], nums[j], nums[k]} );
                    ++j;
                    --k;
                    //去重
                    while( nums[j] == nums[j-1] )
                        ++j;
                    while( nums[k] == nums[k+1] )
                        --k;
                }
            }
        }
        return vec;
    }
};
