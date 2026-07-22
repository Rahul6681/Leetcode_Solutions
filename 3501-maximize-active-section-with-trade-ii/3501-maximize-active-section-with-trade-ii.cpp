class Solution {
    struct Group {
        int start;
        int length;
    };

    class SparseTable {
    public:
        SparseTable(const vector<int>& nums) {
            int n = nums.size();
            if (n == 0) return;
            int lg = __lg(n) + 1;
            st.assign(lg, vector<int>(n));
            st[0] = nums;
            for (int k = 1; k < lg; k++) {
                for (int i = 0; i + (1 << k) <= n; i++) {
                    st[k][i] = max(st[k - 1][i],
                                   st[k - 1][i + (1 << (k - 1))]);
                }
            }
        }

        int query(int l, int r) const {
            int k = __lg(r - l + 1);
            return max(st[k][l], st[k][r - (1 << k) + 1]);
        }

    private:
        vector<vector<int>> st;
    };

public:
    vector<int> maxActiveSectionsAfterTrade(string s,
                                            vector<vector<int>>& queries) {

        int ones = count(s.begin(), s.end(), '1');

        auto [zeroGroups, zeroGroupIndex] = getZeroGroups(s);

        if (zeroGroups.empty())
            return vector<int>(queries.size(), ones);

        SparseTable st(getZeroMergeLengths(zeroGroups));

        vector<int> ans;

        for (auto &q : queries) {

            int l = q[0];
            int r = q[1];

            int left =
                zeroGroupIndex[l] == -1
                    ? -1
                    : zeroGroups[zeroGroupIndex[l]].length -
                          (l - zeroGroups[zeroGroupIndex[l]].start);

            int right =
                zeroGroupIndex[r] == -1
                    ? -1
                    : r - zeroGroups[zeroGroupIndex[r]].start + 1;

            auto p = mapToAdjacentGroupIndices(
                zeroGroupIndex[l] + 1,
                s[r] == '1'
                    ? zeroGroupIndex[r]
                    : zeroGroupIndex[r] - 1);

            int start = p.first;
            int end = p.second;

            int best = ones;

            if (s[l] == '0' &&
                s[r] == '0' &&
                zeroGroupIndex[l] + 1 == zeroGroupIndex[r]) {

                best = max(best, ones + left + right);

            } else if (start <= end) {

                best = max(best,
                           ones + st.query(start, end));
            }

            if (s[l] == '0' &&
                zeroGroupIndex[l] + 1 <=
                    (s[r] == '1'
                         ? zeroGroupIndex[r]
                         : zeroGroupIndex[r] - 1)) {

                best = max(best,
                           ones + left +
                               zeroGroups[zeroGroupIndex[l] + 1].length);
            }

            if (s[r] == '0' &&
                zeroGroupIndex[l] < zeroGroupIndex[r] - 1) {

                best = max(best,
                           ones + right +
                               zeroGroups[zeroGroupIndex[r] - 1].length);
            }

            ans.push_back(best);
        }

        return ans;
    }

private:
    pair<vector<Group>, vector<int>>
    getZeroGroups(const string &s) {

        vector<Group> groups;
        vector<int> idx;

        for (int i = 0; i < (int)s.size(); i++) {

            if (s[i] == '0') {

                if (i > 0 && s[i - 1] == '0')
                    groups.back().length++;
                else
                    groups.push_back({i, 1});
            }

            idx.push_back((int)groups.size() - 1);
        }

        return {groups, idx};
    }

    vector<int>
    getZeroMergeLengths(const vector<Group> &groups) {

        vector<int> res;

        for (int i = 0; i + 1 < (int)groups.size(); i++)
            res.push_back(groups[i].length +
                          groups[i + 1].length);

        return res;
    }

    pair<int, int>
    mapToAdjacentGroupIndices(int startGroup,
                              int endGroup) {

        return {startGroup, endGroup - 1};
    }
};