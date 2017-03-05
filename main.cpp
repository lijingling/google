#include <iostream>
#include <fstream>
#include <vector>
#include <cstdlib>
#include <string>
using namespace std;

void GetPointNum(string test, int& rows, int& cols)
{
    const char* c = test.c_str();
    rows = 0;
    cols = 0;
    int j = 0;
    while(c[j] != ' ')
    {
        rows = rows*10 + (c[j]-'0');
        j++;
    }
    j = j+1;
    while(c[j] != 0)
    {
        cols = cols*10 + (c[j]-'0');
        j++;
    }
    cout << rows << ' ' << cols << endl;
}
int main()
{
    ifstream out;
    string str = "A-small-attempt3.in";
    out.open(str.c_str(), ios::in);

    ofstream in;
    in.open("output.txt", ios::trunc);
    string case_title = "Case #";

    string line;
    vector<string> text;
    while(!out.eof()){
        std::getline(out,line);
        text.push_back(line);
        //cout <<line<<endl;
    }

    out.close();
    //cout << text.size()<<endl;
    //cout << text[0] << endl;
    int testcase = atof(text[0].c_str());
    cout << testcase << endl;

    //for(int i=0; i<testcase; i++)
    for(int i=0; i<1; i++)
    {
        int rows = 1000;
        int cols = 500;
        //GetPointNum(text[i+1], rows, cols);
        rows -= 1;
        cols -= 1;
        int result = 0;

        if(rows>=cols)
        {
            for(int i=0; i<cols; i++)
            {
                int sizetemp = i+1;
                if(sizetemp == 1)
                    result += (cols-i) * (rows-i);
                else if((sizetemp % 2) == 0)
                    result += (cols-i) * (rows-i)*2;
                else
                    result += (cols-i) * (rows-i)*3;
            }
            cout << result << endl;
        }
        else
        {
            for(int i=0; i<rows; i++)
            {
                int sizetemp = i+1;
                if(sizetemp == 1)
                    result += (cols-i) * (rows-i);
                else if((sizetemp % 2) == 0)
                    result += (cols-i) * (rows-i)*2;
                else
                    result += (cols-i) * (rows-i)*3;
            }
            cout << result << endl;
        }




        //write in file
        in << case_title << (i+1) << ": " << result << "\n";
    }
    in.close();
    return 0;
}
