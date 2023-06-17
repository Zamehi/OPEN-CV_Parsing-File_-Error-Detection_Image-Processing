#pragma once
/*Name : Zunaira Amir   ,    email:  i210780@nu.edu.pk*/
#pragma warning(disable:4996)

#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc.hpp>

#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
#include "Stack.h"
#include "Queue.h"



using namespace std;
using namespace cv;

// ***********************************************************************************************
// Find substring in a string
int find_substring(string str1, string str2)
{

    int check = 0, s2 = size(str2), s1 = size(str1), index = 0;
    int p = 0;
    char* st1 = new char[s1 + 1];
    char* st2 = new char[s2 + 1];
    char c = str2[0];
    strcpy(st1, str1.c_str());
    strcpy(st2, str2.c_str());
    for (int i = 0; i < s1 + 1; i++)
    {
        if (c == st1[i])
        {
            index = i;
            for (int v = index; v < (s2 + index); v++)
            {
                c = st2[p];
                if (c == st1[v])
                {
                    check = 1;
                    p++;
                }
                else
                {
                    check = 0;
                    p = 0;
                    break;
                }
            }
            if (check == 1)
            {
                return 1;
            }
        }

    }

    if (check == 0)
    {
        return 0;
    }
}



// ***********************************************************************************************
// convert number to string
string convertIntegerToStr(int N)
{


    int m = N;
    int digit = 0;

    // Count digits in number N
    while (m)
    {
        // Increment number of digits
        digit++;
        m = m / 10;
    }

    // Declare string for result
    string arr;

    // Declare duplicate string
    string arr1;

    // accommodate it to character array
    int index = 0;
    while (N)
    {
        arr1.push_back((N % 10) + 48);// [++index] = (N % 10) + 48;

        N = N / 10;
    }
    // Reverse the array for result
    int i;
    for (i = 0; i < index; i++)
    {
        arr[i] = arr1[index - i];
    }
    // Return char array
    return arr1;
}



// ***********************************************************************************************
// Operation Performer 
string solve(char exp, Stack <string>& st)
{
    int x = stoi(st.get_data());// -48;
    st.pop();
    int y = stoi(st.get_data());// -48;
    st.pop();
    if (exp == '*')
    {
        x = y * x;
    }
    else if (exp == '/')
    {
        x = y / x;
    }
    else if (exp == '+')
    {
        x = y + x;
    }
    else if (exp == '-')
    {
        x = y - x;
    }
    else if (exp == '^')
    {
        x = int(pow(y, x));
    }

    // Check if answer is more than one digit
    return to_string(x);
}



// ***********************************************************************************************
// Read from a txt file 
string read(string name)
{
    string ret, final;
    ifstream file;
    file.open(name);
    if (file.fail())
    {
        cout << "File failed to open, enter valid string." << endl;

    }
    else
    {
        while (file.eof() == 0)
        {
            getline(file, ret);
            final.append(ret);
            final.push_back('\n');
        }
    }
    file.close();
    return final;
}


// ***********************************************************************************************
// Write in the file 


// ***********************************************************************************************
// Reversing a string
string reverse(string str)
{
    int i, len = 0, n;
    char temp;
    len = int(str.length());
    n = len - 1;
    for (i = 0; i <= (len / 2); i++)
    {
        temp = str[i];
        str[i] = str[n];
        str[n] = temp;
        n--;
    }
    return str;
}



// ***********************************************************************************************
// OUTPUT STRING overloading
ostream& operator<<(ostream& os, string& msg)
{
    os << msg.c_str();

    return os;
}


// ***********************************************************************************************
// Prefix to POST fix
string pretopost(string exp) 
{
    string op;
    // Making string kind of stack
    Stack <string>st;
    int s = int(exp.length() - 1); int check = 0;
   
    // If character string
        for (int i = s-1; i>=0; i--)
        {

            if ((exp[i] > 64 && exp[i] < 91) || (exp[i] > 96 && exp[i] < 123))
            {
                string str;
                str = exp[i];
                st.push(str);
            }
            // If operator found , solve 
            else if (exp[i] == 42 || exp[i] == 43 || exp[i] == 45 || exp[i] == 47 || exp[i] == 94)
            {
                // Appending the string into another through .append 
                // store operand
                if (st.get_head() == NULL)
                {
                    string str = "Invalid Expression";
                    return str;
                }
                else if (st.get_head()->next_add == NULL) 
                {
                    op.append(st.get_data());
                    st.pop();
                    op.push_back(exp[i]);
                    // Pushing the whole statement back to stack
                    st.push(op);
                }
                else
                {
                    
                    op.append(st.get_data());
                    st.pop();
                    op.append(st.get_data());
                    st.pop();
                    op.push_back(exp[i]);
                    
                    // Pushing the whole statement back to stack
                    st.push(op);
                }

            }
            op = "";
        }
    
        while (st.get_head() != NULL)
        {
            op.append(st.get_data());
            st.pop();
        }
    return op;
}


