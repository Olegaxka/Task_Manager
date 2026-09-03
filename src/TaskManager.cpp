#include <iostream>
#include <algorithm>
#include <numeric>

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

bool TaskManager::allOfTasksByStatus(bool status) const
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

bool TaskManager::anyOfTasksByStatus(bool status) const
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

bool TaskManager::noneOfTasksByStatus(bool status) const
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

void TaskManager::forEachTasksByID() const
{
	std::for_each(
		saveTasks.begin(),
		saveTasks.end(),
		[](const Task& a)
		{
			std::cout << a.getId() << " ";
		}
	);
}

void TaskManager::forEachTasksSetPriority(int id)
{
	std::for_each(
		saveTasks.begin(),
		saveTasks.end(),
		[id](Task& a)
		{
			if (id == a.getId()) {
				int newPriority = a.getPriority() + 1;
				a.setPriority(newPriority);
			}
		}
	);
}

void TaskManager::forEachAllTasksSetPriority()
{
	std::for_each(
		saveTasks.begin(),
		saveTasks.end(),
		[](Task& a)
		{
			if (a.getStatus() == true)
			{
				int newPriority = a.getPriority() + 1;
				a.setPriority(newPriority);
			}
		}
	);
}

void TaskManager::forEachFalseTasksSetPriority()
{
	std::for_each(
		saveTasks.begin(),
		saveTasks.end(),
		[](Task& a)
		{
			if (a.getStatus() == false)
			{
				a.setPriority(1);
			}
		}
	);
}

std::vector<int> TaskManager::transformTasksByID()
{
	std::vector<int> id(saveTasks.size());

	std::transform(
		saveTasks.begin(),
		saveTasks.end(),
		id.begin(),
		[](Task& a)
		{
			return a.getId();
		}
	);

	return id;
}

std::vector<int> TaskManager::transformTasksByPriority() const
{
	std::vector<int> priority(saveTasks.size());

	std::transform(
		saveTasks.begin(),
		saveTasks.end(),
		priority.begin(),
		[](const Task& a)
		{
			return a.getPriority();
		}
	);

	return priority;
}

std::vector<std::string> TaskManager::transformTasksToDescriptions()
{
	std::vector<std::string> descriptions(saveTasks.size());

	std::transform(
		saveTasks.begin(),
		saveTasks.end(),
		descriptions.begin(),
		[](const Task& a)
		{
			return a.getDescription();
		}
	);

	return descriptions;
}

std::vector<std::string> TaskManager::transformTasksToNames()
{
	std::vector<std::string> names(saveTasks.size());

	std::transform(
		saveTasks.begin(),
		saveTasks.end(),
		names.begin(),
		[](const Task& a)
		{
			return a.getName();
		}
	);

	return names;
}

int TaskManager::countTotalPriority()
{
	auto priority = std::accumulate(
		saveTasks.begin(),
		saveTasks.end(),
		0,
		[](int priority, const Task& a)
		{
			return priority + a.getPriority();
		}
	);
	return priority;
}

int TaskManager::countCompletedPriority()
{
	
	auto priority = std::accumulate(
		saveTasks.begin(),
		saveTasks.end(),
		0,
		[](int priority, const Task& a)
		{
			if (a.getStatus() == true) {
				return priority + a.getPriority();
			}
			else
			{
				return priority + 0;
			}
		}
	);
	return priority;
}

std::vector <Task> TaskManager::findTasksByPriority(int priority) const
{
	std::vector <Task> copy;

	std::copy_if(
		saveTasks.begin(),
		saveTasks.end(),
		std::back_inserter(copy),
		[priority](const Task& a)
		{
			return a.getPriority() == priority;
		}
	);
	return copy;
}

Task* TaskManager::getMinPriorityTask()
{
	auto minElement = std::min_element(
		saveTasks.begin(),
		saveTasks.end(),
		[](const Task& a, const Task& b)
		{
			return a.getPriority() < b.getPriority();
		}
	);
	if (minElement == saveTasks.end())
	{
		return nullptr;
	}
	return &(*minElement);
}

Task* TaskManager::getMaxPriorityTask()
{
	auto maxElement = std::max_element(
		saveTasks.begin(),
		saveTasks.end(),
		[](const Task& a, const Task& b)
		{
			return a.getPriority() < b.getPriority();
		}
	);
	if (maxElement == saveTasks.end())
	{
		return nullptr;
	}
	return &(*maxElement);
}

bool TaskManager::containsTaskWithPriority(int priority) const
{
	std::vector<int> priorities = transformTasksByPriority();

	std::sort(
		priorities.begin(),
		priorities.end()
	);

	return std::binary_search(
		priorities.begin(),
		priorities.end(),
		priority
	);
}

Task* TaskManager::findFirstTaskWithPriority(int priority)
{
	auto it = std::lower_bound(
		saveTasks.begin(),
		saveTasks.end(),
		priority,
		[](const Task& task, int priority)
		{
			return task.getPriority() < priority;
		}
	);

	if (it != saveTasks.end())
	{
		return &(*it);
	}

	return nullptr;
}