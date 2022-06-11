#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

/*
 * Complete the 'birthday' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts following parameters:
 *  1. INTEGER_ARRAY s
 *  2. INTEGER d
 *  3. INTEGER m
 */

int birthday(vector<int> s, int d, int m) {
    int birthDay = d;
    int birthMonth = m;
    int successCount = 0;
    int arraySize = s.size();
    int numIterations = 0;

    //Capture the user's birth day and birth month
    //Birth day must be equal to the sum of contiguous segments

    //number of contiguous segments must be equal to the birth month.

    //Plan, start at front of the array, have sub for loop
    // that starts at n and sums n-1 adjacent values to the first value.
    for (auto it = s.begin(); it != s.end(); ++it) {
        int runningTotal = 0;
        std::vector <int> subArray;

        for (int j = 0; ((j < birthMonth) && ((numIterations + j ) < arraySize)); j++) {
            subArray.push_back(s[numIterations + j]);
        }
        numIterations++;
        int subArraySize = subArray.size();
        if (subArraySize == birthMonth) {
            for (int i = 0; i < subArraySize; i++) {
                runningTotal += subArray[i];
            }
            if (runningTotal == birthDay) {
                successCount++;
            }
        }
    }

    return successCount;

}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string n_temp;
    getline(cin, n_temp);

    int n = stoi(ltrim(rtrim(n_temp)));

    string s_temp_temp;
    getline(cin, s_temp_temp);

    vector<string> s_temp = split(rtrim(s_temp_temp));
    if (n >= 1 && n <= 100) {
        vector<int> s(n);

        for (int i = 0; i < n; i++) {
            int s_item = stoi(s_temp[i]);
            if (s_item >= 1 && s_item <= 5) {
                s[i] = s_item;
            }
        }

        string first_multiple_input_temp;
        getline(cin, first_multiple_input_temp);

        vector<string> first_multiple_input = split(rtrim(first_multiple_input_temp));

        int d = stoi(first_multiple_input[0]);

        int m = stoi(first_multiple_input[1]);

        if ((d >= 1 && d <= 31) && (m >= 1 && m <= 12)) {
            int result = birthday(s, d, m);
            fout << result << "\n";
        }
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