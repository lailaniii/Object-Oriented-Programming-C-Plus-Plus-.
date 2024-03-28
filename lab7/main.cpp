#include <iostream>
#include <fstream>
#include <string>
using namespace std;

/// @brief writes sample size number of strings
/// Example output: if n=3 and arr a [1,2,3]
///1
///2
///3
/// @param filename
/// @param arr
/// @param sample size

void writeToFile(string filename, int *arr, int SAMPLE_SIZE) {
    ofstream file(filename);
    for (int i = 0; i < SAMPLE_SIZE; i++) {
        file << arr[i] << "\n";
    }
    file.close();
    printf("Wrote to %s\n", filename.c_str());
}

/// @brief writes sample size number of strings
/// Example output: if n = 2 and arr = ["cat", "dog"]
///cat
///dog
/// @param filename
/// @param arr
/// @param sample_size

void writeToFile(string filename, string *arr, int SAMPLE_SIZE) {
    ofstream file(filename);
    for (int i = 0; i < SAMPLE_SIZE; i++) {
        file << arr[i] << "\n";
    }
    file.close();
    printf("Wrote to %s\n", filename.c_str());
}


/// @brief writes sample_size number of strings
/// Example output; if n=2 and arr = ["c", "d"]
///c
///d
/// @param filename
/// @param arr
/// @param sample_size

void writeToFile(string filename, char * arr, int SAMPLE_SIZE){
    ofstream file(filename);
    string val;


    for(int i = 0; i < SAMPLE_SIZE; i++){
        file <<arr[i];
        file << "\n";
    }
    file.close();
    printf("wrote to %s\n",filename. c_str());
}

    /// @brief reads the content of any file
    /// @param filename

    void readFile(string filename){
        ifstream file(filename);
        if(file.is_open()){
            string line;
            while(getline(file, line)){
            cout << line << endl;
}
}
        else {
            file.close();
        }
    }

int main(){
    const int SAMPLE_SIZE = 10;
    int array_int[SAMPLE_SIZE] = {1,2,3,4,5,6,7,8,9,10};
    string array_str[SAMPLE_SIZE] = {"This","is","a","sentence. ",
                                    "This","is","another","sentence. ",
                                    "The", "end."};
    char array_char[SAMPLE_SIZE] = {'a','b','c','d','e','0','1','2','3','4'};

    string int_file = "array_int.csv";
    writeToFile(int_file, array_int, SAMPLE_SIZE); //ARR IS ALREADY A POINTER

    // Do the same for the other arrays
    // CREATE a string varibale as the filename and assign it the value "array_str.csv"

    string str_file = "array_str.csv";

    // CALL writeToFile using the string variable above, array_str, and SAMPLESIZE as parameters

    writeToFile(str_file, array_str, SAMPLE_SIZE);

    //CREATE a string varibale as the filename and assign it the value "array_char.csv"

    string char_file = "array_char.csv";

    //CALL writeToFile using the string variable above, array_char, and SAMPLESIZE as parameters

    writeToFile(char_file, array_char, SAMPLE_SIZE) ;

    //CALL readFile() on all three generated files

    readFile(int_file);
    readFile(str_file);
    readFile(char_file);

    return 0;
}