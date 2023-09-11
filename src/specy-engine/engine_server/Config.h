
#pragma once

#include <iostream>
#include <string>
#include <stdio.h>
#include <yaml-cpp/yaml.h>

// template <typename T>
// void operator>>(const YAML::Node &node, T &i);
extern YAML::Node config;

enum class ConfigStatus
{
    kOK = 0,
    kConfigReadError,
};

// loadYamlFile is used to obtain configuration for yaml file.
uint32_t loadConfigFromYamlFile(std::string name);

// simple function to verify ipv4
bool CheckIPAddrIsValid(std::string str);

// simple function to verfy port
bool CheckPortIsValid(std::string str);