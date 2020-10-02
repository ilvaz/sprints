#include <ncurses.h>
#include "locale.h"
#include <unistd.h>
#include <stdlib.h>

#define DELAY 300000

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct s_str
{
    char *s;
    int x;
    int y;
}               t_str;

char *mx_strnew(const int size){
    char *s = malloc(size + 1);
    for (int i = 0; i <= size; i++) {
        s[i] = '\0';
    }
    return s;
}

int mx_strlen(const char *s) {
	int i = 0;
	while (s[i] != '\0') {
		i++;
	}
	return i;
}

char *mx_strdup(const char *str) {
    int i = 0; 
    while (str[i] != '\0') {
        i++;
    }
    char *result = malloc(i + 1);
    for (int j = 0; j <= i; j++) {
        result[j] = str[j];
    }
    result[i + 1] = '\0';
    return result;
}

char *mx_strcat(char *s1, const char *s2) {
    int l = mx_strlen(s1);
    int i;
    for(i = 0; s2[i] != '\0'; i++) {
        s1[l + i] = s2[i];
    }
    s1[l + i] = '\0';
    return s1;
}

char *mx_strjoin(const char *s1, const char *s2) {
    int size = mx_strlen(s1) + mx_strlen(s2);
    char *result = mx_strnew(size);
    result = mx_strdup(s1);
    mx_strcat(result, s2);
    result[size] = '\0';
    return result;
}

char *mx_addchar(char *s, char c)  {
    int size = mx_strlen(s) + 1;
    char *result = mx_strnew(size);
    result = mx_strdup(s);
    result[size - 1] = c;
    result[size] = '\0';
    return result;
}

char get_random_num(void)
{
	return 33 + (random() % 94);
}

int main()
{	
    
    setlocale(LC_ALL, "");
    
    int x = 0;
    int y = 0;
    int max_y = 0;
    int max_x = 0;
    int next_y = 0;
    int direction = 1;

	initscr();
    noecho(); // Don't echo any keypresses
    curs_set(FALSE); // Don't display a cursor

    getmaxyx(stdscr, max_y, max_x);

    start_color();
    init_pair(1, COLOR_GREEN, COLOR_BLACK);
    init_pair(2, COLOR_WHITE, COLOR_BLACK);
    attron(COLOR_PAIR(1));
    
    char *s = " ";
    int i = 0;
    char b = '0';
    char tmp;
    while(1) {
        clear();
        for (int j = i - 1; j >= 0; j--) {
            if (j == 1) {
                attron(COLOR_PAIR(2));
            } else {
                attron(COLOR_PAIR(1));
            }
            if(j < mx_strlen(s)) {
                char c = s[j];
                move(y - j, x);
                addch(c);
                b = get_random_num();
                //addch(y - j, x, &c);
                //mvprintw(y - j, x, &c);
                if (mx_strlen(s) < 6) {
                    s = mx_addchar(s, b);
                }
            }
        }   
        //mvprintw(y, x, s); // Print our "ball" at the current xy position
        refresh();
        usleep(DELAY); // Shorter delay between movements
        if (mx_strlen(s) < 3) {
            //s = mx_strjoin(s, "\no");
        }

        next_y = y + direction;

        if(next_y >= max_y || next_y < 0) {
            y = 0;
            x += 3;
            i = 0;
            s = " ";
           
        } else {
            y += direction;
        }
        if (i < mx_strlen(s)) {
            i++;
        } 
    }
    
    endwin();
	return 0;
}
