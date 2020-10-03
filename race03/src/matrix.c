#include "matrix.h"

int main()
{	
    setlocale(LC_ALL, "");
    
    int max_y = 0;
    int max_x = 0;

	initscr();
    noecho(); 
    curs_set(FALSE);

    getmaxyx(stdscr, max_y, max_x);

    start_color();
    init_pair(1, COLOR_GREEN, COLOR_BLACK);
    init_pair(2, COLOR_WHITE, COLOR_BLACK);

    attron(COLOR_PAIR(1));
    
    int size = 0;
    t_str **m = mx_generate_matrix(&size, max_y, max_x);
    //size -= 1;

    nodelay(stdscr, TRUE);

    while(1) {
        clear();
       
        for (int i = 0; i < size; i++) {
            mx_up_case(m[i]);
        }

        refresh();
        usleep(DELAY);

        for (int i = 0; i < size; i++) {
            mx_down_case(m[i], max_y);
        }

       for (int i = 0; i < size ; i++) {
            if (m[i]->end < 0) {
                //free(m[i]->s);
                free(m[i]);
                m[i] = mx_generate_str(max_y, max_x);
            }
        }
        if (getch() == 'q') {
		    break;
        }
    }
    endwin();
	return 0;
}
