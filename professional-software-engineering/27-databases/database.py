"""
============================================================
Database Connection Layer
============================================================

Responsible only for creating and configuring
the SQLite database connection.

Keeping this separate means the rest of the
application does not need to know how the
database connection is created.
"""

import sqlite3


DATABASE_NAME = "tasks.db"


def create_connection():
    """
    Create a connection to the SQLite database.
    """

    connection = sqlite3.connect(
        DATABASE_NAME
    )

    # Allows foreign key constraints to work
    # correctly in SQLite.
    connection.execute(
        "PRAGMA foreign_keys = ON"
    )

    return connection


def initialise_database():
    """
    Create database tables and indexes.
    """

    connection = create_connection()

    with open(
        "schema.sql",
        "r",
        encoding="utf-8"
    ) as schema_file:

        schema = schema_file.read()

    connection.executescript(schema)

    connection.commit()

    connection.close()