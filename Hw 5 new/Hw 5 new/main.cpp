//
//  main.cpp
//  Hw 5 new
//
//  Created by Eric Klicker on 11/1/16.
//  Copyright © 2016 Eric Klicker. All rights reserved.
//

#include <iostream>
#include <string>
#include <vector>

using namespace std;

template <typename T>
int linearSearch(const T list[], T key, int arraysize)
{
    for(int i=0; i < arraysize; i++)
        if(key == list[i])
            return i;
    return -1;
}




int main()
{
 //12.2
    int intList[] = { 1, 2, 4, 5, 6, 9};
    double doubleList[] = {1.1, 5.4, 6.0, 7.8, 9.0, 3.3};
    string stringList[] = {"Hi", "Hello", "Hey", "Greetings", "Bonjour", "Hola"};
    
    cout << "The index of the element is " << linearSearch(intList, 5, 6) << endl;
    cout << "The index of the element is " << linearSearch(doubleList, 1.1, 6) << endl;
    cout << "The index of the element is " << linearSearch(stringList, string("Hello"), 6) << endl;
    cout << endl;
    
    
    return 0;
}