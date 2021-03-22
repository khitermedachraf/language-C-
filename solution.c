#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <dirent.h>
#include <getopt.h>

int main(int argc, char *argv[]) {
	char buf;
    DIR *d;
    int s;
    FILE *fd;
    struct dirent *dir;
 
    s= getopt(argc,argv,"tdp");

	if(argc == 2)
		printf("Manque d'arguments!\nUsage: cat [filename] ...\n");
	else {
        d= opendir(argv[2]);
            if (d){
                if (s == 't'){ // -d : trie les fichiers selon la date de la dernière modification.
            /* code */
                    printf(" trie les fichiers selon leur taille.\n");
                    d= opendir(argv[2]);
                    while ((dir = readdir(d)) != NULL) {
                        printf("%s\n", dir->d_name);
                    }
                     closedir(d)
                }
            if (s == 't'){ // -t : trie les fichiers selon leur taille.
                /* code */
                    printf(" trie les fichiers selon leur taille.\n");
                    d= opendir(argv[2]);
                    while ((dir = readdir(d)) != NULL) {
                              printf("%s\n", dir->d_name);
                              int count = 0;
                              fd = fopen(dir->d_name, 'r');
                              if (fd == NULL){printf("Le fichier %s n'existe pas !\n",dir->d_name);}
                               else {
                                   char ch;
                                   while((ch = fgetc(fp)) != EOF)
                                        count++;
                                
                                fclose(fd);	
                                printf("le nom de fichier est :%s \n",dir->d_name);
                                printf("le nombre d'octets est :%d\n\n***\n",count);
                                }
  

                 }
                closedir(d);
                }
           if (s == 'd'){ // -d : trie les fichiers selon la date de la dernière modification.
                /* code */
                    printf("-d : trie les fichiers selon la date de la dernière modification.\n");
                    d= opendir(argv[2]);
                    while ((dir = readdir(d)) != NULL) {
                              printf("%s\n", dir->d_name);

                  }
                closedir(d);    
                }
           if (s == 'p'){ // -p : trie les fichiers selon leurs droits d’accès (privilège). Un fichier avec les droits d’accès 777 sera classé en premier.
                /* code */
                    printf("-p : trie les fichiers selon leurs droits d’accès (privilège).");
                    d= opendir(argv[2]);
                    while ((dir = readdir(d)) != NULL) {
                              printf("%s\n", dir->d_name);

                   }
                    closedir(d);
                }
        }
	    return EXIT_SUCCESS;
	}
}
