//
// Created by pedro on 06/02/2022.
//

#include "../include/Component.h"

Component::Component(GameObject &associated) : associated(associated) {
}

Component::~Component() = default;