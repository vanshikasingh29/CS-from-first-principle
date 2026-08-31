"""
============================================================
Repository Layer
============================================================

Responsible for database operations.

The rest of the application communicates
with this repository rather than writing SQL
everywhere.
"""

from database import create_connection


class TaskRepository:

    def create_user(
        self,
        name: str,
        email: str
    ) -> int:
        """
        Insert a new user and return their ID.
        """

        connection = create_connection()

        cursor = connection.execute(
            """
            INSERT INTO users (name, email)
            VALUES (?, ?)
            """,
            (name, email)
        )

        connection.commit()

        user_id = cursor.lastrowid

        connection.close()

        return user_id


    def create_task(
        self,
        user_id: int,
        title: str
    ) -> int:
        """
        Insert a task belonging to a user.
        """

        connection = create_connection()

        cursor = connection.execute(
            """
            INSERT INTO tasks
            (user_id, title)
            VALUES (?, ?)
            """,
            (user_id, title)
        )

        connection.commit()

        task_id = cursor.lastrowid

        connection.close()

        return task_id


    def get_user_tasks(
        self,
        user_id: int
    ) -> list[tuple]:
        """
        Retrieve all tasks belonging to a user.
        """

        connection = create_connection()

        cursor = connection.execute(
            """
            SELECT
                id,
                title,
                completed
            FROM tasks
            WHERE user_id = ?
            ORDER BY id
            """,
            (user_id,)
        )

        tasks = cursor.fetchall()

        connection.close()

        return tasks


    def complete_task(
        self,
        task_id: int
    ) -> None:
        """
        Mark a task as completed.
        """

        connection = create_connection()

        connection.execute(
            """
            UPDATE tasks
            SET completed = 1
            WHERE id = ?
            """,
            (task_id,)
        )

        connection.commit()

        connection.close()


    def count_tasks(
        self,
        user_id: int
    ) -> int:
        """
        Demonstrates an aggregate SQL query.
        """

        connection = create_connection()

        cursor = connection.execute(
            """
            SELECT COUNT(*)
            FROM tasks
            WHERE user_id = ?
            """,
            (user_id,)
        )

        count = cursor.fetchone()[0]

        connection.close()

        return count