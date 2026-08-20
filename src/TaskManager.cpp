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
	for (size_t i = 0; i < saveTasks.size(); i++)
	{
		if (saveTasks[i].getId() == id)
		{
			return &saveTasks[i];
		}
	}
	return nullptr;
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