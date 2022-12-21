#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
// #include <sys/types.h>
/*
 * Print the Process ID of the application
 */
int main(int ac, char **av) {

  FILE *stream;
  char *line = NULL;
  size_t len = 0;
  ssize_t nread;

  if (ac != 2) {
    fprintf(stderr, "Usage: %s <file>\n", av[0]);
    exit(EXIT_FAILURE);
  }
  stream = fopen(av[1], "r");
  if (stream == NULL) {
    perror("fopen");
    exit(EXIT_FAILURE);
  }
  while ((nread = getline(&line, &len, stream)) != -1) {
    printf("Retrieved line of length %zd: \n", nread);
    fwrite(line, nread, 1, stdout);
  }
  free(line);
  fclose(stream);
  exit(EXIT_SUCCESS);
  /*
   * Printing the Child & Parent PID
  pid_t my_pid, parent_pid;
  my_pid = getpid();
  parent_pid = getppid();

  printf("%u\n", my_pid);
  printf("%u\n", parent_pid);
  *
  */
}
