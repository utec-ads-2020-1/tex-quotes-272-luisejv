#include <iostream>
#include <string>
#include <sstream>
#include <vector>

using namespace std;

int main() {
    string line;
    char quoteOrientation = 'd';
    while(getline(cin, line)){
        vector<char> newLine;
        stringstream ss(line);
        char path;
        while (ss >> noskipws >> path){
            if (path == '"'){
                if (quoteOrientation == 'd'){
                    newLine.push_back('`');
                    newLine.push_back('`');
                    quoteOrientation = 'u';
                } else {
                    newLine.push_back('\'');
                    newLine.push_back('\'');
                    quoteOrientation = 'd';
                }
            } else {
                newLine.push_back(path);
            }
        }
        for (auto p : newLine){
            cout << p;
        }
        cout << endl;
    }
}
