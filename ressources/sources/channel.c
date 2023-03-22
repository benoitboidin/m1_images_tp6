#include <stdlib.h>
#include <stdio.h>
#include <math.h>

enum channel_disp_mode { Cdm_normalize, Cdm_absval };

float *channel_to_float(unsigned char *channel, int size){
    printf("channel_to_float\n");
    
    float *result = malloc(size * sizeof(float));

    for (int i = 0; i < size; i++){
        result[i] = channel[i] * 2 - 127;
    }
    printf("done\n");

    return result;
}

unsigned char *channel_to_uchar(float *fchannel, int size, enum channel_disp_mode mode){
    printf("channel_to_uchar\n");

    unsigned char *result = malloc(size * sizeof(unsigned char));

    if (mode == Cdm_normalize){
        for (int i = 0; i < size; i++){
            result[i] = (fchannel[i] + 127) / 2;
        }
    } else if (mode == Cdm_absval){
        for (int i = 0; i < size; i++){
            result[i] = fabs(fchannel[i]);
        }
    }

    return result;

    printf("done\n");
}

