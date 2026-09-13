#pragma once

enum class MenuChoice { ShowColor, SetColor, Invalid };

MenuChoice parseMenuChoice(const char* line);
