"""
Presentation Layer

Responsible for HTTP communication.

Routes should remain thin.

Business logic belongs in the application layer.
"""

from flask import Blueprint
from flask import jsonify
from flask import request

from application.task_service import TaskService


def create_task_routes(
    service: TaskService
):

    task_routes = Blueprint(
        "tasks",
        __name__
    )

    @task_routes.post("/tasks")
    def create_task():

        data = request.get_json()

        if data is None:

            return jsonify(
                {
                    "error":
                    "JSON body required."
                }
            ), 400

        try:

            task = service.create_task(
                data.get("title", "")
            )

            return jsonify(
                {
                    "id": task.id,
                    "title": task.title,
                    "completed": task.completed
                }
            ), 201

        except ValueError as error:

            return jsonify(
                {
                    "error": str(error)
                }
            ), 400


    @task_routes.get("/tasks")
    def list_tasks():

        tasks = service.list_tasks()

        result = []

        for task in tasks:

            result.append(
                {
                    "id": task.id,
                    "title": task.title,
                    "completed": task.completed
                }
            )

        return jsonify(result)


    @task_routes.post(
        "/tasks/<int:task_id>/complete"
    )
    def complete_task(task_id):

        try:

            task = service.complete_task(
                task_id
            )

            return jsonify(
                {
                    "id": task.id,
                    "title": task.title,
                    "completed": task.completed
                }
            )

        except ValueError as error:

            return jsonify(
                {
                    "error": str(error)
                }
            ), 404


    return task_routes