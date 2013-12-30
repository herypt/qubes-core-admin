#include <sys/types.h>
#include <xs.h>
#include <stdio.h>
#include <stdlib.h>
int main(int argc, char **argv)
{
	struct xs_handle *xs;
	unsigned int count;
	char **vec;
	char dummy = 0;
	if (argc != 2) {
		fprintf(stderr, "usage: %s xenstore_path\n", argv[0]);
		exit(1);
	}
	xs = xs_daemon_open();
	if (!xs) {
		perror("xs_daemon_open");
		exit(1);
	}
	if (!xs_watch(xs, argv[1], &dummy)) {
		perror("xs_watch");
		exit(1);
	}
	vec = xs_read_watch(xs, &count);
	free(vec);
	vec = xs_read_watch(xs, &count);
	free(vec);
	return 0;
}
