============================================================

CS From First Principles

Phase 5 — Mathematical Foundations for AI

Topic 25 — Gradient Descent & Backpropagation

File:
gradient_descent.py

Purpose:
Implement gradient descent and a simple neural network
training step from first principles.

============================================================
"""

import numpy as np


# ============================================================
# Mean Squared Error
# ============================================================

def mean_squared_error(predictions, targets):
    """
    Calculate Mean Squared Error.

    MSE = mean((prediction - target)^2)
    """

    return np.mean(
        (predictions - targets) ** 2
    )


# ============================================================
# Linear model
# ============================================================

def linear_prediction(x, weight, bias):
    """
    Linear model:

        y = wx + b
    """

    return (
        weight * x
        + bias
    )


# ============================================================
# Linear gradients
# ============================================================

def linear_gradients(
    x,
    predictions,
    targets
):
    """
    Calculate gradients for:

        y = wx + b

    using Mean Squared Error.

    Returns:

        gradient_weight
        gradient_bias
    """

    n = len(x)

    errors = (
        predictions - targets
    )

    gradient_weight = (
        2 / n
        * np.sum(errors * x)
    )

    gradient_bias = (
        2 / n
        * np.sum(errors)
    )

    return (
        gradient_weight,
        gradient_bias
    )


# ============================================================
# Gradient descent
# ============================================================

def train_linear_model(
    x,
    targets,
    learning_rate=0.01,
    epochs=1000
):
    """
    Train a linear model using gradient descent.

    Returns:

        weight
        bias
        loss_history
    """

    weight = 0.0
    bias = 0.0

    loss_history = []

    for _ in range(epochs):

        predictions = linear_prediction(
            x,
            weight,
            bias
        )

        loss = mean_squared_error(
            predictions,
            targets
        )

        loss_history.append(loss)

        gradient_weight, gradient_bias = (
            linear_gradients(
                x,
                predictions,
                targets
            )
        )

        weight = (
            weight
            - learning_rate * gradient_weight
        )

        bias = (
            bias
            - learning_rate * gradient_bias
        )

    return (
        weight,
        bias,
        loss_history
    )


# ============================================================
# Sigmoid activation
# ============================================================

def sigmoid(x):
    """
    Sigmoid activation function.
    """

    return 1 / (
        1 + np.exp(-x)
    )


# ============================================================
# Sigmoid derivative
# ============================================================

def sigmoid_derivative(sigmoid_output):
    """
    Derivative of sigmoid.

    sigmoid'(x) = sigmoid(x) * (1 - sigmoid(x))
    """

    return (
        sigmoid_output
        * (1 - sigmoid_output)
    )


# ============================================================
# Forward propagation
# ============================================================

def forward_pass(
    inputs,
    weights_input_hidden,
    bias_hidden,
    weights_hidden_output,
    bias_output
):
    """
    Perform forward propagation through a small neural network.

    Architecture:

    Input Layer

        ↓

    Hidden Layer

        ↓

    Output Layer
    """

    hidden_input = (
        inputs @ weights_input_hidden
        + bias_hidden
    )

    hidden_output = sigmoid(
        hidden_input
    )

    output_input = (
        hidden_output @ weights_hidden_output
        + bias_output
    )

    prediction = sigmoid(
        output_input
    )

    return (
        hidden_output,
        prediction
    )


# ============================================================
# Single neural network training step
# ============================================================

def neural_network_step(
    inputs,
    targets,
    weights_input_hidden,
    bias_hidden,
    weights_hidden_output,
    bias_output,
    learning_rate=0.1
):
    """
    Perform:

    Forward propagation
        ↓
    Loss calculation
        ↓
    Backpropagation
        ↓
    Parameter update
    """

    # --------------------------------------------------------
    # Forward pass
    # --------------------------------------------------------

    hidden_output, prediction = forward_pass(
        inputs,
        weights_input_hidden,
        bias_hidden,
        weights_hidden_output,
        bias_output
    )

    loss = mean_squared_error(
        prediction,
        targets
    )

    # --------------------------------------------------------
    # Output layer gradient
    # --------------------------------------------------------

    output_error = (
        prediction - targets
    )

    output_delta = (
        output_error
        * sigmoid_derivative(prediction)
    )

    # --------------------------------------------------------
    # Hidden-output weight gradients
    # --------------------------------------------------------

    gradient_hidden_output = (
        hidden_output.T
        @ output_delta
    )

    gradient_bias_output = np.sum(
        output_delta,
        axis=0
    )

    # --------------------------------------------------------
    # Hidden layer gradients
    # --------------------------------------------------------

    hidden_error = (
        output_delta
        @ weights_hidden_output.T
    )

    hidden_delta = (
        hidden_error
        * sigmoid_derivative(hidden_output)
    )

    # --------------------------------------------------------
    # Input-hidden gradients
    # --------------------------------------------------------

    gradient_input_hidden = (
        inputs.T
        @ hidden_delta
    )

    gradient_bias_hidden = np.sum(
        hidden_delta,
        axis=0
    )

    # --------------------------------------------------------
    # Parameter updates
    # --------------------------------------------------------

    weights_hidden_output = (
        weights_hidden_output
        - learning_rate
        * gradient_hidden_output
    )

    bias_output = (
        bias_output
        - learning_rate
        * gradient_bias_output
    )

    weights_input_hidden = (
        weights_input_hidden
        - learning_rate
        * gradient_input_hidden
    )

    bias_hidden = (
        bias_hidden
        - learning_rate
        * gradient_bias_hidden
    )

    return (
        weights_input_hidden,
        bias_hidden,
        weights_hidden_output,
        bias_output,
        loss
    )


# ============================================================
# Demonstration
# ============================================================

def main():

    print("\n==========================================")
    print(" Gradient Descent & Backpropagation")
    print("==========================================")

    # --------------------------------------------------------
    # Gradient descent demonstration
    # --------------------------------------------------------

    print("\n1. Linear Regression")

    x = np.array(
        [1, 2, 3, 4],
        dtype=float
    )

    targets = np.array(
        [3, 5, 7, 9],
        dtype=float
    )

    weight, bias, losses = train_linear_model(
        x,
        targets,
        learning_rate=0.05,
        epochs=1000
    )

    print(
        f"Final weight: {weight:.4f}"
    )

    print(
        f"Final bias: {bias:.4f}"
    )

    print(
        f"Initial loss: {losses[0]:.6f}"
    )

    print(
        f"Final loss: {losses[-1]:.6f}"
    )

    # --------------------------------------------------------
    # Neural network demonstration
    # --------------------------------------------------------

    print("\n2. Neural Network Training Step")

    inputs = np.array(
        [
            [0.0, 0.0],
            [0.0, 1.0],
            [1.0, 0.0],
            [1.0, 1.0]
        ]
    )

    targets = np.array(
        [
            [0.0],
            [1.0],
            [1.0],
            [0.0]
        ]
    )

    np.random.seed(42)

    weights_input_hidden = np.random.randn(
        2,
        2
    )

    bias_hidden = np.zeros(2)

    weights_hidden_output = np.random.randn(
        2,
        1
    )

    bias_output = np.zeros(1)

    (
        weights_input_hidden,
        bias_hidden,
        weights_hidden_output,
        bias_output,
        loss
    ) = neural_network_step(
        inputs,
        targets,
        weights_input_hidden,
        bias_hidden,
        weights_hidden_output,
        bias_output
    )

    print(
        f"Loss before update: {loss:.6f}"
    )

    print(
        "\nOne complete forward + backpropagation "
        "step completed."
    )

    print(
        "\nDemonstration complete."
    )


if __name__ == "__main__":
    main()