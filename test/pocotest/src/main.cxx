#include "PocoThreadTest.h"

void threadTest()
{
	HelloRunnable runnable;
	Poco::Thread thread;
	thread.start(runnable);
	thread.join();
}

void runnableAdapterThreadTest()
{
	Greeter greeter;
	Poco::RunnableAdapter<Greeter> runnableAdapter(greeter, &Greeter::greet);

	Poco::Thread thread;
	thread.start(runnableAdapter);
	thread.join();
}

void threadPoolTest()
{
	HelloRunnable runnable;
	Poco::ThreadPool::defaultPool().start(runnable);
	Poco::ThreadPool::defaultPool().joinAll();
	int cap = Poco::ThreadPool::defaultPool().capacity();
}

void threadLocalTest()
{
	Counter counter;
	Poco::Thread t1;
	Poco::Thread t2;

	t1.start(counter);
	t2.start(counter);

	t1.join();
	t2.join();
}

int main(int argc, char** argv)
{
	threadTest();
	runnableAdapterThreadTest();
	threadPoolTest();
	threadLocalTest();

	getchar();
	return 0;
}