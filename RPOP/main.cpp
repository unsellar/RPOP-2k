#include <iostream>
#include <fstream>
#include <regex>
using namespace std;
//(hel*o)*wrld


int main() {
    string input;
    ifstream file ("/Users/vsevolod/Documents/RPOP/RPOP/input.txt");
    while (getline(file, input))    {
        cout << "input line is '" << input << "  ";
        if (regex_match(input, regex("(hel*o)* wrld")) == 1) cout << "answer is true" << endl;
        else cout << "'  answer is false" << endl;
    }
    return 0;
}
