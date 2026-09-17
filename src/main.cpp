#include <iostream>
#include <limits>

#include "Task.h"
#include "TaskManager.h"

int main()
{
    TaskManager manager;
    int choice = 1;

    while (choice != 0)
    {
        std::cout << "\n========== TASK MANAGER ==========\n\n"
            << "1. Show all tasks\n"
            << "2. Add task\n"
            << "3. Find task\n"
            << "4. Change task status\n"
            << "5. Change task priority\n"
            << "6. Delete task\n"
            << "7. Sort tasks\n"
            << "8. Statistics\n"
            << "0. Exit\n\n"
            << "Select option: ";

        std::cin >> choice;

        if (std::cin.fail())
        {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

            std::cout << "\nInvalid input. Please enter a number.\n";
            continue;
        }

        switch (choice)
        {
        case 0:
            std::cout << "\nGoodbye!\n";
            break;

        case 1:
        {
            std::cout << "\n========== ALL TASKS ==========\n\n";
            manager.showTasks();
            break;
        }

        case 2:
        {
            std::string name;
            std::string description;
            bool status;
            int priority;

            std::cout << "Enter task name:\n";
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::getline(std::cin, name);

            std::cout << "Description:\n";
            std::getline(std::cin, description);

            std::cout << "Status (1 - completed, 0 - not completed):\n";
            std::cin >> status;

            std::cout << "Priority:\n";
            std::cin >> priority;

            manager.createTask(name, description, status, priority);

            std::cout << "\nTask added successfully.\n";
            break;
        }

        case 3:
        {
            int id;

            std::cout << "Enter task ID: ";
            std::cin >> id;

            Task* task = manager.findTask(id);

            if (task == nullptr)
            {
                std::cout << "\nTask not found.\n";
            }
            else
            {
                std::cout << "\n========== TASK ==========\n"
                    << "ID: " << task->getId() << '\n'
                    << "Name: " << task->getName() << '\n'
                    << "Description: " << task->getDescription() << '\n'
                    << "Status: " << (task->getStatus() ? "Completed" : "Not completed") << '\n'
                    << "Priority: " << task->getPriority() << '\n';
            }

            break;
        }

        case 4:
        {
            int id;
            bool status;

            std::cout << "Enter task ID: ";
            std::cin >> id;

            Task* task = manager.findTask(id);

            if (task == nullptr)
            {
                std::cout << "\nTask not found.\n";
            }
            else
            {
                std::cout << "Enter new status (1 - completed, 0 - not completed): ";
                std::cin >> status;

                task->setStatus(status);

                std::cout << "\nTask status changed successfully.\n";
            }

            break;
        }

        case 5:
        {
            int id;
            int priority;

            std::cout << "Enter task ID: ";
            std::cin >> id;

            Task* task = manager.findTask(id);

            if (task == nullptr)
            {
                std::cout << "\nTask not found.\n";
            }
            else
            {
                std::cout << "Enter new priority: ";
                std::cin >> priority;

                manager.setTaskPriorityById(id, priority);

                std::cout << "\nTask priority changed successfully.\n";
            }

            break;
        }

        case 6:
        {
            int id;

            std::cout << "Enter task ID: ";
            std::cin >> id;

            Task* task = manager.findTask(id);

            if (task == nullptr)
            {
                std::cout << "\nTask not found.\n";
            }
            else
            {
                manager.removeTaskById(id);

                std::cout << "\nTask deleted successfully.\n";
            }

            break;
        }

        case 7:
        {
            int priorityChoice;

            std::cout << "\n========== SORT TASKS ==========\n\n"
                << "1. Priority ascending\n"
                << "2. Priority descending\n"
                << "0. Back\n\n"
                << "Select option: ";

            std::cin >> priorityChoice;

            switch (priorityChoice)
            {
            case 1:
                manager.sortTasksByPriority();
                std::cout << "\nTasks sorted by priority ascending.\n";
                break;

            case 2:
                manager.sortTasksByPriorityDescending();
                std::cout << "\nTasks sorted by priority descending.\n";
                break;

            case 0:
                break;

            default:
                std::cout << "\nInvalid option.\n";
                break;
            }

            break;
        }

        case 8:
        {
            std::cout << "\n========== STATISTICS ==========\n\n"
                << "Completed tasks: "
                << manager.countTasksByStatus(true) << '\n'
                << "Not completed tasks: "
                << manager.countTasksByStatus(false) << '\n'
                << "Total priority: "
                << manager.countTotalPriority() << '\n'
                << "Completed priority: "
                << manager.countCompletedPriority() << '\n';

            break;
        }

        default:
            std::cout << "\nInvalid option. Please select a number from 0 to 8.\n";
            break;
        }
    }

    return 0;
}