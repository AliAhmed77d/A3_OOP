// File name:   A3_SheetPb3_20210944.cpp
// Purpose:     Count repeated words in file
// Author(s):   Mohammed Ahmed El-mustafa
// ID(s):       20210944
// Section:     S15
// Date:        12/5/2023
// Version:     1

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <regex>
#include <map>

using namespace std;


int main() {
    map<string,int> words;
    regex regex1(R"([^\w\s\-])");
    string filename;
    cout << "Please enter file name :-" << endl;
    cin >> filename;
//
    fstream file(filename+".txt");
    if(file.is_open()){
        cout << "File is open"<<endl;
        string line;
        while(getline(file,line)){
            string word;
            stringstream lineStream(line);
            while(lineStream >> word){
                word = regex_replace(word,regex1,"");
                if(word.length() > 1){
                    for(char& letter : word){
                        letter = (char)tolower(letter);
                    }
                    if(words.count(word) > 0 ){
                        words[word]++;
                    }else{
                        words[word] = 1;
                    }
                }
            }
        }

        for(auto const& word : words){
            cout << "( " << word.first << " )" << " is repeated " << word.second << " time" << (word.second > 1 ? "s" : "") << endl;
        }
    }else{
        cout << "file is not exist.";
    }
    return 0;
}
