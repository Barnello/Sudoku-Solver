# Sudoku-Solver
An application to solve sudoku in real time from an image

The algorithm to solve the Suduko board will be written in cpp
1. Function to solve the board in real time
2. Function to print the board in preperation for displaying the baord
3. Main function to feed into the the application

The end goal of this solution will be for users to take a snippet of a suduko board on their computer and feed into the algorithm.

The application will either use the image to display the solution or just display in text for the user to add in.

This repository will be testing and reporting the efficiency and accuracy of the following methods of solving a suduko board:
1. Generating sudoku boards before and after being filled in (two images) and training a CNN to recognize the solutions without any rule-based processing.
2. Generating sudoku boards before being filled in and providing the labels of the solution in a 2D matrix to train a model without rule-based processing. 
3. Generating canny edge detection, paired with a number detection model, to create the 2D matrix without the solution and plugging into rule-based processing.

