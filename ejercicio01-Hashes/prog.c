//DME

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>    //FORK, SLEEP, wait
#include <sys/types.h> //PID_T, KILL
#include <sys/wait.h>  //WAIT
#include <signal.h>    //signal, KILL

int main(int argc, char const *argv[])
{

    if (argc <= 1)
    {
        printf("Añada al menos una ruta de archivo \n");
        return 0;
    }
    else
    {
        char MD5[] = "md5sum ";
        char SHA1[] = "sha1sum ";
        char SHA256[] = "sha256sum ";
        char SHA512[] = "sha512sum ";
        char HASHES[] = ".hashes";
        for (int i = 1; i < argc; i++)
        {

            if (fork() == 0)
            { // codigo de los hijos
                // char archivo[] = argv[1];
                char comando[256] = "";
                char fichero[256] = "";
                char ficheroDes[256] = "";
                strcat(fichero, argv[i]);    // fichero
                
                // MD5
                strcat(ficheroDes, fichero); // fichero
                strcat(comando, MD5);        //"md5sum "
                strcat(comando, fichero);    //"md5sum fichero"
                strcat(comando, " >> ");      //"md5sum fichero >> "
                strcat(ficheroDes, HASHES);  //"fichero.hashes"
                strcat(comando, ficheroDes); //"md5sum fichero >> fichero.hashes"
                
                system(comando);

                memset(comando,'\0', sizeof(comando)); //https://stackoverflow.com/questions/8465090/what-is-the-best-way-to-empty-a-char-string-in-c
                memset(ficheroDes,'\0', sizeof(ficheroDes));
                //SHA1
                strcat(ficheroDes, fichero); // fichero
                strcat(comando, SHA1);        //"sha1sum "
                strcat(comando, fichero);    //"sha1sum fichero"
                strcat(comando, " >> ");      //"sha1sum fichero >> "
                strcat(ficheroDes, HASHES);  //"fichero.hashes"
                strcat(comando, ficheroDes); //"sha1sum fichero >> fichero.hashes"

                system(comando);
                
                memset(comando,'\0', sizeof(comando));
                memset(ficheroDes,'\0', sizeof(ficheroDes));
                //SHA256
                strcat(ficheroDes, fichero); // fichero
                strcat(comando, SHA256);        //"sha256sum "
                strcat(comando, fichero);    //"sha256sum fichero"
                strcat(comando, " >> ");      //"sha256sum fichero >> "
                strcat(ficheroDes, HASHES);  //"fichero.hashes"
                strcat(comando, ficheroDes); //"sha256sum fichero >> fichero.hashes"

                system(comando);
                
                memset(comando,'\0', sizeof(comando));
                memset(ficheroDes,'\0', sizeof(ficheroDes));
                //SHA512
                strcat(ficheroDes, fichero); // fichero
                strcat(comando, SHA512);        //"sha512sum "
                strcat(comando, fichero);    //"sha512sum fichero"
                strcat(comando, " >> ");      //"sha512sum fichero >> "
                strcat(ficheroDes, HASHES);  //"fichero.hashes"
                strcat(comando, ficheroDes); //"sha512sum fichero >> fichero.hashes"

                system(comando);
                
                memset(comando,'\0', sizeof(comando));
                memset(ficheroDes,'\0', sizeof(ficheroDes));

                return 0;
            }
        }
        int estado;
        int pidHijo;
        for (int i = 1; i < argc; i++)
        {
            pidHijo = wait(&estado);
            if (WEXITSTATUS(estado) == 0)
            {
                printf("El hijo con PID: %d ha finalizaado con exito\n", pidHijo);
            } else {
                printf("El hijo con PID: %d ha finalizaado con error\n", pidHijo);
            }
        }
        return 0;
    }
}