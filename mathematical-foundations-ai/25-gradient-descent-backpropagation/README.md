# Topic 25 — Gradient Descent & Backpropagation

This lab implements the mathematical foundations behind neural network learning.

## Concepts

- Loss functions
- Gradients
- Gradient descent
- Learning rates
- Forward propagation
- Backpropagation
- Parameter updates
- Mean squared error

## Gradient Descent

Gradient descent updates parameters in the direction that reduces a loss function.

Mathematically:

θ = θ - α∇J(θ)

Where:

- θ = model parameter
- α = learning rate
- ∇J(θ) = gradient of the loss function

## Forward Propagation

A model first calculates predictions:

Input

↓

Weighted computation

↓

Prediction

↓

Loss calculation

## Backpropagation

Backpropagation calculates how much each parameter contributed to the error.

Conceptually:

Loss

↓

Gradient calculation

↓

Error propagation

↓

Parameter gradients

↓

Parameter updates

## Practical Connection

These concepts are fundamental to:

- neural networks
- deep learning
- machine learning
- optimisation
- computer vision
- natural language processing

## Implementation

This lab implements:

- linear regression
- mean squared error
- analytical gradients
- gradient descent training
- a small neural network
- manual forward propagation
- manual backpropagation

The goal is to understand how learning algorithms work internally rather than relying entirely on machine learning frameworks.

