#include <vector>
#include <iostream>
#include <iomanip>
#include <string>
#include <limits>
using namespace std;

struct Routes {
    string start, end, start_end_time;
    int fare, available_seats;
};

struct UserRoutes {
    string name, phone, start, end, start_end_time;
    int fare;
    vector<int> seat_numbers;
};

void printTicketDetails(const UserRoutes &ticket) {
    cout << "\n=========== Ticket Details ===========\n";
    cout << "Name: " << ticket.name << endl;
    cout << "Phone: " << ticket.phone << endl;
    cout << "Route: From " << ticket.start << " to " << ticket.end << endl;
    cout << "Time: " << ticket.start_end_time << endl;
    cout << "Fare: " << ticket.fare << " PKR" << endl;
    cout << "Seats: ";
    for (size_t i = 0; i < ticket.seat_numbers.size(); ++i) {
        cout << ticket.seat_numbers[i] << (i < ticket.seat_numbers.size() - 1 ? ", " : "\n");
    }
    cout << "====================================\n\n";
}

int main() {
    string LHR = "Lahore", ISL = "Islamabad", KAR = "Karachi", MLT = "Multan", FAS = "Faisalabad";
    int route_choice, num_tickets, book_again;
    vector<Routes> routes = {
        {LHR, ISL, "12:00 am to 05:00 am", 1500, 30},
        {LHR, KAR, "10:00 am to 05:00 pm", 3000, 10},
        {LHR, MLT, "11:00 pm to 05:00 am", 2000, 24},
        {LHR, FAS, "01:00 pm to 05:00 pm", 1000, 40}
    };

    vector<UserRoutes> user_routes;

    int login_choice;
    cout << "Enter your choice to Login\n1. Customer (Buy Tickets)\n2. Admin (Manage Tickets)\n";
    cin >> login_choice;

    if (login_choice == 1) {
        cout << "Logged in as Customer\n";
    book_again:
        cout << "\nAvailable Routes:\n";
        for (size_t i = 0; i < routes.size(); ++i) {
            cout << i + 1 << ". Route: From " << routes[i].start << " to " << routes[i].end << endl;
            cout << "   Time: " << routes[i].start_end_time << endl;
            cout << "   Fare: " << routes[i].fare << " PKR\n";
            cout << "   Available Seats: " << routes[i].available_seats << "\n\n";
        }

        cout << "Enter your route choice: ";
        cin >> route_choice;

        if (route_choice < 1 || route_choice > routes.size()) {
            cout << "Invalid route choice. Please try again.\n";
            goto book_again;
        }

        cout << "Enter the number of tickets you want to book: ";
        cin >> num_tickets;

        int ticket_choice = route_choice - 1;
        if (num_tickets <= routes[ticket_choice].available_seats) {
            UserRoutes new_ticket;

            cout << "Enter your name: ";
            cin.ignore();
            getline(cin, new_ticket.name);
            cout << "Enter your phone number: ";
            getline(cin, new_ticket.phone);

            new_ticket.start = routes[ticket_choice].start;
            new_ticket.end = routes[ticket_choice].end;
            new_ticket.start_end_time = routes[ticket_choice].start_end_time;
            new_ticket.fare = routes[ticket_choice].fare * num_tickets;

            int start_seat = routes[ticket_choice].available_seats - num_tickets + 1;
            for (int i = start_seat; i <= routes[ticket_choice].available_seats; ++i) {
                new_ticket.seat_numbers.push_back(i);
            }

            routes[ticket_choice].available_seats -= num_tickets;
            user_routes.push_back(new_ticket);

            cout << "\nYour ticket has been booked successfully!\n";
            printTicketDetails(new_ticket);

            cout << "Do you want to book another ticket?\n1. Yes\n2. No, view booked tickets\n3. Exit\n";
            cin >> book_again;

            if (book_again == 1) {
                goto book_again;
            } else if (book_again == 2) {
                cout << "\nYour Booked Tickets:\n";
                for (const auto &ticket : user_routes) {
                    printTicketDetails(ticket);
                }
            } else {
                exit(0);
            }
        } else {
            cout << "Sorry, only " << routes[ticket_choice].available_seats << " seats are available for this route.\n";
            cout << "Do you want to try again?\n1. Yes\n2. No\n";
            cin >> book_again;
            if (book_again == 1) {
                goto book_again;
            } else {
                exit(0);
            }
        }
    } else if (login_choice == 2) {
		cout << "LogedIn as Admin" << endl;
		again_in_admin:
		int manage_choice;
		cout << "Enter your choice to manage that ticket, enter 1 to add more route, 2 to modify existing route and 3 to delete any existing route:  " << endl;
		cin >> manage_choice;

		if (manage_choice == 1) {
			Routes new_route;
			cout << "Enter start location: ";
			cin.ignore(); 
			getline(cin, new_route.start);
			cout << "Enter end location: ";
			cin.ignore();
			getline(cin, new_route.end);
			cin.ignore();
			cout << "Enter start and end time: ";
			getline(cin, new_route.start_end_time);
			cout << "Enter fare: ";
			cin >> new_route.fare;
			cout << "Enter available seats: ";
			cin >> new_route.available_seats;
			routes.push_back(new_route);
			cout << "New route added successfully." << endl;
			goto again_in_admin;
		} else if (manage_choice == 2) {
		    
		    cout<< "These are the available routes : -" << endl;
		    for (int i = 0; i < routes.size(); i++) {
			int index_choice = i;
			cout << ++index_choice << ". " << endl;
			cout << "Route: from  " << routes[i].start << " to " << routes[i].end << endl;
			cout << "Time: " << routes[i].start_end_time << endl;
			cout << "Fare: " << routes[i].fare << endl;
			cout << "Available Seats: " << routes[i].available_seats << endl;
			cout << endl;
		}
			int route_index;
			enter_m_route_again:
			cout << "Enter the route number to modify: ";
			cin >> route_index;
			route_index--;
			if (route_index >= 0 && route_index < routes.size()) {
				cout << "Enter new start location: ";
				cin.ignore();
				getline(cin, routes[route_index].start);
				cout << "Enter new end location: ";
			    getline(cin, routes[route_index].end);
				cout << "Enter new start and end time: ";
				getline(cin, routes[route_index].start_end_time);
				cout << "Enter new fare: ";
				cin >> routes[route_index].fare;
				cout << "Enter new available seats: ";
				cin >> routes[route_index].available_seats;
				cout << "Route modified successfully." << endl;
				goto again_in_admin;
			} else {
				cout << "Invalid route number." << endl;
				goto enter_m_route_again;
			}
		} 
		else if (manage_choice == 3) {
			int route_index;
			enter_d_route_again:
			cout << "Enter the route number to delete: ";
			cin >> route_index;
			route_index--;
			if (route_index >= 0 && route_index < routes.size()) {
				routes.erase(routes.begin() + route_index);
				cout << "Route deleted successfully." << endl;
				goto again_in_admin;
			} else {
				cout << "Invalid route number." << endl;
				goto enter_d_route_again;
				
			}
		} 
		else {
			cout << "Invalid choice." << endl;
			goto again_in_admin;
		}
	}
	else {
		cout << "Invalid Choice" << endl;
	}



	return 0;
}
