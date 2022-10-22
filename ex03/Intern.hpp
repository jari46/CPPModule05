#ifndef INTERN_HPP
#define INTERN_HPP

#include <string>

#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

class Intern {
  private:
    int nameToInt(const std::string& name) const;
    static Form* makeShrubberyCreationForm(const std::string& target);
    static Form* makeRobotomyRequestForm(const std::string& target);
    static Form* makePresidentialPardonForm(const std::string& target);

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
