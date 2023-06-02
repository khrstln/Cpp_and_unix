#include "Utils.hpp"
#include "ExecuteCommands.hpp"

int main() {
    std::string commandString =
        "PRINT_CONSOLE Hello, world!\n"
        "LOOP 3\n"
        "  PRINT_CONSOLE Inside loop\n"
        "  PRINT_FILE output.txt Loop iteration\n"
        "  + 2 3\n"
        "  * 4 5\n"
        "ENDLOOP\n"
        "PRINT_CONSOLE Done\n";

    std::vector<Command*> commands = processCommandString(commandString);
    executeCommands(commands);

    // Cleanup
    for (auto command : commands) {
        delete command;
    }

    return 0;
}
