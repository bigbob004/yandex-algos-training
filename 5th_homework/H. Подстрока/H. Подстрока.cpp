#include <iostream>

using namespace std;

pair<int, int> search_subs(char* s, const int& size_of_s, const int& k) {
    int sym_to_cnt[123]{ 0 };
    int sym_to_first_pos[123]{ 0 };
    int i = 0, j = 0;
    int best_i = 0, best_length = 0;
    for (; j < size_of_s;) {
        while (j < size_of_s && sym_to_cnt[s[j]] < k) {
            if (sym_to_cnt[s[j]] == 0)
                sym_to_first_pos[s[j]] = j;
            ++sym_to_cnt[s[j++]];
        }
        if (best_length < j - i) {
            best_i = i;
            best_length = j - i;
        }
        if (j < size_of_s) {
            for (int k = i; k <= sym_to_first_pos[s[j]]; k++) {
                --sym_to_cnt[s[k]];
            }
            ++sym_to_first_pos[s[j]];
            i = sym_to_first_pos[s[j]];
        }
    }
    return make_pair(best_length , best_i + 1);
}

int main()
{
    int n, k;
    cin >> n >> k;

    char* s = new char[n];
    for (int i = 0; i < n; ++i)
        cin >> s[i];
    

    pair<int, int> res = search_subs(s, n, k);
    cout << res.first << " " << res.second;
}

