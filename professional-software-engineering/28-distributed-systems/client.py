"""
Client

Used to interact with Service A.

Start Service B first, then Service A,
then run this file.
"""

import requests


SERVICE_A_URL = "http://127.0.0.1:5000"


def create_order(order_id: str):
    """Send an order to Service A."""

    response = requests.post(
        f"{SERVICE_A_URL}/orders",
        json={
            "order_id": order_id
        },
        timeout=5
    )

    print("Status:", response.status_code)
    print("Response:", response.json())


def check_health():
    """Check whether Service A is healthy."""

    response = requests.get(
        f"{SERVICE_A_URL}/health",
        timeout=5
    )

    print("Health:", response.json())


if __name__ == "__main__":

    check_health()

    create_order("ORDER-001")

    # Sending the same order again demonstrates idempotency.
    create_order("ORDER-001")