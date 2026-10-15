#include <stdio.h>
int main(){
    int notes[] = {100,50,20,10,5,2,1};
    int N = 242;
    int count = 0;
    int size = sizeof(notes)/sizeof(notes[0]);
    for(int i=0;i<size;i++){
        if(N==0){
            break;
        }
        count =count+ N/notes[i];
        // printf("%d notes of %d\n",count,notes[i]);
        N = N%notes[i];
        
    }
    printf("%d notes",count);
}