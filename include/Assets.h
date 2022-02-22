//
// Created by pedro on 22/02/2022.
//

#ifndef IDJ_ENGINE_ASSETS_H
#define IDJ_ENGINE_ASSETS_H


#include <string>

#define IDE 1

class Assets {
public:
    static std::string getPrefix();

    static std::string getAudio(std::string);

    static std::string getImg(std::string);

    static std::string getMap(std::string);
};

#endif // IDJ_ENGINE_ASSETS_H