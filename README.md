# Toy Robot (TR)

## Overview and Requirements

This project is based on the Toy Robot Coding Challenge C++ 2023 by. The requirements of the project are in the file: **Toy Robot Code Challenge C++ 2023.pdf**

In summary, the application is a simulation of a toy robot moving on a square table top, of dimensions 5 units x 5 units. There are no other obstructions on the table surface. The robot is free to roam around the surface of the table, but must be prevented from falling to destruction. Any movement that would result in the robot falling from the table must be prevented, however further valid movement commands must still be allowed.

## Pre-requisites

**IDE (Integrated Development Environment)**: Microsoft Visual Studio Professional 2017 Version 15.9.16

![image](https://user-images.githubusercontent.com/57872874/236676380-da8e731f-b292-4b67-bd67-af8e64ecb165.png)


**Target Platform:** Windows 10, **Windows SDK Version:** 10.0.17763.0

![image](https://user-images.githubusercontent.com/57872874/236676474-d91c8634-b565-4395-b29d-0c998404af31.png)



## Building TR

### 1. Clone github repository
       https://github.com/nestrebilla/TR.git

![image](https://user-images.githubusercontent.com/57872874/236677885-0cbd23af-c2b2-43fa-8e46-8835095ef482.png)

### 2. Open TR.sln via MS Visual Studio

Go to File > Open > Project/Solution. Right-click TR.sln and click Open.

![image](https://user-images.githubusercontent.com/57872874/236678287-a01d716f-e472-4548-9535-085e938da34c.png)

### 3. Build TR.sln Solution

Select the Configuration (Release or Debug) and Target Platform (x86 or x64).

![image](https://user-images.githubusercontent.com/57872874/236678649-219d7de6-3124-4760-b17f-2dbfe1a5e863.png)

On the Solution Explorer Window, right-click on "Solution 'TR'" and click Build Solution.
![image](https://user-images.githubusercontent.com/57872874/236678749-89c01ab7-76ac-48b7-bf9b-f5bd0dfda148.png)

Output files are located in the '{_SolutionDir_}\\{_Configuration_}' directory.

![image](https://user-images.githubusercontent.com/57872874/236678986-b530e6b9-20b0-4206-b966-51c904ae8a80.png)


## Using TR 

After building the solution (TR.sln), go to the output directory '{_SolutionDir_}\\{_Configuration_}' and run TR.exe.

The application can read commands of the following form:
1. PLACE X,Y,F
2. MOVE
3. LEFT
4. RIGHT
5. REPORT

### PLACE X,Y,F

PLACE will put the toy robot on the table in position X,Y and facing NORTH, SOUTH, EAST or WEST.

![image](https://user-images.githubusercontent.com/57872874/236679743-9995a5c8-c891-4524-9ef1-9c0ed021ce0e.png)



## Running TR Unit Tests
