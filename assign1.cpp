/***********************************************************
 CSCI 241 - Assignment 1 - Fall 2017
 
 Progammer: Sam Piecz
 Z-ID: Z1732715
 Section: 1
 TA: Sumaiya Abdul
 Date Due: September 14, 2017
 
 Purpose: This program pulls data from a CSV and prints it.
 ************************************************************/

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


/***************************************************************
 Class Provider
 
 Use: Creates a new data type called Provider.
 ***************************************************************/
class Provider
{
    private:
        // list class variables
        char number[7] = {},
        specialty[41] = {},
        name[41] = {},
        address_part_1[41] = {},
        address_part_2[31] = {},
        address_part_3[38] = {},
        phone_number[15] = {};
        
    public:
        // methods
        Provider();
        Provider(const char*,const char*, const char*,const char*, const char*,const char*,const char*);
        void print();
};


// Declare functions so that I may declare them in main
int build_provider_array(Provider []);
void print_provider_array(Provider[], int);


// It's yah boi, main()!  This little beauty just runs other functions.
// Nothing super fancy.
int main()
{
    // sets the number of providers to 0
    int num_of_providers = 0;
    
    // Creates a provider object and allows
    // a maximum of 40 entries
    Provider all_providers[40];
    
    // this creates a variable
    num_of_providers = build_provider_array(all_providers);
    
    // passes argument containing all providers
    // passes argument containing the number of providers
    // that way it has the providers to print out,
    // and it also knows when to stop
    print_provider_array(all_providers, num_of_providers);
    
    return 0;
}


/***************************************************************
 build_provider_array
 
 Use: Oh boy.  Where to start.  Well, this bad larry builds
 arrays.  It starts by declaring some variables so that we can
 do what we need to.  Then it opens up a csv file. Next up, is
 the while loop.  It just loops until it can't get anymore data.
 It also creates a provider object instance and ties each 
 individual provider object to it's required data.
 
 Parameters: 1. provider_array[]:  Just an empty array.  This is needed
 because we have to pack each individual provider into a provider
 array.  Inception.
 
 Returns: A count.  Need to be able to loop through the provider
 array.
 ***************************************************************/
int build_provider_array(Provider provider_array[])
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
    
    // create counter
    int count = 0;
    
    // open csv as inFile
    inFile.open("providers.csv");
    if (!inFile)
    {
        // if not file error
        cerr << "Unable to open input file. \n";
        exit(1);
    }
    
    // Try and get providers first data field, which is number.
    // If it is present, continue looping through file.
    while (getline(inFile, number ,','))
    {
        // Get's all data from CSV.  Use's comma a delimeter -- so it can split the data up.
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
        
        // concatenate name for easier formatting
        name = last_name + ", " + first_name;
        
        // if middle name exists format the name this way
        // some providers have no middle initial
        if(middle_initial.length() != 0){
            name += ", " + middle_initial;
        }
        
        // Add the title to the name
        name += ", " + title;
        
        // concatenate address part 3
        address_part_3 = city + ", " + state + " " + zip_code;

        // create instance of class and provide each string as argument
        // while converting the string
        Provider individual_provider(number.c_str(),
                   name.c_str(),
                   specialty.c_str(),
                   address_part_1.c_str(),
                   address_part_2.c_str(),
                   address_part_3.c_str(),
                   phone_number.c_str());
        
        // this uses the count variable to start packing the array at index 0
        // the count ++ will increment the count variable so it doesn't over pack
        // another variable
        provider_array[count] = individual_provider;
        
        // see comments on line above ^^^
        count++;
        
    }
    
    // returns the count variable for use above
    return count;
}


/***************************************************************
 print_provider_array
 
 Use: Loops through array of each individual provider and calls
 the provider print method to output each individual provider's
 data.
 
 Parameters: 1. p_array: An array containing arrays of each
 individual provider's data.
 
 2. j: Placeholder for loop, nothing worth describing.
 ***************************************************************/
void print_provider_array(Provider provider_array[], int j)
{
    // loops through each item in provider array and prints it
    for (int i = 0; i < j; i++)
    {
        provider_array[i].print();
    }
}


/***************************************************************
 Provider
 
 Use: Method that allows instation of an instance of the Provider class
 
 Parameters: nothing
 Returns: nothing
 ***************************************************************/
Provider::Provider()
{
}


/***************************************************************
 Provider
 
 Use: Method that allows the updating or setting of Provider data
 
 Parameters: 1. ar: an array of integers to be sorted.
 2. numItems: the number of items to be sorted.
 Returns: nothing
 ***************************************************************/
Provider::Provider(const char* number_1,
                   const char* name_1,
                   const char* specialty_1,
                   const char* address_part_1_1,
                   const char* address_part_2_1,
                   const char* address_part_3_1,
                   const char* phone_number_1)
{
    strcpy(number, number_1);
    strcpy(name, name_1);
    strcpy(specialty, specialty_1);
    strcpy(address_part_1, address_part_1_1);
    strcpy(address_part_2, address_part_2_1);
    strcpy(address_part_3, address_part_3_1);
    strcpy(phone_number, phone_number_1);
}


/***************************************************************
 print
 
 Use: Well.  If you didn't already guess what this function does,
 I know it's a hard one, it prints provider data.  Pretty neat.
 
 Parameters: nothing
 Returns: nothing
 ***************************************************************/
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

