#include <iostream>
#include <fstream>
#include <regex>
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

int main() {
    task2();
}
