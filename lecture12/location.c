#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
	char *protocol;
	char *host;
	char *pathname;
	char *search;
	char *hash;
	int port;
} Location;

Location *parse_url(char *url);

int main() {
	char url[500] = "";
	fgets(url, 500, stdin);	 // Get url string
	Location *l = parse_url(url);
	printf("Location {\n  protocol: %s,\n  host: %s,\n", l->protocol, l->host);
	if (l->port) {
		printf("  port: %d,\n", l->port);
	} else {
		printf("  port: (default),\n");
	}
	printf("  pathname: /%s,\n  search: ?%s,\n  hash: #%s,\n}\n", l->pathname,
		   l->search, l->hash);
	return 0;
}

#define s_protocal 0x01
#define s_host 0x02
#define s_port 0x03
#define s_pathname 0x04
#define s_search 0x05
#define s_hash 0x06

Location *parse_url(char *url) {
	//  printf("%s\n", url);
	int strindex = 0;
	unsigned int state = s_protocal;

	// alloca memories
	Location *location = malloc(sizeof(*location));
	location->protocol = calloc(sizeof(char) * 500, sizeof(char));
	location->host = calloc(sizeof(char) * 500, sizeof(char));
	location->pathname = calloc(sizeof(char) * 500, sizeof(char));
	location->search = calloc(sizeof(char) * 500, sizeof(char));
	location->hash = calloc(sizeof(char) * 500, sizeof(char));

	// default value
	location->port = 0;

	char *c = url;
	while (*c != '\0' && *c != '\n') {
		//  putchar(*c);
		switch (state) {
			case s_protocal:
				if (*c == ':' && *(c + 1) == '/' && *(c + 2) == '/') {
					//  puts("(host)");
					c += 2;
					location->protocol[strindex++] = '\0';
					strindex = 0;
					state = s_host;
				} else {
					location->protocol[strindex++] = *c;
				}
				break;
			case s_host:
				if (*c == ':') {
					//  puts("(post)");
					location->host[strindex++] = '\0';
					strindex = 0;
					state = s_port;

				} else if (*c == '/') {
					//  puts("(pathname)");
					location->host[strindex++] = '\0';
					strindex = 0;
					state = s_pathname;
				} else if (*c == '?') {
					//  puts("(search)");
					location->pathname[strindex++] = '\0';
					strindex = 0;
					state = s_search;
				} else if (*c == '#') {
					//  puts("(hash)");
					location->pathname[strindex++] = '\0';
					strindex = 0;
					state = s_hash;
				} else {
					location->host[strindex++] = *c;
				}
				break;
			case s_port:
				if (*c == '/') {
					//  puts("(pathname)");
					state = s_pathname;
				} else if (*c == '?') {
					//  puts("(search)");
					state = s_search;
				} else if (*c == '#') {
					//  puts("(hash)");
					state = s_hash;
				} else {
					location->port = location->port * 10 + (*c - '0');
				}
				break;
			case s_pathname:
				if (*c == '?') {
					//  puts("(search)");
					location->pathname[strindex++] = '\0';
					strindex = 0;
					state = s_search;
				} else if (*c == '#') {
						//  puts("(hash)");
					location->pathname[strindex++] = '\0';
					strindex = 0;
					state = s_hash;
				} else {
					location->pathname[strindex++] = *c;
				}
				break;
			case s_search:
				if (*c == '#') {
					//  puts("(hash)");
					location->search[strindex++] = '\0';
					strindex = 0;
					state = s_hash;
				} else {
					location->search[strindex++] = *c;
				}
				break;
			case s_hash:
				if (*c == '?') {
					//  puts("(search)");
					location->hash[strindex++] = '\0';
					strindex = 0;
					state = s_search;
				} else {
					location->hash[strindex++] = *c;
				}
				break;
		}
		c++;
	}

	return location;
}
