# LineUp Management System in C++
![Queue System Image](https://github.com/Amer-css/LineUp-Project/blob/main/queue-system-qms-system-service-counter-scenario-0.jpg?raw=true)

This C++ project implements an object-oriented queue management system designed to issue tickets, estimate waiting times, display queue details, and serve customers in sequence. It's ideal for applications that require customer queue management, such as banks or hospitals.

## Main Classes

### `clsQueueLine`
**Description**: Manages the entire queue, tracks issued tickets, monitors waiting clients, and calculates estimated waiting times.

**Key Properties**:
- `_TotalTickets`: Total number of issued tickets.
- `_AverageServeTime`: Average time required to serve one client.
- `_Prefix`: Custom prefix for ticket numbers, like "A" or "B".

### `clsTicket`
**Description**: Represents a ticket issued when a new client joins the queue.

**Key Properties**:
- `_Number`: Client's unique ticket number.
- `_TicketTime`: Timestamp when the ticket was issued.
- `_WaitingClients`: Number of clients waiting when the ticket was issued.
- `_ExpectedServeTime`: Estimated service time based on waiting clients and average serve time.

## Key Functions

### `clsTicket` Functions
- **`FullNumber`**: Returns the complete ticket number (e.g., A01, B02) for easier readability.
- **`ExpectedServeTime`**: Estimates service time for the client.
- **`PrintA` & `PrintB`**: Print ticket details with different prefixes (A or B) for multi-queue systems.

### `clsQueueLine` Functions
- **`IssueTicket`**: Issues a new ticket and adds it to the queue.
- **`WhoIsNext`**: Returns the ticket number of the next client to be served.
- **`ServeNextClient`**: Serves the next client by removing their ticket from the queue.
- **`PrintInfo`**: Displays queue information like total issued tickets and current waiting clients.
- **`PrintAllTicketA` & `PrintAllTicketB`**: Prints all tickets in the queue by prefix, providing a quick view for staff.

## Additional Notes

- Utilizes `queue` to manage clients in a **FIFO (First-In-First-Out)** order.
- `stack` is included but currently unused; could be applied for undo functionality in the future.
- `clsDate` is used to record actual timestamps, adding credibility and tracking capabilities.

## Sample Usage

```cpp
// Example of creating a queue system and issuing a ticket
clsQueueLine queue("A", 5); // Prefix "A" and average serve time of 5 minutes
queue.IssueTicket();
queue.PrintInfo();
