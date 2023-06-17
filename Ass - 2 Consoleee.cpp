/*Name : Zunaira Amir   ,    email:  i210780@nu.edu.pk*/


#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc.hpp>

#include <iostream>
#include <string>
#include <fstream>
#include "functions.h"
#include "functions2.h"


using namespace cv;
using namespace std;


int main()
{

    //*********************************----------------************************************
    // 
    // ********************************----------------************************************

    string test_files[7] = { "C:\\Users\\Zunaira\\Documents\\Data Assignment 2\\A2\\Test_files\\Test-1.txt","C:\\Users\\Zunaira\\Documents\\Data Assignment 2\\A2\\Test_files\\Test-2.txt","C:\\Users\\Zunaira\\Documents\\Data Assignment 2\\A2\\Test_files\\Test-3.txt","C:\\Users\\Zunaira\\Documents\\Data Assignment 2\\A2\\Test_files\\Test-4.txt","C:\\Users\\Zunaira\\Documents\\Data Assignment 2\\A2\\Test_files\\Test-5.txt","C:\\Users\\Zunaira\\Documents\\Data Assignment 2\\A2\\Test_files\\Test-6.txt","C:\\Users\\Zunaira\\Documents\\Data Assignment 2\\A2\\Test_files\\Test-7.txt" };
    string final;
    string str;


    // ------------------------------------   /|   -------------------------------------------
    // ------------------------------------  / |   -------------------------------------------
    // ------------------------------------    |   -------------------------------------------
    // ------------------------------------    |   -------------------------------------------
    // ------------------------------------    |   -------------------------------------------


    for (int i = 0; i < 7; i++)
    {
       cout << test_files[i] << endl;
        str = read(test_files[i]);
        str = tag_check(str, i );
        final.append(str);
        final.push_back('\n');
        final.append("\n\t\t\t\t\t\t\t\t\t\t________________\n");
        final.append("\t\t\t\t\t\t\t\t\t\t****************\n");
        str = "";
    }


    // --------------------------------    ___    ------------------------------------------
    // --------------------------------       \   ------------------------------------------
    // --------------------------------    ___/   ------------------------------------------
    // --------------------------------       \   ------------------------------------------
    // --------------------------------    ___/   ------------------------------------------


    int* prior = new int[2];
    prior = priority_queue(test_files);


    string last_line = "LRU Results: Total Hits : ";
    final.append(last_line);
    final.append(to_string(prior[0]));
    final.append(", Total Faults : ");
    final.append(to_string(prior[1]));
   

    ofstream myfile("C:\\Users\\Zunaira\\Documents\\Ass - 2 Consoleee\\A2\\Output_files\\Result-1.txt");
    if (!myfile) 
    {
        cout << "Cannot open file.\n";
        return 1;
    }
  
    if (myfile.is_open())
    {
        myfile << final;
    }
   
     myfile.close();

 
    return 0;
}
