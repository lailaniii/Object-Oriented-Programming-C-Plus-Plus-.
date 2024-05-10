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

/**
 * @brief writes to file the time it took to search with respect to the 
 * size of the vector, n 
 * Number of Elements (n)  Time (sec)
  XXXX                      X.XXXXX
  XXXX                      X.XXXXX
 * @param filename (string) : filename (e.g output_1000_numbers.csv)
 *  @param times (vector<double>) : average times
 * @param n (vector<int>) : sizes of vectors 
*/
void writeTimes(string filename, const vector<double> times, const vector<int> n){
    ofstream myFile(filename);

    myFile << "Number of Elements (n)\t Time (sec)" << endl;
    for(int i = 0; i < times.size(); i++){

        myFile << n[i] << "\t" << times[i] << "\n";
    }
    myFile.close();
    cout << "Wrote to " << filename << endl;
}

/**
 * @brief computes the average of the elements in vector, a 
 * 
 * @param a vector of double
 * @return double
*/
double average(const vector<double> a){
    double sum = 0.0;
    for(int i = 0; i < a.size(); i++){
        sum += a[i];
    }
    return sum / a.size();
}

int main(){

    //test elements to search for 
    vector<int> elem_to_find;
    vecGen("test_elem.csv", elem_to_find);

    //size (n) of all tests
    vector<int> file_sizes;
    vecGen("sizes.csv", file_sizes);

    //n list of numbers 
    vector<int>v;

    //results of times 
    vector<double> times;

    //results of times
    vector<double> avg;

    // create a for loop to iterate through the file sizes 
        for(int i = 0; i < file_sizes.size(); i++) {
        // get the name/size of the file and assign it to string called filename
            string filename = to_string(file_sizes[i]) + "_numbers.csv";
        //call vecGen on filename and v 
            vecGen(filename, v);
        //print filename (this will be good for debugging)
            cout << filename << endl;
        //call times.clear() // this ensures that we reset times everytime we read a new file
            times.clear();
        // create another for loop to iterate through all the elements from elem_to_find.
        for(int j = 0; j < elem_to_find.size(); j++){
            int elem = elem_to_find[j];
        //stopwatches the time
            clock_t start = clock();                         
            int index_if_found = binarySearch(v, 0, v.size() -1, elem);      
            clock_t end = clock();                              
        //calculates the total time it took in seconds 
            double elapsed_time_in_sec = (double(end - start) / CLOCKS_PER_SEC);

            // append the elapsed_time_in_sec to the vector,times (hint: push_back())
            times.push_back(elapsed_time_in_sec);
        }
            //This code should be within the for loop that iterates 
            //through all the elements from elem_to_find

        // call average on the vector, times and save it as a double. This code should be
        // outside the for loop that iterates through all elements from elem_to_find
        // but within the for loop that iterates through the file sizes
       double avg_times = average(times);

       // append the double to avg. (hint:push_back())
       avg.push_back(avg_times);
       // This code should be outside the for loop that iterates through
       // all the elements from elem_to_find
       // but within the for loop that iterates through the file sizes
       cout << "Average time for iterativeSearch: " << avg_times << endl;
    }
    
    //outside both for loops call writeTimes with the appropriate parameters
    // the first parameter should be "iterativeSearch_times.cvs"
    //read the function brief to complete the rest of the parameters
    writeTimes("iterativeSearch_times.csv", times, file_sizes);

    //call avg.clear() to reset avg. so we can use it for binarySearch
    avg.clear();

    // repeat the nested for loops for iterativeSearch, but call binarySearch instead

    for(int i = 0; i < file_sizes.size(); i++) {
        // get the name/size of the file and assign it to string called filename
        string filename = to_string(file_sizes[i]) + "_numbers.csv";
        //call vecGen on filename and v 
        vecGen(filename, v);
        //print filename (this will be good for debugging)
        cout <<  filename << endl;
        //call times.clear() // this ensures that we reset times everytime we read a new file
        times.clear();
        // create another for loop to iterate through all the elements from elem_to_find.
        for(int j = 0; j < elem_to_find.size(); j++){
            int elem = elem_to_find[j];
        //stopwatches the time
            clock_t start = clock();                         
            int index_if_found = binarySearch(v, 0, v.size() -1, elem);      
            clock_t end = clock();                              
        //calculates the total time it took in seconds 
            double elapsed_time_in_sec = (double(end - start) / CLOCKS_PER_SEC);

            // append the elapsed_time_in_sec to the vector,times (hint: push_back())
            times.push_back(elapsed_time_in_sec);
        }
            //This code should be within the for loop that iterates 
            //through all the elements from elem_to_find

        // call average on the vector, times and save it as a double. This code should be
        // outside the for loop that iterates through all elements from elem_to_find
        // but within the for loop that iterates through the file sizes
       double avg_times = average(times);
    
       // append the double to avg. (hint:push_back())
       avg.push_back(avg_times);
       // This code should be outside the for loop that iterates through
       // all the elements from elem_to_find
       // but within the for loop that iterates through the file sizes
       cout << "Average time for binarySearch:" << avg_times << endl;
    }
    
    //outside both for loops call writeTimes with the appropriate parameters
    // the first parameter should be "binarySearch_times.cvs"
    //read the function brief to complete the rest of the parameters
    writeTimes("binarySearch_times.csv", times, file_sizes);

    return 0;

}