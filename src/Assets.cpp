
#include "Assets.h"

std::string Assets::getAudio(std::string path) {
    return getPrefix() + "audio/" + path;
}

std::string Assets::getImg(std::string path) {
    return getPrefix() + "img/" + path;
}

std::string Assets::getMap(std::string path) {
    return getPrefix() + "map/" + path;
}

std::string Assets::getPrefix() {
    if (IDE) {
        return "../assets/";
    } else {
        return "./assets/";
    }
}
