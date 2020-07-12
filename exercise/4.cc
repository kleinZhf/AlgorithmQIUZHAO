#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

class Solution{
public:
    double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2)
    {
        if(nums1.size() > nums2.size())
        {
            return findMedianSortedArrays(nums2, nums1);
        }

        int m = nums1.size();
        int n = nums2.size();

        int totalLeft = (m + n + 1) / 2;

        int left = 0;
        int right = m;

        while(left < right)
        {
            int i = left + (right - left) / 2;
            int j = totalLeft - i;
            if(nums2[j - 1] > nums1[i])
            {
                left = i + 1;
            }
            else
            {
                right = i;
            }
        }

        // another binary condition
        // while(left < right)
        // {
        //     int i = left + (right - left + 1) / 2;
        //     int j = halfLen - i;

        //     if(nums1[i - 1] > nums2[j])
        //     {
        //         right = i - 1;
        //     }
        //     else
        //     {
        //         left = i;
        //     }
        // }

        int i = left;
        int j = totalLeft - i;
        int nums1LeftMax = (i == 0 ? INT_MIN : nums1[i - 1]);
        int nums1RightMin = (i == m ? INT_MAX : nums1[i]);
        int nums2LeftMax = (j == 0 ? INT_MIN : nums2[j - 1]);
        int nums2RightMin = (j == n ? INT_MAX : nums2[j]);

        if((m + n) % 2 == 1)
        {
            return max(nums1LeftMax, nums2LeftMax);
        }
        else
        {
            return (double) (max(nums1LeftMax, nums2LeftMax) + min(nums1RightMin, nums2RightMin)) / 2.0;
        }
    }
};

int main(void)
{
    vector<int> nums1{1, 2};
    vector<int> nums2{3, 4};

    cout << Solution().findMedianSortedArrays(nums1, nums2) << endl;
    return 0;
}

