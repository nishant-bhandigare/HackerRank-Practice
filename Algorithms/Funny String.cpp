#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);

/*
 * Complete the 'funnyString' function below.
 *
 * The function is expected to return a STRING.
 * The function accepts STRING s as parameter.
 */

string funnyString(string s) {
    string string1 = s;
    string string2 = s;
    reverse(string2.begin(), string2.end());
    
    int n = s.size();
    int diff1, diff2;
    
    int flag = 0;
    
    for(int i=0;i<n-1;i++){
        diff1 = abs((int)string1[i]-(int)string1[i+1]);
        diff2 = abs((int)string2[i]-(int)string2[i+1]);
        
        if(diff1 != diff2){
            flag = 1;
            break;
        }
    }
    
    if(flag==1){
        return "Not Funny";
    }
    else {
        return "Funny";
    }
}   

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string q_temp;
    getline(cin, q_temp);

    int q = stoi(ltrim(rtrim(q_temp)));

    for (int q_itr = 0; q_itr < q; q_itr++) {
        string s;
        getline(cin, s);

        string result = funnyString(s);

        fout << result << "\n";
    }

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
