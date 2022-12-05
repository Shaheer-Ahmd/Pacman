#include <iostream>
#include <windows.h>
#include <mmsystem.h>
#pragma comment("lib, winmm.lib")
using namespace std;



int main ()
{ 
    PlaySound(TEXT("pacman_beginning.wav"), NULL, SND_ASYNC | SND_FILENAME);    

}
