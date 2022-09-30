#include <stdio.h>
#include <unistd.h>    //FORK, SLEEP, wait
#include <sys/types.h> //PID_T
#include <sys/wait.h>  //WAIT
#include <signal.h>    //signal

void manejadorDeSenyal(int numSenyal);

int main(int argc, char const *argv[])
{
    signal(SIGUSR1, manejadorDeSenyal);

    printf("PID: %d\n", getpid());
    sleep(20);
    return 0;
}

void manejadorDeSenyal(int numSenyal)
{
    printf("He recibido una señal número: %d\n", numSenyal);
}