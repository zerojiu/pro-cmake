#include <iostream>
#include <Poco/Thread.h>
#include <Poco/RunnableAdapter.h>
#include <Poco/ThreadPool.h>
#include <Poco/Runnable.h>
#include <Poco/ThreadLocal.h>

class HelloRunnable : public Poco::Runnable {
public:
	virtual  void run() override;
};

class Greeter {
public:
	void greet();
};

class Counter : public Poco::Runnable
{
public:
	virtual void run() override;
};