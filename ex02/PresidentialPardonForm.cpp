#include <iostream>
#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm()
  : Form(PARDON_FORM_NAME, PARDON_FORM_SIGN, PARDON_FORM_EXEC) {}

PresidentialPardonForm::PresidentialPardonForm(const std::string& target)
  : Form(PARDON_FORM_NAME, PARDON_FORM_SIGN, PARDON_FORM_EXEC, target) {}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& src)
  : Form(PARDON_FORM_NAME, PARDON_FORM_SIGN, PARDON_FORM_EXEC, src.getTarget()) {
    *this = src;
  }

//recommend to not use
PresidentialPardonForm &PresidentialPardonForm::operator=(const PresidentialPardonForm& src) {
	if (this != &src) {
		mSigned = src.mSigned;
		//other attribute is all constant.
	}
	return *this;
}

PresidentialPardonForm::~PresidentialPardonForm(void) {}

//-------------------------------------------------------------------//

void PresidentialPardonForm::execute(const Bureaucrat &b) const {
  checkExecutable(b);
  //Otherwise, throw an appropriate exception.

  std::cout << "    * " << mTarget << " has been pardoned by Zaphod Beeblebrox!" << std::endl;
}