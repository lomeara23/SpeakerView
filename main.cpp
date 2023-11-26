#include "SpeakerView.h"

int main(int argc, char const *argv[])
{
    SpeakerView *testRoom = new SpeakerView("Test.txt");
    testRoom->generateRoom();

    return 0;
}


