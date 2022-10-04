#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>    //FORK, SLEEP, wait
#include <sys/types.h> //PID_T, KILL
#include <sys/wait.h>  //WAIT
#include <signal.h>    //signal, KILL

int main(int argc, char const *argv[])
{
    execl("/usr/bin/firefox", "firefox", "https://educa.aragon.es", NULL);
    system("/usr/bin/firefox");

    // char* v[]={"firefox", "https://educa.aragon.es", NULL};
    // execv("usr/bin/firefox", v);

    //system("ls -l > ls.txt");

    return 0;
}