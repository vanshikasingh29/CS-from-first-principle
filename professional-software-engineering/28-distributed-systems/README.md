# Topic 28 — Distributed Systems

A practical laboratory exploring the foundations of distributed systems.

## Concepts Demonstrated

* Service-to-service communication
* REST APIs
* Service boundaries
* Health checks
* Network failures
* Request timeouts
* Retry mechanisms
* Idempotency
* Message queues
* Independent services

## Architecture

```text
              HTTP
Client ──────────────────► Service A
                              │
                              │ HTTP
                              ▼
                         Service B
                              │
                              ▼
                         Order Store
```

The services run independently and communicate through HTTP.

## Running

Install dependencies:

```bash
pip install -r requirements.txt
```

Start Service B:

```bash
python service_b.py
```

In another terminal, start Service A:

```bash
python service_a.py
```

In a third terminal:

```bash
python client.py
```

## Tests

```bash
pytest
```

## Key Engineering Ideas

### Failure

Distributed systems assume that network communication can fail.

Service A therefore uses:

* timeouts
* retries
* error handling

### Idempotency

Service B tracks processed order IDs.

If the same request is received twice, it does not process the order twice.

This is important because distributed systems can experience:

* retries
* duplicate requests
* network uncertainty

### Message Queues

`MessageQueue` demonstrates the basic producer/consumer model used by systems such as Kafka, RabbitMQ and other messaging infrastructure.

## Learning Outcome

This laboratory provides a practical foundation for understanding how independent services communicate, fail, retry and maintain reliable behaviour across network boundaries.
