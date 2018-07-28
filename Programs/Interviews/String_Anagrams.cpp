#include <bits/stdc++.h>

using namespace std;

int stavroshash(char c1) {
    
    return (c1-'a');
    
}

// Complete the makeAnagram function below.
int makeAnagram(string a, string b) {

    //Check comparison between vector and array
    array<int,26> occurrences;
    set<int>   indices;
    
    //Could group these two together
    for (auto x : a) {
        int ind = stavroshash(x);
        auto p = indices.emplace(ind);
        ++occurrences[ind];
    }
    for (auto x : b) {
        int ind = stavroshash(x);
        auto p = indices.emplace(ind);
        ++occurrences[ind];
    }
    
    int flag{0};
    for (auto in  : indices) {
        cout<<in<<'\n';
        if (occurrences[in]%2 != 0) {
            ++flag;           
        }
    }
    
    return flag;

}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string a;
    getline(cin, a);

    string b;
    getline(cin, b);

    int res = makeAnagram(a, b);

    fout << res << "\n";

    fout.close();

    return 0;
}
