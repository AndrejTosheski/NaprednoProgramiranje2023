#include <iostream>
#include <string>
#include <fstream>
using namespace std;

int main()
{
    string filename, text;
    cout << "Name of the text document: ";
    getline(cin, filename);
    cout << "Write text: ";
    getline(cin, text);

    ofstream outfile;
    outfile.open(filename, ios::app);
    if (!outfile){
        cerr << "Can't open file!" << endl;
        return 1;
    }

    outfile << text << endl;
    outfile.close();
    cout << "Text added" << endl;
    return 0;
}