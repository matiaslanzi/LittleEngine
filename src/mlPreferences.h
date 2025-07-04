#ifndef PREFERENCES_H
#define PREFERENCES_H

#include <string>
#include <fstream>
#include <map>

class Preferences {
private:
    std::map<std::string, std::string> settings;
    std::string configFile;
    
    void setDefaults();
    
public:
    Preferences(const std::string& filename = "config.txt");
    
    // Getters with default fallbacks
    float getFloat(const std::string& key, float defaultValue = 0.0f);
    int getInt(const std::string& key, int defaultValue = 0);
    bool getBool(const std::string& key, bool defaultValue = false);
    std::string getString(const std::string& key, const std::string& defaultValue = "");
    
    // Setters
    void setFloat(const std::string& key, float value);
    void setInt(const std::string& key, int value);
    void setBool(const std::string& key, bool value);
    void setString(const std::string& key, const std::string& value);
    
    // File operations
    bool load();
    bool save();
};

#endif
