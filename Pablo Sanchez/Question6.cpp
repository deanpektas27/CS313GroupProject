//Question 6
//Pablo Sanchez

#include <iostream>
#include <string>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
using namespace std;

//Question 6

string encrypted;
bool solved = false;
int threshold = 1;
int stored = 0;
char storedAttempts[3][32];

string cipher(string m, const char k[]) {
    string temp;
    //scramble secret message
    for (int i = 0; i < m.length(); i++) {
        temp += m[i] + (k[i % 32] - 64);
    }
    return temp;
}
string decipher(string m, const char k[]) {
    string temp;
    //unscramble secret message
    for (int i = 0; i < m.length(); i++) {
        temp += m[i] - (k[i % 32] - 64);
    }
    return temp;
}
int test(char*  a, const char k[]) {
    int counter = 0;
    bool added = false;
    
    //check for matches
    for (int i = 0; i < 32; i++) {
        if (a[i] == k[i]) {
            counter++;
        }
    }

    //are all a match?
    if (counter == 32) {
        cout << "Deciphering complete!" << endl;
        cout << "Secret message is: " << decipher(encrypted, a);
        solved = true;
        return 0;
    }

    //if not all match, do the matches go over the threshold?
    else if (counter > threshold) {
        for (int i = 0; i < 32; i++) {
            //if so then lets store it
            storedAttempts[stored % 2][i] = a[i];
        }
        threshold++;
        stored++;
        return 1;
    }

    //if not then it was not a good attempt
    else return 2;
}
char* createAttempt(int t) {
    
    char* temp1 = new char[32];
    char* temp2 = new char[32];

    //if no stored attempts yet
    if (t < 3) {
        for (int i = 0; i < 32; i++) {
            temp1[i] = 'A' + rand() % 26;
        }
        return temp1;
    }

    //when we have stored attempts
    else {
        //make new random guess to mix in with stored attemts
        temp1 = createAttempt(0);
        for (int i = 0; i < 32; i++) {
            storedAttempts[2][i] = temp1[i];
            //new attempt from a mix of the 2 saved arrays and new random array
            temp2[i] = storedAttempts[rand() %3][i];
            //random++;
        }
        return temp2;
    }
}
void print(char* a) {
    for (int i = 0; i < 32; i++) {
        cout << a[i];
    }
}


int main() {
    srand(time(nullptr));
    //keep track of attempts made
    int attempts = 0;
    //for the return value from the test function
    int tested;
    //empty array to store the current attempt
    char* attempt = new char[32];

    //secret message and key for vigenere cipher
    string message = "Roses are red, violets are blue. My friend aced this class and now I will too!";
    const char KEY[32] = { 'Q', 'E', 'T', 'J', 'X','I','U','P','A','B','L','O','Z','G','H','C','F','D','V','W','Y','M','I','O','R','G','K','N','S','W','W','W' };
    
    //store encrypted message in a variable
    encrypted = cipher(message, KEY);

    cout << "Secret Message displayedhere: \n" << endl << encrypted << endl << endl;

    while (!solved) {
        cout << "\nCurrent attempts: " << attempts << "." << endl;
        cout << "Stored Attempts: " << stored << endl;
            attempts++;
            //Here we can limit the attempts if desired
            if (attempts > 5000) {
                cout << "\nPassed limit of attempts. Best attempt was: ";
                //show best attempt
                print(storedAttempts[stored % 2]);
                //apply best attempt to the secret message
                cout << "\nApplied is: " << decipher(encrypted, storedAttempts[stored % 2]);
                break;
            }
            //create new attempt
            attempt = createAttempt(threshold);
            cout << "Current generated guess is: "; 
            //show the attempt as a char array
            print(attempt);
            //apply the attempt to the secret message to see how well it works
            cout << endl << "Apply current attempt to encrypted message: " << decipher(encrypted, attempt);
            cout << endl << "Now running test...";
            //test return the int depending on how many matches we have between the key and the attempt
            tested = test(attempt, KEY);
            if (tested == 0) {
                continue;
            }
            else if (tested == 1) {
                cout << "Good generated attempt found and added to list";
            }
            else {
                cout << "not a good generated attempt. Try again.";
            } 
    }
}