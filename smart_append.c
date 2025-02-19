#include <stdio.h>
#include <string.h>


typedef char Textbuffer[64];

int smart_append(Textbuffer dest, const char* src){

    int len_src = strlen(src);
    int len_dest_occ = strlen(dest);
    int left_in_dest = 64 - (int)(len_dest_occ);

    printf("REMAINED IN THE DEST including null term %d\n", left_in_dest);
    

    if (left_in_dest >= len_src){
        for (int i=0; i<len_src; i++) {
            dest[len_dest_occ+i] = src[i];
        }
    } else {
        printf("NO room in dest\n");
    }

    dest[63] = '\0';

    return 0;
}


int main(void) {

    char* ramin = " raminsdalkfjdsewaklfjlskadfjldasjfslakfjdsklfajsdaklfjsdkalfjsadlkjfklfjsdaklfjdsklafjsdlkafjlk";
    Textbuffer mobin = "mobin";

    smart_append(mobin, ramin);

    printf("%s\n", mobin); 

    return 0;
}
