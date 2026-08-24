#include <iostream>

#include "TaskManager.h"
#include "Task.h"

void TaskManager::addTask(const Task& task)
{
	saveTasks.push_back(task);
}

void TaskManager::removeTask(int id)
{
	for (size_t i = 0; i < saveTasks.size(); i++)
	{
		if (saveTasks[i].getId() == id)
		{
			saveTasks.erase(saveTasks.begin() + i);
		}
	}
}

const Task* TaskManager::findTask(int id) const
{
	for (size_t i = 0; i < saveTasks.size(); i++)
	{
		if (saveTasks[i].getId() == id)
		{
			return &saveTasks[i];
		}
	}
	return nullptr;
}

Task* TaskManager::findTask(int id)
{
	auto it = std::find_if(
		saveTasks.begin(),
		saveTasks.end(),
		[id] (const Task& task)
		{
			return (task.getId() == id);
		}
	);

	if (it != saveTasks.end())
	{
		return &(*it);
	}
	else
	{
		return nullptr;
	}
}

void TaskManager::showTasks() const
{
	for (size_t i = 0; i < saveTasks.size(); i++)
	{
		std::cout << "ID: " << saveTasks[i].getId() << '\n'
			<< "name: " << saveTasks[i].getName() << '\n'
			<< "Description: " << saveTasks[i].getDescription() << '\n'
			<< "Status: " << saveTasks[i].getStatus() << '\n'
			<< "Priority: " << saveTasks[i].getPriority() << '\n' << '\n';
	}
}

Task* TaskManager::createTask(std::string name, std::string description, bool status, int priority)
{
	Task myTask = { nextId, name, description, status, priority };

	saveTasks.push_back(myTask);
	
	nextId++;

	// последний индекс = saveTasks.size() - 1;
	return &saveTasks[saveTasks.size() - 1];
}

std::vector<Task> TaskManager::findTasksByStatus(bool status) const
{
	std::vector<Task> result;

	auto it = std::find_if(
		saveTasks.begin(),
		saveTasks.end(),
		[status](const Task& task)
		{
			return (task.getStatus() == status);
		}
	);

	while (it != saveTasks.end())
	{
		result.push_back(*it);

		auto nextIt = std::find_if(
			std::next(it),
			saveTasks.end(),
			[status](const Task& task)
			{
				return (task.getStatus() == status);
			}
		);

		it = nextIt;
	}

	return result;
}