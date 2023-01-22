#include <iostream>
#include <ctime>
#include <fstream>
#include <experimental/filesystem>

int main() {
    std::time_t start_time = std::time(nullptr);
    int duration = 3600; // 30 minutes in seconds
    std::string source_folder = "Folder with files to copy";
    std::string destination_folder = "./Speedtest_Cache";
    double total_speed = 0;
    int file_count = 0;

    while (std::difftime(std::time(nullptr), start_time) < duration) {
        try {
            for (const auto &entry : std::experimental::filesystem::directory_iterator(source_folder)) {
                std::string source_file = entry.path();
                std::string destination_file = destination_folder + source_file.substr(source_file.rfind("/"));
                std::uintmax_t file_size = std::experimental::filesystem::file_size(source_file);
                std::time_t start_copy = std::time(nullptr);
                std::cout << "Started copying " << source_file << " at " << std::asctime(std::localtime(&start_copy)) << std::endl;
                std::experimental::filesystem::copy_file(source_file, destination_file, std::experimental::filesystem::copy_options::overwrite_existing);
                std::time_t end_copy = std::time(nullptr);
                double copy_time = std::difftime(end_copy, start_copy);
                double speed = (file_size / copy_time) * 8;
                total_speed += speed;
                file_count++;
                std::cout << source_file << " copied at " << speed / (1024 * 1024) << " Mbps" << std::endl;
                std::cout << "Aborted by user. Deleting copied files..." << std::endl;
                for (const auto &entry : std::experimental::filesystem::directory_iterator(destination_folder)) {
                    std::experimental::filesystem::remove(entry.path());
                }
                std::cout << "Files deleted." << std::endl;
                int remaining_time = (start_time + duration) - std::time(nullptr);
                std::cout << "Remaining time: " << remaining_time << " seconds" << std::endl;
            }
        } catch (std::exception &e) {
            std::cout << "Error: " << e.what() << std::endl;
            std::cout << "Waiting for the server connection..." << std::endl;
            std::this_thread::sleep_for(std::chrono::seconds(5)); // wait for 5 seconds before trying again
        }
    }

    double average_speed = total_speed / file_count;
    std::cout << "Avg. speed: " << average_speed / (1024 * 1024) << " Mbps" << std::endl
    std::cout << "Loop ran for " << duration/60 << " minutes." << std::endl;
    return 0;
}