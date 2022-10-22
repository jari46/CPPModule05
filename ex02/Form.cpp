#include <iostream>
#include "Bureaucrat.hpp"
#include "Form.hpp"

Form::Form() 
	: mSigned(false), mGradeRequiredToSign(1), mGradeRequiredToExecute(1) {
	//std::cout << "Form: Default Constructor called" << std::endl;
}

//Any attempt to instantiate a Form using an invalid grade,
//must throw an exception.
Form::Form(const std::string& name, const int gradeRequiredToSign, const int gradeRequiredToExecute) 
	: mName(name), mSigned(false), mGradeRequiredToSign(gradeRequiredToSign), mGradeRequiredToExecute(gradeRequiredToExecute) {
	//std::cout << "Form: My Constructor called" << std::endl;
	if (mGradeRequiredToSign < GRADE_MAX || mGradeRequiredToExecute < GRADE_MAX)
		throw GradeTooHighException();
	if (mGradeRequiredToSign > GRADE_MIN || mGradeRequiredToExecute > GRADE_MIN)
		throw GradeTooLowException();
}

Form::Form(const std::string& name, const int gradeRequiredToSign, const int gradeRequiredToExecute, const std::string& target) 
	: mName(name), mSigned(false), mGradeRequiredToSign(gradeRequiredToSign), mGradeRequiredToExecute(gradeRequiredToExecute), mTarget(target) {
	//std::cout << "Form: My Constructor called" << std::endl;
	if (mGradeRequiredToSign < GRADE_MAX || mGradeRequiredToExecute < GRADE_MAX)
		throw GradeTooHighException();
	if (mGradeRequiredToSign > GRADE_MIN || mGradeRequiredToExecute > GRADE_MIN)
		throw GradeTooLowException();
}

Form::Form(const Form& src) 
	: mName(src.getName()), mSigned(src.getSigned()), \
	mGradeRequiredToSign(src.getGradeRequiredToSign()), \
	mGradeRequiredToExecute(src.getGradeRequiredToExecute()) {
	//std::cout << "Form: Copy constructor called" << std::endl;
}

//recommend to not use
Form& Form::operator=(const Form& src) {
	//std::cout << "Form: Copy assignment operator called" << std::endl;
	if (this != &src) {
		mSigned = src.mSigned;
		//other attribute is all constant.
	}
	return *this;
}

Form::~Form() {
		//std::cout << "Form: Destructor called" << std::endl;
}

//--------------------------------------------------------//

std::string Form::getName() const {
	return mName;
}

bool Form::getSigned() const {
	return mSigned;
}

int Form::getGradeRequiredToSign() const {
	return mGradeRequiredToSign;
}

int Form::getGradeRequiredToExecute() const {
	return mGradeRequiredToExecute;
}

std::string Form::getTarget() const {
	return mTarget;
}

void Form::setSigned(int sign) {
	mSigned = sign;
}

//--------------------------------------------------------//

void Form::beSigned(const Bureaucrat &b) {
	if (b.getGrade() > mGradeRequiredToSign)
		throw GradeTooLowException();
	else
		mSigned = true;
}

//have to check that the form is signed 
//and that the grade of the bureaucrat attempting to execute the form 
//is high enough. 
//Otherwise, throw an appropriate exception.
void Form::checkExecutable(const Bureaucrat &b) const {
	if (mSigned == false)
		throw (NotSignedException());
	if (b.getGrade() > mGradeRequiredToExecute)
		throw (GradeTooLowException());
}

//--------------------------------------------------------//

std::ostream &operator<<(std::ostream &os, Form const &b) {
	os << " * Name: " << b.getName()  << std::endl \
	<< " * Signed: " << b.getSigned()  << std::endl \
	<< " * Grade required to sign: " << b.getGradeRequiredToSign()  << std::endl \
	<< " * Grade required to execute: " << b.getGradeRequiredToExecute() << std::endl;
	return os;
}

//--------------------------------------------------------//

const char* Form::GradeTooHighException::what() const throw() {
	return "the grade is too high!";
}

const char* Form::GradeTooLowException::what() const throw() {
	return "the grade is too low!";
}

const char* Form::NotSignedException::what() const throw() {
	return "the form is not signed yet!";
}