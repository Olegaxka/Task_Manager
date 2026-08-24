#include <iostream>

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

	manager.showTasks();

	manager.removeTask(2);

	Task* task = manager.findTask(2);

	if (task == nullptr)
	{
		std::cout << "Task was deleted" << '\n';
	}

	Task* task5 = manager.findTask(999);

	if (task5 == nullptr)
	{
		std::cout << "Task not found\n";
	}


	manager.showTasks();

	std::vector<Task> status;

	status = manager.findTasksByStatus(true);

	for (size_t i = 0; i < status.size(); i++)
	{
		std::cout << status[i].getId() << " " ;
	}

	std::cout << '\n';

	for (const auto& task : status)
	{
		std::cout << task.getId() << " ";
	}

	std::cout << '\n';

	status = manager.findTasksByStatus(false);

	for (size_t i = 0; i < status.size(); i++)
	{
		std::cout << status[i].getId() << " ";
	}
	
}