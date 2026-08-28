import numpy as np


# ============================================================
# Matrix-vector multiplication
# ============================================================

def matrix_vector_multiply(matrix, vector):
    """
    Multiply a matrix by a vector.

    Parameters:
        matrix: NumPy matrix
        vector: NumPy vector

    Returns:
        Resulting vector
    """

    return matrix @ vector


# ============================================================
# Eigenvalue and eigenvector calculation
# ============================================================

def calculate_eigenpairs(matrix):
    """
    Calculate eigenvalues and eigenvectors.

    NumPy is used for the numerical eigenvalue calculation.

    Returns:
        eigenvalues
        eigenvectors
    """

    eigenvalues, eigenvectors = np.linalg.eig(matrix)

    return eigenvalues, eigenvectors


# ============================================================
# Eigenpair verification
# ============================================================

def verify_eigenpair(matrix, eigenvector, eigenvalue, tolerance=1e-9):
    """
    Verify:

        A v = lambda v

    The small tolerance accounts for floating-point error.
    """

    left_side = matrix @ eigenvector
    right_side = eigenvalue * eigenvector

    return np.allclose(
        left_side,
        right_side,
        atol=tolerance
    )


# ============================================================
# Display eigenpairs
# ============================================================

def display_eigenpairs(matrix):
    """
    Calculate and display eigenvalues and eigenvectors.
    """

    eigenvalues, eigenvectors = calculate_eigenpairs(matrix)

    print("Matrix:")
    print(matrix)

    print("\nEigenpairs")
    print("----------")

    for i, eigenvalue in enumerate(eigenvalues):

        eigenvector = eigenvectors[:, i]

        verified = verify_eigenpair(
            matrix,
            eigenvector,
            eigenvalue
        )

        print(f"\nEigenvalue: {eigenvalue:.4f}")

        print("Eigenvector:")
        print(eigenvector)

        print(
            f"Verified A*v = lambda*v: "
            f"{verified}"
        )


# ============================================================
# Demonstration
# ============================================================

def main():
    """
    Demonstrate eigenvalue computation.
    """

    print("\n==========================================")
    print(" Eigenvalues & Eigenvectors Demonstration")
    print("==========================================")

    matrix = np.array(
        [
            [4, 1],
            [2, 3]
        ],
        dtype=float
    )

    display_eigenpairs(matrix)

    print("\nDemonstration complete.")


if __name__ == "__main__":
    main()