#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

pair<int, int> search_min_sub_segment(const vector<int>& Trees, const int& cnt_uniq_trees) {
    vector<int> unique(cnt_uniq_trees + 1);
    int cnt_of_uniq = 0;
    int best_l = 1, best_r = Trees.size();
    for (int l = 0, r = 0;r < Trees.size();) {
        int elem = Trees[r];
        if (!unique[elem]++)
            ++cnt_of_uniq;
        ++r;
        if (cnt_of_uniq == cnt_uniq_trees) {
            while (unique[elem]) {
                elem = Trees[l];
                --unique[elem];
                ++l;
            }
            --cnt_of_uniq;
            if (r - l < best_r - best_l) {
                best_r = r;
                best_l = l;
            }
        }
    }
    return make_pair(best_l, best_r);
}

int main()
{
    int N, K;
    cin >> N >> K;

    vector<int> trees(N);
    for (auto& tree : trees)
        cin >> tree;

    pair<int, int> ans = search_min_sub_segment(trees, K);
    cout << ans.first << " " << ans.second;
}

