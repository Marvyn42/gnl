#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <fcntl.h>

int main()
{
  /* Un file descriptor */
  int fd;
  /* Un buffer */
  char buf[128];
  /* Taille lu : */
  int size;
 
  /* On ouvre le fichier : en fait on recupere un fd sur le fichier*/
  fd = open("test.c", O_RDONLY);
  /* il ne peut pas y avoir de fd negatif,
  ** si open nous retourne -1 c'est que l'ouverture a echoue
  ** dans ce cas on quitte
  */
  if (fd == -1)
   return 1;
   
  /*
  ** On lit :
  ** on passe a read :
  ** - le fd,
  ** - le buffer
  ** - la taille du buffer
  ** Attention si tu passe une taille de buffer plus grande que la taille de ton buffer,
  ** ton programme devient sensible aux Buffer Overflow
  */
  size = read (fd, buf, 127);
   
  /*
  ** On raoute un '\0' à la fin de la chaine lu, pour être sur d'avoir une chaine de caractères valide.
  ** size correspondant a l'index du dernier caractere du buffer + 1.
  ** Ceci est utile si tu veux utiliser ta chaine dans une fonction comme strcmp() ou printf()
  */
 
  buf[size] = 0;
   
  /*
  ** On affiche ce que l'on vient de lire dans la console :
  ** NOTE :
  ** il existe des FD speciaux :
  ** Le fd 1 est la sortie standart ( console )
  */
 
  write (1, buf, size);
 
  /* Ne pas oublier de libérer ton file descriptor */
  close(fd);
 
  return 0;
}
