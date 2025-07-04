#include "mlPreferences.h"
#include <sstream>

Preferences::Preferences(const std::string& filename) : configFile(filename) {
    setDefaults();
    load();
}

void Preferences::setDefaults() {
    settings["window_width"] = "1066";
    settings["window_height"] = "600";
    settings["frame_rate"] = "30.0";
    settings["speed_scale"] = "0.1";
    settings["amplitude"] = "50";
}

float Preferences::getFloat(const std::string& key, float defaultValue) {
    auto it = settings.find(key);
    if (it != settings.end()) {
        return std::stof(it->second);
    }
    return defaultValue;
}

int Preferences::getInt(const std::string& key, int defaultValue) {
    auto it = settings.find(key);
    if (it != settings.end()) {
        return std::stoi(it->second);
    }
    return defaultValue;
}

void Preferences::setFloat(const std::string& key, float value) {
    settings[key] = std::to_string(value);
}

void Preferences::setInt(const std::string& key, int value) {
    settings[key] = std::to_string(value);
}

bool Preferences::load() {
    std::ifstream file(configFile);
    if (!file.is_open()) return false;
    
    std::string line;
    while (std::getline(file, line)) {
        size_t pos = line.find('=');
        if (pos != std::string::npos) {
            std::string key = line.substr(0, pos);
            std::string value = line.substr(pos + 1);
            settings[key] = value;
        }
    }
    return true;
}

bool Preferences::save() {
    std::ofstream file(configFile);
    if (!file.is_open()) return false;
    
    for (const auto& pair : settings) {
        file << pair.first << "=" << pair.second << std::endl;
    }
    return true;
}
