/**
 * @file CosaPingPong.ino
 * @version 1.0
 *
 * @section License
 * Copyright (C) 2012, Mikael Patel
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
 * You should have received a copy of the GNU Lesser General
 * Public License along with this library; if not, write to the
 * Free Software Foundation, Inc., 59 Temple Place, Suite 330,
 * Boston, MA  02111-1307  USA
 *
 * @section Description
 * Cosa FSM example with three interacting finite state machines.
 * 
 * This file is part of the Arduino Che Cosa project.
 */

#include "Cosa/FSM.h"
#include "Cosa/Event.h"
#include "Cosa/Watchdog.h"

/**
 * Simple echo state machine: Listens for an event. When received
 * steps to echo state and on a timeout prints its name and sends an
 * event before stepping back to listen state.
 */
class Echo : public FSM {

private:
  FSM* _port;
  const char* _name;

public:
  /**
   * Construct the echo state machine. Put in listen state as
   * initial state when started. Name and port must be bound
   * before started.
   */
  Echo() : FSM(listenState), _port(0), _name(0) {}

  /**
   * Bind name and port. The name is used for the trace print
   * and the state machine will receive the echo event.
   * @param[in] name string in program memory.
   * @param[in] fsm state machine to receive the event.
   */
  void bind(const char* name, FSM* fsm)
  {
    _name = name;
    _port = fsm;
  }

  /**
   * The states; listen and echo.
   */
  static bool listenState(FSM* fsm, uint8_t type)
  {
    Echo* echo = (Echo*) fsm;
    trace.print_P(echo->_name);
    fsm->set_state(echoState);
    fsm->set_timer(512);
    return (1);
  }

  static bool echoState(FSM* fsm, uint8_t type)
  {
    Echo* echo = (Echo*) fsm;
    echo->_port->send(Event::USER_TYPE);
    fsm->set_state(listenState);
  };
};

// The three echo state machines
Echo ping;
Echo pong;
Echo pang;

void setup()
{
  // Start the trace output stream
  trace.begin(9600, PSTR("CosaPingPong: started"));

  // Start the watchdog for timeout handling
  Watchdog::begin(16, SLEEP_MODE_IDLE, Watchdog::push_timeout_events);

  // Bind the state machines to each other and give them names
  ping.bind(PSTR("ping > "), &pong);
  pong.bind(PSTR("pong > "), &pang);
  pang.bind(PSTR("pang!\n"), &ping);

  // Start the state machines
  ping.begin();
  pong.begin();
  pang.begin();

  // And send an event to the first to kick them off
  ping.send(Event::USER_TYPE);
}

void loop()
{
  // The basic event dispatcher
  Event event;
  Event::queue.await(&event);
  event.dispatch();
}

