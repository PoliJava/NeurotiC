#include "input.h"

// This is the code that contains the funnctions to amke the input of the 
//immages from the dataset as input and convert the immagess into valures 
//for the matrix




int read_pixel(FILE *file, float immagine[28][28]){
    printf("Start the function to read the pixels of the image\n");

    int pixel=0;
    for(int i=0; i<28; i++){
        for(int j=0; j<28; j++){
            pixel = fgetc(file);
        
            if (pixel == EOF){
                printf("Il file è vuoto");
                return 0;
            }
            immagine[i][j]= (float)pixel; // because pixel is integer while matrix is a float
        }
                
    }

    printf("\nfuncton completed with success!");
    return 1;
};