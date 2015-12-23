/*
 * Copyright (C) 2015  Zubax Robotics  <info@zubax.com>
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 *
 * Author: Pavel Kirienko <pavel.kirienko@zubax.com>
 */

#pragma once

#include <cstdint>
#include <array>

namespace board
{

void init();

__attribute__((noreturn))
void die(int error);

void restart();

void setStatusLED(bool state);
void setTrafficLED(bool state);

void enableCANPower(bool state);
void enableCANTerminator(bool state);

typedef std::array<std::uint8_t, 12> UniqueID;
void readUniqueID(UniqueID& out_bytes);

typedef std::array<std::uint8_t, 128> DeviceSignature;
bool tryReadDeviceSignature(DeviceSignature& out_sign);
bool tryWriteDeviceSignature(const DeviceSignature& sign);

}
