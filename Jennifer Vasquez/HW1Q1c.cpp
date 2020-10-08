// Jeniffer Vasquez
//  HW#1Q1c
//  The following code will take in random strings utilizing move semantics
//  for both vectors and Linked Lists

#include <iostream>
#include <vector>

using namespace std;
using namespace chrono;

void generateVec(vector <string> &vec, int l)
{
    string word; // declare word to be string
    char r; // declare r to be a char
    for(int i = 0; i < l; ++i) // outer loop will determine how many strings
    {
        for (int j = 0; j < 5; ++j) // inner loop is to determine the length of each string
        {
            r = rand() % 26 + 'a'; // generates random # and adds it to 'a', choosing a random char and storing in r
            word += r; // will add a char 5 times into 'word' to create a string
        }
        vec.push_back(word); // push_back the 'word' into the vector in the i'th position
        word.clear(); // will clear the word to be able to run the code again and start a new string
        cout<< vec[i] << endl; // will print the i'th string in the vector
    }
}



int main()
{
    int l = 5; // initalizes the # of strings
    vector <string> vec; // declare vector of type string
    
    auto t1 = high_resolution_clock::now(); // begins timing vec
    generateVec(vec, l); // call vector function and generate vector of strings of length l
    auto t2 = high_resolution_clock::now(); // stops timing vec
    auto duration1 = duration_cast<microseconds>( t2 - t1 ).count(); // calculates duration
    
    cout<< "\nVector takes " << duration1 << " microseconds.\n";
    
    return 0;
}
