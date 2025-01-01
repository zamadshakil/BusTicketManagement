# Bus Ticket Management System  

This project is a simple console-based **Bus Ticket Management System** implemented in C++. It allows customers to book tickets for available bus routes and provides a framework for administrators to manage routes and seat availability.  

---

## **Features**  

 * @file BusTicketManagement.cpp
 * @brief This file contains the implementation of a simple bus ticket management system.
 * 
 * The system allows customers to buy tickets for various bus routes and allows admins to manage the routes.
 * 
 * Structures:
 * - Routes: Represents a bus route with start and end locations, time, fare, and available seats.
 * - user_Routes: Represents a user's booked route with start and end locations, time, fare, and seat number.
 * 
 * Functions:
 * - main: The main function that drives the program. It provides options for customers to buy tickets and for admins to manage routes.
 * 
 * Customer Flow:
 * - The customer logs in and views available routes.
 * - The customer selects a route and the number of tickets to buy.
 * - If the requested number of tickets is available, the tickets are booked and details are displayed.
 * - If not, the customer is prompted to book again or exit.
 * 
 * Admin Flow:
 * - The admin logs in and views available routes.
 * - The admin can add new routes, modify existing routes, or delete routes.
 * - After performing an action, the admin is returned to the main admin menu.
 * 
 * Input:
 * - User input for login choice, route selection, number of tickets, and admin actions.
 * 
 * Output:
 * - Displays available routes, booking confirmation, and admin actions results.

 
### **Customer Functionalities**  
- View available bus routes, including:  
  - Departure and arrival locations.  
  - Travel times.  
  - Ticket fares.  
  - Available seats.  
- Book tickets dynamically:  
  - Validates seat availability before booking.  
  - Displays detailed ticket information after successful booking.  
  - Updates available seats for each route after a booking.  
- Option to reattempt booking if preferred seats are unavailable.  

### **Admin Functionalities** *(Under Development)*  
- Manage bus routes dynamically:  
  - Add new routes.  
  - Remove existing routes.  
  - Update route details (e.g., seat availability, fare).  
- View all routes with complete details.  

---

## **Technologies Used**  

- **Language**: C++  
- **Libraries**:  
  - `<iostream>` for input/output operations.  
  - `<vector>` for dynamic storage of routes and user bookings.  
  - `<string>` for handling textual data like route names and times.  

---

## **How to Run the Project**  

### **Prerequisites**  
- A C++ compiler (e.g., GCC, MinGW, or Visual Studio).  
- Basic knowledge of running console applications.  

### **Steps to Run**  
1. Clone the repository:  
   ```bash  
   git clone https://github.com/zamadshakil/BusTicketManagement.git  
   cd BusTicketManagement  
