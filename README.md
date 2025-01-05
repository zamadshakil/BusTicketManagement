
# Bus Ticket Management System

This project is a console-based **Bus Ticket Management System** implemented in C++. It allows customers to book tickets for available bus routes and provides a framework for administrators to manage routes and seat availability.

---

## **Features**

### **Customer Functionalities**
- **View Available Bus Routes:**
  - Departure and arrival locations.
  - Travel times.
  - Ticket fares.
  - Available seats.
- **Book Tickets:**
  - Validates seat availability before booking.
  - Allows multiple ticket purchases in a single transaction.
  - Displays detailed ticket information after successful booking.
  - Updates seat availability dynamically after booking.
- **Retry Booking:**
  - Prompts customers to book again if preferred seats are unavailable.

### **Admin Functionalities**
- **Manage Bus Routes:**
  - Add new routes with complete details.
  - Remove existing routes from the system.
  - Update route details, such as fare or seat availability.
- **View All Routes:**
  - Displays a summary of all routes with complete details, including available seats.

---

## **Code Overview**

The implementation leverages C++ features like structures and dynamic memory handling to ensure efficient data management.

- **Structures:**
  - `Routes`: Represents a bus route with start and end locations, timing, fare, and seat availability.
  - `user_Routes`: Represents customer bookings, storing details like route information and booked seats.

- **Main Logic:**
  - Provides a menu-driven interface for both customers and admins.
  - Customer actions include viewing routes and booking tickets.
  - Admin actions include managing bus routes and their details.

- **Key Functions:**
  - `main()`: Drives the program with separate flows for customers and admins.
  - Customer-specific and admin-specific functions handle respective operations like viewing, booking, and managing routes.

---

## **Technologies Used**

- **Programming Language:** C++
- **Standard Libraries:**
  - `<iostream>`: For input and output operations.
  - `<vector>`: For dynamic storage of routes and bookings.
  - `<string>`: For managing textual data like route names and times.

---

## **How to Run the Project**

### **Prerequisites**
- A C++ compiler (e.g., GCC, MinGW, or Visual Studio).
- Basic knowledge of running console-based applications.

### **Steps to Run**
1. Clone the repository:
   ```bash
   git clone https://github.com/zamadshakil/BusTicketManagement.git
   cd BusTicketManagement
   ```
2. Compile the code:
   ```bash
   g++ BusTicketManagement.cpp -o BusTicketManagement
   ```
3. Run the program:
   ```bash
   ./BusTicketManagement
   ```

---

## **Future Enhancements**
- Add user authentication for customers and admins.
- Implement data persistence using file handling.
- Introduce ticket cancellation and modification features.
- Enhance the user interface for better usability.
