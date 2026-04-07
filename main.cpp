#include <iostream>
#include <fstream>
using namespace std;


bool isKeyword(string token) {
    string keyw[] = {"int","float","double","char","return","if","else","while","for","void"};
    for (int i = 0; i < 10; i++)
        if (token == keyw[i]) return true;
    return false;
}


bool isOperator(string token) {
    string optr[] = {"+","-","*","/","=","<<",">>","<",">","=="};
    for (int i = 0; i < 10; i++)
        if (token == optr[i]) return true;
    return false;
}


bool isPunctuation(string token) {
    string punc[] = {"(",")","{","}",";",","};
    for (int i = 0; i < 6; i++)
        if (token == punc[i]) return true;
    return false;
}


bool isNumber(string token) {
    for (int i = 0; token[i] != '\0'; i++)
        if (token[i] < '0' || token[i] > '9') return false;
    return true;
}


bool isIdentifier(string token) {
    if (!((token[0] >= 'a' && token[0] <= 'z') || (token[0] >= 'A' && token[0] <= 'Z') || token[0] == '_'))
        return false;
    for (int i = 1; token[i] != '\0'; i++)
        if (!((token[i] >= 'a' && token[i] <= 'z') ||
              (token[i] >= 'A' && token[i] <= 'Z') ||
              (token[i] >= '0' && token[i] <= '9') ||
              token[i] == '_'))
            return false;
    return true;
}


void tokenize() {
    ifstream file("data.txt");
    string token;

    string keywords[50], identifiers[50], operators[50], punctuations[50], numbers[50], stringConstants[50];
    int k=0, id=0, op=0, p=0, num=0, sc=0;

    if (!file) {
        cout << "File doesn't exits\n";
        return;
    }

    cout << "Token identification:\n\n";

    while (file >> token) {


        if (token[0] == '"') {
            string strConst = token;
            while (strConst.back() != '"' && file >> token) {
                strConst += " " + token;
            }
            cout << strConst << " -- StringConstant\n";
            stringConstants[sc++] = strConst;
            continue;
        }

        if (isKeyword(token)) {
            cout << token << " -- Keyword\n";
            keywords[k++] = token;
        }
        else if (isOperator(token)) {
            cout << token << " -- Operator\n";
            operators[op++] = token;
        }
        else if (isPunctuation(token)) {
            cout << token << " -- Punctuation\n";
            punctuations[p++] = token;
        }
        else if (isNumber(token)) {
            cout << token << " -- Number\n";
            numbers[num++] = token;
        }
        else if (isIdentifier(token)) {
            cout << token << " -- Identifier\n";
            identifiers[id++] = token;
        }
        else {
            cout << token << " -- Unknown\n";
        }
    }


    cout << "\nIdentifier\n";
    for (int i = 0; i < id; i++)
        cout << i+1 << ". Identifier :" << identifiers[i] << endl;

    cout << "\nKeyword\n";
    for (int i = 0; i < k; i++)
        cout << i+1 << ". Keyword :" << keywords[i] << endl;

    cout << "\nOperator\n";
    for (int i = 0; i < op; i++)
        cout << i+1 << ". Operator :" << operators[i] << endl;

    cout << "\nPunctuation\n";
    for (int i = 0; i < p; i++)
        cout << i+1 << ". Punctuation :" << punctuations[i] << endl;

    cout << "\nNumber\n";
    for (int i = 0; i < num; i++)
        cout << i+1 << ". Number :" << numbers[i] << endl;

    cout << "\nConstant\n";
    for (int i = 0; i < sc; i++)
        cout << i+1 << ". StringConstant :" << stringConstants[i] << endl;

    file.close();
}

int main() {
    tokenize();
    return 0;
}
