
"""
============================================================

CS From First Principles

Phase 5 — Mathematical Foundations for AI

Topic 24 — Multivariable Calculus

File:
calculus.py

Purpose:
Explore partial derivatives, gradients and numerical
differentiation.

============================================================
"""

import math


# ============================================================
# Example multivariable function
# ============================================================

def function(x, y):
    """
    Example function:

        f(x, y) = x^2 + 3xy + y^2
    """

    return (
        x ** 2
        + 3 * x * y
        + y ** 2
    )


# ============================================================
# Analytical partial derivative with respect to x
# ============================================================

def partial_x(x, y):
    """
    ∂f/∂x

    For:

        f(x,y) = x² + 3xy + y²

    we obtain:

        ∂f/∂x = 2x + 3y
    """

    return 2 * x + 3 * y


# ============================================================
# Analytical partial derivative with respect to y
# ============================================================

def partial_y(x, y):
    """
    ∂f/∂y

    ∂f/∂y = 3x + 2y
    """

    return 3 * x + 2 * y


# ============================================================
# Numerical partial derivative
# ============================================================

def numerical_partial_x(x, y, h=1e-5):
    """
    Approximate ∂f/∂x using the central difference method.

        f'(x) ≈ [f(x+h) - f(x-h)] / 2h
    """

    return (
        function(x + h, y)
        - function(x - h, y)
    ) / (2 * h)


def numerical_partial_y(x, y, h=1e-5):
    """
    Approximate ∂f/∂y using central differences.
    """

    return (
        function(x, y + h)
        - function(x, y - h)
    ) / (2 * h)


# ============================================================
# Gradient
# ============================================================

def gradient(x, y):
    """
    Calculate the analytical gradient.

        ∇f = [∂f/∂x, ∂f/∂y]
    """

    return (
        partial_x(x, y),
        partial_y(x, y)
    )


# ============================================================
# Numerical gradient
# ============================================================

def numerical_gradient(x, y):
    """
    Calculate the gradient using numerical derivatives.
    """

    return (
        numerical_partial_x(x, y),
        numerical_partial_y(x, y)
    )


# ============================================================
# Directional derivative
# ============================================================

def directional_derivative(x, y, direction):
    """
    Calculate the directional derivative.

    D_u f = ∇f · u

    The direction vector is normalised before calculating
    the dot product.
    """

    dx, dy = direction

    magnitude = math.sqrt(
        dx ** 2 + dy ** 2
    )

    if magnitude == 0:
        raise ValueError(
            "Direction vector cannot be zero."
        )

    unit_x = dx / magnitude
    unit_y = dy / magnitude

    gradient_x, gradient_y = gradient(x, y)

    return (
        gradient_x * unit_x
        + gradient_y * unit_y
    )


# ============================================================
# Demonstration
# ============================================================

def main():

    print("\n==========================================")
    print(" Multivariable Calculus Demonstration")
    print("==========================================")

    x = 2.0
    y = 3.0

    print(f"\nPoint: ({x}, {y})")

    print(
        f"\nf(x,y) = {function(x, y):.4f}"
    )

    print(
        f"Partial derivative ∂f/∂x = "
        f"{partial_x(x, y):.4f}"
    )

    print(
        f"Partial derivative ∂f/∂y = "
        f"{partial_y(x, y):.4f}"
    )

    print(
        f"Gradient = {gradient(x, y)}"
    )

    print(
        f"Numerical gradient = "
        f"{numerical_gradient(x, y)}"
    )

    direction = (1.0, 1.0)

    print(
        f"Directional derivative "
        f"in direction {direction}: "
        f"{directional_derivative(x, y, direction):.4f}"
    )

    print("\nDemonstration complete.")


if __name__ == "__main__":
    main()