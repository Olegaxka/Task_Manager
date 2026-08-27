#include <iostream>
#include <algorithm>

#include "TaskManager.h"
#include "Task.h"

void TaskManager::showTasks() const
{
	for (size_t i = 0; i < saveTasks.size(); i++)
	{
		std::cout << "ID: " << saveTasks[i].getId() << '\n'
			<< "Name: " << saveTasks[i].getName() << '\n'
			<< "Description: " << saveTasks[i].getDescription() << '\n'
			<< "Status: " << saveTasks[i].getStatus() << '\n'
			<< "Priority: " << saveTasks[i].getPriority() << '\n' << '\n';
	}
}

void TaskManager::addTask(const Task& task)
{
	saveTasks.push_back(task);
}

void TaskManager::removeTask(int id)
{
	auto it = std::remove_if(
		saveTasks.begin(),
		saveTasks.end(),
		[id](const Task& task)
		{
			return task.getId() == id;
		}
	);

	saveTasks.erase(it, saveTasks.end());
}

Task* TaskManager::createTask(std::string name, std::string description, bool status, int priority)
{
	Task myTask = { nextId, name, description, status, priority };

	saveTasks.push_back(myTask);

	nextId++;

	// последний индекс = saveTasks.size() - 1;
	return &saveTasks[saveTasks.size() - 1];
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

void TaskManager::sortTasksByPriority()
{
	sort(
		saveTasks.begin(),
		saveTasks.end(),
		[](const Task& a, const Task& b)
		{
			return a.getPriority() < b.getPriority();
		}
	);
}

void TaskManager::sortTasksByPriorityDescending()
{
	sort(
		saveTasks.begin(),
		saveTasks.end(),
		[](const Task& a, const Task& b)
		{
			return a.getPriority() > b.getPriority();
		}
	);
}

void TaskManager::sortTasksByPriorityAndId()
{
	sort(
		saveTasks.begin(),
		saveTasks.end(),
		[](const Task& a, const Task& b)
		{
			if (a.getPriority() != b.getPriority())
			{
				return a.getPriority() < b.getPriority();
			}
			else 
			{
				return a.getId() < b.getId();
			}
		}
	);
}

void TaskManager::sortTasksByPriorityStable()
{
	std::stable_sort(
		saveTasks.begin(),
		saveTasks.end(),
		[](const Task& a, const Task& b)
		{
			return a.getPriority() < b.getPriority();
		}
	);
}

size_t TaskManager::countTasksByStatus(bool status) const
{
	auto count = std::count_if(
		saveTasks.begin(),
		saveTasks.end(),
		[status](const Task& a)
		{
			return a.getStatus() == status;
		}
	);
	return count;
}

size_t TaskManager::countTasksByPriority(int priority) const
{
	auto count = std::count_if(
		saveTasks.begin(),
		saveTasks.end(),
		[priority](const Task& a)
		{
			return a.getPriority() == priority;
		}
	);
	return count;
}

bool TaskManager::allTasksByStatus(bool status) const
{
	auto all_of = std::all_of(
		saveTasks.begin(),
		saveTasks.end(),
		[status](const Task& a)
		{
			return a.getStatus() == status;
		}
	);
	return all_of;
}

bool TaskManager::anyTasksByStatus(bool status) const
{
	auto any_of = std::any_of(
		saveTasks.begin(),
		saveTasks.end(),
		[status](const Task& a)
		{
			return a.getStatus() == status;
		}
	);
	return any_of;
}

bool TaskManager::noneTasksByStatus(bool status) const
{
	auto none_of = std::none_of(
		saveTasks.begin(),
		saveTasks.end(),
		[status](const Task& a)
		{
			return a.getStatus() == status;
		}
	);
	return none_of;
}