#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>
#include <exception>

#define GRADE_MAX 1
#define GRADE_MIN 150

class Form;

class Bureaucrat {
	private:
		const std::string mName;
		int mGrade;
	
	public:
		Bureaucrat();
		Bureaucrat(const std::string name, int grade);
		Bureaucrat(const Bureaucrat& src);
		Bureaucrat& operator=(const Bureaucrat& src);
		~Bureaucrat();

		const std::string getName() const;
		int getGrade() const;

		void incrementingGrade();
		void decrementingGrade();

		//If the form got signed, it will print something
		void signForm(Form &form);/* added */

		class GradeTooHighException : public std::exception {
			public:
				const char *what() const throw();
		};

		class GradeTooLowException : public std::exception {
			public:
				const char *what() const throw();
		};
};

std::ostream &operator<<(std::ostream &os, Bureaucrat const &b);

#endif //BUREAUCRAT_HPP