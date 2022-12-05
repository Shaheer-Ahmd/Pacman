            
            if(ghost_row<=pacman_row) //GO DOWN
            { ig = 1; jg = 0; }
            else if(ghost_row>pacman_row) //GO UP
            { ig = -1; jg = 0; }
            else if(ghost_col<=pacman_col) //GO RIGHT
            { jg = 1; ig = 0; }
            else if(ghost_col>pacman_col) //GO LEFT