#include "config.h"

void get(char *in, char *out)
{
        int did = *in++; //device id
        int vid = *in; //variable id
        *out++ = 0;
        *out = devices[did].values[vid];
}
