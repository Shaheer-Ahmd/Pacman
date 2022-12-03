#include <iostream>
#include <windows.h>
#include <time.h>
#include <cstdlib>
#include <stdlib.h>
#include <string>
#include <cmath>
using namespace std;

const int row = 24;
const int col = 80;
const string wall = "#";
const string food = ".";
const string no_food = " ";
const string pacman = "C";
const string ghost1 = "A";

short pacman_col = rand() % (col - 2) + 1;
short pacman_row = row-2;
short ghost_col = rand() % (col - 2) + 1;
short ghost_row = 1;
int score = 0;
int i = 0;    int j = 0;    int ig = 0;    int jg = 0; int precedence_count = 0; int k =0 ;int l = 0;

string map[row][col] = {
    {wall,wall,wall,wall,wall,wall,wall,wall,wall,wall,wall,wall,wall,wall,wall,wall,wall,wall,wall,wall,wall,wall,wall,wall,wall,wall,wall,wall,wall,wall,wall,wall,wall,wall,wall,wall,wall,wall,wall,wall,wall,wall,wall,wall,wall,wall,wall,wall,wall,wall,wall,wall,wall,wall,wall,wall,wall,wall,wall,wall,wall,wall,wall,wall,wall,wall,wall,wall,wall,wall,wall,wall,wall,wall,wall,wall,wall,wall,wall},
    {wall,food,food,food,food,food,food,food,food,food,food,food,food,food,food,food,food,food,food,food,food,food,food,food,food,food,food,food,food,food,food,food,food,food,food,food,food,food,food,food,food,food,food,food,food,food,food,food,food,food,food,food,food,food,food,food,food,food,food,food,food,food,food,food,food,food,food,food,food,food,food,food,food,food,food,food,food,food,wall},
    {wall,food,food,food,wall,wall,wall,wall,wall,wall,wall,wall,wall,wall,wall,food,food,food,food,food,food,food,food,food,food,food,food,food,wall,wall,wall,wall,wall,wall,wall,wall,wall,wall,wall,food,food,food,food,food,food,food,food,food,food,food,food,food,food,food,food,food,food,wall,wall,wall,wall,wall, wall,wall,wall,wall,wall,food,food,food,food,food,food,food,food,food,food,food,wall},
    {wall,food,food,food,wall,wall,wall,wall,wall,wall,wall,wall,wall,wall,wall,food,food,food,food,food,food,food,food,food,food,food,food,food,wall,wall,wall,wall,wall,wall,wall,wall,wall,wall,wall,food,food,food,food,food,food,food,food,food,food,food,food,food,food,food,food,food,food,wall,food,food,food,wall,food,wall,food,food,food,wall,food,food,food,food,food,food,food,food,food,food,wall},
    {wall,food,food,food,wall,wall,food,food,food,food,food,food,food,food,food,food,food,food,food,food,food,food,food,food,food,food,food,food,wall,wall,wall,wall,wall,wall,wall,wall,wall,wall,wall,food,food,food,food,food,food,food,food,food,food,food,food,food,food,food,food,food,food,wall,food,food,food,food,food,food,food,food,food,wall,food,food,food,food,food,food,food,food,food,food,wall},
    {wall,food,food,food,wall,wall,food,wall,wall,wall,wall,wall,wall,wall,wall,food,food,food,food,food,food,food,food,food,food,food,food,food,wall,wall,wall,wall,wall,wall,wall,wall,wall,wall,wall,food,food,food,food,food,food,food,food,food,food,food,food,food,food,food,food,food,food,wall,food,food,food,wall,food,wall,food,food,food,wall,food,food,food,food,food,food,food,food,food,food,wall},
    {wall,food,food,food,wall,wall,food,food,food,food,food,food,food,food,food,food,food,food,food,food,food,food,food,food,food,food,food,food,wall,wall,wall,wall,wall,wall,wall,wall,wall,wall,wall,food,food,food,food,food,food,food,food,food,food,food,food,food,food,food,food,food,food,wall,wall,wall,wall,wall, wall,wall,wall,wall,wall,food,food,food,food,food,food,food,food,food,food,food,wall},
    {wall,food,food,food,wall,wall,wall,wall,wall,wall,wall,wall,wall,wall,wall,food,food,food,food,food,food,food,food,food,food,food,food,food,food,food,food,food,food,food,food,food,food,food,food,food,food,food,food,food,food,food,food,food,food,food,food,food,food,food,food,food,food,food,food,food,food,food,food,food,food,food,food,food,food,food,food,food,food,food,food,food,food,food,wall},
    {wall,food,food,food,wall,wall,wall,wall,wall,wall,wall,wall,wall,wall,wall,food,food,food,food,food,food,food,food,food,food,food,food,food,food,food,wall,wall,wall,wall,wall,wall,wall,wall,wall,food,food,food,food,food,food,food,food,food,food,food,food,wall,wall,wall,wall,wall,wall,wall,wall,wall,food,food,food,food,food,food,food,food,food,food,food,food,food,food,food,food,food,food,wall},
    {wall,food,food,food,food,food,food,food,food,food,food,food,food,wall,wall,food,food,food,food,food,food,food,food,food,food,food,food,food,food,food,wall,wall,wall,wall,wall,wall,wall,wall,wall,food,food,food,food,food,food,food,food,food,food,food,food,wall,wall,wall,wall,wall,wall,wall,wall,wall,food,food,food,food,food,food,food,food,food,food,food,food,food,food,food,food,food,food,wall},
    {wall,food,food,food,wall,wall,wall,wall,wall,wall,wall,wall,wall,wall,wall,food,food,food,food,food,food,food,food,food,food,food,food,food,food,food,wall,wall,wall,wall,wall,wall,wall,wall,wall,food,food,food,food,food,food,food,food,food,food,food,food,wall,wall,wall,wall,wall,wall,wall,wall,wall,food,food,food,food,food,food,food,food,food,food,food,food,food,food,food,food,food,food,wall},
    {wall,food,food,food,wall,wall,wall,wall,wall,wall,wall,wall,wall,wall,wall,food,food,food,food,food,food,food,food,food,food,food,food,food,food,food,food,food,food,food,food,food,food,food,food,food,food,food,food,food,food,food,food,food,food,food,food,food,food,food,food,food,food,food,food,food,food,food,food,food,food,food,food,food,food,food,food,food,food,food,food,food,food,food,wall},
    {wall,food,food,food,food,food,food,food,food,food,food,food,food,food,food,food,food,food,food,food,food,food,food,food,food,food,food,food,food,food,food,wall,wall,wall,wall,wall,wall,wall,wall,wall,wall,wall,wall,wall,wall,wall,wall,wall,wall,wall,wall,wall,wall,wall,wall,wall,wall,wall,wall,wall,wall,wall,wall,wall,wall,wall,wall,wall,food,food,food,food,food,food,food,food,food,food,wall},
    {wall,food,food,food,food,food,food,food,food,food,food,food,food,food,food,food,food,food,food,food,food,food,food,food,food,food,food,food,food,food,food,wall,wall,wall,wall,wall,wall,wall,wall,wall,wall,wall,wall,wall,wall,wall,wall,wall,wall,wall,wall,wall,wall,wall,wall,wall,wall,wall,wall,wall,wall,wall,wall,wall,wall,wall,wall,wall,food,food,food,food,food,food,food,food,food,food,wall},
    {wall,food,food,food,food,wall,wall,wall,wall,wall,wall,wall,wall,wall,wall,wall,food,food,food,food,food,food,food,food,food,food,food,food,food,food,food,wall,wall,wall,wall,wall,wall,wall,wall,wall,wall,wall,wall,wall,wall,wall,wall,wall,wall,wall,wall,wall,wall,wall,wall,wall,wall,wall,wall,wall,wall,wall,wall,wall,wall,wall,wall,wall,food,food,food,food,food,food,food,food,food,food,wall},
    {wall,food,food,food,food,wall,wall,wall,wall,wall,wall,wall,wall,wall,wall,wall,food,food,food,food,food,food,food,food,food,food,food,food,food,food,food,food,food,food,food,food,food,food,food,food,food,food,food,food,food,food,food,food,food,food,food,food,food,food,food,food,food,food,food,food,food,food,food,food,food,food,food,food,food,food,food,food,food,food,food,food,food,food,wall},
    {wall,food,food,food,food,wall,wall,wall,wall,wall,wall,wall,wall,wall,wall,wall,food,food,food,food,food,food,food,food,food,food,food,food,food,food,food,food,food,food,food,food,food,food,food,food,food,food,food,food,food,food,food,food,food,food,food,food,food,food,food,food,food,food,food,food,food,food,food,food,food,food,food,wall,wall,wall,wall,wall,wall,food,food,food,food,food,wall},
    {wall,food,food,food,food,food,food,food,food,food,food,food,food,food,food,food,food,food,food,food,food,food,food,food,food,wall,wall,wall,wall,wall,wall,wall,wall,wall,wall,wall,wall,wall,wall,wall,wall,wall,wall,wall,food,food,food,food,food,food,food,food,food,food,food,food,food,food,food,food,food,food,food,food,food,food,food,wall,wall,wall,wall,wall,wall,food,food,food,food,food,wall},
    {wall,food,food,food,food,food,wall,wall,wall,wall,food,food,food,food,food,food,food,food,food,food,food,food,food,food,food,wall,wall,wall,wall,wall,wall,wall,wall,wall,wall,wall,wall,wall,wall,wall,wall,wall,wall,wall,food,wall,wall,wall,wall,wall,wall,wall,wall,wall,wall,wall,wall,wall,wall,wall,wall,wall,wall,wall,wall,wall,food,wall,wall,wall,wall,wall,wall,food,food,food,food,food,wall},
    {wall,food,food,food,food,food,wall,wall,wall,wall,wall,wall,food,food,food,food,food,food,food,food,food,food,food,food,food,wall,wall,wall,food,food,food,food,food,food,food,food,food,food,food,food,food,wall,wall,wall,food,food,food,food,food,food,food,food,food,food,food,food,food,food,food,food,food,food,food,food,food,food,food,wall,wall,wall,wall,wall,wall,food,food,food,food,food,wall},
    {wall,food,food,food,food,food,wall,wall,wall,wall,wall,wall,wall,wall,wall,food,food,food,food,food,food,food,food,food,food,wall,wall,wall,food,food,food,food,wall,wall,wall,wall,wall,food,food,food,food,wall,wall,wall,food,food,food,food,food,food,food,food,food,food,food,food,food,food,food,food,food,food,food,food,food,food,food,wall,wall,wall,wall,wall,wall,food,food,food,food,food,wall},
    {wall,food,food,food,food,food,wall,wall,wall,wall,wall,wall,wall,wall,wall,food,food,food,food,food,food,food,food,food,food,wall,wall,wall,food,food,food,food,wall,wall,wall,wall,wall,food,food,food,food,wall,wall,wall,food,food,food,food,food,food,food,food,food,food,food,food,food,food,food,food,food,food,food,food,food,food,food,wall,wall,wall,wall,wall,wall,food,food,food,food,food,wall},
    {wall,food,food,food,food,food,food,food,food,food,food,food,food,food,food,food,food,food,food,food,food,food,food,food,food,food,food,food,food,food,food,food,food,food,food,food,food,food,food,food,food,food,food,food,food,food,food,food,food,food,food,food,food,food,food,food,food,food,food,food,food,food,food,food,food,food,food,food,food,food,food,food,food,food,food,food,food,food,wall},
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


void gotoxy(short x,short y)
{
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),{y,x});
}

void ColorPrint(const string text, int fg_color, int bg_color)
{
    static const char begin_sequence[]{0x1B,'[','\0'};
    static const char reset[]{0x1B,'[','0','m','\0'};

    cout << begin_sequence << fg_color << ';' << bg_color << 'm' << text << reset;
}

void coutyellow(string s)
{
	ColorPrint(s,33,40);
}
void coutblue(string s)
{
	ColorPrint(s,96,40);
}
void coutred(string s)
{
	ColorPrint(s,31,40);
}
void coutblack(string s)
{
    ColorPrint(s,30,40);
}
void print_map()
{
    for(int i=0;i<row;i++)
    {   
        for(int j= 0 ;j<col;j++)
        {
            if(map[i][j] == wall)
            coutblue(map[i][j]);
            else if(map[i][j]==food)
            coutyellow(map[i][j]);
        
        }
        cout<<endl;
    }
}



int main(){
    
    system("CLS");
    srand(time(0));
    ShowConsoleCursor(false);
    //MAP INITIALIZATION
    print_map();
    gotoxy(0, col+1);
    coutblue("Score: ");
    coutblue(to_string(score));
    
    //PAC INITIALIZATION
    gotoxy(pacman_row,pacman_col);
    
    coutyellow(pacman);
    gotoxy(ghost_row,ghost_col);
    
    coutred(ghost1);
    
    bool alive = true;
    while(alive)
    {
       
        if (GetAsyncKeyState(VK_UP)) {i = -1; j=0;}
        else if (GetAsyncKeyState(VK_DOWN)) { i = 1; j=0;}
        else if (GetAsyncKeyState(VK_RIGHT)) {j = 1; i=0;}
        else if (GetAsyncKeyState(VK_LEFT)) {j = -1; i=0;}

        if(map[pacman_row + i][pacman_col + j]!=wall)
        {
            if(map[pacman_row][pacman_col] == food)
            {
                map[pacman_row][pacman_col] = no_food;
                score++;
            }  
            
            gotoxy(pacman_row,pacman_col);
            coutblack(no_food);
            pacman_row += i;
            pacman_col += j;
            gotoxy(pacman_row,pacman_col);
            coutyellow(pacman);
            
        }   

        if(precedence_count==10) precedence_count = 0;
        if(precedence_count<5){
            
            if(ghost_col<=pacman_col) //GO RIGHT
            { jg = 1; ig = 0; }
            else if(ghost_col>pacman_col) //GO LEFT
            {jg = -1; ig = 0; }
            else if(ghost_row<=pacman_row) //GO DOWN
            { ig = 1; jg = 0; }
            else if(ghost_row>pacman_row) //GO UP
            { ig = -1; jg = 0; }
        }
        else{
            
            if(ghost_row<=pacman_row) //GO DOWN
            { ig = 1; jg = 0; }
            else if(ghost_row>pacman_row) //GO UP
            { ig = -1; jg = 0; }
            else if(ghost_col<=pacman_col) //GO RIGHT
            { jg = 1; ig = 0; }
            else if(ghost_col>pacman_col) //GO LEFT
            {jg = -1; ig = 0; }
            
        }
        precedence_count++;
        if(map[ghost_row + ig][ghost_col + jg]!=wall)
        {
            gotoxy(ghost_row,ghost_col);
            if(map[ghost_row][ghost_col] == food) coutyellow(food);
            else coutblack(no_food);
            ghost_row += ig;
            ghost_col += jg;
            gotoxy(ghost_row,ghost_col);
            coutred(ghost1);
        }
        else
        {
             if(jg == 1)//GO RIGHT
            {
                if(ghost_row<=pacman_row){ 
                    if(map[ghost_row+1][ghost_col]!=wall){ k = 1; l = 0;} //DOWN
                    else if(map[ghost_row-1][ghost_col]!=wall){ k = -1; l=0;} //UP
                    else if(map[ghost_row][ghost_col-1]!=wall){ k = 0; l = -1;} //LEFT
                }
                else{
                    if(map[ghost_row-1][ghost_col]!=wall){k = -1; l=0;} //UP
                    else if(map[ghost_row+1][ghost_col]!=wall){k = 1; l = 0;} //DOWN
                    else if(map[ghost_row][ghost_col-1]!=wall){k = 0; l = -1;} //LEFT
                }
            }
            else if(jg == -1) // GO LEFT
            {
                if(ghost_row<=pacman_row){
                    if(map[ghost_row+1][ghost_col]!=wall){ k = 1; l = 0;} //DOWN
                    else if(map[ghost_row-1][ghost_col]!=wall){ k = -1; l=0;} //UP
                    else if(map[ghost_row][ghost_col+1]!=wall){ k = 0; l = 1;} //RIGHT
                }
                else{
                    if(map[ghost_row-1][ghost_col]!=wall){k = -1; l=0;} //UP
                    else if(map[ghost_row+1][ghost_col]!=wall){k = 1; l = 0;} //DOWN
                    else if(map[ghost_row][ghost_col+1]!=wall){k = 0; l = 1;} //RIGHT
                }
            }
            else if(ig==-1)// GO UP
            {
                if(ghost_col<=pacman_col){
                    if(map[ghost_row][ghost_col+1]!=wall){ k = 0; l = 1;} //RIGHT
                    else if(map[ghost_row][ghost_col-1]!=wall){ k = 0; l=-1;} //LEFT
                    else if(map[ghost_row+1][ghost_col]!=wall){ k = 1; l = 0;} //DOWN
                }
                else{
                    if(map[ghost_row][ghost_col-1]!=wall){k = 0; l=-1;} //LEFT
                    else if(map[ghost_row][ghost_col+1]!=wall){k = 0; l = 1;} //RIGHT
                    else if(map[ghost_row+1][ghost_col]!=wall){k = 1; l = 0;} //DOWN
                }
            }
            else if(ig==1)// GO DOWN
            {
                if(ghost_col<=pacman_col){
                    if(map[ghost_row][ghost_col+1]!=wall){ k = 0; l = 1;} //RIGHT
                    else if(map[ghost_row][ghost_col-1]!=wall){ k = 0; l=-1;} //LEFT
                    else if(map[ghost_row-1][ghost_col]!=wall){ k = -1; l = 0;} //UP
                }
                else{
                    if(map[ghost_row][ghost_col-1]!=wall){k = 0; l=-1;} //RIGHT
                    else if(map[ghost_row][ghost_col+1]!=wall){k = 0; l = 1;} //LEFT
                    else if(map[ghost_row-1][ghost_col]!=wall){k = -1; l = 0;} //UP
                }
            }

            gotoxy(ghost_row,ghost_col);
            if(map[ghost_row][ghost_col] == food) coutyellow(food);
            else coutblack(no_food);
            ghost_row += k;
            ghost_col += l;
            gotoxy(ghost_row,ghost_col);
            coutred(ghost1);
            }
    
    
        if((pacman_row == ghost_row && pacman_col == ghost_col))
        {
            alive = false;
        }
        
        gotoxy(0, col+8);
        coutblue(to_string(score));
       
        Sleep(40);
    }


    gotoxy(row+2,4);
    coutred("You Failed. Your score was: ");
    coutblue(to_string(score));
    return 0;
}

