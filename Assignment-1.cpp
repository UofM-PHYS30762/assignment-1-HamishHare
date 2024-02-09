// Assignment 1 - Hamish Hare
// Program to calculate transition energy using simple Bohr formula

// Headers
#include<iostream>
#include<iomanip>
#include<limits>
#include<math.h>

// Constants
const double ev_to_joule = 1.60218e-19;

// Functions
int get_valid_integer()
{
  // Prompt for an integer until a valid input is given
  int user_input;
  bool valid{false};
  do
  {
    std::cin>>user_input;
    
    if(std::cin.fail())
    {
      std::cout<<"Please enter a valid integer: ";
    }
    else if(user_input < 1)
    {
      std::cout<<"Please enter an integer greater than zero: ";
    }
    else valid = true;

    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
  }while(!valid);

  // Return the output
  std::cout<<"You entered "<<user_input<<std::endl;
  return user_input;
}

char get_valid_char(char option1, char option2)
{
  // Prompt for a character until a valid input is given
  // which matches one of the allowed options above
  char user_input;
  bool valid{false};
  do
  {
    std::cin>>user_input;
    
    if(std::cin.fail())
    {
      std::cout<<"Please enter one of the allowed characters ("<<
      option1<<" or "<<option2<<"): ";
    }
    else if(user_input != option1 && user_input != option2)
    {
      std::cout<<"Please enter one of the allowed characters ("<<
      option1<<" or "<<option2<<"): ";
    }
    else valid = true;

    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
  }while(!valid);

  // Return the output
  std::cout<<"You entered "<<user_input<<std::endl;
  return user_input;
}

// Compute photon energy, Delta E = 13.6*(Z^2)*(1/n_j^2-1/n_i^2) eV
double calculate_energy(int atomic_num, int n_init, int n_fin)
{
  return 13.6*pow(atomic_num, 2.0)*(pow(n_fin, -2.0) - pow(n_init, -2.0));
}

int main()
{
  // Variables
  int atomic_number;
  int n_initial;
  int n_final;

  char energy_unit;
  double energy;

  char continue_tag{'n'};

  // Perform the calculation until the user asks to stop
  do
  {
    // Get an atomic number from the user
    std::cout<<"Enter the atomic number for the atom: ";
    atomic_number = get_valid_integer();

    // Get initial and final quantum numbers from user
    std::cout<<"Enter the initial quantum number: ";
    n_initial = get_valid_integer();
    std::cout<<"Enter the final quantum number: ";
    n_final = get_valid_integer();

    // Validate for n_initial >= n_final
    while(n_initial < n_final)
    {
      std::cout<<"Your final state ("<<n_final<<
      ") is greater than your initial state ("<<
      n_initial<<")."<<std::endl;
      std::cout<<"Please enter a new final quantum number: ";
      n_final = get_valid_integer();
    }

    // Get an input of the units (either eV or J)
    std::cout<<"Would you like the energy in eV (e) or Joules (J)?: ";
    energy_unit = get_valid_char('e', 'J');

    // Compute the photon energy and output the answer
    energy = calculate_energy(atomic_number, n_initial, n_final); // eV

    // .. format energy
    if(energy_unit == 'e')
    {
      std::cout<<"The photon released in the transition from n="<<n_initial<<
      " to n="<<n_final<<" has an energy of "<<std::setprecision(3)<<energy<<" eV"<<std::endl;
    }
    else
    {
      energy*=ev_to_joule;
      std::cout<<"The photon released in the transition from n="<<n_initial<<
      " to n="<<n_final<<" has an energy of "<<std::setprecision(3)<<energy<<" J"<<std::endl;
    }

    // Ask if they want to repeat the calculation
    std::cout<<"Would you like to calculate another transition (y/n)?: ";
    continue_tag = get_valid_char('y', 'n');
  }
  while(continue_tag == 'y');

  return 0;
}
