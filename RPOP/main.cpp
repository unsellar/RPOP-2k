#include <iostream>
#include <fstream>
#include <regex>
#include <map>
#include <stdio.h>
#include <string.h>
using namespace std;


//(hel*o)* wrld regex
bool isNumber(const std::string& str) {
    try {
        int num = std::stoi(str);
        return true;
    } catch(std::invalid_argument& e) {
        return false;
    }
}


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
        {"return", "T_return"},
        {"printf", "T_printf"}
    };
    
    map<string, string> indents_allowers = {
        {"int", "T_int"},
        {"char", "T_char"},
        {"float", "T_float"},
        {"void", "T_void"},
        
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
    
    string line;
    string delimeter = " ";
    bool indentcreation = 0;             //возможность инициализации переменной
    int indentcreation_expire = 0;
    string indentslist[10];              //список существующих переменных
    int numberofindents = 0;
    bool functionbody = 0;
    
    string commentstopper = "\*/";
    string input;
    ifstream file ("/Users/vsevolod/Documents/RPOP/RPOP/input2.txt");
    int linecounter = 0;
    while(getline(file, line)){//берем по строчке
        int pos = 0;
        linecounter += 1;
//        indentcreation = 0;
        
        while(line != ""){

            string token = line.substr(0, line.find(delimeter));//берем новый токен
            
            if(token == "/*"){                                       //comments noindent influence
                while(token != commentstopper){
                    token = line.substr(0, line.find(delimeter));
                    pos += token.length() + 1;
                    line = line.substr(token.length());
                    while(line[0] == ' ') line = line.substr(1);
                }
            }
            
            else if(reserved[token] != ""){                          //reserved
                cout << reserved[token] << ", -" << endl;
                if(indents_allowers[token] != "") indentcreation = 1; //отслеживание предпологаемого обозначения новой переменной
            }
            
            else if(symbols[token] != ""){                           //symbols
                cout << symbols[token] << ", -" << endl;
                if (symbols[token] == "T_open_brace") functionbody = 1; //отслеживание нахождения в теле функции
                if (symbols[token] == "T_close_brace") functionbody = 0;
            }
            
            else if(token[0] == '\"'){
                cout << "T_stringcon, " << token;
                cout << endl;
            }
            
            else if(token != ""){
                if(find(begin(indentslist), end(indentslist), token) != end(indentslist) /* and functionbody == 1*/){  //если такая переменная уже cуществует вывести
                    cout << "T_indent, " << token << endl;
                    
                }else if(indentcreation == 1){                                              //если переменную можно создать + создание
                    indentslist[numberofindents] = token;
                    numberofindents += 1;
                    cout << "T_indent, " << token << endl;
                    //indentcreation = 0; //завершение создание переменной
                    
                }
                else if(isNumber(token)){                                                                 //если это число
                    cout << "T_indent, " << token << endl;
                    
                }else{
                    cout << endl << "Error on " << linecounter << ":" << pos + 1 << endl;
                    cout << "Problematic token is: " << token << endl;
                    return true;
                }
                
            }
            
            if(indentcreation == 1 and indentcreation_expire == 1){indentcreation = 0; indentcreation_expire = 0;}
            else if(indentcreation == 1 and indentcreation_expire == 0){indentcreation_expire = 1;}
            pos += token.length() + 1;
            if (line != "") line = line.substr(token.length());
            while(line[0] == ' ') line = line.substr(1);
        }
    }
    if(functionbody == 1){ cout << " SECOND } NOT FOUND" << endl; return false;}
    return true;

}

int main() {
    int taskn = -1;
    cout << "Task number (2/3): ";
//    cin >> taskn;
    taskn = 3;
    if (taskn == 2) task2();
    if (taskn == 3) lexer();
    return 0;
}
