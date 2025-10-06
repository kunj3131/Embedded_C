# External and Internal Linkage

if we define static varible in global and use extern keyword it means we compile using 'External Linkage' method.

Output is Error:
/usr/bin/ld: /tmp/cczwAM0p.o: warning: relocation against `externalAndInternal' in read-only section `.text'
/usr/bin/ld: /tmp/cczwAM0p.o: in function `main':
main.c:(.text+0xa): undefined reference to `externalAndInternal'
/usr/bin/ld: warning: creating DT_TEXTREL in a PIE
collect2: error: ld returned 1 exit status


But if we use Internal Linkage method and 
main.c:
#include <stdio.h>
#include "externalInternal.c"

int main(){
        printf("%d\n",externalAndInternal);
}

we get output 
