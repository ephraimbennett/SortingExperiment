#include <iostream>
#include <ctime>
#include <fstream>
#include <string>

#include "Merge.h"
#include "Insertion.h"



using namespace std;

vector<int> test(const vector<int> &, int, int);

/**
 * Right now, main is set up to conduct the experiment for Q2, however it can easily be changed back to Q1 as well.
 * This can be done by adjusting the N value, and the number of times ran to the desired sizes. To make this a "pure"
 * Merge Sort, simply set the K value = 0.
 */
int main()
{
    ifstream instream("../nums.txt");
    if (!instream.is_open())
    {
        cout << "Can't find file." << endl;
    }

    vector<int> arr;
    string x;
    int N = 125000;
    for (size_t i = 0; i < N; ++i)
    {
        getline(instream, x);
        arr.push_back(stoi(x));
    }
    instream.close();

    test(arr, 1, 2400);
}

/**
 * Since merge sort is recursive and must take the vector by reference, if we run the same sort multiple times, we are
 * passing in an already sorted vector. Use this method to pass in the vector by copy so the original does not
 * change.
 */
void mergeWrapper(vector<int> arr, int k)
{
    mergeSort(arr, 0, arr.size() - 1, k);
}

vector<int> test(const vector<int> &arr, int times, int k)
{
    vector<int> t = arr;
    std::clock_t start_time = std::clock();
    for (size_t i = 0; i < times; ++i) {
        insertionSort(t);
    }
    std::clock_t insertion_time = std::clock() - start_time;
    std::cout << "Insertion Time: "
            << ((double) insertion_time) / (double) CLOCKS_PER_SEC
            << " seconds" << std::endl;

    
    t = arr;
    start_time = std::clock();
    for (size_t i = 0; i < times; ++i) {
        mergeWrapper(t, k);
    }
    std::clock_t merge_time = std::clock() - start_time;
    std::cout << "Merge Time: "
            << ((double) merge_time) / (double) CLOCKS_PER_SEC
            << " seconds" << std::endl;

    vector<int> res = {insertion_time, merge_time};
    return res;
}