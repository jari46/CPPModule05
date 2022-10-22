#ifndef PRESIDENTIAL_PARDON_FORM_HPP
#define PRESIDENTIAL_PARDON_FORM_HPP

#include <string>
#include "Form.hpp"

#define PARDON_FORM_NAME "Presidential Pardon Form"
#define PARDON_FORM_SIGN 25
#define PARDON_FORM_EXEC 5

class PresidentialPardonForm : public Form {
 public:
  PresidentialPardonForm();
  explicit PresidentialPardonForm(const std::string& target);/* added */
  PresidentialPardonForm& operator=(const PresidentialPardonForm& src);
  PresidentialPardonForm(const PresidentialPardonForm& src);
  virtual ~PresidentialPardonForm();
  
  virtual void execute(const Bureaucrat& b) const;/* added */
};

#endif  // PRESIDENTIAL_PARDON_FORM_HPP
