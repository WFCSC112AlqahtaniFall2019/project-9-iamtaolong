//
// Created by Tao on 11/21/19.
//
#include <iostream>
#include <fstream>
#include "Data.h"
#include <string>
using namespace std;

// !!!!!!!!!
// i use the data from the Kaggle, which is a dataset about twitter and tweets
// https://www.kaggle.com/taniaj/australian-election-2019-tweets
// i still use the likes they received to sort

//default constructor
Data :: Data() {

    // gender is a string
    //gender = "";
    // age is an int
    favorite_count = 0;
    // friendscount is also an int
    retweet_count = 0;
    // likescount is an int
    //likesReceivedCount = 0;

}


// alternative constructor
Data :: Data (int Aretweet_count, int Afavorite_count) {

    // gender is a string
    retweet_count = Aretweet_count;
    // age is an int
    favorite_count = Afavorite_count;
    // friendscount is also an int
    //friendsCount = AfriendsCount;
    // likescount is an int
    //likesReceivedCount = AlikesReceivedCount;

}

// > overloader
// overloads the comparison operators (< or >).
// You will choose at least one attribute from your data set to be the comparison attribute.
// friend operator
bool operator > (const Data &previousUser, const Data &FBUser) {

    // return bigger
    return previousUser.favorite_count > FBUser.favorite_count;
}


// > overloader
// overloads the comparison operators (< or >).
// You will choose at least one attribute from your data set to be the comparison attribute.
// friend operator
bool operator < (const Data &previousUser, const Data &FBUser) {

    return previousUser.favorite_count < FBUser.favorite_count;

    // return smaller
    /*if (this->likesReceivedCount > FBUser.likesReceivedCount) {
        return false;
    }
        // return smaller
    else if (this->likesReceivedCount < FBUser.likesReceivedCount) {
        return true;
    }
        // same return smaller
    else {
        return false;
    }*/
}


// Overloads the output stream operator
// This will be used by the Linked List class to print the contents of a Linked List class
ostream& operator << (ostream& os, const Data FBuser) {

// print out the contents
// print method for all message
    os << "User's retweet_count: " << FBuser.retweet_count;
    os << "\t\t,\t\t favorite_count: " << FBuser.favorite_count;
    //os << "\t\t,\t\t num of FRIENDS: " << FBuser.friendsCount;
    //os << "\t\t,\t\t num of LIKES ❤: " << FBuser.likesReceivedCount;
    return os;
}