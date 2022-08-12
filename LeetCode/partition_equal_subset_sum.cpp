class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum = 0;
        bitset<20005> bs(1);
        
        for(auto x : nums) {
            sum += x;
            bs |= bs << x;
        }

        return (!(sum & 1) && bs[sum / 2]);
    }
};