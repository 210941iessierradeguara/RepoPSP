#include <stdio.h>
#include <unistd.h>    //FORK, SLEEP, wait
#include <sys/types.h> //PID_T, KILL
#include <sys/wait.h>  //WAIT
#include <signal.h>    //signal, KILL

void manejadorDeSenyal(int numSenyal);

int main(int argc, char const *argv[])
{
    if (argc <= 1)
    {
        printf("Añada al menos una ruta de archivo \n");
        return 0;
    } else {
        for (int i = 1; i < argc; i++)
        {
            printf("%d \n", i);
            
            pid_t numfork = fork();
            if (numfork == 0)
            {
                //hijo
                sleep(1);

                kill(getppid(), SIGUSR1);
            } else {
                //padre
                signal(SIGUSR1, manejadorDeSenyal);
                pause();

                int p;
                int estado;
                p = wait(&estado);
                printf("El hijo: %d ha terminado con estado %d: \n",p, WEXITSTATUS(estado));
            }
        }
    }
    return 0;
}

void manejadorDeSenyal(int numSenyal)
{
    printf("He recibido una señal número: %d\n", numSenyal);
}