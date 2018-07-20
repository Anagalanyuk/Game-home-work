#pragma once
char** StepLeft(char** level, int key, const int const rows, const int const columns, char loader, char borders, char leftsidebox, char rightsidebox);
char** StepRight(char** level, int key, const int const rows, const int const columns, char loader, char borders, char leftsidebox, char rightsidebox);
char** StepUp(char** level, int key, const int const rows, const int const columns, char loader, char borders, char rightsidebox);
char** StepDown(char** level, int key, const int const rows, const int const columns, char loader, char borders, char rightsidebox);