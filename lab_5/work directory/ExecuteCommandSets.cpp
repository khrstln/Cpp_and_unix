#include "ExecuteCommandSets.hpp"
#include "ExecuteCommands.hpp"

#include <iostream>

// Функция executeCommandSets для параллельного исполнения наборов команд
void executeCommandSets(const std::vector<std::vector<Command*>>& commandSets) {
    std::vector<std::thread> threads;
    int threadIndex = 1;

    for (const auto& commandSet : commandSets) {
        threads.emplace_back([commandSet, threadIndex]() {
            std::chrono::steady_clock::time_point startTime = std::chrono::steady_clock::now();
            std::cout << "Thread " << threadIndex << " started." << std::endl;

            executeCommands(commandSet); // Выполнение команд набора

            std::chrono::steady_clock::time_point endTime = std::chrono::steady_clock::now();
            std::chrono::duration<double> duration = endTime - startTime;
            std::cout << "Thread " << threadIndex << " finished. Execution time: " << duration.count() << "s" << std::endl;
        });

        ++threadIndex;
    }

    // Дождитесь завершения всех потоков
    for (auto& thread : threads) {
        thread.join();
    }
}

