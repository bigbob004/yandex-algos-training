#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void make_prefix(const vector<int>& y, vector<int>& prefix_l_to_r) {
    for (int i = 0; i < y.size() - 1; ++i) {
        prefix_l_to_r[i + 2] = prefix_l_to_r[i + 1];
        int difference = y[i + 1] - y[i];
        if (difference > 0)
            prefix_l_to_r[i + 2] += difference;
    }
}

int get_rising(const int& l, const int& r, const vector<int>& prefix) {
    return prefix[r] - prefix[l];
}


int main()
{
    int N;
    int M = 0;
    int L = 1, R = 1;
    cin >> N;
    vector<int> y_coordinates;
    vector<int> prefix_l_to_r(N + 1);
    vector<int> prefix_r_to_l(N + 1);
    for (int i = 0; i < N; ++i) {
        int buf_x = 0, buf_y;
        cin >> buf_x >> buf_y;
        y_coordinates.push_back(buf_y);
    }
    make_prefix(y_coordinates, prefix_l_to_r);
    reverse(y_coordinates.begin(), y_coordinates.end());
    make_prefix(y_coordinates, prefix_r_to_l);

    cin >> M;
    for (int i = 0; i < M; ++i) {
        int L = 0, R = 0;
        cin >> L >> R;
        if(R - L >= 0)
            cout << get_rising(L, R, prefix_l_to_r) << endl;
        else
            cout << get_rising(N - L + 1, N - R + 1, prefix_r_to_l) << endl;
    }

    return 0;
}

