#include <stddef.h>
size_t mystrlen(const char *s){
	size_t len;
	for(len = 0; s[len] != 0; len++);
	return len;
}
