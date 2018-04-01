#include <iostream>
#include <string>
#include <memory>

class AbstractHello
{
public:
	AbstractHello(const std::string& name_);
	virtual ~AbstractHello();
	virtual void print() const = 0;

public:
	const std::string& name() const { return _name; }

private:
	const std::string _name;
};

AbstractHello::AbstractHello(const std::string& name_) : _name(name_)
{
	std::cout << "--- Construct Hello(" << _name << ")" << std::endl;
}

AbstractHello::~AbstractHello()
{
	std::cout << "--- Destroy Hello(" << _name << ")" << std::endl;
}

class Hello : public AbstractHello
{
public:
	Hello(const std::string& name_ = "World") : AbstractHello(name_) {}
	void print() const;
};

void Hello::print() const
{
	std::cout << "--- Hello " << name() << '!' << std::endl;
}

int main()
{
	std::cout << std::string(80,'=') << std::endl;
	std::cout << "--> Begin Hello Program" << std::endl;
	//std::auto_ptr<AbstractHello> hello(new Hello());
	auto hello = std::make_unique<Hello>();
	hello->print();
	hello = std::make_unique<Hello>("People");
	hello->print();	std::cout << "--> End Hello Program" << std::endl;

	return 0;
}
