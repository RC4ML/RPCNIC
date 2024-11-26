#pragma once

#include "util.hpp"
#include "libr.hpp"
#include <gflags/gflags.h>

static bool stop_flag;

static void ctrl_c_handler(int) { stop_flag = true; }
