#include "SpeakerFileReader.h"

SpeakerFileReader::SpeakerFileReader(){
    throw runtime_error("No file provided");
}
SpeakerFileReader::SpeakerFileReader(string fp){
    in.open(fp);
    colCount = 0;
    lineCount = 0;
    double dbl;
    string line;
    getline(in, line);
    istringstream iss(line);
    while(iss >> dbl){
        colCount++;
    }
    reset();
    string nullStr;
    while(getline(in, nullStr)){
        lineCount++;
    }
    reset();
    
}
SpeakerFileReader::~SpeakerFileReader(){
    in.close();
}

int SpeakerFileReader::getColCount(){
    return colCount;
}
int SpeakerFileReader::getLineCount(){
    return lineCount;
}
double** SpeakerFileReader::getHeights(){
    double **heights = new double*[lineCount];
    for(int i = 0 ; i < lineCount ; i++){
        heights[i] = new double[colCount];
    }
    string line;
    int currLine = 0;
    int currCol = 0;
    while(getline(in, line)){
        currCol = 0;
        while((line.find(" ") != string::npos)){
            double num = stod(line.substr(0,line.find(" ")));
            line = line.substr(line.find(" ")+1);
            heights[currLine][currCol] = num;
            currCol++;
        }
        double num = stod(line.substr(0,line.find(" ")));
        line = line.substr(line.find(" ")+1);
        heights[currLine][currCol] = num;
        currLine++;
        currCol++;
    }
    reset();
    return heights;
}

void SpeakerFileReader::reset(){
    in.clear();
    in.seekg(0);
}