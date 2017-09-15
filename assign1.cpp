//*************************************************************
// CSCI 241 - Assignment 1
//
// Progammer: Sam Piecz
//
// Purpose: Read data from csv, pack data to array, print data.
//*************************************************************

#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstdlib>
#include <cstring>
#include <string>

using std::cerr;
using std::cout;
using std::endl;
using std::fixed;
using std::ifstream;
using std::setprecision;
using std::string;
using std::cin;

//void build_array();


class Provider
{
    private:
        // list class variables
    
        // fill rest of arrays out
        char number[7] = {},
        specialty[41] = {},
        name[41] = {},
        address_part_1[41] = {},
        address_part_2[31] = {},
        address_part_3[38] = {},
        phone_number[15] = {};

    public:
        // list methods
        // declare more methods
        Provider();
        Provider(const char*,const char*, const char*,const char*, const char*,const char*,const char*);

        void print();
};


int build_provider_array(Provider []);
void print_provider_array(Provider[], int);

int main()
{
    int num_of_providers = 0;
    
    Provider not_p[40];
    
    num_of_providers = build_provider_array(not_p);
    
    print_provider_array(not_p, num_of_providers);
    
    return 0;
}

int build_provider_array(Provider p_array[])
{
    
    ifstream inFile;
    string number,
    specialty,
    name,
    last_name,
    first_name,
    middle_initial,
    title,
    address_part_1,
    address_part_2,
    address_part_3,
    city,
    state,
    zip_code,
    phone_number;
    
    // create count
    int count = 0;
    
    // open csv as inFile
    inFile.open("providers.csv");
    if (!inFile)
    {
        // if not file error
        cerr << "Unable to open input file. \n";
        exit(1);
    }
    
    while (getline(inFile, number ,','))
    {
        // make sure to check order of file and allocate proper memory
        getline(inFile, specialty, ',');
        getline(inFile, last_name, ',');
        getline(inFile, first_name, ',');
        getline(inFile, middle_initial, ',');
        getline(inFile, title, ',');
        getline(inFile, address_part_1, ',');
        getline(inFile, address_part_2, ',');
        getline(inFile, city, ',');
        getline(inFile, state, ',');
        getline(inFile, zip_code, ',');
        getline(inFile, phone_number);
        
        // concatenate name
        
        name = last_name + ", " + first_name;
        
        if(middle_initial.length() != 0){
            name += ", " + middle_initial;
        }
        
        name += ", " + title;
        
        // concatenate address part 3
        address_part_3 = city + ", " + state + " " + zip_code;
        
        // also check if a middle initial is available
        // otherwise this will break stufff
        
        // create instance of class and provide each string as argument
        // while converting the string
        
        // pack in the rest of the variables ie name etc
        Provider p(number.c_str(), name.c_str(), specialty.c_str(), address_part_1.c_str(), address_part_2.c_str(), address_part_3.c_str(), phone_number.c_str());
        
        p_array[count] = p;
        
        count++;
    
    }
    
    
    return count;
}

void print_provider_array(Provider p_array[], int j)
{
    for (int i = 0; i < j; i++)
    {
        p_array[i].print();
    }
}

// Method that allows instation of an instance of the Provider class
Provider::Provider()
{
}

// Method that allows the updating or setting of Provider data
Provider::Provider(const char* number_1,const char* name_1,const char* specialty_1, const char* address_part_1_1,const char* address_part_2_1,const char* address_part_3_1,const char* phone_number_1)
{
    strcpy(number, number_1);
    strcpy(name, name_1);
    strcpy(specialty, specialty_1);
    strcpy(address_part_1, address_part_1_1);
    strcpy(address_part_2, address_part_2_1);
    strcpy(address_part_3, address_part_3_1);
    strcpy(phone_number, phone_number_1);
}

// Prints provider data
void Provider::print()
{
    // print provider
    cout << "#" << number << endl;
    cout << name << endl;
    cout << specialty << endl;
    cout << address_part_1 << endl;
    cout << address_part_2 << endl;
    cout << address_part_3 << endl;
    cout << phone_number << endl;
    cout << "\n";
}



