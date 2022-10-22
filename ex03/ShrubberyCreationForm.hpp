#ifndef SHRUBBERY_CREATION_FORM_HPP
#define SHRUBBERY_CREATION_FORM_HPP

#include <string>
#include "Form.hpp"

#define SHRUB_FORM_NAME "S.F."
#define SHRUB_FORM_SIGN 145
#define SHRUB_FORM_EXEC 137

class ShrubberyCreationForm : public Form {
 public:
  ShrubberyCreationForm();
  ShrubberyCreationForm(const std::string& target);/* added */
  ShrubberyCreationForm(const ShrubberyCreationForm& src);
  ShrubberyCreationForm& operator=(const ShrubberyCreationForm& src);
  virtual ~ShrubberyCreationForm();
  
  virtual void  execute(const Bureaucrat& executor) const;/* added */

  class NotOpenedException : public std::exception {/* added */
  public:
    const char *what() const throw();
  };
};

#endif  // SHRUBBERY_CREATION_FORM_HPP
