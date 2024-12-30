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
};
int main() {
	string LHR = "Lahore", ISL = "Islamabad", KAR = "Karachi", MLT = "Multan", FAS = "Faisalabad";
	int route_choice, num_tickets, book_again; 
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
		for (int i = 0; i < routes.size(); i++) {
			int index_choice=i;
			cout << ++index_choice << ". " << endl;
			cout << "Route: from  " << routes[i].start << " to " << routes[i].end << endl;
			cout << "Time: " << routes[i].start_end_time << endl;
			cout << "Fare: " << routes[i].fare << endl;
			cout << "Available Seats: " << routes[i].available_seats << endl;
			cout << endl;
		}

		cout << "Enter your choice to buy that ticket: " << endl;
		cin >> route_choice;
		cout << "Enter the number of tickets you want to buy: " << endl;
		cin >> num_tickets;
		if (num_tickets <= routes[--route_choice].available_seats)
		{
			user_routes.push_back({ routes[--route_choice].start, routes[--route_choice].end, routes[--route_choice].start_end_time, routes[--route_choice].fare, routes[--route_choice].available_seats });
			routes[--route_choice].available_seats = routes[--route_choice].available_seats - 1;
			cout << "Your Ticket has been booked successfully" << endl;
			cout << "Your Ticket Details are:- " << endl;
			cout << "Route: from  " << user_routes.back().start << " to " << user_routes.back().end << endl;
			cout << "Time: " << user_routes.back().start_end_time << endl;
			cout << "Fare: " << user_routes.back().fare << endl;
			cout << "Seat Number: " << user_routes.back().seat_num << endl;
		}
		else {
			cout << "Sorry!" <<  num_tickets << " Seats are not available for this route" << endl;
			cout << "Available Seats are: " << routes[--route_choice].available_seats << endl;
			cout << "Do you wanna book any other ticket(with less seats or other route.)\n Then enter 1 to book again and 2 to Exit: ";
			cin >> book_again;
			if (book_again == 1) goto bookagain;
			else exit(0);
		}




	}
	else if (login_choice == 2) {
		cout << "LogedIn as Admin" << endl;
	}
	else {
		cout << "Invalid Choice" << endl;
	}



























	/*string LHR = "Lahore", ISL="Islamabad", KAR="Karachi", MLT="Multan", FAS = "Faisalabad";
	int a = 10;
	vector<Routes> routes = {
		{LHR, ISL, "12:00 am to 05:00 am", 1500},
		{LHR, KAR, "10:00 am to 05:00 pm", 3000},
		{LHR, MLT, "11:00 pm to 05:00 am", 2000},
		{LHR, FAS, "01:00 pm to 05:00 pm", 1000}
	};
	cout << routes.size() << endl;
	for (int i = 0; i < routes.size(); i++) {
		cout << "Route: " << routes[i].start << endl;
		cout << "Route: " << routes[i].end << endl;
		cout << "Time: " << routes[i].start_end_time << endl;
		cout << "Fare: " << routes[i].fare << endl;
		cout << endl;
	}
	routes.push_back({ ISL, KAR, "12:00 am to 05:00 am", 4000 });
	cout << routes.size() << endl;
	for (int i = 0; i < routes.size(); i++) {
		cout << "Route: " << routes[i].start << endl;
		cout << "Route: " << routes[i].end << endl;
		cout << "Time: " << routes[i].start_end_time << endl;
		cout << "Fare: " << routes[i].fare << endl;
		cout << endl;
	}*/



















	return 0;
}