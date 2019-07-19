#include "config.h"

void set(char *in, char *out)
{
        int did = *in++; //device id
        int vid = *in++; //variable id
        int val = *in;
        *out = 0;
        devices[did].values[vid] = val;
}
