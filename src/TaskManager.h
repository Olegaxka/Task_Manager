#pragma once

#include "Task.h"

#include <vector>

class TaskManager
{
private:
	std::vector <Task> saveTasks;
	int nextId = 1;

public:
	void addTask(const Task& task);
	void removeTask(int id);

	const Task* findTask(int id) const;
	Task* findTask(int id);

	void showTasks() const;

	Task* createTask(std::string name, std::string description, bool status, int priority);

	std::vector<Task> findTasksByStatus(bool status) const;
};
