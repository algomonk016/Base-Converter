#include "bits/stdc++.h"
using namespace std;

map<char, int> mp_from;
map<int, char> mp_to;

// functions

// to convert number to Decimal
string numToDecimal(string num, int base);

// to convert Decimal to any base
string numToBase(string num, int to_base);

int main() {
    // #ifndef ONLINE_JUDGE
    //     freopen("input.txt", "r", stdin);
    //     freopen("output.txt", "w", stdout);
    // #endif

    cout<<"Enter base of number: \n";
    int from_base; cin>>from_base;
    
    // store the characters and their values in separate maps
    // using maps, it'll very easy to get corresponding value
    for(int i=0; i<min(10, from_base); i++) {
        char ch = i + '0';
        mp_from[ch] = i;
    }

    if(from_base > 10) {
        cout<<"Enter char and their value: \n";
        for(int i=10; i<from_base; i++) {
            char character; cin>>character;
            int value; cin>>value;

            if(value >= from_base) {
                cout<<"Invalid Value\n Enter a valid value: ";
                cin>>value;
            }

            mp_from[character] = value;
        }
    }

    cout<<"Enter number: \n";
    string from_num; cin>>from_num;

    // just to pass the validation of number
    mp_from['.'] = -100;
    // validate entered number
    for(auto i:from_num) {
        
        if(mp_from.find(i) == mp_from.end()) {
            cout<<"Invalid Number, Try with some other number\n";
            return 0;
        }
    }

    cout<<"Enter base in which we have to convert: \n";
    int to_base; cin>>to_base;

    // store the characters and their values in separate maps
    // using maps, it'll very easy to get corresponding value
    for(int i=0; i<min(to_base, 10); i++) {
        char ch = i + '0';
        mp_to[i] = ch;
    }

    if(to_base > 10) {
        cout<<"Enter char and their value: \n";
        for(int i=10; i<to_base; i++) {
            char character; cin>>character;
            int value; cin>>value;

            if(value >= to_base) {
                cout<<"\n Invalid Value \n Enter a valid value";
                cin>>value;
            }

            mp_to[value] = character;
        }
    }

    if(from_base == to_base) {
        cout<<"Converting to same base\n";
        cout<<from_num<<endl;
    } else {

        string decimalNumber = "", to_num="";

        if(from_base != 10) {
            decimalNumber = numToDecimal(from_num, from_base);
            cout<<"\nNumber in base 10: "<<decimalNumber;
        }

        if(to_base != 10) {
            to_num = numToBase(decimalNumber, to_base);
            cout<<"\nNumber in base "<<to_base<<": "<<to_num;
        }
    }

    return 0;
}

string numToDecimal(string num, int base) {
    string decimalNumber = "";

    vector<int> fractoinalPart, integerPart;

    // storing integer part and fractional part separately
    int i=0;
    while(num[i]!='.' && i<num.length()) {
        integerPart.push_back(mp_from[num[i]]);
        i++;
    }
    i++;

    while(i<num.length()) {
        fractoinalPart.push_back(mp_from[num[i]]);
        i++;
    }

    reverse(integerPart.begin(), integerPart.end());

    cout<<"\n\nConverting number in base 10:\n";

    if(fractoinalPart.size()>0) {
        double decNum=0;
        int power = 1;
        int cnt=0;
        for(auto j:integerPart) {
            // printing steps
            cout<<"("<<j<<"*"<<base<<"^"<<cnt<<") + ";
            cnt++;

            // actual calculation
            decNum += j*power;
            power *= base;
        }

        power = base;
        cnt = 1;
        for(auto j:fractoinalPart) {
            // printing steps
            cout<<"("<<j<<"*"<<base<<"^-"<<cnt<<")";
            if(cnt<fractoinalPart.size()) {
                // print +
                cout<<" + ";
            }
            cnt++;

            // actual calculation
            decNum += (float)j/(float)power;
            power *= base;
        }

        decimalNumber = to_string(decNum);

    } else {
        long long int decNum=0;
        int power = 1;
        int cnt=1;
        for(auto j:integerPart) {
            // printing calculation
            cout<<"("<<j<<"*"<<base<<"^"<<cnt<<")";
            if(cnt<integerPart.size()) {
                // print "+"
                cout<<" + ";
            } else {
                // dont't print +
            }
            cnt++;

            // actual calculation
            decNum += j*power;
            power *= base;
        }
        decimalNumber = to_string(decNum);
    }

    return decimalNumber;
}

string numToBase(string num, int to_base) {
    
    int i=0;
    string fractionalPart="", integerPart="";
    
    while(num[i]!='.' && i<num.length()) {
        integerPart+=num[i++];
    }
    i++;

    while(i<num.length()) {
        fractionalPart+=num[i++];
    }

    // converting string to long
    long long int intPart = stol(integerPart, nullptr, 10);
    double fracPart;
    
    // if there is some fractional part, then convert the string to double
    if(fractionalPart.length()>0)
        fracPart = stol(fractionalPart, nullptr, 10);

    // now, the double will look like, '3298219' but we want '.3298219', so divide it by power of 10
    fracPart/=pow(10,fractionalPart.length());

    // string to store answer
    string finalNum="";

    cout<<"\n\nConverting from base 10 to base "<<to_base<<": \n";
    cout<<"\nInteger part of base 10 Number: \n";

    while(intPart > 0) {        
        int temp = intPart % to_base;
        
        // printing steps
        cout<<intPart<<"/"<<to_base<<",  ";
        cout<<"Remainder: "<<temp<<endl;

        finalNum+= mp_to[temp];
        intPart/=to_base;
    }

    // reversing the order of remainders obtained
    reverse(finalNum.begin(), finalNum.end());

    // for fractional part
    if(fractionalPart.length()>0) {
        // adding '.' in final string
        finalNum+= ".";

        cout<<"\nFractional Part of base 10 number: \n";

        int cnt = 0;
        while(cnt++<=fractionalPart.length() && fracPart>0.00) {

            fracPart*=to_base;
            int temp = (int)fracPart;
            
            cout<<fracPart<<" * "<<to_base<<" ==> ";
            cout<<temp<<endl;

            finalNum += mp_to[temp];
            if(temp>0) {
                fracPart = abs(temp-fracPart);
            }
        }
    }

    return finalNum;
}

/*

SAMPLE-INPUT
---------------
6
345.34
16
A 10
B 11
C 12
D 13
E 14
F 15


SAMPLE-OUTPUT
----------------
Converting number in base 10:
(5*6^0) + (4*6^1) + (3*6^2) + (3*6^-1) + (4*6^-2)
Number in base 10: 137.611111

Converting from base 10 to base 16: 

Integer part of base 10 Number: 
137/16,  Remainder: 9
8/16,  Remainder: 8

Fractional Part of base 10 number: 
9.77778 * 16 ==> 9
12.4444 * 16 ==> 12
7.11066 * 16 ==> 7
1.7705 * 16 ==> 1
12.3279 * 16 ==> 12
5.24698 * 16 ==> 5
3.95162 * 16 ==> 3

Number in base 16: 89.9C71C53

*/ 