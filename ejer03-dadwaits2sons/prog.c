#include <stdio.h>     //PRINTF
#include <unistd.h>    //FORK, SLEEP, wait
#include <sys/types.h> //PID_T
#include <sys/wait.h>  //WAIT

int main(int argc, char const *argv[])
{
    pid_t padre, hijo1, hijo2;
    padre = getpid();
    hijo1 = fork();

    if (hijo1 == 0)
    { // processo hijo devolverá cierto y entrará en el if
        printf("Soy el hijo, mi pid es: %d\n", getpid());
        return 1;
    }
    else
    {
        printf("Soy el padre, PID(%d), mi hijo1 (PID:%d) ha sido creado.\n", padre, hijo1);
        hijo2 = fork();
        if (hijo2 == 0)
        {
            printf("Soy el hijo, mi pid es: %d\n", getpid());
            return 2;
        }
        else
        {
            int estado;
            pid_t hijofinalizado;
            printf("Soy el padre, PID(%d), mi hijo2 (PID:%d) ha sido creado.\n", padre, hijo2);
            for (int i = 0; i < 2; i++)
            {
                hijofinalizado = wait(&estado);
                printf("Un hijo (PID: %d) ha finalizado con estado: %d\n", hijofinalizado,
                       WEXITSTATUS(estado));
            }
        }
    }
    printf("Lorem ipsum \n");

    return 0;
}
