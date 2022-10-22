#include "Intern.hpp"

Intern::Intern() {}

Intern::Intern(const Intern& src) {
  *this = src;
}

Intern& Intern::operator=(const Intern& src) {
  if (this != &src) {
    //do nothing
  }
  return *this;
}

Intern::~Intern() {}

static int nameToInt(const std::string& name) {
  std::string formNames[3] = \
    {SHRUB_FORM_NAME, ROBO_FORM_NAME, PARDON_FORM_NAME};

  for (int i = 0; i < 3; ++i) {
    if (name == formNames[i])
      return i;
  }
  return -1;
}

Form* Intern::makeForm(const std::string& name, const std::string& target) {
  switch (nameToInt(name)) {
    case SHRUB_REQUEST :
      return new ShrubberyCreationForm(target);
      break ;
    case ROBO_REQUEST :
      return new RobotomyRequestForm(target);
      break ;
    case PARDON_REQUEST :
      return new PresidentialPardonForm(target);
      break ;
    default :
      std::cout << "no such form..." << std::endl;
      return NULL;
  }
}

const char* Intern::NoMatchingTypeException::what(void) const throw() {
  return ("No Matching Type");
}
