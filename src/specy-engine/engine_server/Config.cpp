// LICENSE: Apache 2.0
// https://github.com/RegTech-OXH/compliance-engine
//
// Author:
//
// This file inplements methods for obtaining config.

#include "regex"
#include "Config.h"

YAML::Node config;

// loadYamlFile is used to obtain configuration for yaml file.
uint32_t loadConfigFromYamlFile(std::string name)
{
  try
  {
    config = YAML::LoadFile(name);
  }
  catch (YAML::BadFile &e)
  {
    std::cout << "read config error!" << std::endl;
    return uint32_t(ConfigStatus::kConfigReadError);
  }

  return uint32_t(ConfigStatus::kOK);
}

// simple function to verify ipv4
bool CheckIPAddrIsValid(std::string str)
{
    std::regex reg("^((25[0-5]|2[0-4][0-9]|[01]?[0-9][0-9]?)\.){3}(25[0-5]|2[0-4][0-9]|[01]?[0-9][0-9]?)$");
    return regex_match(str, reg);
}

// simple function to verify port
bool CheckPortIsValid(std::string str)
{
    std::regex reg("^([0-9]{1,4}|[1-5][0-9]{4}|6[0-4][0-9]{3}|65[0-4][0-9]{2}|655[0-2][0-9]|6553[0-5])$");
    return regex_match(str, reg);
}