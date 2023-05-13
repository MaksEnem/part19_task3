#include <iostream>
#include <fstream>

int main() {

	std::fstream statement;

	std::string name[10];
	std::string surname[10];
	int amount_to_be_paid[10];
	std::string data[10];

	statement.open("statement.txt");

	if (statement.is_open()) {

		int max_sum = 0;
		int total_sum = 0;
		int max;

		for (int i = 0; i < 10; ++i) {

			statement >> name[i] >> surname[i] >> amount_to_be_paid[i] >> data[i];

			if (amount_to_be_paid[i] > max_sum) {

				max_sum = amount_to_be_paid[i];
				max = i;

			}

			total_sum += amount_to_be_paid[i];

			if (i == 9) {

				std::cout << "Person with the highest payout: " << name[max] << " " << surname[max] << std::endl;

			}
		}					

		std::cout << "The maximum payout amount is: " << max_sum << std::endl;
		std::cout << "The total amount according to the statement: " << total_sum << std::endl;

		statement.close();

	}
	else {

		std::cout << "WARNING!\n";
		std::cout << "ERROR!!!\n";
		std::cout << "File is not open\n";

	}	
}