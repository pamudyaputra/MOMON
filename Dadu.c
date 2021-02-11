
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>
#include <math.h>


int dice(void)
{
    // Use current time as seed for random generator
    srand(time(0));
 	int i;
 	int dice = 0;
 	
    for(i = 0; i < 2; i++) {
       dice += (rand() % 6) + 1;
 	}
    return dice;
}
