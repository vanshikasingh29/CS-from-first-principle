"""
Application Entry Point

This file performs dependency composition.

It connects:

Repository
    ↓
Service
    ↓
HTTP Routes
"""

from flask import Flask

from infrastructure.task_repository import (
    TaskRepository
)

from application.task_service import (
    TaskService
)

from presentation.routes import (
    create_task_routes
)


def create_app():

    app = Flask(__name__)

    repository = TaskRepository()

    service = TaskService(
        repository
    )

    routes = create_task_routes(
        service
    )

    app.register_blueprint(
        routes,
        url_prefix="/api"
    )

    return app


if __name__ == "__main__":

    app = create_app()

    app.run(
        debug=True
    )