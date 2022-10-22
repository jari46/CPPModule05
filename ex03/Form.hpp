#ifndef FORM_HPP
#define FORM_HPP

#include <iostream>
#include <exception>
#include "Bureaucrat.hpp"

#define GRADE_MAX 1
#define GRADE_MIN 150

class Bureaucrat;

class Form {
	private:
		const std::string mName;
		bool mSigned;
		const int mGradeRequiredToSign;
		const int mGradeRequiredToExecute;
		const std::string mTarget;

	public:
		Form();
		Form(const std::string& name, const int gradeRequiredToSign, const int gradeRequiredToExecute);
		Form(const std::string& name, const int gradeRequiredToSign, const int gradeRequiredToExecute, const std::string& target);
		Form(const Form& src);
		Form& operator=(const Form& src);
		virtual ~Form();

		std::string getName() const;
		bool getSigned() const;
		int getGradeRequiredToSign() const;
		int getGradeRequiredToExecute() const;
		std::string getTarget() const;

		void setSigned(int sign);

		void beSigned(const Bureaucrat &b);
		void checkExecutable(const Bureaucrat &b) const;
  	virtual void  execute(const Bureaucrat& executor) const = 0;

		class GradeTooHighException : public std::exception {
			public:
				const char *what() const throw();
		};

		class GradeTooLowException : public std::exception {
			public:
				const char *what() const throw();
		};

		class NotSignedException : public std::exception {
			public:
				const char *what() const throw();
		};
};

std::ostream &operator<<(std::ostream &os, Form const &b);

#endif // FORM_HPP