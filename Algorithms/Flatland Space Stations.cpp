#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);

bool contains(std::vector<int> vec, int target) {
    return std::find(vec.begin(), vec.end(), target) != vec.end();
}

// Complete the flatlandSpaceStations function below.
int flatlandSpaceStations(int n, vector<int> c) {
    int maxDistance = 0;
    int nextCity;
    int previousCity;
    int nextDistance;
    int previousDistance;
    int j;

    if (n == c.size()) {
        return 0;
    }

    sort(c.begin(), c.end()); // Ensure the vector is sorted for correct indexing

    for (int currentCity = 0; currentCity < n; currentCity++) {
        if (contains(c, currentCity)) {
            continue;
        }

        // Find the nearest stations around currentCity
        for (j = 0; j < c.size(); j++) {
            if (c[j] > currentCity) {
                break;
            }
        }

        if (j == 0) {
            // Only nextCity exists
            nextCity = c[j];
            nextDistance = nextCity - currentCity;
            if (nextDistance > maxDistance) {
                maxDistance = nextDistance;
            }
        } else if (j == c.size()) {
            // Only previousCity exists
            previousCity = c[j - 1];
            previousDistance = currentCity - previousCity;
            if (previousDistance > maxDistance) {
                maxDistance = previousDistance;
            }
        } else {
            // Both previous and next cities exist
            nextCity = c[j];
            previousCity = c[j - 1];
            nextDistance = nextCity - currentCity;
            previousDistance = currentCity - previousCity;

            if (nextDistance < previousDistance) {
                if (nextDistance > maxDistance) {
                    maxDistance = nextDistance;
                }
            } else {
                if (previousDistance > maxDistance) {
                    maxDistance = previousDistance;
                }
            }
        }
    }

    return maxDistance;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string nm_temp;
    getline(cin, nm_temp);

    vector<string> nm = split_string(nm_temp);

    int n = stoi(nm[0]);

    int m = stoi(nm[1]);

    string c_temp_temp;
    getline(cin, c_temp_temp);

    vector<string> c_temp = split_string(c_temp_temp);

    vector<int> c(m);

    for (int i = 0; i < m; i++) {
        int c_item = stoi(c_temp[i]);

        c[i] = c_item;
    }

    int result = flatlandSpaceStations(n, c);

    fout << result << "\n";

    fout.close();

    return 0;
}

vector<string> split_string(string input_string) {
    string::iterator new_end = unique(input_string.begin(), input_string.end(), [] (const char &x, const char &y) {
        return x == y and x == ' ';
    });

    input_string.erase(new_end, input_string.end());

    while (input_string[input_string.length() - 1] == ' ') {
        input_string.pop_back();
    }

    vector<string> splits;
    char delimiter = ' ';

    size_t i = 0;
    size_t pos = input_string.find(delimiter);

    while (pos != string::npos) {
        splits.push_back(input_string.substr(i, pos - i));

        i = pos + 1;
        pos = input_string.find(delimiter, i);
    }

    splits.push_back(input_string.substr(i, min(pos, input_string.length()) - i + 1));

    return splits;
}
