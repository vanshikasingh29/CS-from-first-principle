"""
Service A

Represents a separate service that communicates with Service B
over HTTP.

This demonstrates:
- service-to-service communication
- retries
- timeouts
- failure handling
"""

from flask import Flask, jsonify, request
import requests


app = Flask(__name__)

SERVICE_B_URL = "http://127.0.0.1:5001"


def send_order_to_service_b(order_id: str) -> dict:
    """
    Send an order to Service B.

    A small retry mechanism is used because distributed systems
    must assume that network communication can fail.
    """

    payload = {
        "order_id": order_id
    }

    max_attempts = 3

    for attempt in range(max_attempts):

        try:
            response = requests.post(
                f"{SERVICE_B_URL}/orders",
                json=payload,
                timeout=2
            )

            response.raise_for_status()

            return response.json()

        except requests.RequestException:

            # Retry failed network requests.
            if attempt == max_attempts - 1:
                raise

    raise RuntimeError("Unable to communicate with Service B")


@app.get("/health")
def health():
    """Health-check endpoint."""
    return jsonify({
        "service": "service-a",
        "status": "healthy"
    })


@app.post("/orders")
def create_order():
    """
    Create an order and forward it to Service B.
    """

    data = request.get_json()

    if not data or "order_id" not in data:
        return jsonify({
            "error": "order_id is required"
        }), 400

    order_id = data["order_id"]

    try:
        result = send_order_to_service_b(order_id)

        return jsonify({
            "service": "service-a",
            "downstream": result
        }), 201

    except requests.RequestException:
        return jsonify({
            "error": "Service B unavailable"
        }), 503


if __name__ == "__main__":
    app.run(port=5000)