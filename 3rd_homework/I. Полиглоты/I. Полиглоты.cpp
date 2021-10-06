#include <iostream>
#include <map>
#include <string>]
#include <vector>

using namespace std;


int main()
{
    map<string, int> languages_to_count;
    int N;
    vector<string> all_pupils_know;

    cin >> N;
    for (int i = 0; i < N; ++i) {
        int count_languages = 0;
        cin >> count_languages;
        for (int j = 0; j < count_languages; ++j) {
            string language;
            cin >> language;
            if (languages_to_count.count(language) == 0)
                languages_to_count[language] = 0;
            languages_to_count[language] += 1;
        }
    }

    for (auto& item : languages_to_count) {
        if (item.second == N) {
            all_pupils_know.push_back(item.first);
        }
    }

    cout << all_pupils_know.size() << endl;
    for (auto& item : all_pupils_know)
        cout << item << endl;

    cout << languages_to_count.size() << endl;
    for (auto& item : languages_to_count)
        cout << item.first << endl;

    
}


