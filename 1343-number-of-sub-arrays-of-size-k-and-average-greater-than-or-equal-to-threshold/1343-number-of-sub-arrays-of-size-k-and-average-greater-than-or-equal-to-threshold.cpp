class Solution {
public:
    int numOfSubarrays(vector<int>& arr, int k, int threshold) {
        int i = 0;
        int j = 0;

        int ans = INT_MIN;
        int sum = 0;
        int count = 0;
        
        while(j < arr.size())
        {
            sum += arr[j];

            if(j-i+1 < k)
                j++;
            else if(j-i+1 == k)
            {
                int temp = (sum*1.0)/(k*1.0);
                if(temp >= threshold)
                {
                    count++;
                }
                sum -= arr[i];
                i++;j++;
            }
        }
        return count;
    }
};