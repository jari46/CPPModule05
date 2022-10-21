#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>
#include <exception>

#define GRADE_MAX 1
#define GRADE_MIN 150

class Bureaucrat {
	private:
		const std::string mName;// A constant name.
		int mGrade;// possible grade: 1(highest) ~ 150(lowest)
	
	public:
		Bureaucrat();
		Bureaucrat(const std::string name, int grade);
		Bureaucrat(const Bureaucrat& src);
		Bureaucrat& operator=(const Bureaucrat& src);
		~Bureaucrat();

		class GradeTooHighException : public std::exception {
			public:
				GradeTooHighException();
				const char *what() const throw();
				~GradeTooHighException() throw();
		};

		class GradeTooLowException : public std::exception {
			public:
				GradeTooLowException();
				const char *what() const throw();
				~GradeTooLowException() throw();
		};

		const std::string getName() const;
		int getGrade() const;

		void incrementingGrade();
		void decrementingGrade();
};

std::ostream &operator<<(std::ostream &os, Bureaucrat const &b);

#endif //BUREAUCRAT_HPP