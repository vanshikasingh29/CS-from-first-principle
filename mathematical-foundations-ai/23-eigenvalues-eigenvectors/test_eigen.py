"""
============================================================

CS From First Principles

Phase 5 — Mathematical Foundations for AI

Topic 23 — Eigenvalues & Eigenvectors

File:
test_eigen.py

Purpose:
Automated tests for eigenvalue and eigenvector operations.

============================================================
"""

import numpy as np

from eigen import (
    matrix_vector_multiply,
    calculate_eigenpairs,
    verify_eigenpair
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

        print(f"[PASS] {test_name}")

        tests_passed += 1

    else:

        print(f"[FAIL] {test_name}")

        tests_failed += 1


# ============================================================
# Matrix-vector multiplication
# ============================================================

def test_matrix_vector_multiplication():

    matrix = np.array(
        [
            [2, 0],
            [0, 3]
        ],
        dtype=float
    )

    vector = np.array(
        [1, 1],
        dtype=float
    )

    result = matrix_vector_multiply(
        matrix,
        vector
    )

    expected = np.array(
        [2, 3],
        dtype=float
    )

    assert_test(
        np.allclose(result, expected),
        "Matrix-vector multiplication"
    )


# ============================================================
# Eigenvalue calculation
# ============================================================

def test_eigenvalues():

    matrix = np.array(
        [
            [2, 0],
            [0, 3]
        ],
        dtype=float
    )

    eigenvalues, _ = calculate_eigenpairs(matrix)

    expected = [2, 3]

    passed = all(
        any(
            np.isclose(
                eigenvalue,
                expected_value
            )
            for eigenvalue in eigenvalues
        )
        for expected_value in expected
    )

    assert_test(
        passed,
        "Eigenvalue calculation"
    )


# ============================================================
# Eigenvector verification
# ============================================================

def test_eigenvector():

    matrix = np.array(
        [
            [2, 0],
            [0, 3]
        ],
        dtype=float
    )

    vector = np.array(
        [1, 0],
        dtype=float
    )

    passed = verify_eigenpair(
        matrix,
        vector,
        2
    )

    assert_test(
        passed,
        "Eigenvector verification"
    )


# ============================================================
# Invalid eigenpair
# ============================================================

def test_invalid_eigenpair():

    matrix = np.array(
        [
            [2, 0],
            [0, 3]
        ],
        dtype=float
    )

    vector = np.array(
        [1, 0],
        dtype=float
    )

    passed = not verify_eigenpair(
        matrix,
        vector,
        3
    )

    assert_test(
        passed,
        "Invalid eigenpair detection"
    )


# ============================================================
# Main test runner
# ============================================================

def main():

    print("\n==========================================")
    print(" Eigenvalues & Eigenvectors Test Suite")
    print("==========================================\n")

    test_matrix_vector_multiplication()

    test_eigenvalues()

    test_eigenvector()

    test_invalid_eigenpair()

    print("\nResults")
    print("--------------------")

    print(f"Passed: {tests_passed}")

    print(f"Failed: {tests_failed}")

    if tests_failed == 0:

        print(
            "\nAll eigenvalue and eigenvector tests passed."
        )

        return 0

    print(
        "\nSome eigenvalue and eigenvector tests failed."
    )

    return 1


if __name__ == "__main__":
    raise SystemExit(main())