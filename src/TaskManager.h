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

	size_t countTasksByStatus(bool status) const;
	size_t countTasksByPriority(int priority) const;

	bool allOfTasksByStatus(bool status) const;
	bool anyOfTasksByStatus(bool status) const;
	bool noneOfTasksByStatus(bool status) const;

	void forEachTasksByID() const;
	void forEachTasksSetPriority(int id);
	void forEachAllTasksSetPriority();
	void forEachFalsTasksSetPriority();
};
