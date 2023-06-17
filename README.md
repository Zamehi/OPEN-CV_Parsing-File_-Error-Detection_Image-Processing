# Parsing-File_-Error-Detection
Knowledge of queues and stacks

1. Parsing the file : Postfix Prefix expressions
 ![image](https://github.com/Zamehi/Parsing-File_-Error-Detection/assets/129313428/b31fdaf6-73e4-4fd6-b66c-e588247a0d7c)

2. Error Detection
There can be missing tags or invalid expressions, so you have to detect the parsing errors. There will be many tags other than those mentioned above. So, just consider these tags as the starting and ending boundaries of these tags, not more than that. While solving the expression, if you find any invalid expression, print "Invalid Expression" instead of the expression. If you find any missing or extra tags in the file, print Syntax Error.
Output:
So, you said you enjoyed the previous assignment and learned much and more :). Now, tell me about the number of galaxies in the picture. There are 4 galaxies in the image.
3. Least recent unit (LRU):
You have to maintain the queue with a fixed size of 4. In which you will store the file name on the base of their priority. When the queue gets full and you need to delete the item from the queue, you will delete the least recently used item in the queue.
When you start reading the file, you will check the file in the queue. If a file exists in the queue, print File Hit; else, File Fault. At the end of the program, you have to print the total number of hits and faults.
4. Extracting the galaxies (Extend part of Assignment 1)
5. ![Img1](https://github.com/Zamehi/Parsing-File_-Error-Detection/assets/129313428/4349f1dd-1c37-4fe1-9654-596295a028d0)

In previous assignment you have learn the following things:
1. Read the image.
2. Altering the image.
3. Detecting the number of objects in images.
Now in part you have to reuse the previous function and have to generate separate image for each object. (No Screen Shot, save the image properly using openCV).
You are given an image of size 512x512. The image contains clearly distinct objects. The background is BLACK represented by pixel value 0 and objects are displayed in white represented by 255. The goal is to separate each object from the rest of the image. The object can be separated by rest of the image by traversing the image either ROW wise or Column wise. The separated object should be moved to a blank new image. Where all the regions will be black except the area of separated object.
Algorithm:
|paragraph|
So, you said you enjoyed the previous assignment and learned much and more :). Now, tell me about the number of galaxies in the picture. There are |src| \path |\src| galaxies in the image. |\paragraph|
P a g e 4 | 7
Find the starting point of the object. Starting point will the first pixel that is 255 and from this point the whole object originates. Each pixel has 8 neighbors. Top, bottom, left, right and 4 diagonal pixels. Not all pixels have same value. The focus of algorithm will be on those pixels which are 255 to find the whole object.
![img_BFT3](https://github.com/Zamehi/Parsing-File_-Error-Detection/assets/129313428/140ff13c-95c6-4d5a-8dd5-3a5163772252)
![img_DFT1](https://github.com/Zamehi/Parsing-File_-Error-Detection/assets/129313428/281dbbb3-40af-4d64-9537-0b662b4b657c)
![img_DFT2](https://github.com/Zamehi/Parsing-File_-Error-Detection/assets/129313428/2a7b3e41-eec6-451f-a1ae-1b51195e937e)



