# Toy Robot (TR)

## Overview and Requirements

This project is based on the Toy Robot Coding Challenge C++ 2023. The requirements of the project are in the file: **Toy Robot Code Challenge C++ 2023.pdf**

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

The origin (0,0) can be considered to be the SOUTH WEST most corner. It is required that the first command to the robot is a PLACE command, after that, any sequence of commands may be issued, in any order, including another PLACE command. The application should discard all commands in the sequence until a valid PLACE command has been executed.

### MOVE

MOVE will move the toy robot one unit forward in the direction it is currently facing.

![image](https://user-images.githubusercontent.com/57872874/236679865-1a5c273d-39b8-4b86-b091-80c01ee4ec3f.png)

### LEFT and RIGHT

LEFT and RIGHT will rotate the robot 90 degrees in the specified direction without changing the position of the robot.

![image](https://user-images.githubusercontent.com/57872874/236679937-8035e65c-56bd-4d24-85be-c82c4b37225a.png)

### REPORT

REPORT will announce the X,Y and F of the robot.

![image](https://user-images.githubusercontent.com/57872874/236680092-04d3717a-3615-4193-92cf-298b415ac708.png)

A robot that is not on the table can choose to ignore the MOVE, LEFT, RIGHT and REPORT commands.



## Running TR Unit Tests

On MS Visual Studio, go to Test > Run > All Tests.

![image](https://user-images.githubusercontent.com/57872874/236680250-af538eff-5096-41e0-b3a3-e0211ba02cec.png)

Test results will be shown on the Test Explorer window.

![image](https://user-images.githubusercontent.com/57872874/236680306-9ae09573-f38d-4782-ae84-d9b30b076d66.png)


## Test Data

### Test Case 1a (Happy path - MOVE and LEFT/RIGHT)

Input:

PLACE 0,0,NORTH

MOVE

RIGHT

MOVE

LEFT

REPORT

Output: 1,1,NORTH

![image](https://user-images.githubusercontent.com/57872874/236680626-96c175b4-b8dc-4ab2-975b-fafa02358fb8.png)


### Test Case 1b (Happy path - MOVE to valid position)

Input:

PLACE 0,0,NORTH

MOVE

REPORT

Output: 0,1,NORTH

![image](https://user-images.githubusercontent.com/57872874/236681105-0f21aabe-31a6-4cdc-bca3-c50a630824ce.png)


### Test Case 1c (Happy path - turn LEFT)

Input:

PLACE 0,0,NORTH

LEFT

REPORT

Output: 0,0,WEST

![image](https://user-images.githubusercontent.com/57872874/236681556-76c3f7be-9be7-4c30-b8cc-f1541fb40467.png)


### Test Case 1d (Happy path - MOVE and LEFT/RIGHT)

Input:

PLACE 1,2,EAST

MOVE

MOVE

LEFT

MOVE

REPORT

Output: 3,3,NORTH

![image](https://user-images.githubusercontent.com/57872874/236681814-7e97ee31-538c-449f-b890-6c2724970bd0.png)


### Test Case 2 (Alternate path: invalid face direction)

Input:

PLACE 0,0,fdsfs

Output:

Error: Invalid robot face direction

![image](https://user-images.githubusercontent.com/57872874/236680794-bcb49076-eb15-4f6f-93e5-fb96e210465f.png)


### Test Case 3 (Alternate path: invalid/out-of-bounds position coordinates)

Input:

PLACE 5,-1,NORTH

Output:

Error: Invalid position

![image](https://user-images.githubusercontent.com/57872874/236680940-a1ff36c9-ef0d-4929-8067-27d6bae4a579.png)

