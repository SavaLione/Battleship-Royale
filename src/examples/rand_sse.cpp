#include <time.h>

#include "rand_sse.h"

int main()
{
    srand_sse(time(NULL));

    unsigned int u_i_random[4];
    rand_sse(u_i_random);
    
    return 0;
}