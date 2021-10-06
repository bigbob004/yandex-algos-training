#include <iostream>
#include <algorithm>
#include<vector>

using namespace std;

void extend(int* rect, int d) {
    rect[0] -= d;
    rect[1] += d;
    rect[2] -= d;
    rect[3] += d;
}

void intersect(int* navigator, int* set) {
    set[0] = max(navigator[0], set[0]);
    set[1] = min(navigator[1], set[1]);
    set[2] = max(navigator[2], set[2]);
    set[3] = min(navigator[3], set[3]);
}



int main()
{
    int t, d, n;
    cin >> t >> d >> n;

    int set_Rect[4] = { 0};

    for (int i = 0; i < n; ++i) {
        extend(set_Rect, t);
        int x, y;
        cin >> x >> y;
        int rect_navigator[4] = {x - y, x - y, x + y, x + y};
        extend(rect_navigator, d);
        intersect(rect_navigator, set_Rect);
    }

    vector<vector<int>> points;
    for (int x_minus_y = set_Rect[0]; x_minus_y <= set_Rect[1]; ++x_minus_y)
        for (int x_plus_y = set_Rect[2]; x_plus_y <= set_Rect[3]; ++x_plus_y) {
            int two_x = x_minus_y + x_plus_y;
            if ((two_x) % 2 == 0)
                points.push_back({ two_x / 2 , x_plus_y - (two_x / 2)});
}

    cout << points.size() << endl;
    for (auto& point : points)
        cout << point[0] << " " << point[1] << endl;
}
