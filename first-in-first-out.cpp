#include "INCLUDES/first-in-first-out.h"


FirstInFirstOut::FirstInFirstOut(vector<Pcb> processes) : SchedulingAlgorithm(processes) {
}

int FirstInFirstOut::selectProcess(){


	if (isCurrentProcessSet == false)
	{
		if (getReadyQueue().size() != 0)
		{
			setCurrentProcess(getReadyQueue().front());

			vector<Pcb> tempReady = getReadyQueue();
			tempReady.erase(tempReady.begin());
			setReadyQueue(tempReady);

			isCurrentProcessSet = true;

			return getCurrentProcess().getPid();
		}
	}

	return -1;
}

/*
 * @Override verbose function
 */
void FirstInFirstOut::printVerbose(string message)
{

	if (verbose == 1)
	{
		cout << "\n[first-in-first-out.cpp] " << message;
	}
}
