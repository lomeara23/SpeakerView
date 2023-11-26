#ifndef SPEAKERVIEW_H
#define SPEAKERVIEW_H

#include <iostream>
#include "MonoStack.h"
#include "SpeakerFileReader.h"

using namespace std;

class SpeakerView{
    private:
        MonoStack<double> **monoArr;
        SpeakerFileReader *fr;

        int columns;
        int lines;

    public:
        SpeakerView(); //Default constructor
        SpeakerView(string filePath); //Overloaded constructor
        ~SpeakerView(); //Destructor

        void generateRoom();

        bool colPush(MonoStack<double> *column, double data);
};
#endif