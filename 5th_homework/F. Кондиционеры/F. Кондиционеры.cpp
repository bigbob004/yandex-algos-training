#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int Search_min_price(const vector<int>& clases, const vector<vector<int>> models) {
    int i = clases.size() - 1, j = models.size() - 1;
    int min_price = 0;
    int cur_price = 1001;
    for (;i >= 0; i--) {
        while (j >= 0 && models[j][0] >= clases[i]) {
            if (models[j][1] < cur_price)
                cur_price = models[j][1];
            --j;
        }
        min_price += cur_price;
        j = models.size() - 1;
        cur_price = 1001;
        }
    return min_price;
}

int main()
{
    int n;
    cin >> n;

    vector<int> clases(n);
    for (auto& item : clases)
        cin >> item;

    int m;
    cin >> m;

    vector<vector<int>> models(m, vector<int>(2));
    for (auto& item : models)
        cin >> item[0] >> item[1];
    sort(models.begin(), models.end(),
        [](const vector<int>& lhs, const vector<int>& rhs) {
            return lhs[0] < rhs[0];
        });

    cout << Search_min_price(clases, models);



    
}

