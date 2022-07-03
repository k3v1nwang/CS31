#include <iostream>
#include <string>
#include <cassert>
using namespace std;

int locateMaximum(const string array[], int n);
bool hasDuplicates(const string array[], int n);
bool matchingValuesTogether(const string array[], int n);
int countSs(const string array[], int n);
bool isInDecreasingOrder(const string array[], int n);
int divide(string array[], int n, string divider);
int shiftLeft(string array[], int n, int amount, string placeholderToFillEmpties);

int main()
{
    string people[5] = { "a", "a", "b", "c", "c" };
    assert(locateMaximum(people, 5) == 3);
    string shift[10] = { "samwell", "jon", "margaery", "daenerys", "tyrion", "a", "b", "c", "d", "e" };
    string shift2[]5] = { "c", "b", "b", "a", "a" };
    assert(shiftLeft(shift2, 3, 3, "foo") == 3 == shift2[2] == "foo" && shift2[4] == "a");
    assert(shiftLeft(shift, 8, 5, "lol") == 5 && shift[5] == "lol" && shift[0] == "a" && shift[8] == "d");
    string dup[10] = { "samwell", "jon", "margaery", "daenerys", "a", "a", "c", "a", "e", "e" };
    string match[6] = { "a", "b", "b", "d", "c", "c" };
    assert(matchingValuesTogether(dup, 10) == false);
    assert(matchingValuesTogether(match, 6) == true);
    assert(hasDuplicates(dup, 10) == true);
    string sS[5] = { "ssss", "g", "s", "sss", "SSS" };
    assert(countSs(sS, 5) == 11);
    string dec[5] = { "c", "b", "b", "a", "a" };
    assert(isInDecreasingOrder(dec, 1) == false);
    string div[5] = { "b", "c", "b", "e", "h" };
    assert(divide(div,5, "a") == 0 );

}

int locateMaximum(const string array[], int n)
{
    //Return the index of the largest item found in the array or -1 if n <= 0.
    if (n <= 0)
        return (-1);
    int max = 0;
    for (int k = 0; k < n; k++)
    {
        if (array[k] > array[max])
            max = k;    //set values to max if new max is found
    }
    return(max);
}

bool hasDuplicates(const string array[], int n)
{
    //If there is a value that is repeatedly found in the array, return true otherwise false or if n <= 0 return false
    if (n <= 0)
        return false;
    for (int k = 0; k < n; k++)
    {
        for (int i = k + 1; i < n; i++)
        {
            if (array[k] == array[i])
                return true;
        }
    }
    return(false);
}

bool matchingValuesTogether(const string array[], int n)
{
    if (n <= 0)
        return false;

    if (hasDuplicates(array, n)) //duplicate detected somewhere within array
    {
        for (int k = 0; k < n; k++)
        {
            for (int i = k + 1; i < n; i++)
            {
                if (array[k] == array[i])   //when the duplicate is found
                {
                    if (i - k != 1) //return false if next element is not the same 
                        return false;
                    else
                        break; //break out of loop if it is 
                }
            }
        }
        return true;
    }
    else
        return true; //return true if no duplicates were detected
}

int countSs(const string array[], int n)
{
    //Return the number of  's' or 'S' characters found inside each of the elements of the passed array or if n <= 0 return -1
    if (n <= 0)
        return -1;
    int counter = 0;
    for (int k = 0; k < n; k++)
    {
        string check = array[k];
        for (int i = 0; i < check.size(); i++)  //loop within size of each string to check for 's' or 'S'
        {
            if (check[i] == 's' || check[i] == 'S')
                counter++;
        }
    }
    return(counter);
}

bool isInDecreasingOrder(const string array[], int n)
{
    if (n <= 0)
        return false;
    //check to see that the value in front if less than the value before it
    for (int k = 0; k < n; k++)
    {
        int j = k + 1;
        if (j < n && array[j] > array[k])   //j must be within the bounds of n
            return false;
    }
    //return true if successfullly looped through
    return(true);
}

int divide(string array[], int n, string divider)
{
    if (n <= 0)
        return 0;
    int start = 0;
    int end = n - 1;
    string temp;
    //while loop continues until start and end values meet 
    while (start < end)
    {
        if (array[start] <= divider)    //if less than divider, move to next element in array
            start++;
        if (array[start] > divider)     //if grater than divider, swap element with the one at the end 
        {
            temp = array[start];
            array[start] = array[end];
            array[end] = temp;
            end--;      //swapped values are guranteed to be greater so check the value before it
        }
    }
    
    // return the pos of the first element larger than divider
    int pos = 0;
    for (int k = 0; k < n; k++)
    {
        if (array[k] <= divider)
            pos++;
        else
            break;
    }
    return pos;
}

int shiftLeft(string array[], int n, int amount, string placeholderToFillEmpties)
{
    if (n <= 0)
        return 0;
    if (amount >= n)
        return n;
    //starting from position 0 of array, replace string with string from amount positions away
    int replace;
    for (int k = amount; k < n; k++)
    {
        replace = k - amount;
        array[replace] = array[k];
        array[k] = placeholderToFillEmpties;
    }
    //if there are gaps in the array that did not get replaced with the placeholder, replace it
    for (int j = n - amount; j < n; j++)
    {
        if (array[j] != placeholderToFillEmpties)
            array[j] = placeholderToFillEmpties;
    }
    //count number of times placeholder shows up
    int counter = 0;
    for (int i = 0; i < n; i++)
    {
        if (array[i] == placeholderToFillEmpties)
            counter++;
    }

    return(counter);
}