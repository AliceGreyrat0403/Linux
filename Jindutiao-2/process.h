#pragma once

#include <stdio.h>

typedef void (*flush_t)(double total, double current, double speed, const char *userinfo);
void Process(double total, double current, double speed, const char *userinfo);

