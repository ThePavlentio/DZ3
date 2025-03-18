#include <iostream>
#include <fstream>
#include <string>

class Address
{
private:
	std::string city{};
	std::string street{};
	int building{};
	int aparts{};

public:

	Address() = default;

	Address(std::string cityName, std::string streetName, int buildingNum, int apartsNum)
	{
		city = setCity(cityName);
		street = setStreet(streetName);
		building = setBuilding(buildingNum);
		aparts = setAparts(apartsNum);
	}

	std::string setCity(std::string cityName) { city = cityName; return city; }
	std::string setStreet(std::string streetName) { street = streetName; return street; }
	int setBuilding(int buildingNum) { building = buildingNum; return building; }
	int setAparts(int apartsNum) { aparts = apartsNum; return aparts; }

	std::string get_output_address()
	{
		std::string outputAddress = city + ", " + street + ", " + std::to_string(building) + ", " + std::to_string(aparts) + '\n';

		return outputAddress;
	}

	std::string get_city() { return city; }
	std::string get_street() { return street; }

	~Address(){}
};



int main()
{
	setlocale(LC_ALL, "rus");

	std::string city{};
	std::string street{};
	int building{};
	int aparts{};

	int numAddress{};

	std::ifstream ifile("in2.txt");

	ifile >> numAddress;

	Address* arrAddress = new Address[numAddress];

	if (ifile.is_open())
	{
		for (int i{}; i < numAddress; ++i)
		{
			ifile >> city;
			ifile >> street;
			ifile >> building;
			ifile >> aparts;

			arrAddress[i].setCity(city);
			arrAddress[i].setStreet(street);
			arrAddress[i].setBuilding(building);
			arrAddress[i].setAparts(aparts);
		}
	}

	ifile.close();

	std::ofstream ofile("out2.txt");

	if (ofile.is_open())
	{
		for (int i{}; i < numAddress; ++i)
		{
			for (int j{}; j < numAddress - 1; ++j)
			{
				if (arrAddress[j].get_city() > arrAddress[j + 1].get_city())
				{
					Address temp = arrAddress[j];
					arrAddress[j] = arrAddress[j + 1];
					arrAddress[j + 1] = temp;
				}

				else if (arrAddress[j].get_city() == arrAddress[j + 1].get_city())
				{
					if (arrAddress[j].get_street() > arrAddress[j + 1].get_street())
					{
						Address temp = arrAddress[j];
						arrAddress[j] = arrAddress[j + 1];
						arrAddress[j + 1] = temp;
					}
				}
			}
		}
	}

	for (int i{}; i < numAddress; ++i)
	{
		ofile << arrAddress[i].get_output_address();
	}

	ofile.close();

	delete[] arrAddress;

	return 0;
}