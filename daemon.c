#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/stat.h>

int main(int argc, char* argv[]) {
   pid_t pid = 0;
   pid_t sid = 0;

   pid = fork();

   if (pid < 0) {
       perror("Error: Couldn't start daemon (fork returned < 0).\n");
       exit(EXIT_FAILURE);
   }

   if (pid > 0) {
       printf("Daemon created. Process id: %d\n", pid);
       exit(EXIT_SUCCESS);
   }

   umask(0);
   sid = setsid();

   if (sid < 0) {
       exit(EXIT_FAILURE);
   }

   chdir("/");
   close(STDIN_FILENO);
   close(STDOUT_FILENO);
   close(STDERR_FILENO);

   // Write the main logic of the daemon here.
   // E.g., write the while (true) loop.

   return 0;
}
