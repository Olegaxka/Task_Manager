#include "Task.h"

std::string Task::getName() const
{
	return name;
}

std::string Task::getDescription() const
{
	return description;
}

bool Task::getStatus() const 
{
	return status;
}

int Task::getPriority() const
{
	return priority;
}

int Task::getId() const
{
	return id;
}

void Task::setStatus(bool status)
{
	this->status = status;
}

void Task::setPriority(int priority)
{
	Task::priority = priority;
}