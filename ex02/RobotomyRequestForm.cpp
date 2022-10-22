#include <iostream>
#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm()
  : Form(ROBO_FORM_NAME, ROBO_FORM_SIGN, ROBO_FORM_EXEC) {}

RobotomyRequestForm::RobotomyRequestForm(const std::string& target)
  : Form(ROBO_FORM_NAME, ROBO_FORM_SIGN, ROBO_FORM_EXEC, target) {}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& src)
  : Form(ROBO_FORM_NAME, ROBO_FORM_SIGN, ROBO_FORM_EXEC, src.getTarget()) {
    *this = src;
  }

//recommend to not use
RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm& src) {
	if (this != &src) {
		mSigned = src.mSigned;
		//other attribute is all constant.
	}
	return *this;
}

RobotomyRequestForm::~RobotomyRequestForm(void) {}

//-------------------------------------------------------------------//

void RobotomyRequestForm::execute(const Bureaucrat &b) const {
  checkExecutable(b);
  //Otherwise, throw an appropriate exception.
  
  std::cout << "drrrrrrrrrrrrrrr..." << std::endl;
  bool isSuccessed = std::rand() / 2;
  if (isSuccessed) {
    std::cout << "    * " << mTarget << " became robot!" << std::endl;
  } else {
    std::cout << "    * " << mTarget << " failed to become robot..." << std::endl;
  }
}