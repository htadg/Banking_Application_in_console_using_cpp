#include<iostream> 
#include <windows.h>
#include <conio.h>
using namespace std;
int main()
    { 
    COORD coord; 
    coord.X = 100; 
    coord.Y = 80;



    _SMALL_RECT Rect;
    Rect.Top = 0;
    Rect.Left = 0;
    Rect.Bottom = 79;
    Rect.Right = 99;

    // Get handle of the standard output
    HANDLE Handle = GetStdHandle(STD_OUTPUT_HANDLE);
    if (Handle == NULL)
        {
        cout<<"Failure in getting the handle\n"<<GetLastError();

        }

    // Set screen buffer size to that specified in coord
    if(!SetConsoleScreenBufferSize(Handle, coord))
        {
    

        }

    // Set the window size to that specified in Rect
    if(!SetConsoleWindowInfo(Handle, TRUE, &Rect))
        { 
        cout<<"Failure in setting window size\n"<<GetLastError();

        } 

    } 

