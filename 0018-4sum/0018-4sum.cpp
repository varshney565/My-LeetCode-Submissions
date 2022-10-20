class Solution {
public:
    vector<vector < int>> fourSum(vector<int> &nums, int target)
        {
            vector<vector < int>> res;
            int n = nums.size();
            sort(nums.begin(), nums.end());

            for (int i = 0; i < n; i++)
            {
                for (int j = i + 1; j < n; j++)
                {
                   	//nums[i]+nums[j]+nums[k]+nums[l]==target
                   	//nums[k]+nums[l]=target-nums[i]-nums[j];

                    int k = j + 1;
                    int l = n - 1;
                    long long target1 = (long long)target - nums[i] - nums[j];

                    while (k < l)
                    {
                        int sum = nums[k] + nums[l];

                        if (sum < target1)
                        {
                            k++;
                        }
                        else if (sum > target1)
                        {
                            l--;
                        }
                        else
                        {
                            vector<int> quad = { nums[i],nums[j],nums[k],nums[l]};
                            res.push_back(quad);
                            k++;
                            while (k < l && nums[k] == nums[k - 1])
                                k++;
                            l--;
                            while (k < l && nums[l] == nums[l + 1])
                                l--;
                        }
                    }

                    while (j + 1 < n && nums[j] == nums[j + 1])
                    {
                        j++;
                    }
                }
                while (i + 1 < n && nums[i] == nums[i + 1])
                {
                    i++;
                }
            }
            return res;
        }
};