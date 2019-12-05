//
// Created by Tao on 11/12/19.
//
#ifndef PROJECT7_DATA_H
#define PROJECT7_DATA_H

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

// i use the data from the Kaggle, which is a dataset about Facebook users
// url: https://www.kaggle.com/sheenabatra/facebook-data
// This exploratory data analysis gives insights from Facebook dataset which consists of identifying users that can be
//     focused more to increase the business. These valuable insights should help Facebook to take intelligent decision to
//     identify its useful users and provide correct recommendations to them.

// This dataset contains 100203 entries with 15 columns.

class Data {

    // construct a friend operator to get ostream
    // Overloads the output stream operator. This will be used by the Linked List class to print
    // the contents of a Linked List class (and also any class that inherits it).
    friend ostream& operator << (ostream& os, Data a);


public:

    // default constructor
    Data();

    // alternative constructor
    Data(int Aretweet_count, int Afavorite_count);

    //●	overloads the comparison operators (< or >). You will choose at least one attribute from your data set to be the
    // comparison attribute. They can be used by the Linked List class to compare the contents of a Linked List class (and also any class that inherits it).
    // Overloads the output stream operator
    // This will be used by the Linked List class to print the contents of a Linked List class
    // bool operator > (const Data &FBUser);

    // friend operator
    friend bool operator > (const Data &previousUser, const Data &FBUser);
    // bool operator < (const Data &FBUser);

    // friend operator
    friend bool operator < (const Data &previousUser, const Data &FBUser);


private:

    // includes at least 4 data members with the proper data type matching the data attributes in your data set.
    // 4 values we are examining: gender, age, friends, likes
    // 1 string, 3 int
    int retweet_count;
    int favorite_count;

};
#endif //PROJECT7_DATA_H