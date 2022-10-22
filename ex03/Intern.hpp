#ifndef INTERN_HPP
#define INTERN_HPP

#include <string>

#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

enum request {
  SHRUB_REQUEST,
  ROBO_REQUEST,
  PARDON_REQUEST,
  WRONG_REQUEST,
};

class Intern {
 public:
  Intern();
  Intern(const Intern& src);
  Intern& operator=(const Intern& src);
  ~Intern();

  Form* makeForm(const std::string& name, const std::string& target);

  class NoMatchingTypeException : public std::exception {
   public:
      const char* what(void) const throw();
  };
};

#endif  // INTERN_HPP
