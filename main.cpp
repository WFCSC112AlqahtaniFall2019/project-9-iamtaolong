#include <iostream>
#include <ctime>
#include <fstream>
#include <string>
#include <vector>
#include "Data.h"
using namespace std;

template <class T>
void bubbleSort(vector <T>& array, int length);
template <class T>
void selectionSort(vector <T>& array, int size);
template <class T>
void mergeSort(vector<T>& array, vector<T>& tmp, int left, int right);
template <class T>
void Quicksort(vector<T>& numbers, int i, int k);

int main() {
    // in fstream
    // open input file of auspol2019.csv
    ifstream inFile;
    inFile.open("../auspol2019.csv");

    // check if the input file is opened correctly
    if (!inFile.is_open()){
        cout << "Input file cannot be opened correctly" << endl;
        return 1;
    }

    // until reach the end of the file
    for(int n=1000;n<=10000;n=n+1000) {

        // form dataV
        vector<Data> dataV(n);

        int count = 0;
        while (count < n) {
            // use four string to read csv
            // gender, age, friends, likes
            // get string from csv
            // getline to get gender

            //int retweet_count;
            //int favorite_count;

            string retweet_count1;
            getline(inFile, retweet_count1, ',');

            // getline to get favorite_count
            string favorite_count1 ;
            getline(inFile, favorite_count1);


            // use stoi to make string to int
            // get age, friendsCount, likesReceivedCount from stoi
            int retweet_count = stoi(retweet_count1);
            int favorite_count = stoi(favorite_count1);

            // create an object through data
            Data nextUser = Data(retweet_count, favorite_count);
            dataV.at(count) = nextUser;
            count++;
        }

        // Creates 4 copies of dataV called dataV_B, dataV_S, dataV_Q, dataV_M.
        vector<Data> dataV_B = dataV;
        vector<Data> dataV_S = dataV;
        vector<Data> dataV_Q = dataV;
        vector<Data> dataV_M = dataV;

        vector<int> intV(n);
        cout << endl;

        // Creates 4 copies of intV called intV_B, intV_S, intV_Q, intV_M
        vector<int> intV_B = intV;
        vector<int> intV_S = intV;
        vector<int> intV_Q = intV;
        vector<int> intV_M = intV;

        //sort vectors

        //BubbleSort
        clock_t start_bubbleSortData = clock();
        bubbleSort<Data>(dataV_B, dataV_B.size());
        clock_t end_bubbleSortData = clock();

        clock_t start_bubbleSortInt = clock();
        bubbleSort<int>(intV_B, intV_B.size());
        clock_t end_bubbleSortInt = clock();


        //SelectionSort
        clock_t start_SelectionSortData = clock();
        selectionSort(dataV_S, dataV_S.size());
        clock_t end_SelectionSortData = clock();

        clock_t start_SelectionSortInt = clock();
        selectionSort(intV_S, intV_S.size());
        clock_t end_SelectionSortInt = clock();

        //QuickSort

        clock_t start_quickSortData = clock();
        Quicksort(dataV_Q, 0, dataV_Q.size());
        clock_t end_quickSortData = clock();

        clock_t start_quickSortInt = clock();
        Quicksort(intV_Q, 0, intV_Q.size());
        clock_t end_quickSortInt = clock();

        //MergeSort
        vector<Data> DataTemp(dataV_M.size());
        vector<int> IntTemp(intV_M.size());

        clock_t start_mergeSortData = clock();
        mergeSort(dataV_M, DataTemp, 0, dataV_M.size() - 1);
        clock_t end_mergeSortData = clock();

        clock_t start_mergeSortInt = clock();
        mergeSort(intV_M, IntTemp, 0, intV_M.size() - 1);
        clock_t end_mergeSortInt = clock();

        // get time
        double elapsed_bubbleSortData = double(end_bubbleSortData - start_bubbleSortData) / CLOCKS_PER_SEC;
        double elapsed_bubbleSortInt = double(end_bubbleSortInt - start_bubbleSortInt) / CLOCKS_PER_SEC;
        double elapsed_SelectionSortData = double(end_SelectionSortData - start_SelectionSortData) / CLOCKS_PER_SEC;
        double elapsed_SelectionSortInt = double(end_SelectionSortInt - start_SelectionSortInt) / CLOCKS_PER_SEC;
        double elapsed_mergeSortData = double(end_mergeSortData - start_mergeSortData) / CLOCKS_PER_SEC;
        double elapsed_mergeSortInt = double(end_mergeSortInt - start_mergeSortInt) / CLOCKS_PER_SEC;
        double elapsed_quickSortData = double(end_quickSortData - start_quickSortData) / CLOCKS_PER_SEC;
        double elapsed_quickSortInt = double(end_quickSortInt - start_quickSortInt) / CLOCKS_PER_SEC;

        // print time
        cout << n << ": "
                  << "\t" << elapsed_bubbleSortData
                  << "\t" << elapsed_bubbleSortInt
                  << "\t" << elapsed_SelectionSortData
                  << "\t" << elapsed_SelectionSortInt
                  << "\t" << elapsed_quickSortData
                  << "\t" << elapsed_quickSortInt
                  << "\t" << elapsed_mergeSortData
                  << "\t" << elapsed_mergeSortInt;

        //BubbleSort
        clock_t start_bubbleSortData2 = clock();
        bubbleSort<Data>(dataV_B, dataV_B.size());
        clock_t end_bubbleSortData2 = clock();

        clock_t start_bubbleSortInt2 = clock();
        bubbleSort<int>(intV_B, intV_B.size());
        clock_t end_bubbleSortInt2 = clock();

        //SelectionSort
        clock_t start_SelectionSortData2 = clock();
        selectionSort(dataV_S, dataV_S.size());
        clock_t end_SelectionSortData2 = clock();

        clock_t start_SelectionSortInt2 = clock();
        selectionSort(intV_S, intV_S.size());
        clock_t end_SelectionSortInt2 = clock();

        //QuickSort
        clock_t start_quickSortData2 = clock();
        Quicksort(dataV_Q, 0, dataV_Q.size());
        clock_t end_quickSortData2 = clock();

        clock_t start_quickSortInt2 = clock();
        Quicksort(intV_Q, 0, intV_Q.size());
        clock_t end_quickSortInt2 = clock();

        //MergeSort
        vector<Data> DataTemp2(dataV_M.size());
        vector<int> IntTemp2(intV_M.size());

        clock_t start_mergeSortData2 = clock();
        mergeSort(dataV_M, DataTemp, 0, dataV_M.size() - 1);
        clock_t end_mergeSortData2 = clock();

        clock_t start_mergeSortInt2 = clock();
        mergeSort(intV_M, IntTemp, 0, intV_M.size() - 1);
        clock_t end_mergeSortInt2 = clock();

        // get time
        double elapsed_bubbleSortData2 = double(end_bubbleSortData2 - start_bubbleSortData2) / CLOCKS_PER_SEC;
        double elapsed_bubbleSortInt2 = double(end_bubbleSortInt2 - start_bubbleSortInt2) / CLOCKS_PER_SEC;
        double elapsed_SelectionSortData2 = double(end_SelectionSortData2 - start_SelectionSortData2) / CLOCKS_PER_SEC;
        double elapsed_SelectionSortInt2 = double(end_SelectionSortInt2 - start_SelectionSortInt2) / CLOCKS_PER_SEC;
        double elapsed_mergeSortData2 = double(end_mergeSortData2 - start_mergeSortData2) / CLOCKS_PER_SEC;
        double elapsed_mergeSortInt2 = double(end_mergeSortInt2 - start_mergeSortInt2) / CLOCKS_PER_SEC;
        double elapsed_quickSortData2 = double(end_quickSortData2 - start_quickSortData2) / CLOCKS_PER_SEC;
        double elapsed_quickSortInt2 = double(end_quickSortInt2 - start_quickSortInt2) / CLOCKS_PER_SEC;

        // print time
        cout << "\t" << elapsed_bubbleSortData2
             << "\t" << elapsed_bubbleSortInt2
             << "\t" << elapsed_SelectionSortData2
             << "\t" << elapsed_SelectionSortInt2
             << "\t" << elapsed_quickSortData2
             << "\t" << elapsed_quickSortInt2
             << "\t" << elapsed_mergeSortData2
             << "\t" << elapsed_mergeSortInt2
             << endl;
    }

    inFile.close();
    return 0;
}


// bubble sort
// cited from my previous project
template<class T>
void bubbleSort(vector <T>& array, int length){
    int currentLoop, currentElement;
    bool signal;
    for (currentLoop = 0; currentLoop < length -1; currentLoop++){
        signal = false;
        for (currentElement = 0; currentElement < length - currentLoop - 1; currentElement++)
            if (array[currentElement+1] < array[currentElement]) {
                swap(array[currentElement], array[currentElement + 1]);
                signal = true;
            }
        if(!signal)
            break;
    }
}

// Selection Sort
template <class T>
void selectionSort(vector <T>& array, int size) {
    int currentMin;
    for (int i = 0; i < size - 1; ++i){
        currentMin = i;
        for (int j = i + 1; j < size; ++j) {
            if (array[j] < array[currentMin]) {
                currentMin = j;
            }
        }
        swap(array[i],array[currentMin]);
    }
}

// Merge Sort List
// From my previous project
template <class T>
void mergeSortedLists(vector<T>& array, vector<T>& tmp, int left, int middle, int right) {
    int i = left;
    int j = middle+1;
    int k = left;

    while(i <= middle && j <= right){
        if(array.at(i) < array.at(j)){
            tmp.at(k) = array.at(i);
            i++;
            k++;
        }else{
            tmp.at(k)= array.at(j);
            j++;
            k++;
        }
    }
    while(j<=right){
        tmp.at(k)=array.at(j);
        j++;
        k++;
    }
    while(i<=middle){
        tmp.at(k)=array.at(i);
        i++;
        k++;
    }
    for(int l=left;l<=right;l++){
        array.at(l)=tmp.at(l);
    }
}

// Merge Sort
// From my previous project
template <class T>
void mergeSort(vector<T>& array, vector<T>& tmp, int left, int right) {
    int n = (right +left)/2;
    if (left==right) {
        return;
    }
    else if (left < right) {
        mergeSort(array, tmp, left, n );
        mergeSort(array, tmp, n  + 1, right);
        mergeSortedLists(array, tmp, left, n, right);
    }
}


// Quick Sort List
// From Zybook
template <class T>
int Partition(vector<T>& numbers, int i, int k) {
    int l;
    int h;
    int midpoint;
    T pivot;
    T temp;
    bool done;
    // select pivot
    midpoint = i + (k - i) / 2;
    pivot = numbers[midpoint];
    done = false;
    l = i;
    h = k;
    while (!done) {
        /* Increment l while numbers[l] < pivot */
        while (numbers[l] < pivot) {
            ++l;
        }
        /* Decrement h while pivot < numbers[h] */
        while (pivot < numbers[h]) {
            --h;
        }
        /* If there are zero or one elements remaining,
         all numbers are partitioned. Return h */
        if (l >= h) {
            done = true;
        }
        else {
            /* Swap numbers[l] and numbers[h],
             update l and h */
            temp = numbers[l];
            numbers[l] = numbers[h];
            numbers[h] = temp;
            ++l;
            --h;
        }
    }
    return h;
}

// Quick sort
// From zybook
template <class T>
void Quicksort(vector<T>& numbers, int i, int k) {
    int j;
    /* Base case: If there are 1 or zero elements to sort,
     partition is already sorted */
    if (i >= k) {
        return;
    }
    /* Partition the data within the array. Value j returned
     from partitioning is location of last element in low partition. */
    j = Partition(numbers, i, k);
    /* Recursively sort low partition (i to j) and
     high partition (j + 1 to k) */
    Quicksort(numbers, i, j);
    Quicksort(numbers, j + 1, k);
}

