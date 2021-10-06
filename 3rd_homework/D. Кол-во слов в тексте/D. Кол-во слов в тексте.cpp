#include <iostream>
#include <fstream>
#include <string>
#include <set>

using namespace std;

int Count_unique_words(const string& s) {
    set<string> unique_words;
    string word;
    for (unsigned int i = 0; i < s.size(); ++i) {
        if ((s[i] == '\n') || (s[i] == ' ')) {
            if (word.size() != 0)
                unique_words.insert(word);
            word = "";
            while ((i + 1 != s.size()) && (s[i + 1] == '\n' || s[i + 1] == ' '))
                ++i;
        }
        else
            word += s[i];
    }
    return unique_words.size();
}

int main()
{   
    ifstream f;
    f.open("input.txt");
    string s;
    string text;
    while (getline(f, s)) {
        text += s;
        text += '\n';
    }
    cout << Count_unique_words(text);
    f.close();

    return 0;
}

