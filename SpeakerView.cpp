#include "SpeakerView.h"

SpeakerView::SpeakerView(){

}
SpeakerView::SpeakerView(string filePath){
    fr = new SpeakerFileReader(filePath);
    columns = fr->getColCount();
    lines = fr->getLineCount();
    monoArr = new MonoStack<double>*[columns];
    for(int i = 0 ; i <  columns; i++){
        monoArr[i] = new MonoStack<double>(lines, 'd');
    }
}
SpeakerView::~SpeakerView(){

}

void SpeakerView::generateRoom(){
    double **heights = fr->getHeights();
    for(int currCol = 0 ; currCol < columns ; currCol++){
        int canSeeCount = 0;
        for(int currLine = 0 ; currLine < lines ; currLine++){
            if(colPush(monoArr[currCol], heights[currLine][currCol])){
                canSeeCount++;
            }
        }
        cout << "In column " << currCol+1 << " there are " << canSeeCount << " that can see. Their heights are: ";

        while(!monoArr[currCol]->isEmpty()){
            monoArr[currCol]->pop();
        }

        for(int currLine = 0 ; currLine < lines ; currLine++){
            if(colPush(monoArr[currCol], heights[currLine][currCol])){
                cout << heights[currLine][currCol] << " ";
            }
        }
        cout << "inches." << endl;
    }
}

bool SpeakerView::colPush(MonoStack<double> *column, double data){
    column->push(data);
    return(column->size() == 1);
}