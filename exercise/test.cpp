#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

class Solution {
public:
    int trap(vector<int>& height) {
        if (height.size() < 2) return 0;

        int res = 0;

        int cur = height[0];
        int tallest = 0;
        int tmp = 0;
        for (int i = 0; i < height.size(); ++i) {
            if (height[i] < cur) {
                tmp += cur - height[i];
            }
            else {
                res += tmp;
                tmp = 0;
                cur = height[i];
                tallest = i;
            }
            cout << i << '|' << height[i] << '|' << cur << '|' << tmp << '|' << res << endl;
        }

        cur = height.back();
        tmp = 0;

        for (int j = height.size() - 1; j >= tallest; --j) {
            if (height[j] < cur) {
                tmp += cur - height[j];
            }
            else {
                res += tmp;
                tmp = 0;
                cur = height[j];
            }
        }

        return res;
    }
};

int main(void) {
    vector<int> height{0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1};

    cout << Solution().trap(height) << endl;

    return 0;
}
