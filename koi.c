#include <errno.h>
#include <fcntl.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#define GN "\033[38;5;118m" // Green
#define GC "\033[38;5;248m" // Grey
#define RD "\033[38;5;196m" // Red
#define RT "\033[0m"        // Reset

/* 
 * display file contents to STDOUT with line number and file name
 *
 * Author: Rish <RishOnBash>
 * Date: 23 June, 2026
 * License: MIT
 */

int main(int argc, char *argv[]) {
    if (argc >= 2) {
        for (int i = 1; i < argc; i++) {
            FILE *fp = fopen(argv[i], "r");
            if (!fp) {
            fprintf (stderr, "> %s%s%s: %s\n",
                    RD, argv[i], RT, strerror(errno));
            continue;
            }

            char buffer [1024];
            int count = 0;
            printf ("> %s%s%s\n", GN, argv[i], RT); 
            puts ("");
            while (fgets(buffer, sizeof(buffer), fp)) {
                count++;
                printf ("%s%3d%s %s", GC, count, RT, buffer);
            }
            puts("");
            fclose(fp);
        }

    // read from STDIN
    } else {
        ssize_t b_read;    // bytes read
        unsigned char buf [BUFSIZ];
        while ((b_read = read(STDIN_FILENO, buf, BUFSIZ)) > 0)
            write(STDOUT_FILENO, buf, b_read);
    }
    return 0;
}
