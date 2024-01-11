// Karma.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>

using namespace std;

class String {
private:
    string str;

public:
    String() {}

    String(const char* s) : str(s) {}

    String(const String& other) : str(other.str) {}

    void replace(const char* s) {
        str = s;
    }

    void replace(const String& other) {
        str = other.str;
    }

    String substring(int start, int end) const {
        if (start < 0 || start >= str.length() || end < 0 || end >= str.length() || start > end) {
            return String();
        }

        return String(str.substr(start, end - start + 1).c_str());
    }

    void print() const {
        cout << str;
    }

    int countWords(const char* word) const {
        int count = 0;
        size_t pos = 0;

        while ((pos = str.find(word, pos)) != string::npos) {
            ++count;
            pos += strlen(word);
        }

        return count;
    }
};

int main() {
    String str1;
    String str2("Hello, world!");
    String str3 = str2;

    str1.replace("New String");
    str1.print();
    cout << endl;

    str1.replace(str2);
    str1.print();
    cout << endl;

    String substr = str2.substring(0, 4);
    substr.print();
    cout << endl;

    str2.print();
    cout << endl;

    int wordCount = str2.countWords("world");
    cout << "Word count: " << wordCount << endl;
}




// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
