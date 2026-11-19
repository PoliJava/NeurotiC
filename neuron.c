#include <math.h>
#include "neuron.h"
#include <stdlib.h>
#include <stdio.h>

void neuron_init(neuron *n, long size) {
    n->weights = (float*)malloc(size * sizeof(float));
    
    if(n->weights == NULL){
        fprintf(stderr, "Memory allocation failed for neuron weights.\n");
        exit(EXIT_FAILURE);
    }

    n->input_size = size;
    n->bias = 0.0f;

    n->pre_act = 0.0f;
    n->delta = 0.0f;
    
    n->activation = sigmoid; //we use the sigmoid function as the default activation function 
    n->activation_flx = sigmoid_flx;
}

float act_sum(const float* inputs, const float* weights, float bias, long input_size){
        float a = bias; //as we treat the bias as a weight for input 1 we skip that and just add it to the return value

        for(int i = 0; i < input_size; i++){
            a += inputs[i] * weights[i];
        }

        return a;
    }

float sigmoid(float x){
        return 1 / (1 + expf(-x));
    }

//why flx? short for fluxion. i wanted a short prefix and i found the idea of using such an outdated term funny.
float sigmoid_flx(float x){
    float s = sigmoid(x);
        return s * (1 - s);
    }


float forward(neuron* n, const float* inputs){
    n->pre_act = act_sum(inputs, n->weights, n->bias, n->input_size);

    if(n->activation == NULL){
        return sigmoid(n->pre_act);
    }
    return n->activation(n->pre_act);
}