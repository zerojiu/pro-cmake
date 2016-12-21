#include <iostream>
#include <Poco/Thread.h>
#include <Poco/Runnable.h>

class HelloRunnable : public Poco::Runnable {
	virtual  void run() override;
};