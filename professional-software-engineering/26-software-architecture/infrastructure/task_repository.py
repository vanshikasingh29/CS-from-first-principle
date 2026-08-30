"""
Repository Layer

Responsible for storing and retrieving tasks.

The application service does not need to know
whether data is stored in memory, SQLite,
PostgreSQL, or another system.
"""

from domain.task import Task


class TaskRepository:

    def __init__(self):
        self._tasks = []
        self._next_id = 1

    def add(self, title: str) -> Task:

        task = Task(
            id=self._next_id,
            title=title
        )

        self._tasks.append(task)

        self._next_id += 1

        return task

    def get_all(self) -> list[Task]:

        return self._tasks

    def get_by_id(self, task_id: int) -> Task | None:

        for task in self._tasks:

            if task.id == task_id:
                return task

        return None

    def save(self, task: Task) -> Task:

        return task