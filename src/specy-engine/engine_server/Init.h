// LICENSE: Apache 2.0
// https://github.com/RegTech-OXH/compliance-engine
//
// Author:
//
// This file declares methods for Initiation.
#pragma once

#include <string.h>
#include <getopt.h>

#include "Config.h"

#include <spdlog/spdlog.h>
#include <spdlog/sinks/rotating_file_sink.h>
#include <spdlog/sinks/stdout_color_sinks.h>

int init_logger_config(int argc, char *argv[]);