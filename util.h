/* See LICENSE file for copyright and license details. */
#ifndef UTIL_H
#define UTIL_H

#include <regex.h>
#include <stddef.h>
#include <time.h>

/* main server struct */
struct vhost {
	char *chost;
	char *regex;
	char *dir;
	char *prefix;
	regex_t re;
};

struct map {
	char *chost;
	char *from;
	char *to;
};

extern struct server {
	char *host;
	char *port;
	char *docindex;
	int listdirs;
	struct vhost *vhost;
	size_t vhost_len;
	struct map *map;
	size_t map_len;
} s;

#undef LEN
#define LEN(x) (sizeof (x) / sizeof *(x))

void warn(const char *, ...);
void die(const char *, ...);

#define TIMESTAMP_LEN 30

char *timestamp(time_t, char buf[TIMESTAMP_LEN]);
int esnprintf(char *, size_t, const char *, ...);

void *reallocarray(void *, size_t, size_t);
long long strtonum(const char *, long long, long long, const char **);

#endif /* UTIL_H */
