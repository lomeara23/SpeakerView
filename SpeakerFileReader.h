#include <iostream>
#include <sstream>
#include <fstream>
#include <string>

using namespace std;

class SpeakerFileReader
{
    public:
        SpeakerFileReader();
        SpeakerFileReader(string filePath);
        ~SpeakerFileReader();

        int getColCount();
        int getLineCount();
        double** getHeights();
    private:
        string filePath;
        ifstream in;

        int colCount;
        int lineCount;

        void reset();
};