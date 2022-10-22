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

int Intern::nameToInt(const std::string& name) const {
  std::string formNames[3] = \
    {SHRUB_FORM_NAME, ROBO_FORM_NAME, PARDON_FORM_NAME};

  for (int i = 0; i < 3; ++i) {
    if (name == formNames[i])
      return i;
  }
  throw NoMatchingTypeException();
}

Form* Intern::makeForm(const std::string& name, const std::string& target) {
	Form* (*makeFormFunctions[3])(const std::string& target) = {
                      makeShrubberyCreationForm, \
                      makeRobotomyRequestForm, \
                      makePresidentialPardonForm};
  try {
    return (*makeFormFunctions[nameToInt(name)])(target);
  } catch (const NoMatchingTypeException &e) {
    std::cout << "Why make form failed: " << e.what() << std::endl;
    return NULL;
  }
}

Form* Intern::makeShrubberyCreationForm(const std::string& target) {
  std::cout << "Intern create Shrubbery Creation Form" << std::endl;
  return new ShrubberyCreationForm(target);
}

Form* Intern::makeRobotomyRequestForm(const std::string& target) {
  std::cout << "Intern create Robotomy Request Form" << std::endl;
  return new RobotomyRequestForm(target);
}

Form* Intern::makePresidentialPardonForm(const std::string& target) {
  std::cout << "Intern create Presidential Pardon Form" << std::endl;
  return new PresidentialPardonForm(target);
}

const char* Intern::NoMatchingTypeException::what(void) const throw() {
  return ("No Matching Type");
}
