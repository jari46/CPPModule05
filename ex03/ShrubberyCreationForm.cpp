#include <iostream>
#include <fstream>
#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm()
  : Form(SHRUB_FORM_NAME, SHRUB_FORM_SIGN, SHRUB_FORM_EXEC) {}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string& target)
  : Form(SHRUB_FORM_NAME, SHRUB_FORM_SIGN, SHRUB_FORM_EXEC, target) {}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& src)
  : Form(SHRUB_FORM_NAME, SHRUB_FORM_SIGN, SHRUB_FORM_EXEC, src.getTarget()) {
  }

//recommend to not use
ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm& src) {
	if (this != &src) {
		setSigned(src.getSigned());
		//other attribute is all constant.
	}
	return *this;
}

ShrubberyCreationForm::~ShrubberyCreationForm(void) {}

//-------------------------------------------------------------------//

void ShrubberyCreationForm:: execute(const Bureaucrat& executor) const {
  checkExecutable(executor);
  //Otherwise, throw an appropriate exception.

  std::ofstream out(getTarget() + "_shrubbery");
  if (!out.good())
    throw NotOpenedException();
  std::string shrubbery = "               ,@@@@@@@,\n"
                          "       ,,,.   ,@@@@@@/@@,  .oo8888o.\n"
                          "    ,&%%&%&&%,@@@@@/@@@@@@,8888\\88/8o\n"
                          "   ,%&\\%&&%&&%,@@@\\@@@/@@@88\\88888/88'\n"
                          "   %&&%&%&/%&&%@@\\@@/ /@@@88888\\88888'\n"
                          "   %&&%/ %&%%&&@@\\ V /@@' `88\\8 `/88'\n"
                          "   `&%\\ ` /%&'    |.|        \\ '|8'\n"
                          "       |o|        | |         | |\n"
                          "       |.|        | |         | |\n"
                          "    \\\\/ ._\\//_/__/  ,\\_//__\\\\/// ";
  out << shrubbery;
  out.close();
}

const char *ShrubberyCreationForm::NotOpenedException::what() const throw() {
  return "file open failed!";
}