# Bus Ticket Management System  

This project is a simple console-based **Bus Ticket Management System** implemented in C++. It allows customers to book tickets for available bus routes and provides a framework for administrators to manage routes and seat availability.  

---

## **Features**  

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
