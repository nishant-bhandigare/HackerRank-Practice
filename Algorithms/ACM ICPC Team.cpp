#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

/*
 * Complete the 'acmTeam' function below.
 *
 * The function is expected to return an INTEGER_ARRAY.
 * The function accepts STRING_ARRAY topic as parameter.
 */
 
int countOnes(int num){
    int temp = num;
    int r;
    int count = 0;
    
    while(temp!=0){
        r = temp%10;
        if(r==1){
            count++;
        }
        temp = temp/10;
    }
    return  count;
}

int topics_known(string s1, string s2){
    int count = 0;
    for (int i=0;i<s1.length();i++){
        if(s1[i]=='1' || s2[i]=='1'){
            count++;
        }
    }
    return count;
}

vector<int> acmTeam(vector<string> topic) {
    int max_topics_known = 0;
    int max_teams = 0;
    
    int n = topic.size();
    int temp;
    
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(i==j){
                continue;
            }
            temp = topics_known(topic[i], topic[j]);
            if(temp>max_topics_known){
                max_topics_known = temp;
            }    
        }
    }
    
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            temp = topics_known(topic[i], topic[j]);
            if(temp == max_topics_known){
                max_teams++;
            }    
        }
    }
    
    vector<int> result = {max_topics_known, max_teams};
    return result;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string first_multiple_input_temp;
    getline(cin, first_multiple_input_temp);

    vector<string> first_multiple_input = split(rtrim(first_multiple_input_temp));

    int n = stoi(first_multiple_input[0]);

    int m = stoi(first_multiple_input[1]);

    vector<string> topic(n);

    for (int i = 0; i < n; i++) {
        string topic_item;
        getline(cin, topic_item);

        topic[i] = topic_item;
    }

    vector<int> result = acmTeam(topic);

    for (size_t i = 0; i < result.size(); i++) {
        fout << result[i];

        if (i != result.size() - 1) {
            fout << "\n";
        }
    }

    fout << "\n";

    fout.close();

    return 0;
}

string ltrim(const string &str) {
    string s(str);

    s.erase(
        s.begin(),
        find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace)))
    );

    return s;
}

string rtrim(const string &str) {
    string s(str);

    s.erase(
        find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
        s.end()
    );

    return s;
}

vector<string> split(const string &str) {
    vector<string> tokens;

    string::size_type start = 0;
    string::size_type end = 0;

    while ((end = str.find(" ", start)) != string::npos) {
        tokens.push_back(str.substr(start, end - start));

        start = end + 1;
    }

    tokens.push_back(str.substr(start));

    return tokens;
}
