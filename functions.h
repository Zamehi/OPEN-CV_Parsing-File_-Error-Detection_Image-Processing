#pragma warning(disable:4996)
#include <iostream>
#include "Stack.h"
#include <fstream>
//#include <string>
#include <cstring>
//#include <xstring>

using namespace std;

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
        m = m/10;
    }

    // Declare string for result
    string arr;

    // Declare duplicate string
    string arr1;

    // accommodate it to character array
    int index = 0;
    while (N) 
    {
        arr1.push_back((N % 10) + 48);
        arr1[index++] = (N % 10) + 48;

        N = N/10;
    }
    // Reverse the array for result
    int i;
    for (i = 0; i < index; i++) 
    {
        arr1[i] = arr1[index - i];
    }
    // Return char array
    return arr1;
}



// ***********************************************************************************************
// Operation Performer 
string solve(char exp, Stack <string>& st)
{
    int x = stoi(st.get_data());// -48;
    cout << "The value of x is " << x << endl;
    st.pop();
    int y = stoi(st.get_data());// -48;
    cout << "The value of y is " << y << endl;
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
        x = pow(y, x);
    }

    // Check if answer is more than one digit
    return to_string(x );
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
        //file >> ret;
        //cout << ret;
        while (file.eof()==0) 
        {
            getline(file, ret);
            final.append(ret);
            final.push_back('@');
        }
    }
    //cout << final;
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
    len = str.length();
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
// presedence checker
int presedence(char exp, char data)
{
    //int pres = 0;
    if ((exp == 42 || exp == 47) && (data == 43 || data == 45))
    {//         *             /              +              -

        return 1;  // to push 
    }
    else if ((data == 42 || data == 47) && (exp == 43 || exp == 45))
    {//         *             /              +              -

        return 0;  // to pop everything then push 
    }
    // power ^
    else if (exp == 94 && (data == 42 || data == 47 || data == 43 || data == 45))
    {//             ^               *             /             +             -
        return 1;
    }
    else if (data == 94 && (exp == 42 || exp == 47 || exp == 43 || exp == 45))
    {
        return 0;
    }
    else
    {
        // if + & - || / & * with same presedence
        return 1;
    }
}



// ***********************************************************************************************
// POST FIX
string post_fix(string exp) 
{
   
    int op = 0;
    string final=""; int i = 0;
    Stack <char>st;
    int bracket = 0; // checks presence of brackets
    for (i = 0; exp[i] != '\0'; i++) 
    {
        int size = st.get_size();
        // for opening brackets
        if (exp[i] == 40) 
        {//           (
            st.push(exp[i]);
            bracket ++;
        }


        // for operands
        else if ((exp[i] > 64 && exp[i] < 91) || (exp[i] > 96 && exp[i] < 123)) 
        {
            final.push_back(exp[i]);
        }


        // for closing brackets
        else if (exp[i] == 41) 
        {
             // if there are no opening brackets
            if (bracket == 0) 
            {
                string str = "Invalid Expression";
                return str;
            }
            // for closing brackets
            while (st.get_data() != 40) 
            {
                final.push_back(st.get_data());
                st.pop();
            }
            // not storing '('
            st.pop();
            bracket --;
        }


        // for operators
        else if (exp[i] == 42 || exp[i] == 43 || exp[i] == 45 || exp[i] == 47|| exp [i]== 94)
        {//                *               +               -                /              ^
            
            // check for prescedence of operators
            if (st.get_head()== NULL) 
            {
                st.push(exp[i]);
            }
            else
            {
                int x ;
                x = presedence(exp[i], st.get_data());
                // if presedence is higher
                if (x == 1)
                {
                    st.push(exp[i]);
 
                }
                // If presedence is lower of insertion data 
                else if (x == 0)
                {
                    // if brackets are present
                    if (bracket != 0)
                    {
                        // pop till the presence of the opening bracket ascii 40
                        while (st.get_data() != '(')
                        {
                            final.push_back(st.get_data());
                            st.pop();
                        }
                        st.push(exp[i]);
                    }
                    else if (bracket == 0)
                    {
                        // pop till the stack is empty 
                        while ( st.get_head() != NULL)//st.get_head()->next_add
                        {
                            final.push_back(st.get_data());
                            st.pop();
                        }
                        st.push(exp[i]);
                    }
                }
                op++;
            }
        }
    }
  
    // Checking validity of expression 
    if (bracket !=0) 
    {
        string str = "Invalid Expression";
        return str;
    }
    else 
    {
        while (st.get_head() != NULL) 
        {
            final.push_back(st.get_data());
            st.pop();
        }
    }
    
    return final;

}




// ***********************************************************************************************
// PRE FIX
string pre_fix(string exp)
{
    // 1- Reversing string
    int j = exp.length() - 1;
    exp = reverse(exp);

    // 2- Reversing brackets
    for (int i = 0; i < exp.length() - 1; i++)
    {
        if (exp[i] == '(')
        {
            exp[i] = ')';
        }
        else if (exp[i] == ')')
        {
            exp[i] = '(';
        }
    }

    // 3- Convert to postfix
    exp = post_fix(exp);

    // 4- Again reverse array


    // If invalid expression then do not reverse array
    string invalid = "Invalid Expression"; int check = 0;
    for (int i = 0; i < j; i++) 
    {
        if (exp[i] == invalid[i]) 
        {
            check = 1;
        }
        else
        {
            check = 0;
            break;
        }
    }
    if (check == 0) 
    {
        exp = reverse(exp);
    }


    return exp;

}



// ***********************************************************************************************
// INFIX 
string in_fix(string exp) 
{
    string op;
    // Making string kind of stack
    Stack <string>st; 
    int size = exp.length(); int check = 0;
    for (int i = 0; i < size; i++) 
    {
        if ((exp[i] >= 48 && exp[i] <= 57)|| exp[i]== 32|| exp[i] == 42 || exp[i] == 43 || exp[i] == 45 || exp[i] == 47 || exp[i] == 94)
        {//            0                9            space
            check = 1;
        }
        else 
        {
            check == 0;
            break;
        }
    }
    // If numbers 
    if (check == 1) 
    {
        for (int i = 0; exp[i] != '\0'; i++)
        {
            if (exp[i] >= 48 && exp[i] <= 57)
            {
                string str;
                str = exp[i];
                st.push(str);
            }
            // If operator found , solve 
            else if (exp[i] == 42 || exp[i] == 43 || exp[i] == 45 || exp[i] == 47 )
            {
                if (st.get_head() == NULL || st.get_head()->next_add == NULL)
                {
                    string str = "Invalid Expression";
                    return str;
                }
                op = solve(exp[i], st);
                st.push(op);
                //op.push_back(exp[i]); 
            }
            op = "";
        }
    }
    // If character string
    else 
    {
        for (int i = 0; exp[i] != '\0'; i++)
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
                if (st.get_head()== NULL || st.get_head()->next_add == NULL)
                {
                    string str = "Invalid Expression";
                    return str;
                }
                else 
                {
                    string second;
                    second = st.get_data();
                    st.pop();
                    // store operator
                    // store next operand
                    op.append(st.get_data());
                    st.pop();
                    op.push_back(exp[i]);
                    op.append(second);
                    // Pushing the whole statement back to stack
                    st.push(op);
                }
              
            }
            op = "";
        }
    }
    op.append(st.get_data());
    st.pop();
    return op;
    
}




// ********************************************************************************************
//                                   TASK 1 + 2
// ********************************************************************************************
string tag_check(string exp) 
{
    string copy;
    int size = exp.length() - 1; int check = 1;
    Stack <string> st;
    int start = 0, end = 0;
    for (int i = 0; i < size; i++) 
    {
        if (exp[i] == '|') 
        {
            if (exp[i+1]== '\\')
            {
                // Search for previous starting tag
                string spr;
                spr = st.get_data();
                st.pop(); i++;
                while (exp[i] != '|') 
                {
                    i++;
                }
                i++;
              
            }
            else 
            {
                string tag;
                check == i; i++;
                for ( i; exp[i] != '|'; i++)
                {
                    tag.push_back(exp[i]);
                }
                st.push(tag);// check for pre and post fix
                start = i ;

                // Checking for mathematical expression
                string post, pre, sol, str;
                string spr;
                spr = st.get_data();
                post = "post_exp", pre = "pre_exp", sol = "sol_exp";

                // Saving mathematical expressions in a string 
                for (i= i+1; exp[i]!='|'; i++)
                {
                    str.push_back(exp[i]);
                }
                // Matching which operation to perform
                if (spr == post)
                {
                    str = post_fix(str);
                }
                else if (spr == pre)
                {
                    str = pre_fix(str);
                }
                else if (spr == sol)
                {
                    str = in_fix(str);
                }
                // Now save the expression in the string in the text file
                // Make a new copy string to copy new elements in the string
                copy.append(str);
                copy.push_back(' ');
                i--;
                // Skip the tags 
                /*while (exp[i] != '|')
                {
                    i++;
                }
                i++;*/
            }
           
        }
        else 
        {
            copy.push_back(exp[i]);
        }
    }
    // Checking for presence of any remaining tags
    if (st.get_head() != NULL) 
    {
        string str = "Syntax Error";
        return str;
    }
    return copy;
}



// ********************************************************************************************
//                                     TASK 4
// ********************************************************************************************

// METHOD 1

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




// ********************************************************************************************
//                                     TASK 3
// ********************************************************************************************

int* priority_arr(string file_name[])
{
    ifstream file;
    string ret = "", final = "";
    int* pr_arr = new int[7];
    cout << "String name is " << file_name[0] << endl;
    for (int i = 0; i < 7; i++)
    {
        string number;

        file.open(file_name[i]);
        if (file.fail())
        {
            cout << "File failed to open, enter valid string." << endl;

        }
        else
        {
            //file >> ret;
            //cout << ret;
            while (file.eof() == 0)
            {
                //size_t found = -1;
                getline(file, ret);
                cout << "FILE line is " << ret << endl;
                //size_t found = ret.find("|priority|");
                if (find_substring(ret, "priorty") == 1)//ret.find("priorty") != std::string::npos
                {
                    getline(file, final);
                    file.close();
                    for (int j = 0; final[j] != '\0'; j++)
                    {
                        if (final[j] >= 48 && final[j] <= 57)
                        {
                            number.push_back(final[j]);
                        }

                    }
                    pr_arr[i] = stoi(final);
                    break;
                }
            }
        }
        cout << final;
    }

    return pr_arr;

}

int* priority_queue(string file_name[])
{
    Stack <int> q;
    int hits = 0, fault = 0;
    int queue_size = 0;
    int* arr = new int[7];
    arr = priority_arr(file_name);


    int* check_double = new int[7];
    for (int i = 0; i < 7; i++)
    {
        check_double[i] = arr[i];
    }


    int index = 0;
    q.enque(arr[0]); fault++; check_double[0] = 1;
    queue_size++;
    for (int i = 1; i < 7; i++)
    {
        if (queue_size >= 4 && check_double[i] != -1)
        {
            // delete from start of the queue 
            // one with least priority
            q.deque();
        }
        if (check_double[i] != -1)
        {
            if (arr[i - 1] > arr[i])
            {
                for (int j = 0; j < 7; j++)
                {
                    if (arr[i] == check_double[j])
                    {
                        check_double[j] = -1;
                    }
                }
                q.enque(arr[i]);
                queue_size++;
                fault++;
            }
            else
            {
                for (int j = 0; j < 7; j++)
                {
                    if (arr[i] == check_double[j])
                    {

                        check_double[j] = -1;
                    }
                }
                int index = q.insert_at(arr[i]);
                q.insert(index, arr[i]);
                queue_size++;
                fault++;
            }
        }
        else
        {
            hits++;
        }

    }
    int* LRU = new int[2];
    LRU[0] = hits; LRU[1] = fault;

    return LRU;
}


// ***********************************************************************************************
// Prefix to POST fix
string pretopost(string exp)
{
    string op;
    // Making string kind of stack
    Stack <string>st;
    int size = int(exp.length() - 1); int check = 0;

    // If character string
    for (int i = size - 1; i >= 0; i--)
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
    
    //cout << op;
    return op;
}


