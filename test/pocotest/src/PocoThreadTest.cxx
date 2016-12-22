#include "PocoThreadTest.h"

void HelloRunnable::run()
{
	std::cout << "Hello, world!" << std::endl;
}

void Greeter::greet()
{
	std::cout << "Hello, world!" << std::endl;
}

void Counter::run()
{
	static Poco::ThreadLocal<int> tls;
	for (*tls; *tls < 10; ++(*tls)) {
		std::cout << *tls << std::endl;
	}
}
