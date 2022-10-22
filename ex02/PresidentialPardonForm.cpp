#include <iostream>
#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm()
  : Form(PARDON_FORM_NAME, PARDON_FORM_SIGN, PARDON_FORM_EXEC) {}

PresidentialPardonForm::PresidentialPardonForm(const std::string& target)
  : Form(PARDON_FORM_NAME, PARDON_FORM_SIGN, PARDON_FORM_EXEC, target) {}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& src)
  : Form(PARDON_FORM_NAME, PARDON_FORM_SIGN, PARDON_FORM_EXEC, src.getTarget()) {
  }

//recommend to not use
PresidentialPardonForm &PresidentialPardonForm::operator=(const PresidentialPardonForm& src) {
	if (this != &src) {
		setSigned(src.getSigned());
		//other attribute is all constant.
	}
	return *this;
}

PresidentialPardonForm::~PresidentialPardonForm(void) {}

//-------------------------------------------------------------------//

void PresidentialPardonForm::execute(const Bureaucrat &executor) const {
  checkExecutable(executor);
  //Otherwise, throw an appropriate exception.

  std::cout << "    * " << getTarget() << " has been pardoned by Zaphod Beeblebrox!" << std::endl;
}