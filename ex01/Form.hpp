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
		bool mSigned;//default: false
		const int mGradeRequiredToSign;
		const int mGradeRequiredToExecute;

	public:
		Form();
		Form(std::string name, int gradeRequiredToSign, int gradeRequiredToExecute);
		Form(const Form& src);
		Form& operator=(const Form& src);
		~Form();

		std::string getName() const;
		bool getSigned() const;
		int getGradeRequiredToSign() const;
		int getGradeRequiredToExecute() const;

		//changes the form status to signed if the bureaucrat’s grade is high enough 
		//(higher or egal to the required one)
		//If the grade is too low, throw a Form::GradeTooLowException.
		void beSigned(const Bureaucrat &b);

		class GradeTooHighException : public std::exception {
			public:
				const char *what() const throw();
		};

		class GradeTooLowException : public std::exception {
			public:
				const char *what() const throw();
		};
};

std::ostream &operator<<(std::ostream &os, Form const &b);

#endif // FORM_HPP