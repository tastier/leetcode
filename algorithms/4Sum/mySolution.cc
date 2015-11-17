// my solution
class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> ret;
        if( nums.size() <= 3 )
            return ret;
        sort(nums.begin(), nums.end());
        for(int i = 0; i < nums.size() - 3; ++i){
            if( i >= 1 && nums[i] == nums[i-1] )
                continue;
            int sum = target - nums[i];
            vector<int> v (nums.begin() + i + 1, nums.end());
            vector<vector<int>> tmp ( threeSum( v, sum) );
            for( int j = 0; j < tmp.size(); j++){
                tmp[j].insert(tmp[j].begin(), nums[i]);
                ret.push_back( tmp[j] );
            }
        }
        return ret;
    }
private:
    vector<vector<int>> threeSum(vector<int>& nums, int tar) {
        vector<vector<int>> vec;
        for( int i = 0; i < nums.size() - 2; ++i) {
            //去重
            if( i >= 1 && nums[i] == nums[i-1] )
                continue;
            for( int j = i + 1, k = nums.size() - 1; j < k; ) {
                int tmp = nums[i] + nums[j] + nums[k];
                if(tmp > tar){
                    --k;
                    //去重
                    while( nums[k] == nums[k+1] )
                        --k;                    
                }
                else if(tmp < tar){
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
