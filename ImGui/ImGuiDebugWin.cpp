#include "ImGuiDebugWin.h"

std::vector<std::string> ImGuiDebugWin::messages = {};


std::vector<std::string> ImGuiDebugWin::getMessages()
{
    return messages;
}

void ImGuiDebugWin::AddMessage(const std::string message) {   
    if (!message.empty()) {
        messages.push_back(message);
    }
}

void ImGuiDebugWin::ClearMessages() {
    messages.clear();
}

