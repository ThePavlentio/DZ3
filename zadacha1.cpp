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
    Address(std::string cityName, std::string streetName, int buildingNum, int apartsNum) : city{ cityName }, street{ streetName }, building{ buildingNum }, aparts{ apartsNum }
    {
    }

    void setCity(std::string cityName) { city = cityName; }
    void setStreet(std::string streetName) { street = streetName; }
    void setBuilding(int buildingNum) { building = buildingNum; }
    void setAparts(int apartsNum) { aparts = apartsNum; }
    std::string printAddress()
    {
        std::string outputAddress = city + ", " + street + ", " + std::to_string(building) + ", " + std::to_string(aparts) + "\n";
        return outputAddress;
    }

    ~Address() {};
};

int main()
{
    setlocale(LC_ALL, "rus");

    int numAddresses{};
    std::string city{};
    std::string street{};
    int building{};
    int aparts{};

    std::ifstream ifile{ "in.txt" };

    ifile >> numAddresses;

    Address* arrAddress = new Address[numAddresses];

    if (ifile.is_open())
    {
        for (int i{}; i < numAddresses; ++i)
        {
            ifile >> city;
            arrAddress[i].setCity(city);

            ifile >> street;
            arrAddress[i].setStreet(street);

            ifile >> building;
            arrAddress[i].setBuilding(building);

            ifile >> aparts;
            arrAddress[i].setAparts(aparts);
        }
    }

    ifile.close();


    std::ofstream ofile{ "out.txt" };

    if (ofile.is_open())
    {
        ofile << numAddresses << std::endl;

        for (int i{ numAddresses - 1 }; i >= 0; --i)
        {
            ofile << arrAddress[i].printAddress();
        }
    }

    ofile.close();

    delete[] arrAddress;

    return 0;
}


