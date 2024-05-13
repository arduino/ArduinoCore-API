/*
 * This file is free software; you can redistribute it and/or modify
 * it under the terms of either the GNU General Public License version 2
 * or the GNU Lesser General Public License version 2.1, both as
 * published by the Free Software Foundation.
 */

#ifndef ARDUINOCORE_API_CAN_MSG_RING_BUFFER_H_
#define ARDUINOCORE_API_CAN_MSG_RING_BUFFER_H_

/**************************************************************************************
 * INCLUDE
 **************************************************************************************/

#include <stdint.h>

#include "CanMsg.h"

/**************************************************************************************
 * NAMESPACE
 **************************************************************************************/

namespace arduino
{

/**************************************************************************************
 * CLASS DECLARATION
 **************************************************************************************/

class CanMsgRingbuffer
{
public:
  static size_t constexpr RING_BUFFER_SIZE = 32U;

  CanMsgRingbuffer();

  inline bool isFull() const { return (_num_elems == RING_BUFFER_SIZE); }
  void enqueue(CanMsg const & msg);

  inline bool isEmpty() const { return (_num_elems == 0); }
  CanMsg dequeue();

  inline size_t available() const { return _num_elems; }

private:
  CanMsg _buf[RING_BUFFER_SIZE];
  volatile size_t _head;
  volatile size_t _tail;
  volatile size_t _num_elems;

  inline size_t next(size_t const idx) const { return ((idx + 1) % RING_BUFFER_SIZE); }
};

/**************************************************************************************
 * NAMESPACE
 **************************************************************************************/

} /* arduino */

#endif /* ARDUINOCORE_API_CAN_MSG_RING_BUFFER_H_ */
