/*
 * This file is free software; you can redistribute it and/or modify
 * it under the terms of either the GNU General Public License version 2
 * or the GNU Lesser General Public License version 2.1, both as
 * published by the Free Software Foundation.
 */

/**************************************************************************************
 * INCLUDE
 **************************************************************************************/

#include "CanMsgRingbuffer.h"

/**************************************************************************************
 * NAMESPACE
 **************************************************************************************/

namespace arduino
{

/**************************************************************************************
 * CTOR/DTOR
 **************************************************************************************/

CanMsgRingbuffer::CanMsgRingbuffer()
: _head{0}
, _tail{0}
, _num_elems{0}
{
}

/**************************************************************************************
 * PUBLIC MEMBER FUNCTIONS
 **************************************************************************************/

void CanMsgRingbuffer::enqueue(CanMsg const & msg)
{
  if (isFull())
    return;

  _buf[_head] = msg;
  _head = next(_head);
  _num_elems = _num_elems + 1;
}

CanMsg CanMsgRingbuffer::dequeue()
{
  if (isEmpty())
    return CanMsg();

  CanMsg const msg = _buf[_tail];
  _tail = next(_tail);
  _num_elems = _num_elems - 1;

  return msg;
}

/**************************************************************************************
 * NAMESPACE
 **************************************************************************************/

} /* arduino */
