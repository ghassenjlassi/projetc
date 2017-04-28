#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/times.h>
#include <termios.h>
#include <unistd.h>

/** \file getKey.c
 */

int getKey(void) {
	struct termios oldattr, newattr;
	int ch;
	tcgetattr( STDIN_FILENO, &oldattr );
	newattr = oldattr;
	newattr.c_lflag &= ~( ICANON | ECHO );
	tcsetattr( STDIN_FILENO, TCSANOW, &newattr );
	ch = getchar();
	tcsetattr( STDIN_FILENO, TCSANOW, &oldattr );
	return ch;
}
