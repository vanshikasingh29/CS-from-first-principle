"""
Application Service Layer

Contains application use cases.

This layer coordinates domain objects
and infrastructure.
"""

from domain.task import Task
from infrastructure.task_repository import TaskRepository


class TaskService:

    def __init__(
        self,
        repository: TaskRepository
    ):
        self.repository = repository

    def create_task(
        self,
        title: str
    ) -> Task:

        if not title or not title.strip():

            raise ValueError(
                "Task title cannot be empty."
            )

        return self.repository.add(
            title.strip()
        )

    def list_tasks(self) -> list[Task]:

        return self.repository.get_all()

    def complete_task(
        self,
        task_id: int
    ) -> Task:

        task = self.repository.get_by_id(
            task_id
        )

        if task is None:

            raise ValueError(
                "Task not found."
            )

        task.completed = True

        return self.repository.save(task)