#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>

int main(int argc, const char * argv[]) {
    char buf[100];
    char cChar = 'w';
    if( argc == 2 )
      cChar = argv[1][0];

    int fr = open("./geheimIn", O_RDONLY );
    ssize_t bytes_read = read( fr, buf, sizeof(buf) );
    close(fr);

    for(int i=0; buf[i] != '\0'; i++ ){
      if(buf[i] == cChar)
        printf("%c is in the file", cChar);
    }

    int fw = open("./geheimOut", O_WRONLY );
    write( fw, buf, bytes_read );
    close(fw);
    return 0;
}
