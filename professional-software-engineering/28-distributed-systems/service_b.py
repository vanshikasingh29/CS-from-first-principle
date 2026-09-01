"""
Service B

Represents an independent service in the distributed system.

Service B receives orders and processes them.
"""

from flask import Flask, jsonify, request


app = Flask(__name__)

# Stores processed orders.
# In a real distributed system this would normally be a database.
processed_orders = set()


@app.get("/health")
def health():
    """Health-check endpoint used to determine whether the service is alive."""
    return jsonify({
        "service": "service-b",
        "status": "healthy"
    })


@app.post("/orders")
def process_order():
    """
    Process an order.

    The order ID provides idempotency:
    processing the same order twice does not create duplicate work.
    """

    data = request.get_json()

    if not data or "order_id" not in data:
        return jsonify({
            "error": "order_id is required"
        }), 400

    order_id = data["order_id"]

    # Idempotency check.
    if order_id in processed_orders:
        return jsonify({
            "status": "already_processed",
            "order_id": order_id
        }), 200

    processed_orders.add(order_id)

    return jsonify({
        "status": "processed",
        "order_id": order_id
    }), 201


if __name__ == "__main__":
    app.run(port=5001)