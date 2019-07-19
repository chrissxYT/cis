#include "cmd_names.h"

void run_command(char cmd, char *in, char *out);

void get(char *in, char *out);
void set(char *in, char *out);
void version(char *in, char *out);

inline void run_command(char cmd, char *in, char *out)
{
        switch(cmd)
        {
                case CMD_NONE:    return;
                case CMD_GET:     get(in, out); break;
                case CMD_SET:     set(in, out); break;
                case CMD_VERSION: version(in, out); break;
                default: return;
        }
}
