#ifndef __IVisitor_H
#define __IVisitor_H
class IVisitable;
class IVisitor
{
public:
	virtual void visit(IVisitable* element) = 0;
};

class IVisitable
{
public:
	virtual void accept(IVisitor* visitor) = 0;
};

class RaiseSalaryVisitor : public IVisitor
{
public:
	RaiseSalaryVisitor(double money) : money(money) {};
	virtual void visit(IVisitable* element); // implements in Employee.cpp
private:
	double money;
};

#endif // IVisitor
