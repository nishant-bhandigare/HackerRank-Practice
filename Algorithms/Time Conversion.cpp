#include <bits/stdc++.h>

using namespace std;

/*
 * Complete the 'timeConversion' function below.
 *
 * The function is expected to return a STRING.
 * The function accepts STRING s as parameter.
 */

string timeConversion(string s) {
    int hrs = stoi(s.substr(0,2));
    int min = stoi(s.substr(3,2));
    int sec = stoi(s.substr(7,2)); 
    string range = s.substr(8,2);
    
    if (range == "AM"){
        if(hrs==12){
            return "00" + s.substr(2,6);
        }
        return s.substr(0,8);
    }else{
        if(hrs == 12){
            return s.substr(0,8);
        }
        int temp = hrs + 12;
        return to_string(temp) + s.substr(2,6);
    }
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string s;
    getline(cin, s);

    string result = timeConversion(s);

    fout << result << "\n";

    fout.close();

    return 0;
}
