#include<vector>
#include<iostream>
using namespace std;

struct Routes {
	string start, end, start_end_time;
	int fare, available_seats;
};
int main() {
	string LHR = "Lahore", ISL = "Islamabad", KAR = "Karachi", MLT = "Multan", FAS = "Faisalabad";
	int route_choice; 
	vector<Routes> user_routes, routes = {
		{LHR, ISL, "12:00 am to 05:00 am", 1500, 30},
		{LHR, KAR, "10:00 am to 05:00 pm", 3000, 10},
		{LHR, MLT, "11:00 pm to 05:00 am", 2000, 24},
		{LHR, FAS, "01:00 pm to 05:00 pm", 1000, 40}
	};
	int login_choice;
	cout << "Enter your choice to Login\n1. Customer(Buy a Tickets)\n2. Admin(Manage Tickets)" << endl;
	cin >> login_choice;
	if (login_choice == 1) {
		cout << "Loged in as Customer\n Enter your choice to buy that ticket.\n These are the available routes:- " << endl;
		for (int i = 0; i < routes.size(); i++) {
			int route_choice=i;
			cout << ++route_choice << ". " << endl;
			cout << "Route: from  " << routes[i].start << " to " << routes[i].end << endl;
			cout << "Time: " << routes[i].start_end_time << endl;
			cout << "Fare: " << routes[i].fare << endl;
			cout << "Available Seats: " << routes[i].available_seats << endl;
			cout << endl;
		}


		cout << "Enter your choice to buy that ticket: " << endl;
		cin >> route_choice;
		user_routes.push_back(routes[--route_choice]);
		routes[--route_choice].available_seats = routes[--route_choice].available_seats - 1;
		cout << "Your Ticket has been booked successfully" << endl;





















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