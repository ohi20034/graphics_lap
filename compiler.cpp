#include <bits/stdc++.h>
using namespace std;

void whitespace_counter();
void comment_extractor();
void unused_variable_detector();
void keyword_finder();
void line_counter();
void palindrome_checker();
void string_to_number();
void string_compression();

int main()
{
    int choice = 0;

    while (true)
    {

        cout << "\n==== Compiler Project Menu ====" << '\n';
        cout << "1. Whitespace Counter" << '\n';
        cout << "2. Comment Extractor" << '\n';
        cout << "3. Unused Variable Detector" << '\n';
        cout << "4. Keyword Finder" << '\n';
        cout << "5. Line Counter" << '\n';
        cout << "6. Palindrome Checker" << '\n';
        cout << "7. String to Number" << '\n';
        cout << "8. Function 8" << '\n';
        cout << "9. Exit" << '\n';

        cout << "Enter your choice (1-9): ";
        cin >> choice;


        switch (choice)
        {
        case 1:
            whitespace_counter();
            break;
        case 2:
            comment_extractor();
            break;
        case 3:
            unused_variable_detector();
            break;
        case 4:
            keyword_finder();
            break;
        case 5:
            line_counter();
            break;
        case 6:
            palindrome_checker();
            break;
        case 7:
            string_to_number();
            break;
        case 8:
            string_compression();
            break;
        case 9:
            cout << "Exiting program. Goodbye!" << '\n';
            break;
        default:
            cout << "Invalid choice! Please try again." << '\n';
        }
    }

    return 0;
}

// Define all functions (replace with actual logic)
void whitespace_counter()
{
    cin.ignore();
    string str;
    getline(cin,str);

    int spaceCount = 0;
    for (char ch : str)
    {
        if (ch == ' ')
        {
            spaceCount++;
        }
    }
    cout << "\033[32mSpace Count: " << spaceCount << "\033[0m\n";
}

void comment_extractor()
{
    cin.ignore();

    string str = R"(// This is a single-line comment
#include <iostream>
/* This is a
   multi-line comment */
int main() {
    // This is another single-line comment
    cout << "Hello, World!" << '\n';
    /* Another
       multi-line comment */
    return 0;
})";
    //getline(cin,str);

    int n = str.size();
    bool inMultiLineComment = false;
    string codeWithoutComments = "";

    for (int i = 0; i < str.size(); ++i)
    {
        if (inMultiLineComment)
        {
            if (i + 1 < n && str[i] == '*' && str[i + 1] == '/')
            {
                inMultiLineComment = false;
                cout << "\033[33m" << str.substr(i - 1, 3) << "\033[0m" << '\n';
                ++i;
            }
            else
            {
                cout << "\033[33m" << str[i] << "\033[0m";
            }
        }
        else if (i + 1 < n && str[i] == '/' && str[i + 1] == '/')
        {
            int endOfLine = i;
            while (endOfLine < n && str[endOfLine] != '\n')
            {
                ++endOfLine;
            }
            cout << "\033[33m" << str.substr(i, endOfLine - i) << "\033[0m" << '\n';
            i = endOfLine - 1;
        }
        else if (i + 1 < n && str[i] == '/' && str[i + 1] == '*')
        {
            inMultiLineComment = true;
            cout << "\033[33m" << str.substr(i, 2) << "\033[0m";
            ++i;
        }
        else
        {
            codeWithoutComments += str[i];
        }
    }
    cout << "\n\n\033[32mCode without comments:\033[0m\n\n";
    cout << "\033[32m" << codeWithoutComments << "\033[0m" << '\n';
}

void unused_variable_detector()
{
    cin.ignore();
    string code = R"(
        int x;
        float y;
        int z;
        x = 10;
        y = 20;
        int a = 5;
    )";
    istringstream codeStream(code);
    string line;
    set<string> allVariables;
    set<string> usedVariables;
    while (getline(codeStream, line))
    {
        istringstream lineStream(line);

        string word;
        lineStream >> word;

        if (word == "int" || word == "float" || word == "char" || word == "double")
        {
            string varName;
            lineStream >> varName;
            string is_init;
            lineStream >> is_init;
            if(is_init=="=")
            {
                usedVariables.insert(varName);
            }
            allVariables.insert(varName);
        }
        else
        {
            string init;
            lineStream >> init;
            if(init=="=")
            {
                usedVariables.insert(word);
            }
        }
    }
    cout << "\033[32mUnused variables:\n\033[32m";
    for (auto& var : usedVariables)
    {

        cout << "\033[32m"<< var <<"\033[0m" << '\n';

    }
}
void keyword_finder()
{
    cin.ignore();
    map<string, int> cppKeywords =
    {
        {"alignas", 0}, {"alignof", 0}, {"and", 0}, {"and_eq", 0}, {"asm", 0},
        {"auto", 0}, {"bitand", 0}, {"bitor", 0}, {"bool", 0}, {"break", 0},
        {"case", 0}, {"catch", 0}, {"char", 0}, {"char16_t", 0}, {"char32_t", 0},
        {"class", 0}, {"compl", 0}, {"const", 0}, {"constexpr", 0}, {"const_cast", 0},
        {"continue", 0}, {"decltype", 0}, {"default", 0}, {"delete", 0}, {"do", 0},
        {"double", 0}, {"dynamic_cast", 0}, {"else", 0}, {"enum", 0}, {"explicit", 0},
        {"export", 0}, {"extern", 0}, {"false", 0}, {"float", 0}, {"for", 0},
        {"friend", 0}, {"goto", 0}, {"if", 0}, {"inline", 0}, {"int", 0},
        {"long", 0}, {"mutable", 0}, {"namespace", 0}, {"new", 0}, {"noexcept", 0},
        {"not", 0}, {"not_eq", 0}, {"nullptr", 0}, {"operator", 0}, {"or", 0},
        {"or_eq", 0}, {"private", 0}, {"protected", 0}, {"public", 0}, {"register", 0},
        {"reinterpret_cast", 0}, {"return", 0}, {"short", 0}, {"signed", 0}, {"sizeof", 0},
        {"static", 0}, {"static_assert", 0}, {"static_cast", 0}, {"struct", 0}, {"switch", 0},
        {"template", 0}, {"this", 0}, {"thread_local", 0}, {"throw", 0}, {"true", 0},
        {"try", 0}, {"typedef", 0}, {"typeid", 0}, {"typename", 0}, {"union", 0},
        {"unsigned", 0}, {"using", 0}, {"virtual", 0}, {"void", 0}, {"volatile", 0},
        {"wchar_t", 0}, {"while", 0}
    };
    string code = R"(
#include <iostream>
using namespace std;

int main() {
    int x = 10;
    if (x > 5) {
        cout << "x is greater than 5" << '\n';
    } else {
        cout << "x is less than or equal to 5" << '\n';
    }
    return 0;
}
)";
    stringstream strWord(code);
    string word;
    while (strWord >> word) {
        if (cppKeywords.find(word) != cppKeywords.end()) {
            cppKeywords[word]+=1;
        }
    }
    cout << "\033[32mKeyword occurrences in the code:\033[0m" << '\n';
    bool found = false;
    for (auto& i : cppKeywords) {
        if (i.second > 0) {
            cout << "\033[33m" << i.first << "\033[0m: " << i.second << '\n';
            found = true;
        }
    }

    if (!found) {
        cout << "\033[33m" << "No keywords found in the code." << "\033[33m" << '\n';
    }
}
void line_counter()
{
    cin.ignore();
    string str = R"(// This is a single-line comment
#include <iostream>
/* This is a
   multi-line comment */
int main() {
    // This is another single-line comment
    cout << "Hello, World!" << '\n';
    /* Another
       multi-line comment */
    return 0;
})";

    stringstream strr(str);
    string line;
    int line_count = 0;

    while (getline(strr, line))
    {
        line_count++;
    }
    cout << "\033[33m" << "Total lines in the raw string literal: " << "\033[0m" << line_count << "\033[0m" << '\n';
}
void palindrome_checker()
{
    cin.ignore();
    string str = "abba";
    string str2 =str;
    reverse(str.begin(),str.end());

    if (str == str2)
    {
        cout << "\033[33m" << "The string is a palindrome!" << "\033[0m" << endl;
    }
    else
    {
        cout << "\033[33m" << "The string is not a palindrome." << "\033[0m" << endl;
    }
}
void string_to_number()
{
    cin.ignore();
    int num = 0,i=0;
    bool neg = false;
    string str = "149";

    if(str[0]=='-')
    {
        neg = true;
        i++;
    }
    for(; i<str.size(); i++)
    {
        if(str[i] >= '0' && str[i] <='9')
        {
            num = num * 10 + (str[i] - '0');
        }
    }
    cout << num << endl;
}
void string_compression()
{
    cin.ignore();
    string str="aaaabbdd";
    string compressed = "";
    int count = 1;

    for (int i = 1; i < str.length(); i++)
    {
        if (str[i] == str[i - 1])
        {
            count++;
        }
        else
        {
            compressed += str[i - 1] + to_string(count);
            count = 1;
        }
    }
    compressed += str[str.length() - 1] + to_string(count);
    cout << "\033[33m" << compressed << "\033[0m" << endl;

}
