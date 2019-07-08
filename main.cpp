#include <algorithm>
#include <cstring>
#include <climits>
#include <functional>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <vector>
#include <sstream>


#include "../utils/VectorUtils.hpp"
#include "../utils/PrintUtils.hpp"

// https://leetcode.com/problems/image-smoother/

// #include "../utils/HeapUtils.hpp"
// #include "../utils/BinarySearch.hpp"
// #include "../utils/TreeUtils.hpp"

using namespace std;

#pragma GCC diagnostic ignored "-Wunknown-pragmas"

// Live coding problems, watch at
// https://www.twitch.tv/yipcubed
// https://www.youtube.com/channel/UCTV_UOPu7EWXvYWsBFxMsSA/videos
//

// makes code faster, but larger. Just for LeetCode fun!
#pragma GCC optimise ("Ofast")

// makes stdin not synced so it is faster. Just for LeetCode fun!
static auto __ __attribute__((unused)) = []() {              // NOLINT
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    return nullptr;
}();

class Solution {
public:

    int sumAdd(vector<vector<int>>& M, int r, int c, int maxr, int maxc, int& sum) {
        if (r >= 0 && c >= 0 && r <= maxr && c <= maxc) {
//            PV4(r, c, maxr, maxc);
            sum += M[r][c];
//            PV1(sum);
            return 1;
        } else {
            return 0;
        }
    }

    int average8(vector<vector<int>>& M, int r, int c, int maxr, int maxc) {
        int sum = M[r][c];
        int found = 1;
        found += sumAdd(M, r + 1, c, maxr, maxc, sum);
        found += sumAdd(M, r - 1, c, maxr, maxc, sum);

        found += sumAdd(M, r, c + 1, maxr, maxc, sum);
        found += sumAdd(M, r, c - 1, maxr, maxc, sum);

        found += sumAdd(M, r + 1, c + 1, maxr, maxc, sum);
        found += sumAdd(M, r - 1, c - 1, maxr, maxc, sum);


        found += sumAdd(M, r - 1, c + 1, maxr, maxc, sum);
        found += sumAdd(M, r + 1, c - 1, maxr, maxc, sum);

        return sum / found;
    }
    vector<vector<int>> imageSmoother(vector<vector<int>>& M) {
        if (M.size() == 0 || M[0].size() == 0) return M;
        int maxr = M.size() - 1;
        int maxc = M[0].size() - 1;
        vector<vector<int>> res(maxr + 1);
        for (int r = 0; r <= maxr; ++r) {
            res[r].resize(maxc + 1);
            for (int c = 0; c <= maxc ; ++c) {
                res[r][c] = average8(M, r, c, maxr, maxc);
            }
        }
        return res;
    }
};

void test1() {
//    vector<int> v1{1,1,1};
//    vector<int> v2{1,0,1};
//
//    vector<vector<int>> va{v1, v2, v1};
//
//    cout << " ? " << Solution().imageSmoother(va) << endl;

    // [[2,3,4],[5,6,7],[8,9,10],[11,12,13],[14,15,16]]
    vector<vector<int>> vb {
        vector<int>{2,3,4},
        vector<int>{5,6,7},
        vector<int>{8,9,10},
        vector<int>{11,12,13},
        vector<int>{14,15,16},
    };

    cout << " ? " << Solution().imageSmoother(vb) << endl;
}

void test2() {

}

void test3() {

}