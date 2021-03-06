/*
 * Author: Steven Herrera
 * Project: File Tokenizer
 * Purpose: It's suppposed to enter a file then Tokenizer everything inside.
 *            Afterwards it should only print out the Alpha characters 
 * Notes: This can also take in words like Cat's as one word
 *
 */

#include <iostream>
#include <iomanip>
#include "FileTokenizer.h"
#include "C:\Users\Steven_Dev\Desktop\CS_Stuff\stringTokenizer\StringTokenizer/STokenizer.h"
#include "C:\Users\Steven_Dev\Desktop\CS_Stuff\stringTokenizer\StringTokenizer/token.h"

using namespace std;

void test_f_tokenize_simple();

int main()
{
    test_f_tokenize_simple();
    return 0;
}

void test_f_tokenize_simple() {
    Token t;
    char file[] = "solitude.txt";
    char* file_n = file;
    FTokenizer ftk(file_n);
    ftk >> t;
    int token_count = 0;
    while (ftk.more()) {
        if (t.type_string() == "ALPHA") {
            token_count++;
            cout << setw(10) << token_count
                << setw(3) << left << ":" << setw(25) << left << t.token_str()
                << t.type_string() << endl;
        }
        t = Token();
        ftk >> t;
    }
    cout << "Tokens Found: " << token_count << endl;
    cout << "==========" << endl;

}