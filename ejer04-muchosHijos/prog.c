#include <stdio.h>     //PRINTF
#include <unistd.h>    //FORK, SLEEP, wait
#include <sys/types.h> //PID_T
#include <sys/wait.h>  //WAIT

// definir constantes
#define N_HIJOS 150

int main(int argc, char const *argv[])
{
    for (int i = 0; i < N_HIJOS; i++)
    {
        if (fork() == 0)
        { // codigo de los hijos
            printf("Hola soy el hijo número: %d\n", getpid());
            sleep(1);
            return i;
        }
    }
    int estado;
    int pidHijo;
    for (int i = 0; i < N_HIJOS; i++)
    {
        pidHijo = wait(&estado);
        printf("El hijo %d ha finalizaado con valor de retorno %d\n", pidHijo, WEXITSTATUS(estado));
    }
    return 0;
}
