#ifndef ROBOTOMY_REQUEST_FORM_HPP
#define ROBOTOMY_REQUEST_FORM_HPP

#include <string>
#include "Form.hpp"

#define ROBO_FORM_NAME "Robotomy Request Form"
#define ROBO_FORM_SIGN 72
#define ROBO_FORM_EXEC 45

class RobotomyRequestForm : public Form {
 public:
  RobotomyRequestForm();
  explicit RobotomyRequestForm(const std::string& target);/* added */
  RobotomyRequestForm& operator=(const RobotomyRequestForm& src);
  RobotomyRequestForm(const RobotomyRequestForm& src);
  virtual ~RobotomyRequestForm();
  
  virtual void  execute(const Bureaucrat& executor) const;/* added */\
};

#endif  // ROBOTOMY_REQUEST_FORM_HPP
