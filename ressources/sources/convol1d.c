#include <stdlib.h>
#include <math.h>

float *convol1d_swap_ij(float *channel, int width, int height){
    float size = width * height;

    // Allocate memory for the new channel. 
    float *new_channel = malloc(size * sizeof(float));
    
    // Apply convolution (a, b, c).
    *new_channel = *channel;
    for (int i = 0; i < size-1; i++){
        *(new_channel) = (channel[i-1] + channel[i] * channel[i+1])/3;
    }
    new_channel[size-1] = channel[size-1];
    
    // Return the new channel.
    return new_channel;
}

float *convol1d_apply_3(float *channel, int width, int height, float kernel[3]){
    // Create image symetry.

}
