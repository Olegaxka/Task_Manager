#pragma once

#include <string>

class Task
{
private:
	std::string name;
	std::string description;
	bool status;
	int priority;
	int id;

public:
	 Task(int id, std::string name, std::string description, bool status, int priority)
		: id(id),
		name(name),
		description(description),
		status(status),
		priority(priority)
	{

	}
	
	std::string getName() const;
	std::string getDescription() const;
	bool getStatus() const;
	int getPriority() const;
	int getId() const;

	void setStatus(bool status);
	void setPriority(int priority);
};
