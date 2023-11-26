using namespace std;

int main(int argc, char const *argv[])
{
    int cols = 4;
    int rows = 3;
    double **Hell;
    for(int i = 0 ; i < rows ; i++){
        Hell[i] = new double[cols];
    }

    int currRow = 0;
    while(getline(in,text)) {
        istringstream iss(text);
        double d;
        int currCol = 0;
        while (iss >> d){
            Hell[currRow][currCol] = d;
            currCol++;
        }
        currRow++;
    }
    
    return 0;
}
