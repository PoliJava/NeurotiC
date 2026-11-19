#ifndef NEURON_H
#define NEURON_H

typedef struct neuron{
    float* weights;
    float bias;
    
    long input_size;
    float pre_act;

    float delta;
    
    float (*activation) (float weighted_sum); //function pointer to the activation function (sigmoid)
    float (*activation_flx) (float weighted_sum); //function pointer to the derivative of the activation function (sigmoid_flx)



    //TODO: Implement gradients.
} neuron;

void neuron_init(neuron *n, long size);
float sigmoid(float x);
float sigmoid_flx(float x);
float act_sum(const float* inputs, const float* weights, float bias, long input_size);
float forward(neuron* n, const float* inputs);

#endif
