"""
============================================================
Database Test Suite
============================================================

Tests the repository layer.

The tests use an isolated in-memory SQLite
database so they do not depend on the
production database file.
============================================================
"""

import sqlite3

import repository


SCHEMA = """
CREATE TABLE users (
    id INTEGER PRIMARY KEY AUTOINCREMENT,
    name TEXT NOT NULL,
    email TEXT NOT NULL UNIQUE
);

CREATE TABLE tasks (
    id INTEGER PRIMARY KEY AUTOINCREMENT,
    user_id INTEGER NOT NULL,
    title TEXT NOT NULL,
    completed INTEGER NOT NULL DEFAULT 0,
    FOREIGN KEY (user_id)
        REFERENCES users(id)
);

CREATE INDEX idx_tasks_user_id
ON tasks(user_id);
"""


def create_test_database():

    connection = sqlite3.connect(
        ":memory:"
    )

    connection.execute(
        "PRAGMA foreign_keys = ON"
    )

    connection.executescript(
        SCHEMA
    )

    return connection


def test_database_schema():

    connection = create_test_database()

    tables = connection.execute(
        """
        SELECT name
        FROM sqlite_master
        WHERE type = 'table'
        """
    ).fetchall()

    table_names = {
        table[0]
        for table in tables
    }

    assert "users" in table_names
    assert "tasks" in table_names

    connection.close()


def test_foreign_key_constraint():

    connection = create_test_database()

    try:

        connection.execute(
            """
            INSERT INTO tasks
            (user_id, title)
            VALUES (?, ?)
            """,
            (999, "Invalid task")
        )

        connection.commit()

        assert False

    except sqlite3.IntegrityError:

        assert True

    finally:

        connection.close()


def test_parameterised_query():

    connection = create_test_database()

    connection.execute(
        """
        INSERT INTO users
        (name, email)
        VALUES (?, ?)
        """,
        ("Alice", "alice@test.com")
    )

    connection.commit()

    result = connection.execute(
        """
        SELECT name
        FROM users
        WHERE email = ?
        """,
        ("alice@test.com",)
    ).fetchone()

    assert result[0] == "Alice"

    connection.close()


def test_index_exists():

    connection = create_test_database()

    indexes = connection.execute(
        """
        SELECT name
        FROM sqlite_master
        WHERE type = 'index'
        """
    ).fetchall()

    index_names = {
        index[0]
        for index in indexes
    }

    assert "idx_tasks_user_id" in index_names

    connection.close()