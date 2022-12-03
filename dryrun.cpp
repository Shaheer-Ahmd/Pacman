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
const string food = ".";
const string no_food = " ";
const string pacman = "@";
const string ghost1 = "G";

short pacman_col = rand() % (col - 2) + 1;
short pacman_row = row-2;
short ghost_col = rand() % (col - 2) + 1;
short ghost_row = 1;
int score = 0;

string map[row][col] = {
    {wall,wall,wall,wall,wall,wall,wall,wall,wall,wall,wall,wall,wall,wall,wall,wall,wall,wall,wall,wall,wall,wall,wall,wall,wall,wall,wall,wall,wall,wall,wall,wall,wall,wall,wall,wall,wall,wall,wall,wall,wall,wall,wall,wall,wall,wall,wall,wall,wall,wall,wall,wall,wall,wall,wall,wall,wall,wall,wall,wall,wall,wall,wall,wall,wall,wall,wall,wall,wall,wall,wall,wall,wall,wall,wall,wall,wall,wall,wall},
    {wall,food,food,food,food,food,food,food,food,food,food,food,food,food,food,food,food,food,food,food,food,food,food,food,food,food,food,food,food,food,food,food,food,food,food,food,food,food,food,food,food,food,food,food,food,food,food,food,food,food,food,food,food,food,food,food,food,food,food,food,food,food,food,food,food,food,food,food,food,food,food,food,food,food,food,food,food,food,wall},
    {wall,food,food,food,wall,wall,wall,wall,wall,wall,wall,wall,wall,wall,wall,food,food,food,food,food,food,food,food,food,food,food,food,food,wall,wall,wall,wall,wall,wall,wall,wall,wall,wall,wall,food,food,food,food,food,food,food,food,food,food,food,food,food,food,food,food,food,food,wall,wall,wall,wall,wall, wall,wall,wall,wall,wall,food,food,food,food,food,food,food,food,food,food,wall},
    {wall,food,food,food,wall,wall,wall,wall,wall,wall,wall,wall,wall,wall,wall,food,food,food,food,food,food,food,food,food,food,food,food,food,wall,wall,wall,wall,wall,wall,wall,wall,wall,wall,wall,food,food,food,food,food,food,food,food,food,food,food,food,food,food,food,food,food,food,wall,food,food,food,wall,food,wall,food,food,food,wall,food,food,food,food,food,food,food,food,food,food,wall},
    {wall,food,food,food,wall,wall,food,food,food,food,food,food,food,food,food,food,food,food,food,food,food,food,food,food,food,food,food,food,wall,wall,wall,wall,wall,wall,wall,wall,wall,wall,wall,food,food,food,food,food,food,food,food,food,food,food,food,food,food,food,food,food,food,wall,food,food,food,food,food,food,food,food,food,wall,food,food,food,food,food,food,food,food,food,food,wall},
    {wall,food,food,food,wall,wall,food,wall,wall,wall,wall,wall,wall,wall,wall,food,food,food,food,food,food,food,food,food,food,food,food,food,wall,wall,wall,wall,wall,wall,wall,wall,wall,wall,wall,food,food,food,food,food,food,food,food,food,food,food,food,food,food,food,food,food,food,wall,food,food,food,wall,food,wall,food,food,food,wall,food,food,food,food,food,food,food,food,food,food,wall},
    {wall,food,food,food,wall,wall,food,food,food,food,food,food,food,food,food,food,food,food,food,food,food,food,food,food,food,food,food,food,wall,wall,wall,wall,wall,wall,wall,wall,wall,wall,wall,food,food,food,food,food,food,food,food,food,food,food,food,food,food,food,food,food,food,wall,wall,wall,wall,wall, wall,wall,wall,wall,wall,food,food,food,food,food,food,food,food,food,food,wall},
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

void gotoxy(short x,short y)
{
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),{y,x});
}

void print_map()
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

int main(){

    int i = 0;    int j = 0;    int ig = 0;    int jg = 0; int col_precedence_count = 0; int row_precedence_count = 0;
    system("CLS");
    srand(time(0));
    
    //MAP INITIALIZATION
    print_map();
    gotoxy(0, col+1);
    cout<<"Score: "<<score;
    
    //PAC INITIALIZATION
    gotoxy(pacman_row,pacman_col);
    cout<<pacman;

    //GHOST INITIALIZATION
    gotoxy(ghost_row,ghost_col);
    cout<<ghost1;
    
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
            cout<<no_food;
            pacman_row += i;
            pacman_col += j;
            gotoxy(pacman_row,pacman_col);
            cout<<pacman;
        }

        
        if(col_precedence_count!=5){
            row_precedence_count = 0;
            if(ghost_col<pacman_col) //GO RIGHT
            { jg = 1; ig = 0; }
            else if(ghost_col>pacman_col) //GO LEFT
            {jg = -1; ig = 0; }
            else if(ghost_row<pacman_row) //GO DOWN
            { ig = 1; jg = 0; }
            else if(ghost_row<pacman_row) //GO UP
            { ig = 0; jg = -1; }
            col_precedence_count ++;
        }
        else if(row_precedence_count!=5){
            col_precedence_count = 0;
            if(ghost_row<pacman_row) //GO DOWN
            { ig = 1; jg = 0; }
            else if(ghost_row<pacman_row) //GO UP
            { ig = 0; jg = -1; }
            else if(ghost_col<pacman_col) //GO RIGHT
            { jg = 1; ig = 0; }
            else if(ghost_col>pacman_col) //GO LEFT
            {jg = -1; ig = 0; }
            row_precedence_count ++;
        }

        
        
        
        if(map[ghost_row + ig][ghost_col + jg]!=wall)
        {
            gotoxy(ghost_row,ghost_col);
            if(map[ghost_row][ghost_col] == food) cout<<food;
            else cout<<" ";
            ghost_row += ig;
            ghost_col += jg;
            gotoxy(ghost_row,ghost_col);
            cout<<ghost1;
        }
        else
        {
            if(jg==1)//GO RIGHT
            {
                if(ghost_row<pacman_row){
                    if(map[ghost_row+1][ghost_col]!=wall){}
                    else if(map[ghost_row-1][ghost_col]!=wall){}
                    else if(map[ghost_row][ghost_col-1]!=wall){}
                }
                else{
                    if(map[ghost_row-1][ghost_col]!=wall){}
                    else if(map[ghost_row+1][ghost_col]!=wall){}
                    else if(map[ghost_row][ghost_col-1]!=wall){}
                }
            }
        }
    
    //     else
    //     {   gotoxy(0,40) ; cout<< "In the wall check!";

    //         if(ig == 1)//WALL ON RIGHT 
    //         {   
    //             cout<<"\n"<<"Wall on right before"<<new_xg<<" "<<new_yg;
    //             if(new_yg>new_y)
    //             {
    //                 new_yg -= 1;
    //             }
    //             else if(new_yg<new_y)
    //             {
    //                 new_yg += 1;
    //             }
    //             cout<<"\n"<<"Wall on right after"<<new_xg<<" "<<new_yg;
    //             new_xg -= 1;
    //             gotoxy(new_xg,new_yg);
    //             cout<<g1;
    //         }
    //         else if( ig == -1) //wall on left
    //         {
    //             new_xg += 1;
    //             if(new_yg>new_y)
    //             {
    //                 new_yg -= 1;
    //             }
    //             else if(new_yg<new_y)
    //             {
    //                 new_yg += 1;
    //             }
    //             gotoxy(new_xg,new_yg);
    //             cout<<g1;
    //         }
    //         else if( jg == 1) // wall below
    //         {
    //             new_yg -= 1;
    //             if(new_xg<new_x)
    //             {
    //                 new_xg += 1;
    //             }
    //             else if(new_xg>new_x)
    //             {
    //                 new_xg -= 1;
    //             }
    //             gotoxy(new_xg,new_yg);
    //             cout<<g1;
    //         }
    //         else if( jg == -1) // WALL UP
    //         {   
    //             new_yg += 1;
    //             if(new_xg<new_x)
    //             {
    //                 new_xg += 1;
    //             }
    //             else if(new_xg>new_x)
    //             {
    //                 new_xg -= 1;
    //             }
    //             gotoxy(new_xg,new_yg);
    //             cout<<g1;
                
    //         }

    //         //gotoxy(new_xg-ig,new_yg-jg);
    //         gotoxy(old_yg,old_xg);
    //         if(map[old_yg][old_xg] ==".")
    //             cout<<".";
    //         else
    //             cout<<" "; 
    //     }

    //     old_xg = new_xg;
    //     old_yg = new_yg;
    //    */
       
    //     //gotoxy(0,50);
    //     // printf("Ghost's Position (%i,%i)",new_xg,new_yg);
    //     // cout<<endl;
    //     // printf("Pac's Position (%i,%i)",new_x,new_y);
    //     // int d = sqrt(pow(new_xg-new_x,2)+pow(new_yg-new_y,2));
    //     // cout<<"d: "<<d;
    //     // if((new_x == new_xg && new_y == new_yg) || (new_x == new_xg-ig && new_y == new_yg - jg))
    //     // {
    //     //     alive = false;
    //     // }
        gotoxy(0, col+8);
        cout<<score;
        Sleep(250);
    }


    system("CLS");
    cout<<"You Failed .Your score was: "<<score;
    return 0;
}