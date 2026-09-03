#include <iostream>
#include <algorithm>
#include <numeric>

#include "Task.h"
#include "TaskManager.h"

int main()
{
	TaskManager manager;

	Task* task1 = manager.createTask(
		"Learn C++",
		"i job for my C++ skills",
		true,
		1
	);

	Task* task2 = manager.createTask(
		"Study STL",
		"i wery good learn STL",
		false,
		2
	);

	Task* task3 = manager.createTask(
		"Build Task Manager",
		"I start build my new project",
		true,
		3
	);

	Task* task4 = manager.createTask(
		"Final cute",
		"I end it",
		false,
		1
	);

	Task* task5 = manager.createTask(
		"test",
		"Test",
		false,
		3
	);

	manager.showTasks();

	manager.removeTask(2);

	Task* task = manager.findTask(2);

	if (task == nullptr)
	{
		std::cout << "Task was deleted" << '\n';
	}

	Task* taskNullptr = manager.findTask(999);

	if (taskNullptr == nullptr)
	{
		std::cout << "Task not found\n";
	}

	std::cout << '\n';

	manager.showTasks();

	std::vector<Task> status;

	status = manager.findTasksByStatus(true);

	std::cout << '\n';
	std::cout << "True: ";
	std::cout << '\n';

	for (const auto& task : status)
	{
		std::cout << task.getId() << " ";
	}

	std::cout << '\n';

	std::cout << "Count Status: " << manager.countTasksByStatus(true) << '\n';

	status = manager.findTasksByStatus(false);

	std::cout << "False: ";

	for (const auto& task : status)
	{
		std::cout << task.getId() << " ";
	}
	
	std::cout << '\n';

	std::cout << "Count Status: " << manager.countTasksByStatus(false) << '\n';

	manager.sortTasksByPriority();

	std::cout << "\nAfter sorting priority:\n";

	manager.showTasks();

	manager.sortTasksByPriorityStable();

	std::cout << "\nAfter sorting ByPriorityStable:\n";

	manager.showTasks();

	std::cout << "Count by 1 priority :" << manager.countTasksByPriority(1) << '\n' << '\n';
	
	std::cout << "All true status: " << manager.allOfTasksByStatus(true) << '\n';
	std::cout << "Any true status: " << manager.anyOfTasksByStatus(true) << '\n';
	std::cout << "None true status: " << manager.noneOfTasksByStatus(true) << '\n';

	std::cout << '\n';

	manager.forEachTasksSetPriority(3);
	manager.forEachFalseTasksSetPriority();

	std::cout << '\n';

	manager.showTasks();
	
	auto ids = manager.transformTasksByID();

	std::cout << "transformTasksByID: ";
	for (const auto& task : ids)
	{
		std::cout << task << " ";
	}

	std::cout << '\n';

	auto pri = manager.transformTasksByPriority();

	std::cout << "transformTasksByPriority: ";
	for (const auto& task : pri)
	{
		std::cout << task << " ";
	}

	std::cout << '\n' << '\n';

	auto des = manager.transformTasksToDescriptions();

	std::cout << "transformTasksToDescriptions: ";
	for (const auto& task : des)
	{
		std::cout << '\n' << task << " ";
	}

	std::cout << '\n' << '\n';

	auto nam = manager.transformTasksToNames();

	std::cout << "transformTasksToNames: ";
	for (const auto& task : nam)
	{
		std::cout << '\n' << task << " ";
	}

	std::cout << '\n' << '\n';

	std::cout << "countCompletedPriority: " << manager.countCompletedPriority() << '\n';

	std::cout << '\n';

	auto findTasks = manager.findTasksByPriority(1);

	std::cout << "findTasksByPriority: ";
	for (const auto& task : findTasks)
	{
		std::cout  << task.getId() << " ";
	}

	std::cout << '\n' << '\n';

	Task* minTask = manager.getMinPriorityTask();
	Task* maxTask = manager.getMaxPriorityTask();

	std::cout << "minTask: " << minTask->getId() << '\n';
	std::cout << "maxTask: " << maxTask->getId() << '\n';

	std::vector<int> numbers = { 2, 4, 4, 5, 10, 15, 20 };

	auto lower = std::lower_bound(
		numbers.begin(),
		numbers.end(),
		5
	);

	std::cout << *lower;
}