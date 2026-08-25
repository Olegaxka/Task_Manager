#include <iostream>
#include <algorithm>

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

	for (const auto& task : status)
	{
		std::cout << task.getId() << " ";
	}

	std::cout << '\n';

	status = manager.findTasksByStatus(false);

	std::cout << "False: ";

	for (size_t i = 0; i < status.size(); i++)
	{
		std::cout << status[i].getId() << " ";
	}
	
	std::cout << '\n';

	manager.sortTasksByPriority();

	std::cout << "\nAfter sorting priority:\n";

	manager.showTasks();

	manager.sortTasksByPriorityStable();

	std::cout << "\nAfter sorting ByPriorityStable:\n";

	manager.showTasks();
}