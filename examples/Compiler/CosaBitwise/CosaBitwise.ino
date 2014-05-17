/**
 * @file CosaBitwise.ino
 * @version 1.0
 *
 * @section License
 * Copyright (C) 2014, Mikael Patel
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2.1 of the License, or (at your option) any later version.
 * 
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 * 
 * @section Description
 * Testing code generation of bitwise expressions.
 *
 * This file is part of the Arduino Che Cosa project.
 */

#include "Cosa/InputPin.hh"
#include "Cosa/OutputPin.hh"

// InputPin pin(Board::D0);
// OutputPin led(Board::LED);

void loop()
{
  static uint8_t chsum = 0;
  // bool state = pin.read();
  bool state = InputPin::read(Board::D0);
  chsum = (uint8_t) (chsum << 1) + state;
  // led.write(state);
  OutputPin::write(Board::LED, state);
}