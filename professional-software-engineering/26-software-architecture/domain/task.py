"""
Domain Entity

The domain layer contains the core business objects.

It should not depend on Flask, databases,
or other infrastructure details.
"""

from dataclasses import dataclass


@dataclass
class Task:
    """
    Represents a task in the system.
    """

    id: int
    title: str
    completed: bool = False