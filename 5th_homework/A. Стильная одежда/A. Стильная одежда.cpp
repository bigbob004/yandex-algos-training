#include <iostream>
#include <vector>

using namespace std;

void search_minimal_difference(vector<int> lhs, vector<int> rhs, int ans[]) {
    int i = 0;
    int j = 0;
    int difference = 0;
    bool is_fisrt_difference = true;
    while (i < lhs.size() && j < rhs.size()) {
        if (is_fisrt_difference) {
            difference = abs(lhs[i] - rhs[j]);
            ans[0] = lhs[i];
            ans[1] = rhs[j];
            is_fisrt_difference = false;
        }
        else {
            if (abs(lhs[i] - rhs[j]) < difference) {
                difference = abs(lhs[i] - rhs[j]);
                ans[0] = lhs[i];
                ans[1] = rhs[j];
            }
        }
        if (lhs[i] > rhs[j])
            ++j;
        else
            if (lhs[i] < rhs[j])
                ++i;
            else {
                break;
            }            
    }
}

int main()
{
    int N = 0;
    vector<int> tshirts;
    int M = 0;
    vector<int> pants;

    int buf = 0;

    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> buf;
        tshirts.push_back(buf);
    }

    cin >> M;
    for (int i = 0; i < M; i++) {
        cin >> buf;
        pants.push_back(buf);
    }

    int ans[2] = { -1, -1 };
    search_minimal_difference(tshirts, pants, ans);
    cout << ans[0] << " " << ans[1];

}


