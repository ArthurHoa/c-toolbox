# Perceptron From Scratch

This is an implementation of the perceptron from scratch in C, no library other than the standar C lib is used.

## The perceptron

The perceptron is an artiicial neuron, it is the smallest neural network model.  
It works for two-class linearly separable problems.  

<img href="https://commons.wikimedia.org/wiki/File:Perceptron_moj.png" src="extra/Perceptron.png" width="400">

The multi-layer perceptron (aka. neural network) allows to bypass these two last hypothesis.

## AND Logic gate

We are trying to compute a logic AND door using a perceptron with the following dataset:  

&nbsp;| **TRUE** | **FALSE**
:--:|:--:|:--:
**TRUE**| TRUE | FALSE
**FALSE** | FALSE | FALSE

### Activation functions

Linear | ReLu | Heavyside | Sigmoid
:--:|:--:|:--:|:--:
<img src="extra/linear.png" width="200"> | <img src="extra/relu.png" width="200"> | <img src="extra/heavyside.png" width="200"> | <img src="extra/sigmoid.png" width="200">  

### Results

For computation, let's take:  

FALSE = 0 -> Represented in Blue  
TRUE = 1 -> represented in Red  

and_linear | ReLu | Heavyside | Sigmoid
:--:|:--:|:--:|:--:
<img src="extra/and_linear.png" width="200"> | <img src="extra/and_relu.png" width="200"> | <img src="extra/and_heavyside.png" width="200"> | <img src="extra/and_sigmoid.png" width="200">  

## DOG-2 dataset (linear boundary)

Perceptron can be used for more complex datasets, such as the binary class dataset Dog-2.  
On the following picture, Brittany breed is in blue and Beagle breed is in red, the optimized perceptron boundary is also drawn:  

<img src="extra/dog_2_heavyside.png" width="400">
