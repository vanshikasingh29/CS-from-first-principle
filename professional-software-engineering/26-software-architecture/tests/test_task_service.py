"""
Tests for the application layer.

These tests do not require Flask.

This demonstrates why separating
business logic from HTTP infrastructure
improves testability.
"""

import pytest

from infrastructure.task_repository import (
    TaskRepository
)

from application.task_service import (
    TaskService
)


def create_service():

    repository = TaskRepository()

    return TaskService(
        repository
    )


def test_create_task():

    service = create_service()

    task = service.create_task(
        "Learn clean architecture"
    )

    assert task.id == 1

    assert (
        task.title ==
        "Learn clean architecture"
    )

    assert task.completed is False


def test_complete_task():

    service = create_service()

    task = service.create_task(
        "Write tests"
    )

    completed = service.complete_task(
        task.id
    )

    assert completed.completed is True


def test_empty_title_rejected():

    service = create_service()

    with pytest.raises(ValueError):

        service.create_task("")