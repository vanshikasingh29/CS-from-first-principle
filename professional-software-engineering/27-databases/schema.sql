/*
============================================================
CS From First Principles
Phase 6 — Professional Software Engineering
Topic 27 — Databases & Data Engineering

Database schema demonstrating:
- Relational modelling
- Primary keys
- Foreign keys
- Constraints
- Indexing
============================================================
*/

CREATE TABLE IF NOT EXISTS users (
    id INTEGER PRIMARY KEY AUTOINCREMENT,

    name TEXT NOT NULL,

    email TEXT NOT NULL UNIQUE
);


CREATE TABLE IF NOT EXISTS tasks (
    id INTEGER PRIMARY KEY AUTOINCREMENT,

    user_id INTEGER NOT NULL,

    title TEXT NOT NULL,

    completed INTEGER NOT NULL DEFAULT 0,

    FOREIGN KEY (user_id)
        REFERENCES users(id)
        ON DELETE CASCADE
);


/*
Index used to make queries filtering
tasks by user more efficient.
*/

CREATE INDEX IF NOT EXISTS idx_tasks_user_id
ON tasks(user_id);