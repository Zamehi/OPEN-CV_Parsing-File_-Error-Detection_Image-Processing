//#pragma warning(disable:4996)
/*Name : Zunaira Amir   ,    email:  i210780@nu.edu.pk*/

#include <iostream>
#include <fstream>
#include <string>
//#include <cstring>
#include "Stack.h"
#include "functions2.h"

using namespace std;


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
    string final = ""; int i = 0;
    Stack <char>st;
    int bracket = 0; // checks presence of brackets
    for (i = 0; exp[i] != '\0'; i++)
    {
        int size = st.get_size();
        // for opening brackets
        if (exp[i] == 40)
        {//           (
            st.push(exp[i]);
            bracket++;
        }


        // for operands
        else if ((exp[i] > 64 && exp[i] < 91) || (exp[i] > 96 && exp[i] < 123)|| (exp[i]>= 48 && exp[i]<= 57))
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
            bracket--;
        }


        // for operators
        else if (exp[i] == 42 || exp[i] == 43 || exp[i] == 45 || exp[i] == 47 || exp[i] == 94)
        {//                *               +               -                /              ^

            // check for prescedence of operators
            if (st.get_head() == NULL)
            {
                st.push(exp[i]);
            }
            else
            {
                int x;
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
                        while (st.get_head() != NULL)//st.get_head()->next_add
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
    if (bracket != 0)
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
    int j = int (exp.length() - 1);
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
    int size = int (exp.length() - 1); int check = 0;
    for (int i = 0; i < size; i++)
    {
        if ((exp[i] >= 48 && exp[i] <= 57) || exp[i] == 32 || exp[i] == 42 || exp[i] == 43 || exp[i] == 45 || exp[i] == 47 || exp[i] == 94)
        {//            0                9            space
            check = 1;
        }
        else
        {
            check = 0;
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
            else if (exp[i] == 42 || exp[i] == 43 || exp[i] == 45 || exp[i] == 47)
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

            if ((exp[i] > 64 && exp[i] < 91) || (exp[i] > 96 && exp[i] < 123)|| (exp[i] >= 48 && exp[i] <=57))
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
                if (st.get_head() == NULL || st.get_head()->next_add == NULL)
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
    while (st.get_head() != NULL)
    {
        op.append(st.get_data());
        st.pop();
    }
    return op;

}



// ********************************************************************************************
//                                     TASK 4
// ********************************************************************************************

// METHOD 1
int row_wise_object_BFT(int row, int col, int** arr1)
{


    // Declaring a check array
    int** check_arr = new int* [row];
    for (int i = 0; i < row; i++)
    {
        check_arr[i] = new int[col];
    }
    // int check_arr[7][7];


     // ************************** COPYING ORIGINAL ARRAY **********************
     // CHECK =  original array   --   copying original array

    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            check_arr[i][j] = arr1[i][j];
        }
    }

    // ******************************** NEW ARRAY *********************************
    int** arr2 = new int* [row];
    for (int i = 0; i < row; i++)
    {
        arr2[i] = new int[col];
    }

    bool obj = true;
    int gal = 0;
    Queue my_q;
    while (obj > 0)
    {
        for (int i = 0; i < row; i++)
        {
            for (int j = 0; j < col; j++)
            {
                arr2[i][j] = 0;
            }
        }
        int k, l;
        for (k = 0; k < row; k++)
        {
            for (l = 0; l < col; l++)
            {
                if (check_arr[k][l] != 0)
                {
                    my_q.enque(k, l);
                    obj = true; gal++;

                    goto finish;
                }
                else
                {
                    obj = false;
                }
            }
        }
    finish:
        if (obj == false)
        {
            break;
        }


        int r, c;
        while (my_q.get_head() != NULL)
        {
            r = my_q.get_data();
            c = my_q.get_data2();
            my_q.deque();
            if (r == 0 || c == 0 || r == row - 1 || c == col - 1)
            {
                // checking index in corners
                // First corner  5 7 8 
                if (r == 0 && c == 0)
                {
                    if (arr1[r][c + 1] != 0)// ---------------------------- 5
                    {
                        if (arr2[r][c + 1] == 0)
                        {
                            my_q.enque(r, c + 1);
                        }
                        arr2[r][c + 1] = 255;
                        check_arr[r][c + 1] = 0;
                    }
                    if (arr1[r + 1][c] != 0) // ----------------------- 7
                    {
                        if (arr2[r + 1][c] == 0)
                        {
                            my_q.enque(r + 1, c);
                        }
                        arr2[r + 1][c] = 255;
                        check_arr[r + 1][c] = 255;
                    }
                    if (arr1[r + 1][c + 1] != 0) // ---------------- 8
                    {
                        if (arr2[r + 1][c + 1] == 0)
                        {
                            my_q.enque(r + 1, c + 1);
                        }
                        arr2[r + 1][c + 1] = 255;
                        check_arr[r + 1][c + 1] = 255;
                    }
                }

                // 2nd corner      4 6 7 
                else if (r == 0 && c == col - 1)
                {
                    if (arr1[r + 1][c] != 0) // ----------------------- 7
                    {
                        if (arr2[r + 1][c] == 0)
                        {
                            my_q.enque(r + 1, c);
                        }
                        arr2[r + 1][c] = 255;
                        check_arr[r + 1][c] = 0;
                    }
                    if (arr1[r + 1][c - 1] != 0)// ------------------- 6
                    {
                        if (arr2[r + 1][c - 1] == 0)
                        {
                            my_q.enque(r + 1, c - 1);
                        }
                        arr2[r + 1][c - 1] = 255;
                        check_arr[r + 1][c - 1] = 0;
                    }
                    if (arr1[r][c - 1] != 0) // ---------------------- 4
                    {

                        if (arr2[r][c - 1] == 0)
                        {
                            my_q.enque(r, c - 1);
                        }
                        arr2[r][c - 1] = 255;
                        check_arr[r][c - 1] = 0;
                    }
                }

                //  3rd Corner     2 3 5 
                else if (r == row - 1 && c == 0)
                {
                    if (arr1[r][c + 1] != 0)// ---------------------------- 5
                    {
                        if (arr2[r][c + 1] == 0)
                        {
                            my_q.enque(r, c + 1);
                        }
                        arr2[r][c + 1] = 255;
                        check_arr[r][c + 1] = 0;
                    }
                    if (arr1[r - 1][c] != 0)   //--- ---------------------- 2
                    {
                        if (arr2[r - 1][c] == 0)
                        {
                            my_q.enque(r - 1, c);
                        }
                        arr2[r - 1][c] = 255;
                        check_arr[r - 1][c] = 0;
                    }
                    if (arr1[r - 1][c + 1] != 0)  // ---------------------- 3
                    {
                        if (arr2[r - 1][c + 1] == 0)
                        {
                            my_q.enque(r - 1, c + 1);
                        }
                        arr2[r - 1][c + 1] = 255;
                        check_arr[r - 1][c + 1] = 0;
                    }

                }

                // 4th corner      1 2 4
                else if (r == row - 1 && c == col - 1)
                {
                    if (arr1[r - 1][c - 1] != 0) // ----------------------- 1
                    {
                        if (arr2[r - 1][c - 1] == 0)
                        {
                            my_q.enque(r - 1, c - 1);
                        }
                        arr2[r - 1][c - 1] = 255;
                        check_arr[r - 1][c - 1] = 0;
                    }
                    if (arr1[r - 1][c] != 0)   //--- ---------------------- 2
                    {
                        if (arr2[r - 1][c] == 0)
                        {
                            my_q.enque(r - 1, c);
                        }
                        arr2[r - 1][c] = 255;
                        check_arr[r - 1][c] = 0;
                    }
                    if (arr1[r][c - 1] != 0) // --------------------------- 4
                    {
                        if (arr2[r][c - 1] == 0)
                        {
                            my_q.enque(r, c - 1);
                        }
                        arr2[r][c - 1] = 255;
                        check_arr[r][c - 1] = 0;
                    }
                }

                // Upper row       4 5 6 7 8
                else if (((r == 0) && (c > 0 && c < col - 1)))
                {
                    if (arr1[r][c - 1] != 0) // --------------------------- 4
                    {
                        if (arr2[r][c - 1] == 0)
                        {
                            my_q.enque(r, c - 1);
                        }
                        arr2[r][c - 1] = 255;
                        check_arr[r][c - 1] = 0;
                    }

                    if (arr1[r][c + 1] != 0)// ---------------------------- 5
                    {
                        if (arr2[r][c + 1] == 0)
                        {
                            my_q.enque(r, c + 1);
                        }
                        arr2[r][c + 1] = 255;
                        check_arr[r][c + 1] = 0;
                    }
                    if (arr1[r + 1][c - 1] != 0)// ------------------------ 6
                    {
                        if (arr2[r + 1][c - 1] == 0)
                        {
                            my_q.enque(r + 1, c - 1);
                        }
                        arr2[r + 1][c - 1] = 255;
                        check_arr[r + 1][c - 1] = 0;
                    }
                    if (arr1[r + 1][c] != 0) // --------------------------- 7
                    {
                        if (arr2[r + 1][c] == 0)
                        {
                            my_q.enque(r + 1, c);
                        }
                        arr2[r + 1][c] = 255;
                        check_arr[r + 1][c] = 0;
                    }
                    if (arr1[r + 1][c + 1] != 0) // ----------------------- 8
                    {
                        if (arr2[r + 1][c + 1] == 0)
                        {
                            my_q.enque(r + 1, c + 1);
                        }
                        arr2[r + 1][c + 1] = 255;
                        check_arr[r + 1][c + 1] = 0;
                    }
                }

                // Left col edge   2 3 5 7 8    
                else if (((c == 0) && (r > 0 && r < row - 1))) // row on left
                {
                    if (arr1[r - 1][c] != 0)   //--- ---------------------- 2
                    {
                        if (arr2[r - 1][c] == 0)
                        {
                            my_q.enque(r - 1, c);
                        }
                        arr2[r - 1][c] = 255;
                        check_arr[r - 1][c] = 0;
                    }
                    if (arr1[r - 1][c + 1] != 0)  // ---------------------- 3
                    {
                        if (arr2[r - 1][c + 1] == 0)
                        {
                            my_q.enque(r - 1, c + 1);
                        }
                        arr2[r - 1][c + 1] = 255;
                        check_arr[r - 1][c + 1] = 0;
                    }
                    if (arr1[r][c + 1] != 0)// ---------------------------- 5
                    {
                        if (arr2[r][c + 1] == 0)
                        {
                            my_q.enque(r, c + 1);
                        }
                        arr2[r][c + 1] = 255;
                        check_arr[r][c + 1] = 0;
                    }
                    if (arr1[r + 1][c] != 0) // --------------------------- 7
                    {
                        if (arr2[r + 1][c] == 0)
                        {
                            my_q.enque(r + 1, c);
                        }
                        arr2[r + 1][c] = 255;
                        check_arr[r + 1][c] = 0;
                    }
                    if (arr1[r + 1][c + 1] != 0) // ----------------------- 8
                    {
                        if (arr2[r + 1][c + 1] == 0)
                        {
                            my_q.enque(r + 1, c + 1);
                        }
                        arr2[r + 1][c + 1] = 255;
                        check_arr[r + 1][c + 1] = 0;
                    }


                }

                // Right col edge  1 2 4 6 7
                else if (((c == col - 1) && (r > 0 && r < row - 1)))
                {
                    if (arr1[r - 1][c - 1] != 0) // ----------------------- 1
                    {
                        if (arr2[r - 1][c - 1] == 0)
                        {
                            my_q.enque(r - 1, c - 1);
                        }
                        arr2[r - 1][c - 1] = 255;
                        check_arr[r - 1][c - 1] = 0;
                    }
                    if (arr1[r - 1][c] != 0)   //--- ---------------------- 2
                    {
                        if (arr2[r - 1][c] == 0)
                        {
                            my_q.enque(r - 1, c);
                        }
                        arr2[r - 1][c] = 255;
                        check_arr[r - 1][c] = 0;
                    }
                    if (arr1[r][c - 1] != 0) // --------------------------- 4
                    {
                        if (arr2[r][c - 1] == 0)
                        {
                            my_q.enque(r, c - 1);
                        }
                        arr2[r][c - 1] = 255;
                        check_arr[r][c - 1] = 0;
                    }
                    if (arr1[r + 1][c - 1] != 0)// ------------------------ 6
                    {
                        if (arr2[r + 1][c - 1] == 0)
                        {
                            my_q.enque(r + 1, c - 1);
                        }
                        arr2[r + 1][c - 1] = 255;
                        check_arr[r + 1][c - 1] = 0;
                    }
                    if (arr1[r + 1][c] != 0) // --------------------------- 7
                    {
                        if (arr2[r + 1][c] == 0)
                        {
                            my_q.enque(r + 1, c);
                        }
                        arr2[r + 1][c] = 255;
                        check_arr[r + 1][c] = 0;
                    }
                }

                // Last row        1 2 3 4 5 
                else if ((r == row - 1) && (c > 0 && c < col - 1))     // akhri line ka code
                {
                    if (arr1[r - 1][c - 1] != 0) // ----------------------- 1
                    {
                        if (arr2[r - 1][c - 1] == 0)
                        {
                            my_q.enque(r - 1, c - 1);
                        }
                        arr2[r - 1][c - 1] = 255;
                        check_arr[r - 1][c - 1] = 0;
                    }
                    if (arr1[r - 1][c] != 0)   //--- ---------------------- 2
                    {
                        if (arr2[r - 1][c] == 0)
                        {
                            my_q.enque(r - 1, c);
                        }
                        arr2[r - 1][c] = 255;
                        check_arr[r - 1][c] = 0;
                    }
                    if (arr1[r][c - 1] != 0) // --------------------------- 4
                    {
                        if (arr2[r][c - 1] == 0)
                        {
                            my_q.enque(r, c - 1);
                        }
                        arr2[r][c - 1] = 255;
                        check_arr[r][c - 1] = 0;
                    }
                    if (arr1[r - 1][c + 1] != 0)  // ---------------------- 3
                    {
                        if (arr2[r - 1][c + 1] == 0)
                        {
                            my_q.enque(r - 1, c + 1);
                        }
                        arr2[r - 1][c + 1] = 255;
                        check_arr[r - 1][c + 1] = 0;
                    }
                    if (arr1[r][c + 1] != 0)// ---------------------------- 5
                    {
                        if (arr2[r][c + 1] == 0)
                        {
                            my_q.enque(r, c + 1);
                        }
                        arr2[r][c + 1] = 255;
                        check_arr[r][c + 1] = 0;
                    }
                }
            }
            // Mid elements        1 2 3 4 5 6 7 8
            else // Check for mid elements of the array
            {
                if (arr1[r - 1][c - 1] != 0) // ----------------------- 1
                {
                    if (arr2[r - 1][c - 1] == 0)
                    {
                        my_q.enque(r - 1, c - 1);
                    }
                    arr2[r - 1][c - 1] = 255;
                    check_arr[r - 1][c - 1] = 0;
                }
                if (arr1[r - 1][c] != 0)   //--- ---------------------- 2
                {
                    if (arr2[r - 1][c] == 0)
                    {
                        my_q.enque(r - 1, c);
                    }
                    arr2[r - 1][c] = 255;
                    check_arr[r - 1][c] = 0;
                }
                if (arr1[r][c - 1] != 0) // --------------------------- 4
                {
                    if (arr2[r][c - 1] == 0)
                    {
                        my_q.enque(r, c - 1);
                    }
                    arr2[r][c - 1] = 255;
                    check_arr[r][c - 1] = 0;
                }
                if (arr1[r - 1][c + 1] != 0)  // ---------------------- 3
                {
                    if (arr2[r - 1][c + 1] == 0)
                    {
                        my_q.enque(r - 1, c + 1);
                    }
                    arr2[r - 1][c + 1] = 255;
                    check_arr[r - 1][c + 1] = 0;
                }
                if (arr1[r][c + 1] != 0)// ---------------------------- 5
                {
                    if (arr2[r][c + 1] == 0)
                    {
                        my_q.enque(r, c + 1);
                    }
                    arr2[r][c + 1] = 255;
                    check_arr[r][c + 1] = 0;
                }
                if (arr1[r + 1][c - 1] != 0)// ------------------------ 6
                {
                    if (arr2[r + 1][c - 1] == 0)
                    {
                        my_q.enque(r + 1, c - 1);
                    }
                    arr2[r + 1][c - 1] = 255;
                    check_arr[r + 1][c - 1] = 0;
                }
                if (arr1[r + 1][c] != 0) // --------------------------- 7
                {
                    if (arr2[r + 1][c] == 0)
                    {
                        my_q.enque(r + 1, c);
                    }
                    arr2[r + 1][c] = 255;
                    check_arr[r + 1][c] = 0;
                }
                if (arr1[r + 1][c + 1] != 0) // ----------------------- 8
                {
                    if (arr2[r + 1][c + 1] == 0)
                    {
                        my_q.enque(r + 1, c + 1);
                    }
                    arr2[r + 1][c + 1] = 255;
                    check_arr[r + 1][c + 1] = 0;
                }
            }
        }



        // CONVERTING ARRAY TO IMAGE 

        Mat img2;
        img2 = imread("C:\\Users\\Zunaira\\Documents\\Ass - 2 Consoleee\\A2\\Images\\Img1.png");// put path of the image in original images folder
        Mat copy2;
        img2.convertTo(copy2, CV_8UC1);
        for (int i = 0; i < img2.rows; i++)
        {
            for (int j = 0; j < img2.cols; j++)
            {
                img2.at<Vec3b>(i, j) = arr2[i][j];

            }
        }
        // imshow("Result Image", img2);


         // **********************************************************
         //                   FIGURING OUT STRING 
         // **********************************************************

        string path = "C:\\Users\\Zunaira\\Documents\\Ass - 2 Consoleee\\A2\\Output_files\\img_BFT";
        char p = gal + 48;
        path.push_back(p);
        path.append(".png");
        imwrite(path, img2);
        imshow("object", img2);
        waitKey();

        

        if (obj != false)
        {
            arr1 = check_arr;
        }

    }
    if (obj == 0)
    {
        cout << "Total objects have been simulated" << endl;
    }
    return gal;
}

// METHOD 2
int row_wise_object_DFT(int row, int col, int** arr1)
{

    // Declaring a check array
    int** check_arr = new int* [row];
    for (int i = 0; i < row; i++)
    {
        check_arr[i] = new int[col];
    }

    // ************************** COPYING ORIGINAL ARRAY **********************
    // CHECK =  original array   --   copying original array

    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            check_arr[i][j] = arr1[i][j];
        }
    }

    // ******************************** NEW ARRAY *********************************
    int** arr2 = new int* [row];
    for (int i = 0; i < row; i++)
    {
        arr2[i] = new int[col];
    }

    bool obj = 1;
    int gal = 0;
    Queue my_q;
    while (obj > 0)
    {
        for (int i = 0; i < row; i++)
        {
            for (int j = 0; j < col; j++)
            {
                arr2[i][j] = 0;
            }
        }
        int k, l;
        for (k = 0; k < row; k++)
        {
            for (l = 0; l < col; l++)
            {
                if (check_arr[k][l] != 0)
                {
                    my_q.push(k, l);
                    obj = 1; gal++;

                    goto finish;
                }
                else
                {
                    obj = 0;
                }
            }
        }
    finish:
        if (obj == false)
        {
            break;
        }


        int r, c;
        while (my_q.get_head() != NULL)
        {
            r = my_q.get_data();
            c = my_q.get_data2();
            my_q.pop();
            if (r == 0 || c == 0 || r == row - 1 || c == col - 1)
            {
                // checking index in corners
                // First corner  5 7 8 
                if (r == 0 && c == 0)
                {
                    if (arr1[r][c + 1] != 0)// ---------------------------- 5
                    {
                        if (arr2[r][c + 1] == 0)
                        {
                            my_q.push(r, c + 1);
                        }
                        arr2[r][c + 1] = 255;
                        check_arr[r][c + 1] = 0;
                    }
                    if (arr1[r + 1][c] != 0) // ----------------------- 7
                    {
                        if (arr2[r + 1][c] == 0)
                        {
                            my_q.push(r + 1, c);
                        }
                        arr2[r + 1][c] = 255;
                        check_arr[r + 1][c] = 255;
                    }
                    if (arr1[r + 1][c + 1] != 0) // ---------------- 8
                    {
                        if (arr2[r + 1][c + 1] == 0)
                        {
                            my_q.push(r + 1, c + 1);
                        }
                        arr2[r + 1][c + 1] = 255;
                        check_arr[r + 1][c + 1] = 255;
                    }
                }

                // 2nd corner      4 6 7 
                else if (r == 0 && c == col - 1)
                {
                    if (arr1[r + 1][c] != 0) // ----------------------- 7
                    {
                        if (arr2[r + 1][c] == 0)
                        {
                            my_q.push(r + 1, c);
                        }
                        arr2[r + 1][c] = 255;
                        check_arr[r + 1][c] = 0;
                    }
                    if (arr1[r + 1][c - 1] != 0)// ------------------- 6
                    {
                        if (arr2[r + 1][c - 1] == 0)
                        {
                            my_q.push(r + 1, c - 1);
                        }
                        arr2[r + 1][c - 1] = 255;
                        check_arr[r + 1][c - 1] = 0;
                    }
                    if (arr1[r][c - 1] != 0) // ---------------------- 4
                    {

                        if (arr2[r][c - 1] == 0)
                        {
                            my_q.push(r, c - 1);
                        }
                        arr2[r][c - 1] = 255;
                        check_arr[r][c - 1] = 0;
                    }
                }

                //  3rd Corner     2 3 5 
                else if (r == row - 1 && c == 0)
                {
                    if (arr1[r][c + 1] != 0)// ---------------------------- 5
                    {
                        if (arr2[r][c + 1] == 0)
                        {
                            my_q.push(r, c + 1);
                        }
                        arr2[r][c + 1] = 255;
                        check_arr[r][c + 1] = 0;
                    }
                    if (arr1[r - 1][c] != 0)   //--- ---------------------- 2
                    {
                        if (arr2[r - 1][c] == 0)
                        {
                            my_q.push(r - 1, c);
                        }
                        arr2[r - 1][c] = 255;
                        check_arr[r - 1][c] = 0;
                    }
                    if (arr1[r - 1][c + 1] != 0)  // ---------------------- 3
                    {
                        if (arr2[r - 1][c + 1] == 0)
                        {
                            my_q.push(r - 1, c + 1);
                        }
                        arr2[r - 1][c + 1] = 255;
                        check_arr[r - 1][c + 1] = 0;
                    }

                }

                // 4th corner      1 2 4
                else if (r == row - 1 && c == col - 1)
                {
                    if (arr1[r - 1][c - 1] != 0) // ----------------------- 1
                    {
                        if (arr2[r - 1][c - 1] == 0)
                        {
                            my_q.push(r - 1, c - 1);
                        }
                        arr2[r - 1][c - 1] = 255;
                        check_arr[r - 1][c - 1] = 0;
                    }
                    if (arr1[r - 1][c] != 0)   //--- ---------------------- 2
                    {
                        if (arr2[r - 1][c] == 0)
                        {
                            my_q.push(r - 1, c);
                        }
                        arr2[r - 1][c] = 255;
                        check_arr[r - 1][c] = 0;
                    }
                    if (arr1[r][c - 1] != 0) // --------------------------- 4
                    {
                        if (arr2[r][c - 1] == 0)
                        {
                            my_q.push(r, c - 1);
                        }
                        arr2[r][c - 1] = 255;
                        check_arr[r][c - 1] = 0;
                    }
                }

                // Upper row       4 5 6 7 8
                else if (((r == 0) && (c > 0 && c < col - 1)))
                {
                    if (arr1[r][c - 1] != 0) // --------------------------- 4
                    {
                        if (arr2[r][c - 1] == 0)
                        {
                            my_q.push(r, c - 1);
                        }
                        arr2[r][c - 1] = 255;
                        check_arr[r][c - 1] = 0;
                    }

                    if (arr1[r][c + 1] != 0)// ---------------------------- 5
                    {
                        if (arr2[r][c + 1] == 0)
                        {
                            my_q.push(r, c + 1);
                        }
                        arr2[r][c + 1] = 255;
                        check_arr[r][c + 1] = 0;
                    }
                    if (arr1[r + 1][c - 1] != 0)// ------------------------ 6
                    {
                        if (arr2[r + 1][c - 1] == 0)
                        {
                            my_q.push(r + 1, c - 1);
                        }
                        arr2[r + 1][c - 1] = 255;
                        check_arr[r + 1][c - 1] = 0;
                    }
                    if (arr1[r + 1][c] != 0) // --------------------------- 7
                    {
                        if (arr2[r + 1][c] == 0)
                        {
                            my_q.push(r + 1, c);
                        }
                        arr2[r + 1][c] = 255;
                        check_arr[r + 1][c] = 0;
                    }
                    if (arr1[r + 1][c + 1] != 0) // ----------------------- 8
                    {
                        if (arr2[r + 1][c + 1] == 0)
                        {
                            my_q.push(r + 1, c + 1);
                        }
                        arr2[r + 1][c + 1] = 255;
                        check_arr[r + 1][c + 1] = 0;
                    }
                }

                // Left col edge   2 3 5 7 8    
                else if (((c == 0) && (r > 0 && r < row - 1))) // row on left
                {
                    if (arr1[r - 1][c] != 0)   //--- ---------------------- 2
                    {
                        if (arr2[r - 1][c] == 0)
                        {
                            my_q.push(r - 1, c);
                        }
                        arr2[r - 1][c] = 255;
                        check_arr[r - 1][c] = 0;
                    }
                    if (arr1[r - 1][c + 1] != 0)  // ---------------------- 3
                    {
                        if (arr2[r - 1][c + 1] == 0)
                        {
                            my_q.push(r - 1, c + 1);
                        }
                        arr2[r - 1][c + 1] = 255;
                        check_arr[r - 1][c + 1] = 0;
                    }
                    if (arr1[r][c + 1] != 0)// ---------------------------- 5
                    {
                        if (arr2[r][c + 1] == 0)
                        {
                            my_q.push(r, c + 1);
                        }
                        arr2[r][c + 1] = 255;
                        check_arr[r][c + 1] = 0;
                    }
                    if (arr1[r + 1][c] != 0) // --------------------------- 7
                    {
                        if (arr2[r + 1][c] == 0)
                        {
                            my_q.push(r + 1, c);
                        }
                        arr2[r + 1][c] = 255;
                        check_arr[r + 1][c] = 0;
                    }
                    if (arr1[r + 1][c + 1] != 0) // ----------------------- 8
                    {
                        if (arr2[r + 1][c + 1] == 0)
                        {
                            my_q.push(r + 1, c + 1);
                        }
                        arr2[r + 1][c + 1] = 255;
                        check_arr[r + 1][c + 1] = 0;
                    }


                }

                // Right col edge  1 2 4 6 7
                else if (((c == col - 1) && (r > 0 && r < row - 1)))
                {
                    if (arr1[r - 1][c - 1] != 0) // ----------------------- 1
                    {
                        if (arr2[r - 1][c - 1] == 0)
                        {
                            my_q.push(r - 1, c - 1);
                        }
                        arr2[r - 1][c - 1] = 255;
                        check_arr[r - 1][c - 1] = 0;
                    }
                    if (arr1[r - 1][c] != 0)   //--- ---------------------- 2
                    {
                        if (arr2[r - 1][c] == 0)
                        {
                            my_q.push(r - 1, c);
                        }
                        arr2[r - 1][c] = 255;
                        check_arr[r - 1][c] = 0;
                    }
                    if (arr1[r][c - 1] != 0) // --------------------------- 4
                    {
                        if (arr2[r][c - 1] == 0)
                        {
                            my_q.push(r, c - 1);
                        }
                        arr2[r][c - 1] = 255;
                        check_arr[r][c - 1] = 0;
                    }
                    if (arr1[r + 1][c - 1] != 0)// ------------------------ 6
                    {
                        if (arr2[r + 1][c - 1] == 0)
                        {
                            my_q.push(r + 1, c - 1);
                        }
                        arr2[r + 1][c - 1] = 255;
                        check_arr[r + 1][c - 1] = 0;
                    }
                    if (arr1[r + 1][c] != 0) // --------------------------- 7
                    {
                        if (arr2[r + 1][c] == 0)
                        {
                            my_q.push(r + 1, c);
                        }
                        arr2[r + 1][c] = 255;
                        check_arr[r + 1][c] = 0;
                    }
                }

                // Last row        1 2 3 4 5 
                else if ((r == row - 1) && (c > 0 && c < col - 1))     // akhri line ka code
                {
                    if (arr1[r - 1][c - 1] != 0) // ----------------------- 1
                    {
                        if (arr2[r - 1][c - 1] == 0)
                        {
                            my_q.push(r - 1, c - 1);
                        }
                        arr2[r - 1][c - 1] = 255;
                        check_arr[r - 1][c - 1] = 0;
                    }
                    if (arr1[r - 1][c] != 0)   //--- ---------------------- 2
                    {
                        if (arr2[r - 1][c] == 0)
                        {
                            my_q.push(r - 1, c);
                        }
                        arr2[r - 1][c] = 255;
                        check_arr[r - 1][c] = 0;
                    }
                    if (arr1[r][c - 1] != 0) // --------------------------- 4
                    {
                        if (arr2[r][c - 1] == 0)
                        {
                            my_q.push(r, c - 1);
                        }
                        arr2[r][c - 1] = 255;
                        check_arr[r][c - 1] = 0;
                    }
                    if (arr1[r - 1][c + 1] != 0)  // ---------------------- 3
                    {
                        if (arr2[r - 1][c + 1] == 0)
                        {
                            my_q.push(r - 1, c + 1);
                        }
                        arr2[r - 1][c + 1] = 255;
                        check_arr[r - 1][c + 1] = 0;
                    }
                    if (arr1[r][c + 1] != 0)// ---------------------------- 5
                    {
                        if (arr2[r][c + 1] == 0)
                        {
                            my_q.push(r, c + 1);
                        }
                        arr2[r][c + 1] = 255;
                        check_arr[r][c + 1] = 0;
                    }
                }
            }
            // Mid elements        1 2 3 4 5 6 7 8
            else // Check for mid elements of the array
            {
                if (arr1[r - 1][c - 1] != 0) // ----------------------- 1
                {
                    if (arr2[r - 1][c - 1] == 0)
                    {
                        my_q.push(r - 1, c - 1);
                    }
                    arr2[r - 1][c - 1] = 255;
                    check_arr[r - 1][c - 1] = 0;
                }
                if (arr1[r - 1][c] != 0)   //--- ---------------------- 2
                {
                    if (arr2[r - 1][c] == 0)
                    {
                        my_q.push(r - 1, c);
                    }
                    arr2[r - 1][c] = 255;
                    check_arr[r - 1][c] = 0;
                }
                if (arr1[r][c - 1] != 0) // --------------------------- 4
                {
                    if (arr2[r][c - 1] == 0)
                    {
                        my_q.push(r, c - 1);
                    }
                    arr2[r][c - 1] = 255;
                    check_arr[r][c - 1] = 0;
                }
                if (arr1[r - 1][c + 1] != 0)  // ---------------------- 3
                {
                    if (arr2[r - 1][c + 1] == 0)
                    {
                        my_q.push(r - 1, c + 1);
                    }
                    arr2[r - 1][c + 1] = 255;
                    check_arr[r - 1][c + 1] = 0;
                }
                if (arr1[r][c + 1] != 0)// ---------------------------- 5
                {
                    if (arr2[r][c + 1] == 0)
                    {
                        my_q.push(r, c + 1);
                    }
                    arr2[r][c + 1] = 255;
                    check_arr[r][c + 1] = 0;
                }
                if (arr1[r + 1][c - 1] != 0)// ------------------------ 6
                {
                    if (arr2[r + 1][c - 1] == 0)
                    {
                        my_q.push(r + 1, c - 1);
                    }
                    arr2[r + 1][c - 1] = 255;
                    check_arr[r + 1][c - 1] = 0;
                }
                if (arr1[r + 1][c] != 0) // --------------------------- 7
                {
                    if (arr2[r + 1][c] == 0)
                    {
                        my_q.push(r + 1, c);
                    }
                    arr2[r + 1][c] = 255;
                    check_arr[r + 1][c] = 0;
                }
                if (arr1[r + 1][c + 1] != 0) // ----------------------- 8
                {
                    if (arr2[r + 1][c + 1] == 0)
                    {
                        my_q.push(r + 1, c + 1);
                    }
                    arr2[r + 1][c + 1] = 255;
                    check_arr[r + 1][c + 1] = 0;
                }
            }
        }



        // CONVERTING ARRAY TO IMAGE 

        Mat img2;
        img2 = imread("C:\\Users\\Zunaira\\Documents\\Ass - 2 Consoleee\\A2\\Images\\Img1.png");// put path of the image in original images folder
        Mat copy2;
        img2.convertTo(copy2, CV_8UC1);
        for (int i = 0; i < img2.rows; i++)
        {
            for (int j = 0; j < img2.cols; j++)
            {
                img2.at<Vec3b>(i, j) = arr2[i][j];

            }
        }

        // **********************************************************
        //                   FIGURING OUT STRING 
        // **********************************************************

        string path = "C:\\Users\\Zunaira\\Documents\\Ass - 2 Consoleee\\A2\\Output_files\\img_DFT";
        char p = gal + 48;
        path.push_back(p);
        path.append(".png");
        imwrite(path, img2);
        imshow("object", img2);
        waitKey();

        if (obj != false)
        {
            arr1 = check_arr;
        }



    }
    if (obj == 0)
    {
        cout << "Total objects have been simulated" << endl;
    }
    return gal;

}

// METHOD 1 + METHOD 2
string galaxy_finder(string x)
{
    string s = " No such file exists ";
    string galaxies = "";
    string y;
    for (int i = 0; x[i] != '\0'; i++)
    {
        if (x[i] != 32)
        {
            y.push_back(x[i]);
        }


    }
    string d = "C:\\Users\\Zunaira\\Documents\\Ass - 2 Consoleee\\A2";
    d.append(y);
    d.append(".png");


    Mat img;
    img = imread(d);
    Mat copy;
    img.convertTo(copy, CV_8UC1);
    int row = img.rows;
    int col = img.cols;

    fstream file;
    file.open(d);
    if (file.fail())
    {
        cout << "File failed to open, enter valid string." << endl;
        return s;
    }
    else
    {

        //allocate img_arr dynamically with img.rows and img.cols
        int** array = new int* [row];
        for (int i = 0; i < img.rows; i++)
        {
            array[i] = new int[col];
        }

        // ********************************************************************************
        for (int i = 0; i < img.rows; i++)
        {
            for (int j = 0; j < img.cols; j++)
            {
                array[i][j] = img.at<Vec3b>(i, j)[0];
            }
        }
        galaxies = convertIntegerToStr(row_wise_object_BFT(row, col, array));
        //row_wise_object_DFT(row, col, array);

        return galaxies;
    }

}



// ********************************************************************************************
//                                   TASK 1 + 2
// ********************************************************************************************
string tag_check(string exp, int ind )
{
    string number[7] = { "\t1 st File\n","\t\t  2nd File\n\n", "\t\t3 rd File\n","\t\t4 th File\n", "\t\t\  5th File\n\n", "\t\t6 th File\n", "\t\t7 th File\n" };
    string src = "src";
    string prior = "priorty";
    string copy;
    int size = int (exp.length() - 1); int check = 1;
    Stack <string> st;
    int start = 0, end = 0;
    for (int i = 0; i < size; i++)
    {
        if (exp[i] == '|')
        {
            if (exp[i + 1] == '\\')
            {
                if (st.get_head() != NULL) 
                {
                    st.pop(); i++;
                    while (exp[i] != '|')
                    {
                        i++;
                    }
                    i++;
                }
                else 
                {
                    number[ind].append("\t\t( ó_ò ) Syntax Error ¯\\_(?)_/¯ ");
                    //string str= "Syntax Error";
                    return number[ind];
                }
            }
            else
            {
                string tag;
                check = i; i++;
                for (i; exp[i] != '|'; i++)
                {
                    tag.push_back(exp[i]);
                }
                st.push(tag);// check for pre and post fix
                start = i;

                // Checking for mathematical expression
                string post, pre, sol, str;
                string spr;
                spr = st.get_data();
                post = "post_exp", pre = "pre_exp", sol = "sol_exp";

                // Saving mathematical expressions in a string 
                for (i = i + 1; exp[i] != '|'; i++)
                {
                    str.push_back(exp[i]);
                }
                // Matching which operation to perform

                if (spr == post)
                {
                    string str2;
                    int s = str.size();
                    for (int i = 0; i < s; i++)
                    {
                        if (str[i] != ' ')
                        {
                            str2.push_back(str[i]);
                        }
                    }
                    s = str2.size();
                    // if post
                    if (str2[size - 1] == 42 || str2[size - 1] == 43 || str2[size - 1] == 45 || str2[size - 1] == 47) 
                    {
                        str = " $ Invalid Expression $ ";
                    }
                    // if pre
                    else if (str2[0] == 42 || str2[0] == 43 || str2[0] == 45 || str2[0] == 47) 
                    {
                        str = pretopost(str);
                    }
                    // if infix
                    else 
                    {
                        str = post_fix(str);
                    }
                    
                }
                else if (spr == pre)
                {
                    string str2;
                    int s = str.size();
                    for (int i = 0; i < s; i++)
                    {
                        if (str[i] != ' ')
                        {
                            str2.push_back(str[i]);
                        }
                    }
                    s = str2.size();
                    // if infix already
                    if (((str2[size - 1] >= 48 && str2[size - 1] <= 57) || (str2[size - 1] > 64 && str2[size - 1] < 91) || (str2[size - 1] > 96 && str2[size - 1] < 123) || str2[size - 1] == 40 || str2[size - 1] == 41) && ((str2[0] >= 48 && str2[0] <= 57) || (str2[0] > 64 && str2[0] < 91) || (str2[0] > 96 && str2[0] < 123) || str2[0] == 40 || str2[0] == 41))
                    {
                        str = pre_fix(str);
                    }
                    // if pre
                    else if (str2[0] == 42 || str2[0] == 43 || str2[0] == 45 || str2[0] == 47)
                    {
                        str = " $ Invalid Expression - PREFIX already $ ";
                    }
                    // if postfix
                    else
                    {
                        // post to infix
                        str = in_fix(str);
                        str = pre_fix(str);
                    }
                   
                }
                else if (spr == sol)
                {
                    string str2;
                    int s = str.size();
                    for (int i = 0; i < s; i++)
                    {
                        if (str[i] != ' ')
                        {
                            str2.push_back(str[i]);
                        }
                    }
                    s = str2.size();
                    // if infix already
                    int check = 0;
                    for (int l = 0; str2[l] !='\0'; l++)
                    {
                        if ((str2[l] >= 48 && str2[l] <= 57) || str2[l] == 32 || str2[l] == 42|| str2[l] == 40 || str2[l] == 41 || str2[l] == 43 || str2[l] == 45 || str2[l] == 47 || str2[l] == 94)
                        {//            0                9            space
                            check = 1;
                        }
                        else
                        {
                            check = 0;
                            break;
                        }
                    }
                    if (check == 1) 
                    {
                        str = post_fix(str);
                        str = in_fix(str);
                    }
                    else if (((str2[size - 1] >= 48 && str2[size - 1] <=57) || (str2[size - 1] > 64 && str2[size - 1] < 91) || (str2[size - 1] > 96 && str2[size - 1] < 123)|| str2[size - 1]== 40 || str2[size - 1]== 41) && ((str2[0] >= 48 && str2[0] <= 57) || (str2[0] > 64 && str2[0] < 91) || (str2[0] > 96 && str2[0] < 123) || str2[0] == 40 || str2[0] == 41))
                    {
                        str = " $ Invalid Expression - INFIX already$ ";
                    }
                    // if pre
                    else if (str2[0] == 42 || str2[0] == 43 || str2[0] == 45 || str2[0] == 47)
                    {
                        str = pretopost(str);
                        str = in_fix(str);
                    }
                    // if postfix
                    else
                    {
                        str = in_fix(str);
                    }
                    
                }
                else if (spr == prior) 
                {
                    str = " ";
                }
                else if (spr == src) 
                {
                    str = galaxy_finder(str);
                }
                // Now save the expression in the string in the text file
                // Make a new copy string to copy new elements in the string
                copy.append(str);
                copy.push_back(' ');
                i--;
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
        number[ind].append("\t\t(ó_ò) Syntax Error ¯\\_(?)_/¯");
        return number[ind];
    }
    return copy;
}




// ********************************************************************************************
//                                     TASK 3
// ********************************************************************************************

int* priority_arr(string file_name[])
{
    ifstream file;
    string ret = "", final = "";
    int* pr_arr = new int[7];
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
            
            while (file.eof() == 0)
            {
                //size_t found = -1;
                getline(file, ret);
               
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

