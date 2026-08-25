#pragma once

#include "Task.h"

#include <vector>

class TaskManager
{
private:
	std::vector <Task> saveTasks;
	int nextId = 1;

public:
	void showTasks() const;

	void addTask(const Task& task);
	void removeTask(int id);
	Task* createTask(std::string name, std::string description, bool status, int priority);

	const Task* findTask(int id) const;
	Task* findTask(int id);
	std::vector<Task> findTasksByStatus(bool status) const;

	void sortTasksByPriority();
	void sortTasksByPriorityDescending();
	void sortTasksByPriorityAndId();
	void sortTasksByPriorityStable();
};
