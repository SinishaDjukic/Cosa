/**
 * @file Cosa/Wireless/Driver/VWI/Codec/HammingCodec.hh
 * @version 1.0
 *
 * @section License
 * Copyright (C) 2015, Mikael Patel
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
 * This file is part of the Arduino Che Cosa project.
 */

#ifndef COSA_WIRELESS_DRIVER_VWI_CODEC_HAMMINGCODEC_HH
#define COSA_WIRELESS_DRIVER_VWI_CODEC_HAMMINGCODEC_HH

#include "Cosa/Wireless/Driver/VWI.hh"

/**
 * Hamming 4-to-6 bit codec for the Cosa VWI (Virtual Wire
 * Interface). Detect and correct 1-bit errors.
 */
class HammingCodec : public VWI::Codec {
public:
  /**
   * Construct VirtualWire codec with given bits per symbol, start symbol,
   * and preamble size.
   */
  HammingCodec() :
    VWI::Codec(8, 0x5a55, 8)
  {
  }

  /**
   * @override VWI::Codec
   * Returns pointer to Hamming frame preamble in program memory.
   * @return pointer.
   */
  virtual const uint8_t* get_preamble()
  {
    return (preamble);
  }

  /**
   * @override VWI::Codec
   * Returns symbol for given 4-bit data.
   * @param[in] nibble data.
   * @return 8-bit symbol code.
   */
  virtual uint8_t encode4(uint8_t nibble)
  {
    return (pgm_read_byte(&symbols[nibble & 0xf]));
  };

  /**
   * @override VWI::Codec
   * Returns 4-bit data for given symbol.
   * @param[in] symbol code.
   * @return 4-bit data.
   */
  virtual uint8_t decode4(uint8_t symbol)
  {
    return (pgm_read_byte(&codes[symbol]) & 0x0f);
  }

private:
  /** Symbol mapping table: 4 to 8 bits */
  static const uint8_t symbols[] PROGMEM;

  /** Code mapping table: 8 to 4 bits */
  static const uint8_t codes[] PROGMEM;

  /** Message preamble with start symbol */
  static const uint8_t preamble[] PROGMEM;
};

#endif