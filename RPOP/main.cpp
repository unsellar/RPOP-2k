#include <iostream>
#include <fstream>
#include <regex>
#include <map>
#include <stdio.h>
#include <string.h>
using namespace std;


//(hel*o)* wrld regex


string hello_checker(string input){
    if(input[0] == 'h' and input[1] == 'e'){                     //first two HE
        input.erase(0, 2);
        
        if(input[0] == 'l'){                                     // lll continuation
            while(input[0] == 'l'){
                input.erase(0, 1);
            }
        }
        
        if (input[0] == 'o'){                                    // o last erase
            input.erase(0, 1);
            return input;
        }
    } else {
        return "e";
    }
    return "e";
}

bool wrld_checker(string input){
    if(input.compare(" wrld") == 0) return true;
    return false;
}

bool task2 (){
    string input;
    ifstream file ("/Users/vsevolod/Documents/RPOP/RPOP/input.txt");
    while(getline(file, input)){
        cout << "input line is " << input;
        if(wrld_checker(input)){
            cout << "     answer is true!" << endl;
        }else{
            if(hello_checker(input) != "e"){//1st hello
                input = hello_checker(input);
                while(hello_checker(input) != "e"){//2+hello erasing
                    input = hello_checker(input);
                }
                if(wrld_checker(input)) cout << "     answer is true" << endl;
                else cout << "  answer is false" << endl;
            }else cout << "  answer is false" << endl;
        }
    }
    return true;
}
bool lexer(){
    //Зарезервированные слова языка: char, int, float, void, if, else, while, for, return.
    map<string, string> reserved = {
        {"int", "T_int"},
        {"char", "T_char"},
        {"float", "T_float"},
        {"void", "T_void"},
        {"if", "T_if"},
        {"else", "T_else"},
        {"while", "T_while"},
        {"for", "T_for"},
        {"return", "T_return"}
    };

    map<string, string> symbols = {
        {"=", "T_assign"},
        {"+", "T_add"},
        {"-", "T_subtract"},
        {"*", "T_multiply"},
        {"/", "T_divide"},
        {"%", "T_remainder"},
        {"!", "T_factorial"},
        {"==", "T_equal"},
        {"!=", "T_not_equal"},
        {">=", "T_greater_equal"},
        {">", "T_greater"},
        {"<=", "T_less_equal"},
        {"<", "T_less"},
        {"&&", "T_and"},
        {"||", "T_or"},
        {"(", "T_open_parenthesis"},
        {")", "T_close_parenthesis"},
        {"{", "T_open_brace"},
        {"}", "T_close_brace"},
        {"[", "T_open_square_bracket"},
        {"]", "T_close_square_bracket"},
        {";", "T_semicolon"},
        {",", "T_comma"}
    };
    
    string input;
    ifstream file ("/Users/vsevolod/Documents/RPOP/RPOP/input2.txt");
    while(file >> input){
        if(input == "/*"){                                     //comments
            while(input != "*/"){
                file >> input;
            }
        }
        
        else if(reserved[input] != ""){                          //reserved
            cout << reserved[input] << ", -" << endl;
        }
        
        else if(symbols[input] != ""){                           //symbols
            cout << symbols[input] << ", -" << endl;
        }
        
        else if(input[0] == '\"'){
            cout << "T_stringcon, " << '\"' << input[1];
            while (input.back() != '\"'){
                file >> input;
                cout << input;
            }
            cout << endl;
        }
        
        else cout << "T_indent, " << input << endl;             //indents
    }


    return true;
}

int main() {
    int taskn = -1;
    cout << "Task number (2/3): ";
    cin >> taskn;
    if (taskn == 2) task2();
    if (taskn == 3) lexer();
    return 0;
}
