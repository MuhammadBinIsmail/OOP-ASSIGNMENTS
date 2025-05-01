#include <iostream>
#include <fstream>
#include <string>
#include <filesystem>

using namespace std;
namespace fs = std::filesystem;
class Logger {
private:
    string baseFilename;
    size_t maxFileSize;
    int logCounter;

    string getLogFilename() {
        return baseFilename;
    }
    void rotateLog() {
        string currentFile = getLogFilename();
        if (fs::exists(currentFile) && fs::file_size(currentFile) >= maxFileSize) {
            string newName = "log" + to_string(++logCounter) + ".txt";
            fs::rename(currentFile, newName);
            ofstream clearFile(currentFile); 
            clearFile.close();
        }
    }
public:
    Logger(string filename, size_t maxSize = 1024 * 1024)
        : baseFilename(filename), maxFileSize(maxSize), logCounter(0) {}

    void writeLog(const string& message) {
        rotateLog();
        ofstream outFile(getLogFilename(), ios::app);
        if (outFile.is_open()) {
            outFile << message << endl;
        }
        outFile.close();
    }
};
int main() {
    Logger logger("log.txt");
    for (int i = 0; i < 50000; ++i) {
        logger.writeLog("This is log entry number: " + to_string(i));
    }

    return 0;
}