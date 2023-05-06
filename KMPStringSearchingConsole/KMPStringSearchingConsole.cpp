// KMPStringSearchingConsole.cpp : 此檔案包含 'main' 函式。程式會於該處開始執行及結束執行。
//

#include <iostream>
#include <stdio.h>
#include <windows.h>
#include <string>
#include<conio.h>
#include "KMPStringSearching.h"

#define NORMAL_STYLE (FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED)
#define HIGHLINE_STYLE (BACKGROUND_BLUE | BACKGROUND_GREEN | BACKGROUND_RED | FOREGROUND_BLUE & FOREGROUND_GREEN & FOREGROUND_RED)

using namespace std;
using namespace StringSearching;

int main()
{
    string text = "";
    string keyword = "";

    char operKey = 'E';
    do {
        HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

        //title
        SetConsoleTextAttribute(hConsole, HIGHLINE_STYLE ^ BACKGROUND_RED);
        cout << "KMP Keyword Searching";
        SetConsoleTextAttribute(hConsole, NORMAL_STYLE);
        cout << endl << "------------------------------------------------------------------------------------------" << endl;
        string inputWord = "";
        char temp;

        cout << "Please input ";
        SetConsoleTextAttribute(hConsole, HIGHLINE_STYLE);
        cout << "Text";
        SetConsoleTextAttribute(hConsole, NORMAL_STYLE);
        cout << " : " << "\n";

        //insert words
        inputWord = "";
        temp;
        while (cin.get(temp) && temp != '\n') {
            inputWord += temp;
        }
        text = inputWord;

        cout << endl;
        cout << "Please input ";
        SetConsoleTextAttribute(hConsole, HIGHLINE_STYLE);
        cout << "Keyword";
        SetConsoleTextAttribute(hConsole, NORMAL_STYLE);
        cout << " : " << "\n";
        SetConsoleTextAttribute(hConsole, HIGHLINE_STYLE);

        //insert words
        inputWord = "";
        temp;
        while (cin.get(temp) && temp != '\n') {
            inputWord += temp;
        }
        keyword = inputWord;

        SetConsoleTextAttribute(hConsole, NORMAL_STYLE);

        cout << "------------------------------------------------------------------------------------------" << endl;

        KMPStringSearching* kmp = new KMPStringSearching(keyword);
        int* keys;
        int count = kmp->Search(text, keys);

        //show the count of matchs
        cout << "Found ";
        SetConsoleTextAttribute(hConsole, NORMAL_STYLE ^ FOREGROUND_BLUE);
        cout << to_string(count);
        SetConsoleTextAttribute(hConsole, NORMAL_STYLE);
        cout << " Results : " << "\n";

        //show where the strings are
        int currentSplitIndex = count > 0 ? 0 : -1;
        int closeBracket = -1;
        int textLength = static_cast<int>(text.length());
        for (int c = 0; c < textLength; c++) {
            if (closeBracket == 0) {
                cout << "]";
                SetConsoleTextAttribute(hConsole, NORMAL_STYLE);
            }
            if ((currentSplitIndex > -1 && currentSplitIndex < count)
                && (keys[currentSplitIndex] == c)) {
                SetConsoleTextAttribute(hConsole, HIGHLINE_STYLE | FOREGROUND_RED);
                cout << "[";
                currentSplitIndex++;
                closeBracket = kmp->GetKeywordLength();
            }
            if (closeBracket > -1)
                closeBracket--;
            cout << text[c];
        }
        if (closeBracket == 0)
            cout << "]";
        SetConsoleTextAttribute(hConsole, NORMAL_STYLE);

        delete[] keys;
        delete kmp;

        cout << endl << endl;

        //check continue
        cout << "Press Any Key to start from Keyword; \"E\" for Exit : ";
        operKey = _getch();
        cout << "\n=========================================================================" << endl;
    } while (operKey != 'e' && operKey != 'E');
}

// 執行程式: Ctrl + F5 或 [偵錯] > [啟動但不偵錯] 功能表
// 偵錯程式: F5 或 [偵錯] > [啟動偵錯] 功能表

// 開始使用的提示: 
//   1. 使用 [方案總管] 視窗，新增/管理檔案
//   2. 使用 [Team Explorer] 視窗，連線到原始檔控制
//   3. 使用 [輸出] 視窗，參閱組建輸出與其他訊息
//   4. 使用 [錯誤清單] 視窗，檢視錯誤
//   5. 前往 [專案] > [新增項目]，建立新的程式碼檔案，或是前往 [專案] > [新增現有項目]，將現有程式碼檔案新增至專案
//   6. 之後要再次開啟此專案時，請前往 [檔案] > [開啟] > [專案]，然後選取 .sln 檔案
