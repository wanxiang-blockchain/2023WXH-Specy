#include "Init.h"
#include <fstream>
#include <iostream>

static struct option long_options[] = {
    {"log", required_argument, NULL, 'l'},
    {"config", required_argument, NULL, 'c'}};

using namespace std;

static void parse_args(int argc, char *argv[], string* config_file, string* log_file)
{
    int c = 0;
    int index = 0;
    while (EOF != (c = getopt_long(argc, argv, "l:c:", long_options, &index)))
    {
        switch (c)
        {
        case 'l':
            cout << "Running with argument 'log': " << optarg << endl;
            *log_file = string(optarg);
            break;
        case 'c':
            cout << "Running with argument 'config': " << optarg << endl;
            *config_file = string(optarg);
            break;
        case '?':
            cout << "Running with unknown argument: " << optopt << endl;
            *config_file = string(optarg);
            break;
        default:
            break;
        }
    }
    if (*log_file == "")
    {
        cout << "Running with default argument 'log': ../logs/specy_engine.log" << endl;
        *log_file = "../logs/specy_engine.log";
    }
    if (*config_file == "")
    {
        cout << "Running with default argument 'config': ../config/SpecyEngine.yaml" << endl;
        *config_file = "../config/SpecyEngine.yaml";
    }
    cout << "Finish parsing arguments" << endl;
}

static void setup_logger(string log_file)
{
    auto max_file_size = 1024 * 1024 * 5;
    auto max_file_num = 5;
    auto console_sink_untrusted = std::make_shared<spdlog::sinks::stdout_color_sink_mt>();
    auto file_sink_untrusted = std::make_shared<spdlog::sinks::rotating_file_sink_mt>(log_file, max_file_size, max_file_num);
    std::vector<spdlog::sink_ptr> sinks_untrusted;
    sinks_untrusted.push_back(console_sink_untrusted);
    sinks_untrusted.push_back(file_sink_untrusted);

    auto console_sink_trusted = std::make_shared<spdlog::sinks::stdout_color_sink_mt>();
    auto file_sink_trusted = std::make_shared<spdlog::sinks::rotating_file_sink_mt>(log_file, max_file_size, max_file_num);
    std::vector<spdlog::sink_ptr> sinks_trusted;
    sinks_trusted.push_back(console_sink_trusted);
    sinks_trusted.push_back(file_sink_trusted);

    auto untrusted_logger = std::make_shared<spdlog::logger>("untrusted_logger", begin(sinks_untrusted), end(sinks_untrusted));
    untrusted_logger->set_pattern("[%t][%Y-%m-%d %H:%M:%S.%e][%n][%l][%@,%!] : %v");
    untrusted_logger->set_level(spdlog::level::info);
    untrusted_logger->flush_on(spdlog::level::info);

    auto trusted_logger = std::make_shared<spdlog::logger>("trusted_logger", begin(sinks_trusted), end(sinks_trusted));
    trusted_logger->set_pattern("[%t][%Y-%m-%d %H:%M:%S.%e][%n][%l] : %v");
    trusted_logger->set_level(spdlog::level::info);
    trusted_logger->flush_on(spdlog::level::info);

    spdlog::register_logger(untrusted_logger);
    spdlog::register_logger(trusted_logger);

    spdlog::set_default_logger(untrusted_logger);

    SPDLOG_INFO("Finish setting loggers (console and file)");
}


int init_logger_config(int argc, char *argv[])
{
    string log_file = "";
    string config_file = "";
    parse_args(argc, argv, &config_file, &log_file);
    setup_logger(log_file);

    // obtain config information for yaml file
    if (loadConfigFromYamlFile(config_file) != 0)
    {
        SPDLOG_INFO("obtain config Failure");
        return -1;
    }

    return 0;
}