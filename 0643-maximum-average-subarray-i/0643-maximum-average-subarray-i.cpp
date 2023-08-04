class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        int i = 0;
        int j = 0;

        double ans = INT_MIN;
        double sum = 0.0;
        while(j < nums.size())
        {
            sum+= nums[j];

            if(j - i + 1 < k)
                j++;
            else if(j - i + 1 == k)
            {
                double temp = ((sum * 1.0 )/(k * 1.0));
                ans = max(ans,temp);

                sum -= nums[i];
                i++;j++;
            }
        }
        return ans;

    }
};