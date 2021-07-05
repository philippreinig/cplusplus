/// \brief This define controls the amount of reported messages
#define LOG_LEVEL 1
#include "logger.hpp"
#include "filepolicy.hpp"
#include "consolepolicy.hpp"

/// \brief This class only exists for demonstration purposes.
class UltimativeNotifier
{
public:
	UltimativeNotifier() {
		LOG_LVL2("Powering down shields.");
	}
	~UltimativeNotifier() {
		LOG_LVL2("Reactivating shields.");
	}
};

/// \brief Use a static instance to demonstrate that the logger is active from
///		the very beginning.
UltimativeNotifier g_notify;

int main()
{
	LOG_LVL1("Opening hangar.");

	LOG_LVL0("Last message before policy registration.");

	Logger::instance().registerPolicy(std::make_unique<ConsolePolicy>());
	LOG_LVL0("Registered console policy.");

	Logger::instance().registerPolicy(std::make_unique<FilePolicy>("log.txt"));
	LOG_LVL0("Registered file policy.");

	LOG_ERROR("Ship with id " << 42 << " has no parking ticket.");

	LOG_LVL1("Terminating docking process.");
	return 0;

	// If you did everything correct you should get a file log.txt with the
	// following content (up to formation):
	// Tue Jun 13 15:17:37 2017 [main.cpp : 11] <level 2> Powering down shields.
	// Tue Jun 13 15:17:37 2017 [main.cpp : 21] <level 1> Opening hangar.
	// Tue Jun 13 15:17:37 2017 [main.cpp : 33] <error>   Ship with id 42 has no parking ticket.
	// Tue Jun 13 15:17:37 2017 [main.cpp : 35] <level 1> Terminating docking process.
	// Tue Jun 13 15:17:37 2017 [main.cpp : 12] <level 2> Reactivating shields.
	// If you change the LOG_LEVEL above, the number of messages should
	// increase / decrease by 2 (in each direction respectively).
}