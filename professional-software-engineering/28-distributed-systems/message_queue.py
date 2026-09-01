"""
Simple in-memory message queue.

This demonstrates the basic idea behind asynchronous
communication between distributed services.
"""

from queue import Queue
from typing import Any


class MessageQueue:
    """A simple FIFO message queue."""

    def __init__(self):
        self._queue = Queue()

    def publish(self, message: Any) -> None:
        """Add a message to the queue."""
        self._queue.put(message)

    def consume(self) -> Any:
        """Remove and return the next message."""
        return self._queue.get()

    def empty(self) -> bool:
        """Return True when the queue contains no messages."""
        return self._queue.empty()