//
// Created by James Miller on 11/1/24.
//

#ifndef COMPONENTS_H
#define COMPONENTS_H

#include <string>

#include "Components/Item.h"
#include "Components/Button.h"
#include "Components/Label.h"

// Include platform specific components
//  (If not compiling for that platform, the components
//  will not be included automatically)
#include "Linux/LinuxComponents.h"
#include "Windows/WindowsComponents.h"




#endif //COMPONENTS_H
