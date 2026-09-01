"""
Tests for the distributed systems laboratory.
"""

from message_queue import MessageQueue
from service_b import app, processed_orders


def test_message_queue():
    """Messages should be consumed in FIFO order."""

    queue = MessageQueue()

    queue.publish("message-1")
    queue.publish("message-2")

    assert queue.consume() == "message-1"
    assert queue.consume() == "message-2"

    assert queue.empty()


def test_service_b_health():
    """Service B should expose a health endpoint."""

    client = app.test_client()

    response = client.get("/health")

    assert response.status_code == 200

    data = response.get_json()

    assert data["status"] == "healthy"


def test_order_processing():
    """A new order should be processed."""

    processed_orders.clear()

    client = app.test_client()

    response = client.post(
        "/orders",
        json={
            "order_id": "TEST-001"
        }
    )

    assert response.status_code == 201

    data = response.get_json()

    assert data["status"] == "processed"


def test_idempotency():
    """
    Processing the same order twice should not create
    duplicate processing.
    """

    processed_orders.clear()

    client = app.test_client()

    first_response = client.post(
        "/orders",
        json={
            "order_id": "TEST-002"
        }
    )

    second_response = client.post(
        "/orders",
        json={
            "order_id": "TEST-002"
        }
    )

    assert first_response.status_code == 201
    assert second_response.status_code == 200

    assert second_response.get_json()["status"] == "already_processed"