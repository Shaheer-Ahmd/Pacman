#include <iostream>
#include <windows.h>
#include <time.h>
#include <cstdlib>
#include <stdlib.h>
#include <cmath>
using namespace std;

const int row = 24;
const int col = 80;
const string wall = "#";
const string pac = "@";
const string g1 = "G";
//string map[row][col];
string map[25][80]=
	{
		{wall,wall,wall,wall,wall,wall,wall,wall,wall,wall,wall,wall,wall,wall,wall,wall,wall,wall,wall,wall,wall,wall,wall,wall,wall,wall,wall,wall,wall,wall,wall,wall,wall,wall,wall,wall,wall,wall,wall,wall,wall,wall,wall,wall,wall,wall,wall,wall,wall,wall,wall,wall,wall,wall,wall,wall,wall,wall,wall,wall,wall,wall,wall,wall,wall,wall,wall,wall,wall,wall,wall,wall,wall,wall,wall,wall,wall,wall,wall},
		{wall,".",".",".",".",".",".",".",".",".",".",".",".",".",".",".",".",".",".",".",".",".",".",".",".",".",".",".",".",".",".",".",".",".",".",".",".",".",".",".",".",".",".",".",".",".",".",".",".",".",".",".",".",".",".",".",".",".",".",".",".",".",".",".",".",".",".",".",".",".",".",".",".",".",".",".",".",".",wall},
		{wall,".",".",".",wall,wall,wall,wall,wall,wall,wall,wall,wall,wall,wall,".",".",".",".",".",".",".",".",".",".",".",".",".",wall,wall,wall,wall,wall,wall,wall,wall,wall,wall,wall,".",".",".",".",".",".",".",".",".",".",".",".",".",".",".",".",".",".",wall,wall,wall,wall,wall, wall,wall,wall,wall,wall,".",".",".",".",".",".",".",".",".",".",wall},
		{wall,".",".",".",wall,wall,wall,wall,wall,wall,wall,wall,wall,wall,wall,".",".",".",".",".",".",".",".",".",".",".",".",".",wall,wall,wall,wall,wall,wall,wall,wall,wall,wall,wall,".",".",".",".",".",".",".",".",".",".",".",".",".",".",".",".",".",".",wall,".",".",".",wall,".",wall,".",".",".",wall,".",".",".",".",".",".",".",".",".",".",wall},
		{wall,".",".",".",wall,wall,".",".",".",".",".",".",".",".",".",".",".",".",".",".",".",".",".",".",".",".",".",".",wall,wall,wall,wall,wall,wall,wall,wall,wall,wall,wall,".",".",".",".",".",".",".",".",".",".",".",".",".",".",".",".",".",".",wall,".",".",".",".",".",".",".",".",".",wall,".",".",".",".",".",".",".",".",".",".",wall},
		{wall,".",".",".",wall,wall,".",wall,wall,wall,wall,wall,wall,wall,wall,".",".",".",".",".",".",".",".",".",".",".",".",".",wall,wall,wall,wall,wall,wall,wall,wall,wall,wall,wall,".",".",".",".",".",".",".",".",".",".",".",".",".",".",".",".",".",".",wall,".",".",".",wall,".",wall,".",".",".",wall,".",".",".",".",".",".",".",".",".",".",wall},
		{wall,".",".",".",wall,wall,".",".",".",".",".",".",".",".",".",".",".",".",".",".",".",".",".",".",".",".",".",".",wall,wall,wall,wall,wall,wall,wall,wall,wall,wall,wall,".",".",".",".",".",".",".",".",".",".",".",".",".",".",".",".",".",".",wall,wall,wall,wall,wall, wall,wall,wall,wall,wall,".",".",".",".",".",".",".",".",".",".",wall},
		{wall,".",".",".",wall,wall,wall,wall,wall,wall,wall,wall,wall,wall,wall,".",".",".",".",".",".",".",".",".",".",".",".",".",".",".",".",".",".",".",".",".",".",".",".",".",".",".",".",".",".",".",".",".",".",".",".",".",".",".",".",".",".",".",".",".",".",".",".",".",".",".",".",".",".",".",".",".",".",".",".",".",".",".",wall},
		{wall,".",".",".",wall,wall,wall,wall,wall,wall,wall,wall,wall,wall,wall,".",".",".",".",".",".",".",".",".",".",".",".",".",".",".",wall,wall,wall,wall,wall,wall,wall,wall,wall,".",".",".",".",".",".",".",".",".",".",".",".",wall,wall,wall,wall,wall,wall,wall,wall,wall,".",".",".",".",".",".",".",".",".",".",".",".",".",".",".",".",".",".",wall},
		{wall,".",".",".",".",".",".",".",".",".",".",".",".",wall,wall,".",".",".",".",".",".",".",".",".",".",".",".",".",".",".",wall,wall,wall,wall,wall,wall,wall,wall,wall,".",".",".",".",".",".",".",".",".",".",".",".",wall,wall,wall,wall,wall,wall,wall,wall,wall,".",".",".",".",".",".",".",".",".",".",".",".",".",".",".",".",".",".",wall},
		{wall,".",".",".",wall,wall,wall,wall,wall,wall,wall,wall,wall,wall,wall,".",".",".",".",".",".",".",".",".",".",".",".",".",".",".",wall,wall,wall,wall,wall,wall,wall,wall,wall,".",".",".",".",".",".",".",".",".",".",".",".",wall,wall,wall,wall,wall,wall,wall,wall,wall,".",".",".",".",".",".",".",".",".",".",".",".",".",".",".",".",".",".",wall},
		{wall,".",".",".",wall,wall,wall,wall,wall,wall,wall,wall,wall,wall,wall,".",".",".",".",".",".",".",".",".",".",".",".",".",".",".",".",".",".",".",".",".",".",".",".",".",".",".",".",".",".",".",".",".",".",".",".",".",".",".",".",".",".",".",".",".",".",".",".",".",".",".",".",".",".",".",".",".",".",".",".",".",".",".",wall},
		{wall,".",".",".",".",".",".",".",".",".",".",".",".",".",".",".",".",".",".",".",".",".",".",".",".",".",".",".",".",".",".",wall,wall,wall,wall,wall,wall,wall,wall,wall,wall,wall,wall,wall,wall,wall,wall,wall,wall,wall,wall,wall,wall,wall,wall,wall,wall,wall,wall,wall,wall,wall,wall,wall,wall,wall,wall,wall,".",".",".",".",".",".",".",".",".",".",wall},
		{wall,".",".",".",".",".",".",".",".",".",".",".",".",".",".",".",".",".",".",".",".",".",".",".",".",".",".",".",".",".",".",wall,wall,wall,wall,wall,wall,wall,wall,wall,wall,wall,wall,wall,wall,wall,wall,wall,wall,wall,wall,wall,wall,wall,wall,wall,wall,wall,wall,wall,wall,wall,wall,wall,wall,wall,wall,wall,".",".",".",".",".",".",".",".",".",".",wall},
		{wall,".",".",".",".",wall,wall,wall,wall,wall,wall,wall,wall,wall,wall,wall,".",".",".",".",".",".",".",".",".",".",".",".",".",".",".",wall,wall,wall,wall,wall,wall,wall,wall,wall,wall,wall,wall,wall,wall,wall,wall,wall,wall,wall,wall,wall,wall,wall,wall,wall,wall,wall,wall,wall,wall,wall,wall,wall,wall,wall,wall,wall,".",".",".",".",".",".",".",".",".",".",wall},
		{wall,".",".",".",".",wall,wall,wall,wall,wall,wall,wall,wall,wall,wall,wall,".",".",".",".",".",".",".",".",".",".",".",".",".",".",".",".",".",".",".",".",".",".",".",".",".",".",".",".",".",".",".",".",".",".",".",".",".",".",".",".",".",".",".",".",".",".",".",".",".",".",".",".",".",".",".",".",".",".",".",".",".",".",wall},
		{wall,".",".",".",".",wall,wall,wall,wall,wall,wall,wall,wall,wall,wall,wall,".",".",".",".",".",".",".",".",".",".",".",".",".",".",".",".",".",".",".",".",".",".",".",".",".",".",".",".",".",".",".",".",".",".",".",".",".",".",".",".",".",".",".",".",".",".",".",".",".",".",".",wall,wall,wall,wall,wall,wall,".",".",".",".",".",wall},
		{wall,".",".",".",".",".",".",".",".",".",".",".",".",".",".",".",".",".",".",".",".",".",".",".",".",wall,wall,wall,wall,wall,wall,wall,wall,wall,wall,wall,wall,wall,wall,wall,wall,wall,wall,wall,".",".",".",".",".",".",".",".",".",".",".",".",".",".",".",".",".",".",".",".",".",".",".",wall,wall,wall,wall,wall,wall,".",".",".",".",".",wall},
		{wall,".",".",".",".",".",wall,wall,wall,wall,".",".",".",".",".",".",".",".",".",".",".",".",".",".",".",wall,wall,wall,wall,wall,wall,wall,wall,wall,wall,wall,wall,wall,wall,wall,wall,wall,wall,wall,".",wall,wall,wall,wall,wall,wall,wall,wall,wall,wall,wall,wall,wall,wall,wall,wall,wall,wall,wall,wall,wall,".",wall,wall,wall,wall,wall,wall,".",".",".",".",".",wall},
		{wall,".",".",".",".",".",wall,wall,wall,wall,wall,wall,".",".",".",".",".",".",".",".",".",".",".",".",".",wall,wall,wall,".",".",".",".",".",".",".",".",".",".",".",".",".",wall,wall,wall,".",".",".",".",".",".",".",".",".",".",".",".",".",".",".",".",".",".",".",".",".",".",".",wall,wall,wall,wall,wall,wall,".",".",".",".",".",wall},
		{wall,".",".",".",".",".",wall,wall,wall,wall,wall,wall,wall,wall,wall,".",".",".",".",".",".",".",".",".",".",wall,wall,wall,".",".",".",".",wall,wall,wall,wall,wall,".",".",".",".",wall,wall,wall,".",".",".",".",".",".",".",".",".",".",".",".",".",".",".",".",".",".",".",".",".",".",".",wall,wall,wall,wall,wall,wall,".",".",".",".",".",wall},
		{wall,".",".",".",".",".",wall,wall,wall,wall,wall,wall,wall,wall,wall,".",".",".",".",".",".",".",".",".",".",wall,wall,wall,".",".",".",".",wall,wall,wall,wall,wall,".",".",".",".",wall,wall,wall,".",".",".",".",".",".",".",".",".",".",".",".",".",".",".",".",".",".",".",".",".",".",".",wall,wall,wall,wall,wall,wall,".",".",".",".",".",wall},
		{wall,".",".",".",".",".",".",".",".",".",".",".",".",".",".",".",".",".",".",".",".",".",".",".",".",".",".",".",".",".",".",".",".",".",".",".",".",".",".",".",".",".",".",".",".",".",".",".",".",".",".",".",".",".",".",".",".",".",".",".",".",".",".",".",".",".",".",".",".",".",".",".",".",".",".",".",".",".",wall},
		{wall,wall,wall,wall,wall,wall,wall,wall,wall,wall,wall,wall,wall,wall,wall,wall,wall,wall,wall,wall,wall,wall,wall,wall,wall,wall,wall,wall,wall,wall,wall,wall,wall,wall,wall,wall,wall,wall,wall,wall,wall,wall,wall,wall,wall,wall,wall,wall,wall,wall,wall,wall,wall,wall,wall,wall,wall,wall,wall,wall,wall,wall,wall,wall,wall,wall,wall,wall,wall,wall,wall,wall,wall,wall,wall,wall,wall,wall,wall}}
	;
void gotoxy(short x,short y)
{
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),{x,y});
}

void make_map(string arr[][col])
{
    for (int i = 0;i < row;i++)
    {
        for (int j = 0;j < col;j++)
        {
            if (i == 0 || j == 0)
            {
                arr[i][j] = wall;
            }
            else if (i == row - 1 || j == col - 1)
            {
                arr[i][j] = wall;
            }
            else arr[i][j] = ".";
        }
    }
}

void show_arr(string map[][col])
{
    for(int i=0;i<row;i++)
    {   
        for(int j= 0 ;j<col;j++)
        {
        cout<<map[i][j];
        
        }
        cout<<endl;
    }
}

int main()
{   
    system("CLS");
    srand(time(0));
    show_arr(map);
    short x = rand() % (col - 2) + 1;
    short y = row-2;
    short gx = rand() % (col - 2) + 1;
    short gy = 1;
    
    //PAC INITIALIZATION
    gotoxy(x,y);
    cout<<pac;
    int i=0,j=-1,score = 0;
    gotoxy(col+1,0);
    cout<<"Score: "<<score;
    short old_x = x, old_y = y, new_x = x,new_y = y;

    //GHOST INITIALIZATION
    short xg = rand() % (col-2) +1;
    short yg = 1;
    gotoxy(xg,yg);
    cout<<g1;
    int ig = 0, jg = 0;
    short old_xg = xg, old_yg = yg, new_xg = xg,new_yg = yg;
    bool alive = true;
    while(alive)
    {
        if (GetAsyncKeyState(VK_UP))
        {
            i = 0;
            j = -1;
        }
        else if (GetAsyncKeyState(VK_DOWN))
        {
            i = 0;
            j = 1;
        }
        else if (GetAsyncKeyState(VK_RIGHT))
        {
            i = 1;
            j = 0;
        }
        else if (GetAsyncKeyState(VK_LEFT))
        {
            i = -1;
            j = 0;
        }
        new_x = old_x+i;
        new_y = old_y+j;
        if(map[new_y][new_x]!=wall)
        {
            gotoxy(new_x,new_y);
            cout<<pac;
            gotoxy(old_x,old_y);
            if(map[old_y][old_x] == ".")
            {
                map[old_y][old_x] = " ";
                score++;
            }
            cout<<" ";
            old_x = new_x;
            old_y = new_y;
        }
        
        
        if(new_xg<new_x) //GO RIGHT
        {
            ig = 1;
            jg = 0;
        }
        else if(new_xg>new_x) //GO LEFT
        {
            ig = -1;
            jg = 0;
        }
        else if(new_yg<new_y) //GO DOWN
        {
            ig = 0;
            jg = 1;
        }
        else if(new_yg>new_y) //GO UP
        {
            ig = 0;
            jg = -1;
        }
        
        new_xg = old_xg+ig;
        new_yg = old_yg+jg;

        if(map[new_yg][new_xg]!= wall)
        {
            gotoxy(new_xg,new_yg);
            cout<<g1;
            gotoxy(old_xg,old_yg);
            if(map[old_yg][old_xg] ==".")
                cout<<".";
            else
                cout<<" ";  
            
        }
        else
        {   gotoxy(0,40) ; cout<< "In the wall check!";

            if(ig == 1)//WALL ON RIGHT 
            {   
                cout<<"\n"<<"Wall on right before"<<new_xg<<" "<<new_yg;
                if(new_yg>new_y)
                {
                    new_yg -= 1;
                }
                else if(new_yg<new_y)
                {
                    new_yg += 1;
                }
                cout<<"\n"<<"Wall on right after"<<new_xg<<" "<<new_yg;
                new_xg -= 1;
                gotoxy(new_xg,new_yg);
                cout<<g1;
            }
            else if( ig == -1) //wall on left
            {
                new_xg += 1;
                if(new_yg>new_y)
                {
                    new_yg -= 1;
                }
                else if(new_yg<new_y)
                {
                    new_yg += 1;
                }
                gotoxy(new_xg,new_yg);
                cout<<g1;
            }
            else if( jg == 1) // wall below
            {
                new_yg -= 1;
                if(new_xg<new_x)
                {
                    new_xg += 1;
                }
                else if(new_xg>new_x)
                {
                    new_xg -= 1;
                }
                gotoxy(new_xg,new_yg);
                cout<<g1;
            }
            else if( jg == -1) // WALL UP
            {   
                new_yg += 1;
                if(new_xg<new_x)
                {
                    new_xg += 1;
                }
                else if(new_xg>new_x)
                {
                    new_xg -= 1;
                }
                gotoxy(new_xg,new_yg);
                cout<<g1;
                
            }

            //gotoxy(new_xg-ig,new_yg-jg);
            gotoxy(old_yg,old_xg);
            if(map[old_yg][old_xg] ==".")
                cout<<".";
            else
                cout<<" "; 
        }

        old_xg = new_xg;
        old_yg = new_yg;
       
       
        gotoxy(0,50);
        printf("Ghost's Position (%i,%i)",new_xg,new_yg);
        cout<<endl;
        printf("Pac's Position (%i,%i)",new_x,new_y);
        // int d = sqrt(pow(new_xg-new_x,2)+pow(new_yg-new_y,2));
        // cout<<"d: "<<d;
        if((new_x == new_xg && new_y == new_yg) || (new_x == new_xg-ig && new_y == new_yg - jg))
        {
            alive = false;
        }
        gotoxy(col+8,0);
        cout<<score;
        Sleep(250);
    }
    system("CLS");
    cout<<"You Failed .Your score was: "<<score;
}