"""
============================================================
Topic 27 — Database Engineering Demonstration
============================================================

Demonstrates:

- Database initialisation
- Relational data
- Primary keys
- Foreign keys
- CRUD operations
- Parameterised SQL
- Indexing
- Aggregation
============================================================
"""

from database import initialise_database
from repository import TaskRepository


def main():

    print()
    print("=" * 55)
    print(" Database & Data Engineering Demonstration")
    print("=" * 55)


    # -----------------------------------------------------
    # Initialise database
    # -----------------------------------------------------

    initialise_database()

    repository = TaskRepository()


    # -----------------------------------------------------
    # Create user
    # -----------------------------------------------------

    print("\n1. Creating user")

    user_id = repository.create_user(
        "Alice",
        "alice@example.com"
    )

    print(
        f"Created user with ID: {user_id}"
    )


    # -----------------------------------------------------
    # Create tasks
    # -----------------------------------------------------

    print("\n2. Creating tasks")

    task_one = repository.create_task(
        user_id,
        "Study database indexing"
    )

    task_two = repository.create_task(
        user_id,
        "Learn transactions"
    )

    print(
        f"Created task IDs: "
        f"{task_one}, {task_two}"
    )


    # -----------------------------------------------------
    # Retrieve tasks
    # -----------------------------------------------------

    print("\n3. Retrieving user tasks")

    tasks = repository.get_user_tasks(
        user_id
    )

    for task in tasks:

        task_id, title, completed = task

        print(
            f"{task_id}: "
            f"{title} "
            f"[completed={bool(completed)}]"
        )


    # -----------------------------------------------------
    # Update task
    # -----------------------------------------------------

    print("\n4. Completing first task")

    repository.complete_task(
        task_one
    )

    print("Task completed.")


    # -----------------------------------------------------
    # Aggregate query
    # -----------------------------------------------------

    print("\n5. Counting tasks")

    count = repository.count_tasks(
        user_id
    )

    print(
        f"Total tasks: {count}"
    )


    print("\nDatabase demonstration complete.")


if __name__ == "__main__":
    main()