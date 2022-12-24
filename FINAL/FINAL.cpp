//PlaySound(TEXT("pacman_beginning.WAV"), NULL, SND_SYNC);
//PlaySound(TEXT("pacman_chomp.WAV"),NULL,SND_SYNC);
//PlaySound(TEXT("pacman_death.WAV"),NULL,SND_SYNC);
#include <iostream>
#include <windows.h>
#include <time.h>
#include <cstdlib>
#include <stdlib.h>
#include <string>
#include <cmath>
#include <conio.h>
using namespace std;

const int row = 24;
const int col = 80;
const string wall = "#";
const string food = ".";
const string no_food = " ";
const string pacman = "C";
const string ghost1 = "G";
int target = 40;
bool alive1 = true;
bool alive2 = true;

short pacman_col = rand() % (col - 2) + 1;
short pacman_row = row - 2;
short ghost_col = rand() % (col - 2) + 1;
short ghost_row = 1;
int score = 0;
int t = 0;
int i = 0;    int j = 0;    int ig = 0;    int jg = 0; int precedence_count = 0; int k = 0;int l = 0;

string map[row][col] = {
    {wall,wall,wall,wall,wall,wall,wall,wall,wall,wall,wall,wall,wall,wall,wall,wall,wall,wall,wall,wall,wall,wall,wall,wall,wall,wall,wall,wall,wall,wall,wall,wall,wall,wall,wall,wall,wall,wall,wall,wall,wall,wall,wall,wall,wall,wall,wall,wall,wall,wall,wall,wall,wall,wall,wall,wall,wall,wall,wall,wall,wall,wall,wall,wall,wall,wall,wall,wall,wall,wall,wall,wall,wall,wall,wall,wall,wall,wall,wall},
    {wall,no_food,no_food,no_food,no_food,no_food,no_food,no_food,no_food,no_food,no_food,no_food,no_food,no_food,no_food,no_food,no_food,no_food,no_food,no_food,no_food,no_food,no_food,no_food,no_food,no_food,no_food,no_food,no_food,no_food,no_food,no_food,no_food,no_food,no_food,no_food,no_food,no_food,no_food,no_food,no_food,no_food,no_food,no_food,no_food,no_food,no_food,no_food,no_food,no_food,no_food,no_food,no_food,no_food,no_food,no_food,no_food,no_food,no_food,no_food,no_food,no_food,no_food,no_food,no_food,no_food,no_food,no_food,no_food,no_food,no_food,no_food,no_food,no_food,no_food,no_food,no_food,no_food,wall},
    {wall,no_food,no_food,no_food,wall,wall,wall,wall,wall,wall,wall,wall,wall,wall,wall,no_food,no_food,no_food,no_food,no_food,no_food,no_food,no_food,no_food,no_food,no_food,no_food,no_food,wall,wall,wall,wall,wall,wall,wall,wall,wall,wall,wall,no_food,no_food,no_food,no_food,no_food,no_food,no_food,no_food,no_food,no_food,no_food,no_food,no_food,no_food,no_food,no_food,no_food,no_food,wall,wall,wall,wall,wall, wall,wall,wall,wall,wall,no_food,no_food,no_food,no_food,no_food,no_food,no_food,no_food,no_food,no_food,no_food,wall},
    {wall,no_food,no_food,no_food,wall,wall,wall,wall,wall,wall,wall,wall,wall,wall,wall,no_food,no_food,no_food,no_food,no_food,no_food,no_food,no_food,no_food,no_food,no_food,no_food,no_food,wall,wall,wall,wall,wall,wall,wall,wall,wall,wall,wall,no_food,no_food,no_food,no_food,no_food,no_food,no_food,no_food,no_food,no_food,no_food,no_food,no_food,no_food,no_food,no_food,no_food,no_food,wall,no_food,no_food,no_food,wall,no_food,wall,no_food,no_food,no_food,wall,no_food,no_food,no_food,no_food,no_food,no_food,no_food,no_food,no_food,no_food,wall},
    {wall,no_food,no_food,no_food,wall,wall,no_food,no_food,no_food,no_food,no_food,no_food,no_food,no_food,no_food,no_food,no_food,no_food,no_food,no_food,no_food,no_food,no_food,no_food,no_food,no_food,no_food,no_food,wall,wall,wall,wall,wall,wall,wall,wall,wall,wall,wall,no_food,no_food,no_food,no_food,no_food,no_food,no_food,no_food,no_food,no_food,no_food,no_food,no_food,no_food,no_food,no_food,no_food,no_food,wall,no_food,no_food,no_food,no_food,no_food,no_food,no_food,no_food,no_food,wall,no_food,no_food,no_food,no_food,no_food,no_food,no_food,no_food,no_food,no_food,wall},
    {wall,no_food,no_food,no_food,wall,wall,no_food,no_food,no_food,no_food,no_food,no_food,no_food,no_food,no_food,no_food,no_food,no_food,no_food,no_food,no_food,no_food,no_food,no_food,no_food,no_food,no_food,no_food,wall,wall,wall,wall,wall,wall,wall,wall,wall,wall,wall,no_food,no_food,no_food,no_food,no_food,no_food,no_food,no_food,no_food,no_food,no_food,no_food,no_food,no_food,no_food,no_food,no_food,no_food,wall,no_food,no_food,no_food,wall,no_food,wall,no_food,no_food,no_food,wall,no_food,no_food,no_food,no_food,no_food,no_food,no_food,no_food,no_food,no_food,wall},
    {wall,no_food,no_food,no_food,wall,wall,no_food,no_food,wall,wall,wall,wall,wall,wall,wall,wall,no_food,no_food,no_food,no_food,no_food,no_food,no_food,no_food,no_food,no_food,no_food,no_food,wall,wall,wall,wall,wall,wall,wall,wall,wall,wall,wall,no_food,no_food,no_food,no_food,no_food,no_food,no_food,no_food,no_food,no_food,no_food,no_food,no_food,no_food,no_food,no_food,no_food,no_food,wall,wall,wall,wall,wall, wall,wall,wall,wall,wall,no_food,no_food,no_food,no_food,no_food,no_food,no_food,no_food,no_food,no_food,no_food,wall},
    {wall,no_food,no_food,no_food,wall,wall,no_food,no_food,no_food,no_food,no_food,no_food,no_food,no_food,no_food,no_food,no_food,no_food,no_food,no_food,no_food,no_food,no_food,no_food,no_food,no_food,no_food,no_food,no_food,no_food,no_food,no_food,no_food,no_food,no_food,no_food,no_food,no_food,no_food,no_food,no_food,no_food,no_food,no_food,no_food,no_food,no_food,no_food,no_food,no_food,no_food,no_food,no_food,no_food,no_food,no_food,no_food,no_food,no_food,no_food,no_food,no_food,no_food,no_food,no_food,no_food,no_food,no_food,no_food,no_food,no_food,no_food,no_food,no_food,no_food,no_food,no_food,no_food,wall},
    {wall,no_food,no_food,no_food,wall,wall,no_food,no_food,no_food,no_food,no_food,no_food,no_food,no_food,no_food,no_food,no_food,no_food,no_food,no_food,no_food,no_food,no_food,no_food,no_food,no_food,no_food,no_food,no_food,no_food,wall,wall,wall,wall,wall,wall,wall,wall,wall,no_food,no_food,no_food,no_food,no_food,no_food,no_food,no_food,no_food,no_food,no_food,no_food,wall,wall,wall,wall,wall,wall,wall,wall,wall,no_food,no_food,no_food,no_food,no_food,no_food,no_food,no_food,no_food,no_food,no_food,no_food,no_food,no_food,no_food,no_food,no_food,no_food,wall},
    {wall,no_food,no_food,no_food,wall,wall,no_food,no_food,no_food,no_food,no_food,no_food,no_food,no_food,no_food,no_food,no_food,no_food,no_food,no_food,no_food,no_food,no_food,no_food,no_food,no_food,no_food,no_food,no_food,no_food,wall,wall,wall,wall,wall,wall,wall,wall,wall,no_food,no_food,no_food,no_food,no_food,no_food,no_food,no_food,no_food,no_food,no_food,no_food,wall,wall,wall,wall,wall,wall,wall,wall,wall,no_food,no_food,no_food,no_food,no_food,no_food,no_food,no_food,no_food,no_food,no_food,no_food,no_food,no_food,no_food,no_food,no_food,no_food,wall},
    {wall,no_food,no_food,no_food,wall,wall,wall,wall,wall,wall,wall,wall,wall,wall,wall,no_food,no_food,no_food,no_food,no_food,no_food,no_food,no_food,no_food,no_food,no_food,no_food,no_food,no_food,no_food,wall,wall,wall,wall,wall,wall,wall,wall,wall,no_food,no_food,no_food,no_food,no_food,no_food,no_food,no_food,no_food,no_food,no_food,no_food,wall,wall,wall,wall,wall,wall,wall,wall,wall,no_food,no_food,no_food,no_food,no_food,no_food,no_food,no_food,no_food,no_food,no_food,no_food,no_food,no_food,no_food,no_food,no_food,no_food,wall},
    {wall,no_food,no_food,no_food,wall,wall,wall,wall,wall,wall,wall,wall,wall,wall,wall,no_food,no_food,no_food,no_food,no_food,no_food,no_food,no_food,no_food,no_food,no_food,no_food,no_food,no_food,no_food,no_food,no_food,no_food,no_food,no_food,no_food,no_food,no_food,no_food,no_food,no_food,no_food,no_food,no_food,no_food,no_food,no_food,no_food,no_food,no_food,no_food,no_food,no_food,no_food,no_food,no_food,no_food,no_food,no_food,no_food,no_food,no_food,no_food,no_food,no_food,no_food,no_food,no_food,no_food,no_food,no_food,no_food,no_food,no_food,no_food,no_food,no_food,no_food,wall},
    {wall,no_food,no_food,no_food,no_food,no_food,no_food,no_food,no_food,no_food,no_food,no_food,no_food,no_food,no_food,no_food,no_food,no_food,no_food,no_food,no_food,no_food,no_food,no_food,no_food,no_food,no_food,no_food,no_food,no_food,no_food,wall,wall,wall,wall,wall,wall,wall,wall,wall,wall,wall,wall,wall,wall,wall,wall,wall,wall,wall,wall,wall,wall,wall,wall,wall,wall,wall,wall,wall,wall,wall,wall,wall,wall,wall,wall,wall,no_food,no_food,no_food,no_food,no_food,no_food,no_food,no_food,no_food,no_food,wall},
    {wall,no_food,no_food,no_food,no_food,no_food,no_food,no_food,no_food,no_food,no_food,no_food,no_food,no_food,no_food,no_food,no_food,no_food,no_food,no_food,no_food,no_food,no_food,no_food,no_food,no_food,no_food,no_food,no_food,no_food,no_food,wall,wall,wall,wall,wall,wall,wall,wall,wall,wall,wall,wall,wall,wall,wall,wall,wall,wall,wall,wall,wall,wall,wall,wall,wall,wall,wall,wall,wall,wall,wall,wall,wall,wall,wall,wall,wall,no_food,no_food,no_food,no_food,no_food,no_food,no_food,no_food,no_food,no_food,wall},
    {wall,no_food,no_food,no_food,no_food,wall,wall,wall,wall,wall,wall,wall,wall,wall,wall,wall,no_food,no_food,no_food,no_food,no_food,no_food,no_food,no_food,no_food,no_food,no_food,no_food,no_food,no_food,no_food,wall,wall,wall,wall,wall,wall,wall,wall,wall,wall,wall,wall,wall,wall,wall,wall,wall,wall,wall,wall,wall,wall,wall,wall,wall,wall,wall,wall,wall,wall,wall,wall,wall,wall,wall,wall,wall,no_food,no_food,no_food,no_food,no_food,no_food,no_food,no_food,no_food,no_food,wall},
    {wall,no_food,no_food,no_food,no_food,wall,wall,wall,wall,wall,wall,wall,wall,wall,wall,wall,no_food,no_food,no_food,no_food,no_food,no_food,no_food,no_food,no_food,no_food,no_food,no_food,no_food,no_food,no_food,no_food,no_food,no_food,no_food,no_food,no_food,no_food,no_food,no_food,no_food,no_food,no_food,no_food,no_food,no_food,no_food,no_food,no_food,no_food,no_food,no_food,no_food,no_food,no_food,no_food,no_food,no_food,no_food,no_food,no_food,no_food,no_food,no_food,no_food,no_food,no_food,no_food,no_food,no_food,no_food,no_food,no_food,no_food,no_food,no_food,no_food,no_food,wall},
    {wall,no_food,no_food,no_food,no_food,wall,wall,wall,wall,wall,wall,wall,wall,wall,wall,wall,no_food,no_food,no_food,no_food,no_food,no_food,no_food,no_food,no_food,no_food,no_food,no_food,no_food,no_food,no_food,no_food,no_food,no_food,no_food,no_food,no_food,no_food,no_food,no_food,no_food,no_food,no_food,no_food,no_food,no_food,no_food,no_food,no_food,no_food,no_food,no_food,no_food,no_food,no_food,no_food,no_food,no_food,no_food,no_food,no_food,no_food,no_food,no_food,no_food,no_food,no_food,wall,wall,wall,wall,wall,wall,no_food,no_food,no_food,no_food,no_food,wall},
    {wall,no_food,no_food,no_food,no_food,no_food,no_food,no_food,no_food,no_food,no_food,no_food,no_food,no_food,no_food,no_food,no_food,no_food,no_food,no_food,no_food,no_food,no_food,no_food,no_food,wall,wall,wall,wall,wall,wall,wall,wall,wall,wall,wall,wall,wall,wall,wall,wall,wall,wall,wall,no_food,no_food,no_food,no_food,no_food,no_food,no_food,no_food,no_food,no_food,no_food,no_food,no_food,no_food,no_food,no_food,no_food,no_food,no_food,no_food,no_food,no_food,no_food,wall,wall,wall,wall,wall,wall,no_food,no_food,no_food,no_food,no_food,wall},
    {wall,no_food,no_food,no_food,no_food,no_food,wall,wall,wall,wall,no_food,no_food,no_food,no_food,no_food,no_food,no_food,no_food,no_food,no_food,no_food,no_food,no_food,no_food,no_food,wall,wall,wall,wall,wall,wall,wall,wall,wall,wall,wall,wall,wall,wall,wall,wall,wall,wall,wall,no_food,wall,wall,wall,wall,wall,wall,wall,wall,wall,wall,wall,wall,wall,wall,wall,wall,wall,wall,wall,wall,wall,no_food,wall,wall,wall,wall,wall,wall,no_food,no_food,no_food,no_food,no_food,wall},
    {wall,no_food,no_food,no_food,no_food,no_food,wall,wall,wall,wall,wall,wall,no_food,no_food,no_food,no_food,no_food,no_food,no_food,no_food,no_food,no_food,no_food,no_food,no_food,wall,wall,wall,no_food,no_food,no_food,no_food,no_food,no_food,no_food,no_food,no_food,no_food,no_food,no_food,no_food,wall,wall,wall,no_food,no_food,no_food,no_food,no_food,no_food,no_food,no_food,no_food,no_food,no_food,no_food,no_food,no_food,no_food,no_food,no_food,no_food,no_food,no_food,no_food,no_food,no_food,wall,wall,wall,wall,wall,wall,no_food,no_food,no_food,no_food,no_food,wall},
    {wall,no_food,no_food,no_food,no_food,no_food,wall,wall,wall,wall,wall,wall,wall,wall,wall,no_food,no_food,no_food,no_food,no_food,no_food,no_food,no_food,no_food,no_food,wall,wall,wall,no_food,no_food,no_food,no_food,no_food,no_food,no_food,no_food,no_food,no_food,no_food,no_food,no_food,wall,wall,wall,no_food,no_food,no_food,no_food,no_food,no_food,no_food,no_food,no_food,no_food,no_food,no_food,no_food,no_food,no_food,no_food,no_food,no_food,no_food,no_food,no_food,no_food,no_food,wall,wall,wall,wall,wall,wall,no_food,no_food,no_food,no_food,no_food,wall},
    {wall,no_food,no_food,no_food,no_food,no_food,wall,wall,wall,wall,wall,wall,wall,wall,wall,no_food,no_food,no_food,no_food,no_food,no_food,no_food,no_food,no_food,no_food,wall,wall,wall,wall,wall,wall,wall,wall,wall,wall,wall,wall,wall,wall,wall,wall,wall,wall,wall,no_food,no_food,no_food,no_food,no_food,no_food,no_food,no_food,no_food,no_food,no_food,no_food,no_food,no_food,no_food,no_food,no_food,no_food,no_food,no_food,no_food,no_food,no_food,wall,wall,wall,wall,wall,wall,no_food,no_food,no_food,no_food,no_food,wall},
    {wall,no_food,no_food,no_food,no_food,no_food,no_food,no_food,no_food,no_food,no_food,no_food,no_food,no_food,no_food,no_food,no_food,no_food,no_food,no_food,no_food,no_food,no_food,no_food,no_food,no_food,no_food,no_food,no_food,no_food,no_food,no_food,no_food,no_food,no_food,no_food,no_food,no_food,no_food,no_food,no_food,no_food,no_food,no_food,no_food,no_food,no_food,no_food,no_food,no_food,no_food,no_food,no_food,no_food,no_food,no_food,no_food,no_food,no_food,no_food,no_food,no_food,no_food,no_food,no_food,no_food,no_food,no_food,no_food,no_food,no_food,no_food,no_food,no_food,no_food,no_food,no_food,no_food,wall},
    {wall,wall,wall,wall,wall,wall,wall,wall,wall,wall,wall,wall,wall,wall,wall,wall,wall,wall,wall,wall,wall,wall,wall,wall,wall,wall,wall,wall,wall,wall,wall,wall,wall,wall,wall,wall,wall,wall,wall,wall,wall,wall,wall,wall,wall,wall,wall,wall,wall,wall,wall,wall,wall,wall,wall,wall,wall,wall,wall,wall,wall,wall,wall,wall,wall,wall,wall,wall,wall,wall,wall,wall,wall,wall,wall,wall,wall,wall,wall}

};
void ShowConsoleCursor(bool showFlag)
{
    HANDLE out = GetStdHandle(STD_OUTPUT_HANDLE);

    CONSOLE_CURSOR_INFO     cursorInfo;

    GetConsoleCursorInfo(out, &cursorInfo);
    cursorInfo.bVisible = showFlag; // set the cursor visibility
    SetConsoleCursorInfo(out, &cursorInfo);
}


void gotoxy(short x, short y)
{
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { y,x });
}

void ColorPrint(const string text, int fg_color, int bg_color)
{
    static const char begin_sequence[]{ 0x1B,'[','\0' };
    static const char reset[]{ 0x1B,'[','0','m','\0' };

    cout << begin_sequence << fg_color << ';' << bg_color << 'm' << text << reset;
}

void coutyellow(string s)
{
    ColorPrint(s, 33, 40);
}
void coutblue(string s)
{
    ColorPrint(s, 96, 40);
}
void coutred(string s)
{
    ColorPrint(s, 31, 40);
}
void coutblack(string s)
{
    ColorPrint(s, 30, 40);
}
void InterFace()
{
    string rwall = "##############################################################################\n";
    string rsim = "#                                                                            #\n";
    string wall = "#"; string start = "                      ";
    string rp1 = "       +++       +    ++++++  +           +    +    +             +         ";
    string rp2 = "       ++++    +   +  +    +  + +       + +  +   +  ++            +         ";
    string rp3 = "       +++++   +   +  +    +  +  +     +  +  +   +  + +           +         ";
    string rp4 = "       ++++++  +++++  +       +   +   +   +  +++++  +  +          +         ";
    string rp5 = "       ++++++  +++++  +       +    + +    +  +++++  +   +         +         ";
    string rp6 = "       +++++   +   +  +       +     +     +  +   +  +    +        +         ";
    string rp7 = "       ++++    +   +  +       +           +  +   +  +     +       +         ";
    string rp8 = "       +++     +   +  +       +           +  +   +  +      +      +         ";
    string rp9 = "       +       +   +  +       +           +  +   +  +       +     +         ";
    string rp10 = "       +       +   +  +       +           +  +   +  +        +    +         ";
    string rp11 = "       +       +   +  +       +           +  +   +  +         +   +         ";
    string rp12 = "       +       +   +  +       +           +  +   +  +          +  +         ";
    string rp13 = "       +       +   +  +    +  +           +  +   +  +           + +         ";
    string rp14 = "       +       +   +  +    +  +           +  +   +  +            ++         ";
    string rp15 = "       +       +   +  ++++++  +           +  +   +  +             +         ";
    string rstart = "#                           "; string rstart1 = "                           #\n";
    coutblue(rwall); coutblue(rsim); coutblue(rsim); coutblue(rsim); coutblue(wall); coutyellow(rp1); coutblue(wall); cout << "\n";
    coutblue(wall); coutyellow(rp2); coutblue(wall); cout << "\n"; coutblue(wall); coutyellow(rp3); coutblue(wall); cout << "\n";
    coutblue(wall); coutyellow(rp4); coutblue(wall); cout << "\n"; coutblue(wall); coutyellow(rp5); coutblue(wall); cout << "\n";
    coutblue(wall); coutyellow(rp6); coutblue(wall); cout << "\n"; coutblue(wall); coutyellow(rp7); coutblue(wall); cout << "\n";
    coutblue(wall); coutyellow(rp8); coutblue(wall); cout << "\n"; coutblue(wall); coutyellow(rp9); coutblue(wall); cout << "\n";
    coutblue(wall); coutyellow(rp10); coutblue(wall); cout << "\n"; coutblue(wall); coutyellow(rp11); coutblue(wall); cout << "\n";
    coutblue(wall); coutyellow(rp12); coutblue(wall); cout << "\n"; coutblue(wall); coutyellow(rp13); coutblue(wall); cout << "\n";
    coutblue(wall); coutyellow(rp14); coutblue(wall); cout << "\n"; coutblue(wall); coutyellow(rp15); coutblue(wall); cout << "\n";
    coutblue(rsim); coutblue(rstart); coutblue(start); coutblue(rstart1); coutblue(rsim); coutblue(rsim); coutblue(rwall);
    cout << endl;
    PlaySound(TEXT("pacman_beginning.wav"), NULL, SND_SYNC);
    coutblue("Select the Difficulty Level \n HARD - H \n NORMAL - N \n EASY - E ");
    while (1)
    {
        char inp = _getch();
        if (inp == 'h')
        {
            target += 20;
            break;
        }
        else if (inp == 'n')
        {
            target += 10;
            break;
        }
        else if (inp == 'e')
        {
            break;
        }
        else
        {
            coutblue("\nInvalid difficulty. Please enter H,N or E.");
        }
    }

    coutred("\nInstructions\n");
    coutred("1- Move the Pacman using ARROW keys.");
    coutred("\n2-Try to eat ");
    coutred(to_string(target));
    coutred(" pieces of food within 40 seconds");
    coutred("\n3-Avoid the ghost (unless you like them).\n");
    coutblue("Press any key to start");
    _getch();

}
void game_over()
{
    PlaySound(TEXT("pacman_death.wav"), NULL, SND_SYNC);
    string wall = "#";
    string rwall = "##############################################################################\n";
    string rsim = "#                                                                            #\n";
    string rg1 = "  +++++++   ++++   +             +  ++++  +++++++  +     +  ++++  ++++++++  ";
    string rg2 = "  +        +    +  ++           ++  +     +     +  +     +  +     +      +  ";
    string rg3 = "  +        +    +  + +         + +  +     +     +  +     +  +     +      +  ";
    string rg4 = "  +        +    +  +  +       +  +  +     +     +  +     +  +     +      +  ";
    string rg5 = "  +        ++++++  +   +     +   +  +     +     +  +     +  +     +      +  ";
    string rg6 = "  +        ++++++  +    +   +    +  +     +     +  +     +  +     ++++++++  ";
    string rg7 = "  +        +    +  +     + +     +  +     +     +  +     +  +     +         ";
    string rg8 = "  +        +    +  +      +      +  ++++  +     +  +     +  ++++  + +       ";
    string rg9 = "  +        +    +  +             +  +     +     +  +     +  +     +  +      ";
    string rg10 = "  +        +    +  +             +  +     +     +  +     +  +     +   +     ";
    string rg11 = "  +        +    +  +             +  +     +     +  +     +  +     +    +    ";
    string rg12 = "  +  ++++  +    +  +             +  +     +     +  +     +  +     +     +   ";
    string rg13 = "  +     +  +    +  +             +  +     +     +  +     +  +     +      +  ";
    string rg14 = "  +     +  +    +  +             +  +     +     +    + +    +     +       + ";
    string rg15 = "  +++++++  +    +  +             +  ++++  +++++++     +     ++++  +         ";
    coutblue(rwall); coutblue(rsim); coutblue(rsim); coutblue(rsim); coutblue(wall); coutred(rg1); coutblue(wall); cout << "\n";
    coutblue(wall); coutred(rg2); coutblue(wall); cout << "\n"; coutblue(wall); coutred(rg3); coutblue(wall); cout << "\n";
    coutblue(wall); coutred(rg4); coutblue(wall); cout << "\n"; coutblue(wall); coutred(rg5); coutblue(wall); cout << "\n";
    coutblue(wall); coutred(rg6); coutblue(wall); cout << "\n"; coutblue(wall); coutred(rg7); coutblue(wall); cout << "\n";
    coutblue(wall); coutred(rg8); coutblue(wall); cout << "\n"; coutblue(wall); coutred(rg9); coutblue(wall); cout << "\n";
    coutblue(wall); coutred(rg10); coutblue(wall); cout << "\n"; coutblue(wall); coutred(rg11); coutblue(wall); cout << "\n";
    coutblue(wall); coutred(rg12); coutblue(wall); cout << "\n"; coutblue(wall); coutred(rg13); coutblue(wall); cout << "\n";
    coutblue(wall); coutred(rg14); coutblue(wall); cout << "\n"; coutblue(wall); coutred(rg15); coutblue(wall); cout << "\n";
    coutblue(rsim); coutblue(rsim); coutblue(rsim); coutblue(rwall);
    if (!alive2)
    {
        gotoxy(20, 15);
        coutblue("You failed to eat ");
        coutblue(to_string(target));
        coutblue(" pieces of food in ");
        coutblue(to_string(40));
        coutblue(" seconds.");
        gotoxy(21, 15);
        coutblue("You only managed to eat ");
        coutblue(to_string(score));
    }
    else
    {
        gotoxy(20, 18);
        coutblue("You Died.");
    }
}

void win()
{

    system("CLS");
    string rwall = "###############################################################################\n";
    string rsim = "#                                                                             #\n";
    string win1 = " +           +  +++++++  +     +  +               +  +++++++  +           +  ";
    string win2 = "  +         +   +     +  +     +  +               +     +     ++          +  ";
    string win3 = "   +       +    +     +  +     +  +               +     +     + +         +  ";
    string win4 = "    +     +     +     +  +     +  +               +     +     +  +        +  ";
    string win5 = "     +   +      +     +  +     +  +               +     +     +   +       +  ";
    string win6 = "      + +       +     +  +     +  +               +     +     +    +      +  ";
    string win7 = "       +        +     +  +     +  +               +     +     +     +     +  ";
    string win8 = "       +        +     +  +     +  +               +     +     +      +    +  ";
    string win9 = "       +        +     +  +     +  +       +       +     +     +       +   +  ";
    string win10 = "       +        +     +  +     +   +     + +     +      +     +        +  +  ";
    string win11 = "       +        +     +  +     +    +   +   +   +       +     +         + +  ";
    string win12 = "       +        +     +  +     +     + +     + +        +     +          ++  ";
    string win13 = "       +        +++++++  +++++++      +       +      +++++++  +           +  ";




    coutblue(rwall); coutblue(rsim); coutblue(rsim); coutblue(rsim); coutblue(rsim); coutblue(wall); coutyellow(win1); coutblue(wall); cout << "\n";
    coutblue(wall); coutyellow(win2); coutblue(wall); cout << "\n"; coutblue(wall); coutyellow(win3); coutblue(wall); cout << "\n";
    coutblue(wall); coutyellow(win4); coutblue(wall); cout << "\n"; coutblue(wall); coutyellow(win5); coutblue(wall); cout << "\n";
    coutblue(wall); coutyellow(win6); coutblue(wall); cout << "\n"; coutblue(wall); coutyellow(win7); coutblue(wall); cout << "\n";
    coutblue(wall); coutyellow(win8); coutblue(wall); cout << "\n"; coutblue(wall); coutyellow(win9); coutblue(wall); cout << "\n";
    coutblue(wall); coutyellow(win10); coutblue(wall); cout << "\n"; coutblue(wall); coutyellow(win11); coutblue(wall); cout << "\n";
    coutblue(wall); coutyellow(win12); coutblue(wall); cout << "\n"; coutblue(wall); coutyellow(win13); coutblue(wall); cout << "\n";
    coutblue(rsim); coutblue(rsim); coutblue(rsim); coutblue(rsim); coutblue(rsim); coutblue(rwall);

    PlaySound(TEXT("pacman_win.wav"), NULL, SND_SYNC);
}

void print_map()
{
    for (int i = 0;i < row;i++)
    {
        for (int j = 0;j < col;j++)
        {
            if (map[i][j] == wall)
                coutblue(map[i][j]);
            else if (map[i][j] == food)
                coutyellow(map[i][j]);
            else
                coutblack(map[i][j]);

        }
        cout << endl;
    }
}

void ghost()
{
    if (precedence_count == 10) precedence_count = 0;
    if (precedence_count < 5) {

        if (ghost_col <= pacman_col) //GO RIGHT
        {
            jg = 1; ig = 0;
        }
        else if (ghost_col > pacman_col) //GO LEFT
        {
            jg = -1; ig = 0;
        }
        else if (ghost_row <= pacman_row) //GO DOWN
        {
            ig = 1; jg = 0;
        }
        else if (ghost_row > pacman_row) //GO UP
        {
            ig = -1; jg = 0;
        }
    }
    else {

        if (ghost_row <= pacman_row) //GO DOWN
        {
            ig = 1; jg = 0;
        }
        else if (ghost_row > pacman_row) //GO UP
        {
            ig = -1; jg = 0;
        }
        else if (ghost_col <= pacman_col) //GO RIGHT
        {
            jg = 1; ig = 0;
        }
        else if (ghost_col > pacman_col) //GO LEFT
        {
            jg = -1; ig = 0;
        }

    }
    precedence_count++;
    if (map[ghost_row + ig][ghost_col + jg] != wall)
    {
        gotoxy(ghost_row, ghost_col);
        if (map[ghost_row][ghost_col] == food) coutyellow(food);
        else coutblack(no_food);
        ghost_row += ig;
        ghost_col += jg;
        gotoxy(ghost_row, ghost_col);
        coutred(ghost1);
    }
    else
    {
        if (jg == 1)//GO RIGHT
        {
            if (ghost_row <= pacman_row) {
                if (map[ghost_row + 1][ghost_col] != wall) { k = 1; l = 0; } //DOWN
                else if (map[ghost_row - 1][ghost_col] != wall) { k = -1; l = 0; } //UP
                else if (map[ghost_row][ghost_col - 1] != wall) { k = 0; l = -1; } //LEFT
            }
            else {
                if (map[ghost_row - 1][ghost_col] != wall) { k = -1; l = 0; } //UP
                else if (map[ghost_row + 1][ghost_col] != wall) { k = 1; l = 0; } //DOWN
                else if (map[ghost_row][ghost_col - 1] != wall) { k = 0; l = -1; } //LEFT
            }
        }
        else if (jg == -1) // GO LEFT
        {
            if (ghost_row <= pacman_row) {
                if (map[ghost_row + 1][ghost_col] != wall) { k = 1; l = 0; } //DOWN
                else if (map[ghost_row - 1][ghost_col] != wall) { k = -1; l = 0; } //UP
                else if (map[ghost_row][ghost_col + 1] != wall) { k = 0; l = 1; } //RIGHT
            }
            else {
                if (map[ghost_row - 1][ghost_col] != wall) { k = -1; l = 0; } //UP
                else if (map[ghost_row + 1][ghost_col] != wall) { k = 1; l = 0; } //DOWN
                else if (map[ghost_row][ghost_col + 1] != wall) { k = 0; l = 1; } //RIGHT
            }
        }
        else if (ig == -1)// GO UP
        {
            if (ghost_col <= pacman_col) {
                if (map[ghost_row][ghost_col + 1] != wall) { k = 0; l = 1; } //RIGHT
                else if (map[ghost_row][ghost_col - 1] != wall) { k = 0; l = -1; } //LEFT
                else if (map[ghost_row + 1][ghost_col] != wall) { k = 1; l = 0; } //DOWN
            }
            else {
                if (map[ghost_row][ghost_col - 1] != wall) { k = 0; l = -1; } //LEFT
                else if (map[ghost_row][ghost_col + 1] != wall) { k = 0; l = 1; } //RIGHT
                else if (map[ghost_row + 1][ghost_col] != wall) { k = 1; l = 0; } //DOWN
            }
        }
        else if (ig == 1)// GO DOWN
        {
            if (ghost_col <= pacman_col) {
                if (map[ghost_row][ghost_col + 1] != wall) { k = 0; l = 1; } //RIGHT
                else if (map[ghost_row][ghost_col - 1] != wall) { k = 0; l = -1; } //LEFT
                else if (map[ghost_row - 1][ghost_col] != wall) { k = -1; l = 0; } //UP
            }
            else {
                if (map[ghost_row][ghost_col - 1] != wall) { k = 0; l = -1; } //RIGHT
                else if (map[ghost_row][ghost_col + 1] != wall) { k = 0; l = 1; } //LEFT
                else if (map[ghost_row - 1][ghost_col] != wall) { k = -1; l = 0; } //UP
            }
        }

        gotoxy(ghost_row, ghost_col);
        if (map[ghost_row][ghost_col] == food) coutyellow(food);
        else coutblack(no_food);
        ghost_row += k;
        ghost_col += l;
        gotoxy(ghost_row, ghost_col);
        coutred(ghost1);
    }
}

int main() {
    system("CLS");
    InterFace();

    system("CLS");

    srand(time(0));
    ShowConsoleCursor(false);
    //MAP INITIALIZATION
    for (int i = 0;i < row;i++)
    {
        for (int j = 0;j < col;j++)
        {
            if (j % 3 == 0 && i % 2 == 0 && map[i][j] != wall)
            {
                map[i][j] = food;
            }
        }
    }
    print_map();
    gotoxy(0, col + 1);
    coutblue("Score: ");
    coutblue(to_string(score));

    //PAC INITIALIZATION
    gotoxy(pacman_row, pacman_col);

    coutyellow(pacman);
    gotoxy(ghost_row, ghost_col);

    coutred(ghost1);


    while (alive1 && alive2)
    {

        if (GetAsyncKeyState(VK_UP)) { i = -1; j = 0; }
        else if (GetAsyncKeyState(VK_DOWN)) { i = 1; j = 0; }
        else if (GetAsyncKeyState(VK_RIGHT)) { j = 1; i = 0; }
        else if (GetAsyncKeyState(VK_LEFT)) { j = -1; i = 0; }

        if (map[pacman_row + i][pacman_col + j] != wall)
        {
            if (map[pacman_row][pacman_col] == food)
            {
                map[pacman_row][pacman_col] = no_food;
                score++;
                PlaySound(TEXT("pacman_chomp.WAV"), NULL, SND_ASYNC);
            }

            gotoxy(pacman_row, pacman_col);
            coutblack(no_food);
            pacman_row += i;
            pacman_col += j;
            gotoxy(pacman_row, pacman_col);
            coutyellow(pacman);

        }
        ghost();
        if (pacman_row == ghost_row && pacman_col == ghost_col)
        {
            alive1 = false;
        }
        if (t / 100 >= 40)
        {
            alive2 = false;
        }
        t = t + 10;
        gotoxy(1, col + 1);
        coutblue("Time: ");
        if (t % 100 == 0)
        {
            coutblue(to_string(t / 100));
        }
        gotoxy(0, col + 8);
        coutblue(to_string(score));
        Sleep(65);

    }
    if ((!(pacman_row == ghost_row && pacman_col == ghost_col) && score >= target))
    {
        win();
    }
    else {
        system("CLS");
        game_over();
        gotoxy(28, 0);
        cout << endl;

    }
    return 0;
}