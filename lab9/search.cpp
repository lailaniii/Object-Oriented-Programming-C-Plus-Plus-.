#include <iostream>
#include <vector>
#include <fstream>
#include <ctime>
using namespace std;

/**
 * @brief returns the first index of elem if it exists, otherwise returns -1
 * iterativeSearch starts at the first index and iterates sequentially to the next until it either 
 * finds the element or until it reaches the end (i.e. element does not exist)
 * 
 * @param v : vector of elements
 * @param elem : integer to look for 
 * @return int
*/
int iterativeSearch(vector<int>v, int elem){
    // use a for loop where the index, i goes from 0 to the size of v
    for(int i=0;i<v.size();i++){
    // inside the for loop, use an if statement to check whether the element at i (e.g. v[i]) equals elem
    if(v[i]==elem){
        return i;
    }
    // inside the if statement return i
}
    // outside of the for loop return -1 
    return -1;
}


/**
 * @brief returns the index of elem, if it exists in v. Otherwise it returns -1.
 * It utilizes the fact that v is increasing order (e.g. values go up and
 * duplicates are not allowed).
 * 
 * it calculates the mid from the start and end index. It compares v[mid] (i.e. value)
 * at mid) with elem and decides whether to search the left half(lower values)
 * or right half (upper values).
 * 
 * @param v : vector of elements 
 * @param start : leftmost index (starting value is 0)
 * @param end : rightmost index (starting value is v.size())
 * @param elem : integer to look for
 * @return int
*/
int binarySearch(vector<int> & v, int start, int end, int elem){
    //write an if statement that checks the terminating case
    if(start>end){
    //inside the if statement return -1 
    return -1; 
    }
    // instantiate the midpoint 
    int mid = (start + end)/2;

    // Use if/else statements to do the following:
    // 1) update end (search left half)
    if(v[mid] > elem){
        end = mid - 1;
    }
    // 2) update start (search right half)
    else if (v[mid]< elem){
        start = mid + 1;
    }
    // 3) return mid (found the elem)
    else { 
        return mid; 
    }
    // return a recursive call to binarySearch(...)
    return binarySearch(v, start, end, elem);

}
/**
 * @brief updates v to contain the values from filename (leave as is)
 * 
 * it is expected that the file contain the values ranging from one to
 * one hundred million in ascending order (no duplicates).
 * 
 * @param filename : string 
 * @param v : vector 
*/
void vecGen(string filename, vector<int> & v){
    ifstream file(filename);
    int num;
    v.clear();
    while (file.is_open() && file >> num){
        v.push_back(num);
    }

     file.close();
}
int main(){
    //populate v with 10000 sorted numbers (leave as is)
    vector<int> v;
    vecGen("10000_numbers.csv", v);

    //test elements to search for (leave as is)
    vector<int> elem_to_find;
    vecGen("test_elem.csv", elem_to_find);

    double total_iterative_time = 0.0;
    double total_binary_time = 0.0;

    // reads through all 10 of the test_elem values and calls iterative search
    // and records how long each search took (leave as is)
    for(int i=0; i < elem_to_find.size(); i++) {
        //gets the elem to search for
        int elem = elem_to_find[i];

        //stopwatches the time
        clock_t start = clock();                            // start time
        int index_if_found = iterativeSearch(v, elem);      // call search
        clock_t end = clock();                              // end time
        
        //calculates the total time it took in seconds 
        double elapsed_time_in_sec = (double(end - start)/CLOCKS_PER_SEC);
        
        //prints the index and how long it took to find it
        total_iterative_time += elapsed_time_in_sec;
    }

        // repeats the the loop above so that it records the time
        // it takes for binarySearch to do the same operation

    for(int i=0; i< elem_to_find.size(); i++) {
        //gets the elem to search for
        int elem = elem_to_find[i];

        //stopwatches the time
        clock_t start = clock();                         
        int index_if_found = binarySearch(v, 0, v.size() -1, elem);      
        clock_t end = clock();                              
        //calculates the total time it took in seconds 
        double elapsed_time_in_sec = (double(end - start) / CLOCKS_PER_SEC);
        total_binary_time += elapsed_time_in_sec;
    }
        //prints the index and how long it took to find it
        int num_tests = elem_to_find.size();
        double average_iterative_time = total_iterative_time / num_tests;
        double average_binary_time = total_binary_time / num_tests;

        cout << "Average time for iterativeSearch:" << average_iterative_time << "s" << endl;
        cout << "Average time for binarySearch:" << average_binary_time << "s" << endl;

        double speedup = average_iterative_time / average_binary_time;
        cout << "Speedup: " << speedup << endl;

    return 0;
}