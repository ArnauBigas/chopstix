/*
#
# ----------------------------------------------------------------------------
#
# Copyright 2019 IBM Corporation
#
# Licensed under the Apache License, Version 2.0 (the "License");
# you may not use this file except in compliance with the License.
# You may obtain a copy of the License at
#
# http://www.apache.org/licenses/LICENSE-2.0
#
# Unless required by applicable law or agreed to in writing, software
# distributed under the License is distributed on an "AS IS" BASIS,
# WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
# See the License for the specific language governing permissions and
# limitations under the License.
#
# ----------------------------------------------------------------------------
#
*/
/******************************************************************************
 * NAME        : core/maps.h
 * DESCRIPTION : Parsed from /proc/<pid>/maps
 ******************************************************************************/

#pragma once

#include <string>
#include <vector>

namespace chopstix {

struct MapEntry {
    long addr[2];
    char perm[5];
    long offset;
    int dev[2];
    int inode;
    std::string path;

    bool contains(long a) const { return addr[0] <= a && a < addr[1]; }
};

std::vector<MapEntry> parse_maps(long pid);

#define CHOPSTIX_MAP_FMT "%lx-%lx %s %lx %x:%x %d %s\n"

}  // namespace chopstix
