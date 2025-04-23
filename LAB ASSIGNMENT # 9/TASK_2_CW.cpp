#include <iostream>
#include <vector>
#include <string>

class Logger {
private:
    static const size_t MAX_LOGS = 1000;
    std::vector<std::string> logs;

    void storeLog(const std::string& module, const std::string& message, const std::string& severity) {
        std::string formatted = "[" + severity + "] (" + module + ") " + message;
        if (logs.size() >= MAX_LOGS) {
            logs.erase(logs.begin());
        }
        logs.push_back(formatted);
    }

public:
    void logInfo(const std::string& module, const std::string& message) {
        storeLog(module, message, "INFO");
    }
    
    void logWarning(const std::string& module, const std::string& message) {
        storeLog(module, message, "WARN");
    }
    
    void logError(const std::string& module, const std::string& message) {
        storeLog(module, message, "ERROR");
    }

    friend class AuditManager;
};

class AuditManager {
public:
    std::vector<std::string> getLogs(const Logger& logger, const std::string& password) {
        if (password == "admin123") {
            return logger.logs;
        }
        std::cerr << "Access denied: Invalid credentials." << std::endl;
        return {};
    }
};

int main() {
    Logger logger;
    logger.logInfo("Network", "Connected to server.");
    logger.logInfo("Database", "Query executed successfully.");
    logger.logWarning("Network", "Packet loss detected.");
    logger.logError("Security", "Unauthorized access attempt!");

    AuditManager auditor;
    std::string userPassword;
    std::cout << "Enter password to retrieve logs: ";
    std::cin >> userPassword;

    auto logs = auditor.getLogs(logger, userPassword);
    if (!logs.empty()) {
        std::cout << "\n--- Logs ---\n";
        for (const auto& log : logs) {
            std::cout << log << '\n';
        }
    }
    return 0;
}