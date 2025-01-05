#include<vector>
#include<iostream>
using namespace std;

struct Routes {
	string start, end, start_end_time;
	int fare, available_seats;
};
struct user_Routes {
	string start, end, start_end_time;
	int fare, seat_num;
	vector<int> num_tickets;
};
int main() {
	string LHR = "Lahore", ISL = "Islamabad", KAR = "Karachi", MLT = "Multan", FAS = "Faisalabad";
	int route_choice, num_Tickets, book_again;
	vector<Routes> routes = {
		{LHR, ISL, "12:00 am to 05:00 am", 1500, 30},
		{LHR, KAR, "10:00 am to 05:00 pm", 3000, 10},
		{LHR, MLT, "11:00 pm to 05:00 am", 2000, 24},
		{LHR, FAS, "01:00 pm to 05:00 pm", 1000, 40}
	};
	vector<user_Routes> user_routes = {};
	int login_choice;
	cout << "Enter your choice to Login\n1. Customer(Buy a Tickets)\n2. Admin(Manage Tickets)" << endl;
	cin >> login_choice;
	if (login_choice == 1) {
		cout << "Loged in as Customer\n";
		bookagain:
		cout<< "Enter your choice to buy that ticket.\n These are the available routes : -" << endl;
		for (int i = 0; i < routes.size(); i++)  {
			int index_choice=i;
			cout << ++index_choice << ". " << endl;
			cout << "Route: from  " << routes[i].start << " to " << routes[i].end << endl;
			cout << "Time: " << routes[i].start_end_time << endl;
			cout << "Fare: " << routes[i].fare << endl;
			cout << "Available Seats: " << routes[i].available_seats << endl;
			cout << endl;
		}
		cout << "Enter your route choice to buy that ticket: " << endl;
		cin >> route_choice;
		cout << "Enter the number of tickets you want to buy: " << endl;
		cin >> num_Tickets;
		int ticket_choice = --route_choice;
		if (num_Tickets <= routes[ticket_choice].available_seats)
		{
			user_routes.push_back({ routes[ticket_choice].start, routes[ticket_choice].end, routes[ticket_choice].start_end_time, routes[ticket_choice].fare });
			int seat_num = routes[ticket_choice].available_seats - num_Tickets;
			for (int i = seat_num; i >= routes[ticket_choice].available_seats; i++) {
				user_routes.back().num_tickets.push_back(i);
			}
			routes[ticket_choice].available_seats = routes[ticket_choice].available_seats - 1;

			cout << "Your Ticket has been booked successfully" << endl;
			cout << "Your Ticket Details are:- " << endl;
			cout << "Route: from  " << user_routes.back().start << " to " << user_routes.back().end << endl;
			cout << "Time: " << user_routes.back().start_end_time << endl;
			cout << "Fare: " << user_routes.back().fare << endl;
			cout << "Seat Number: ";
			for (int j = 0; j < num_Tickets; j++)
			{
				cout << user_routes.back().num_tickets[j] << ", ";
			}
			cout << "Do you wanna book any other ticket. \n Then enter 1 to book again, 2 to view own Tickets and 3 to exit: ";
			cin >> book_again;
			if (book_again == 1) goto bookagain;
			else if (book_again == 2) {
				//view own tickets
				cout << "Your Tickets are:- " << endl;
				for (int i = 0; i < user_routes.size(); i++) {
					cout << "Route: from  " << user_routes[i].start << " to " << user_routes[i].end << endl;
					cout << "Time: " << user_routes[i].start_end_time << endl;
					cout << "Fare: " << user_routes[i].fare << endl;
					for (int j = 0; j < user_routes[i].num_tickets.size(); j++)
					{
						cout << "Seat Number: " << user_routes[i].num_tickets[j] << endl;
					}
				}

			}
				else exit(0);
		}
		else {
			cout << "Sorry!" <<  num_Tickets << " Seats are not available for this route" << endl;
			cout << "Available Seats are: " << routes[--route_choice].available_seats << endl;
			cout << "Do you wanna book any other ticket(with less seats or other route.)\n Then enter 1 to book again and 2 to Exit: ";
			cin >> book_again;
			if (book_again == 1) goto bookagain;
			else exit(0);
		}
	}
	else if (login_choice == 2) {
		cout << "LogedIn as Admin" << endl;
		again_in_admin:
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
		int manage_choice;
		cout << "Enter your choice to manage that ticket, enter 1 to add more route, 2 to modify existing route and 3 to delete any existing route:  " << endl;
		cin >> manage_choice;

		if (manage_choice == 1) {
			Routes new_route;
			cout << "Enter start location: ";
			cin >> new_route.start;
			cout << "Enter end location: ";
			cin >> new_route.end;
			cout << "Enter start and end time: ";
			cin>>new_route.start_end_time;
			cout << "Enter fare: ";
			cin >> new_route.fare;
			cout << "Enter available seats: ";
			cin >> new_route.available_seats;
			routes.push_back(new_route);
			cout << "New route added successfully." << endl;
			goto again_in_admin;
		} else if (manage_choice == 2) {
			int route_index;
			enter_m_route_again:
			cout << "Enter the route number to modify: ";
			cin >> route_index;
			route_index--;
			if (route_index >= 0 && route_index < routes.size()) {
				cout << "Enter new start location: ";
				cin >> routes[route_index].start;
				cout << "Enter new end location: ";
				cin >> routes[route_index].end;
				cout << "Enter new start and end time: ";
				cin>> routes[route_index].start_end_time;
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



