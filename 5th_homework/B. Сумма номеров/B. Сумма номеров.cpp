#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int N = 0, K = 0;
    cin >> N >> K;
    vector<int> prefix_sum{ 0 };
    int nums = 0;
    int ans = 0;

    for (int i = 0; i < N; i++) {
        cin >> nums;
        prefix_sum.push_back(prefix_sum[i] + nums);
    }

    int L = 0, R = 0;
    while (R < N + 1) {
        if (prefix_sum[R] - prefix_sum[L] < K)
            ++R;
        else {
            if (prefix_sum[R] - prefix_sum[L] == K) {
                ++ans;
                ++R;
            }
            ++L;
        }
    }

    cout << ans;
}


