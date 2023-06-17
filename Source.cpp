
#include <iostream>
#include <string>
#include <fstream>
#include "functions.h"
#include <cstring>



using namespace std;




int main()
{
    // File reading 
    //string final;
    ////                      The file getting processed and the conve
    //string file_name[7] = { "                                        First File@","                                        Second File@","                                        Third File@" ,"                                        Fourth File@" ,"                                        Fifth File@" ,"                                        Sixth File@" ,"                                        Seventh File@"};
    //string test_files[7] = { "C:\\Users\\Zunaira\\Documents\\Data Assignment 2\\A2\\Test_files\\Test-1.txt","C:\\Users\\Zunaira\\Documents\\Data Assignment 2\\A2\\Test_files\\Test-2.txt","C:\\Users\\Zunaira\\Documents\\Data Assignment 2\\A2\\Test_files\\Test-3.txt","C:\\Users\\Zunaira\\Documents\\Data Assignment 2\\A2\\Test_files\\Test-4.txt","C:\\Users\\Zunaira\\Documents\\Data Assignment 2\\A2\\Test_files\\Test-5.txt","C:\\Users\\Zunaira\\Documents\\Data Assignment 2\\A2\\Test_files\\Test-6.txt","C:\\Users\\Zunaira\\Documents\\Data Assignment 2\\A2\\Test_files\\Test-7.txt" };
    //string str 
    //for (int i = 0; i < 7; i++) 
    //{
    //    str = read(test_files[i]);
    //    str = tag_check(str);
    //    final.append(file_name[i]);
    //    final.append(str);
    //    str = "";
    //    
    //}
    //str = read("C:\\Users\\Zunaira\\Documents\\Data Assignment 2\\\\A2\\\\Test_files\\\\Test-1.txt");
    //str = tag_check(str);
    //cout << str;

    //int* arr = priority_queue(test_files);
    //string p = read("A2\\Test_files\\Test - 7.txt");

   /* string final = { "My first file @ Please take away my soul and add add it @        to yours.@" };

    ofstream myfile("C:\\Users\\Zunaira\\Documents\\Ass - 2 Consoleee\\A2\\Output_files\\Result-1.txt");
    if (!myfile)
    {
        cout << "Cannot open file.\n";
        return 1;
    }
    for (int i = 0; final[i] != '\0'; i++)
    {
       
          myfile << final[i];
    }*/
   string  post = "post_exp", pre = "pre_exp", sol = "sol_exp";

    // Saving mathematical expressions in a string 
   string str = " 9 8 6 * + ";
   str = in_fix(str);
   // // Matching which operation to perform
   //string spr = "post";
   // if (spr == "post")
   // {
   //     string str2;
   //     int s = str.size() ;
   //     for (int i = 0; str[i] != '\0'; i++) 
   //     {

   //     }
   //     for (int i = 0; i < s; i++)
   //     {
   //         if (str[i] != ' ')
   //         {
   //             str2.push_back(str[i]);
   //         }
   //     }
   //     s = str2.size();
   //     if (str2[s - 1] == 42 || str2[s - 1] == 43 || str2[s - 1] == 45 || str2[s - 1] == 47)
   //     {
   //         str = " $ Invalid Expression $ ";
   //     }
   //     else if (str2[0] == 42 || str2[0] == 43 || str2[0] == 45 || str2[0] == 47)
   //     {
   //         str = pretopost(str);
   //     }
   //     else
   //     {
   //         str = post_fix(str);
   //     }

   // }
   // else if (spr == pre)
   // {
   //     str = pre_fix(str);
   // }
   // else if (spr == sol)
   // {
   //     str = in_fix(str);
   // }
    cout << str;

    return 0;
}
