#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <string.h>

float *convol1d_swap_ij(float *channel, int width, int height){
    printf("convol1d_swap_ij\n");
    
    int size = width * height;
    float *sym_channel = malloc((width+2) * height * sizeof(float));
    
    for (int i = 0; i < size; i++){    
        sym_channel[i] = channel[size - i];
    }

    printf("done\n");
    return sym_channel;
}

float *convol1d_apply_3(float *channel, int width, int height, float kernel[3]){
    printf("convol1d_apply_3\n");

    int size = width * height;
    float *new_channel = malloc(size * sizeof(float));

    // Segmentation fault while accessing channel.
    // for (int i = 1; i < size-1; i++){
    //     printf("i = %d\n", i);
    //     new_channel[i] = (channel[i-1] + channel[i] + channel[i+1])/3;
    // }
    
    printf("done\n");
    return new_channel;
}
