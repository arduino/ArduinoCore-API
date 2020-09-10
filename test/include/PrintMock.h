/*
 * Copyright (c) 2020 Arduino.  All rights reserved.
 */

#ifndef PRINT_MOCK_H_
#define PRINT_MOCK_H_

/**************************************************************************************
 * INCLUDE
 **************************************************************************************/

#include <string>

#include <Print.h>

/**************************************************************************************
 * CLASS DECLARATION
 **************************************************************************************/

class PrintMock : public Print
{
public:
  std::string _str;
  virtual size_t write(uint8_t b) override;
};

#endif /* PRINT_MOCK_H_ */
