#include "PocoTest.h"

int main(int argc, char** argv)
{
	HelloRunnable runnable;
	Poco::Thread thread;
	thread.start(runnable);
	thread.join();
	return 0;
}