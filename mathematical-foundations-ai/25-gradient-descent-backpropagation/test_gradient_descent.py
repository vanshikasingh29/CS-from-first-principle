import numpy as np

from gradient_descent import (
    mean_squared_error,
    linear_prediction,
    linear_gradients,
    train_linear_model,
    sigmoid,
    sigmoid_derivative,
    forward_pass,
    neural_network_step
)


tests_passed = 0
tests_failed = 0


# ============================================================
# Simple test framework
# ============================================================

def assert_test(condition, test_name):

    global tests_passed
    global tests_failed

    if condition:

        print(
            f"[PASS] {test_name}"
        )

        tests_passed += 1

    else:

        print(
            f"[FAIL] {test_name}"
        )

        tests_failed += 1


# ============================================================
# Test Mean Squared Error
# ============================================================

def test_mse():

    predictions = np.array(
        [1, 2, 3],
        dtype=float
    )

    targets = np.array(
        [1, 2, 5],
        dtype=float
    )

    result = mean_squared_error(
        predictions,
        targets
    )

    expected = 4 / 3

    assert_test(
        np.isclose(result, expected),
        "Mean squared error"
    )


# ============================================================
# Test linear prediction
# ============================================================

def test_linear_prediction():

    x = np.array(
        [1, 2],
        dtype=float
    )

    result = linear_prediction(
        x,
        weight=2,
        bias=1
    )

    expected = np.array(
        [3, 5],
        dtype=float
    )

    assert_test(
        np.allclose(
            result,
            expected
        ),
        "Linear prediction"
    )


# ============================================================
# Test gradients
# ============================================================

def test_linear_gradients():

    x = np.array(
        [1, 2],
        dtype=float
    )

    predictions = np.array(
        [2, 4],
        dtype=float
    )

    targets = np.array(
        [3, 5],
        dtype=float
    )

    gradient_weight, gradient_bias = (
        linear_gradients(
            x,
            predictions,
            targets
        )
    )

    assert_test(
        np.isclose(
            gradient_weight,
            -3
        ),
        "Weight gradient"
    )

    assert_test(
        np.isclose(
            gradient_bias,
            -2
        ),
        "Bias gradient"
    )


# ============================================================
# Test sigmoid
# ============================================================

def test_sigmoid():

    result = sigmoid(0)

    assert_test(
        np.isclose(
            result,
            0.5
        ),
        "Sigmoid at zero"
    )


# ============================================================
# Test sigmoid derivative
# ============================================================

def test_sigmoid_derivative():

    result = sigmoid_derivative(
        0.5
    )

    assert_test(
        np.isclose(
            result,
            0.25
        ),
        "Sigmoid derivative"
    )


# ============================================================
# Test gradient descent learning
# ============================================================

def test_gradient_descent():

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

    learned = (
        abs(weight - 2) < 0.1
        and
        abs(bias - 1) < 0.1
    )

    assert_test(
        learned,
        "Gradient descent learns parameters"
    )

    assert_test(
        losses[-1] < losses[0],
        "Gradient descent reduces loss"
    )


# ============================================================
# Test forward propagation
# ============================================================

def test_forward_pass():

    inputs = np.array(
        [[1.0, 0.0]]
    )

    weights_input_hidden = np.array(
        [
            [1.0, 0.0],
            [0.0, 1.0]
        ]
    )

    bias_hidden = np.zeros(2)

    weights_hidden_output = np.array(
        [
            [1.0],
            [1.0]
        ]
    )

    bias_output = np.zeros(1)

    hidden_output, prediction = forward_pass(
        inputs,
        weights_input_hidden,
        bias_hidden,
        weights_hidden_output,
        bias_output
    )

    passed = (
        hidden_output.shape == (1, 2)
        and
        prediction.shape == (1, 1)
    )

    assert_test(
        passed,
        "Forward propagation shapes"
    )


# ============================================================
# Test neural network step
# ============================================================

def test_neural_network_step():

    np.random.seed(1)

    inputs = np.array(
        [
            [0.0, 0.0],
            [1.0, 1.0]
        ]
    )

    targets = np.array(
        [
            [0.0],
            [1.0]
        ]
    )

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

    result = neural_network_step(
        inputs,
        targets,
        weights_input_hidden,
        bias_hidden,
        weights_hidden_output,
        bias_output
    )

    loss = result[-1]

    assert_test(
        loss >= 0,
        "Backpropagation training step"
    )


# ============================================================
# Main test runner
# ============================================================

def main():

    print("\n==========================================")
    print(" Gradient Descent Test Suite")
    print("==========================================\n")

    test_mse()

    test_linear_prediction()

    test_linear_gradients()

    test_sigmoid()

    test_sigmoid_derivative()

    test_gradient_descent()

    test_forward_pass()

    test_neural_network_step()

    print("\nResults")
    print("--------------------")

    print(
        f"Passed: {tests_passed}"
    )

    print(
        f"Failed: {tests_failed}"
    )

    if tests_failed == 0:

        print(
            "\nAll gradient descent tests passed."
        )

        return 0

    print(
        "\nSome tests failed."
    )

    return 1


if __name__ == "__main__":
    raise SystemExit(main())