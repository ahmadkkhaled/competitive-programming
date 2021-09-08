// convex hull

#include <bits/stdc++.h>

using namespace std;

#define all(v) v.begin(), v.end()
#define sof(v) (int)v.size()

template<typename T>
ostream &operator<<(ostream &os, const vector<T> &v) {
    for (const T &val: v)
        os << val << ' ';
    return os;
}

vector<int> operator-(const vector<int> &v0, const vector<int> &v1) {
    vector<int> ret(2);
    ret[0] = v0[0] - v1[0];
    ret[1] = v0[1] - v1[1];
    return ret;
}

class Solution {
public:
    /** returns the cross product of the 2 vectors formed by points v0, v1, v2 in order
     * current = (v1 - v0) relative = (v2 - v1)
     * if the cross product is positive, it means `current` must move counter clockwise to align with `relative`
     */
    int cross(const vector<int> &v0, const vector<int> &v1, const vector<int> &v2) {
        vector<int> cur = v1 - v0;
        vector<int> rel = v2 - v1;
        return cur[0] * rel[1] - cur[1] * rel[0];
    }

    vector<vector<int>> outerTrees(vector<vector<int>> &trees) {
        int n = sof(trees);
        if (n < 4)
            return trees;

        bool collinear_x = true, collinear_y = true;
        for(int i = 1; i < n; i++){
            collinear_x &= trees[i][0] == trees[i-1][0];
            collinear_y &= trees[i][1] == trees[i-1][1];
        }

        if(collinear_x || collinear_y)
            return trees;

        sort(all(trees));

        vector<vector<int>> lower = {trees[0], trees[1]};
        for (int i = 2; i < n; i++) {
            while (cross(lower[sof(lower) - 2], lower.back(), trees[i]) < 0) {
                lower.pop_back();
                if (sof(lower) < 2)
                    break;
            }
            lower.push_back(trees[i]);
        }

        vector<vector<int>> upper = {trees[0], trees[1]};
        for (int i = 2; i < n; i++) {
            while (cross(upper[sof(upper) - 2], upper.back(), trees[i]) > 0) {
                upper.pop_back();
                if (sof(upper) < 2)
                    break;
            }
            upper.push_back(trees[i]);
        }

        for(int i = 1; i < sof(upper) - 1; i++)
            lower.push_back(upper[i]);

        return lower;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    vector<vector<int>> v = {{1, 1},
                             {2, 2},
                             {2, 0},
                             {2, 4},
                             {3, 3},
                             {4, 2}};
    cout << Solution().outerTrees(v);
}