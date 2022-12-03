while(alive)
    // {
    //     i = 0;
    //     j = 0;
    //     if (GetAsyncKeyState(VK_UP)) i = -1;
    //     else if (GetAsyncKeyState(VK_DOWN)) i = 1;
    //     else if (GetAsyncKeyState(VK_RIGHT)) j = 1;
    //     else if (GetAsyncKeyState(VK_LEFT)) j = -1;

    //     if(pacman_row < 23 && pacman_row > 1 && pacman_col > 1 && pacman_col < 78 && map[pacman_row + i][pacman_col + j]!=wall){
    //         if(map[pacman_row][pacman_col] == ".")
    //         {
    //             map[pacman_row][pacman_col] = " ";
    //             score++;
    //         }  
    //         pacman_row += i;
    //         pacman_col += j;
    //         gotoxy(pacman_row,pacman_col);
    //         cout<<pacman;
    //     }

        
        
    //     /*if(new_xg<new_x) //GO RIGHT
    //     {
    //         ig = 1;
    //         jg = 0;
    //     }
    //     else if(new_xg>new_x) //GO LEFT
    //     {
    //         ig = -1;
    //         jg = 0;
    //     }
    //     else if(new_yg<new_y) //GO DOWN
    //     {
    //         ig = 0;
    //         jg = 1;
    //     }
    //     else if(new_yg>new_y) //GO UP
    //     {
    //         ig = 0;
    //         jg = -1;
    //     }
        
    //     new_xg = old_xg+ig;
    //     new_yg = old_yg+jg;

    //     if(map[new_yg][new_xg]!= wall)
    //     {
    //         gotoxy(new_xg,new_yg);
    //         cout<<g1;
    //         gotoxy(old_xg,old_yg);
    //         if(map[old_yg][old_xg] ==".")
    //             cout<<".";
    //         else
    //             cout<<" ";  
            
    //     }
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
    //     gotoxy(0, col+8);
    //     cout<<score;
    //     Sleep(250);
    // }

